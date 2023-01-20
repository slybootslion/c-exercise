#include "thread.h"

namespace thread_ex
{
	void test01() {
		//定义线程函数（匿名函数），此函数接收两个参数
		auto func = [](int tId, int num) {
			for (size_t i = 0; i < num; i++) {
//				cout << this_thread::get_id() << endl;
				string str = "thread id:" + to_string(tId) + " print:" + to_string(i) + "\n";
				cout << str;
			}
		};
		// 开一个线程执行线程函数，给线程函数传入两个参数：0, 6
		thread t(func, 0, 6);
//		cout << "t id: " << t.get_id() << endl;
		// 开另一个线程执行线程函数，参数为 1, 6
		thread t2(func, 1, 6);
//		cout << "t2 id: " << t2.get_id() << endl;
		// join方法可以等待线程结束，如果线程不结束就开启另一个线程，那么两个线程是并行执行的
		// 此处两个线程就是并行执行的
		t.join();
		t2.join();
	}

	class MyClass
	{
	public:
		void Func(int a, int b) {
			for (size_t i = 0; i < a; i++)
				cout << i + b << ",";
			cout << endl;
		}
	};

	void test02() {
		MyClass obj;
		// 在新线程中执行对象上的方法，最后两个参数传递给对象方法的参数
		thread t(&MyClass::Func, &obj, 6, 1);
		t.join();
	}

	void test03() {
		auto func = [](int i) {
			string str = "第" + to_string(i) + "个线程在工作\n";
			cout << str;
		};
		unsigned int threadNum = thread::hardware_concurrency();
		threadNum = threadNum == 0 ? 2 : threadNum;
		threadNum = min((int)threadNum, 32);

		cout << "我的电脑可以开启" << threadNum << "个线程" << endl;
		for (size_t i = 0; i < threadNum; ++i) {
			thread t(func, i);
			t.detach();
		}
	}

	class Message
	{
	public:
		string SenderId;
		string MsgContent;
	};

	void test04() {
		Message msg;
		mutex locker;
		auto setMsg = [&](string&& senderId, string&& msgContent) {
			// 如果没有这个锁，msg对象的内容就是混乱的。
			unique_lock guard(locker);
			msg.SenderId = senderId;
			// 模拟耗时
			this_thread::sleep_for(chrono::seconds(1));
			msg.MsgContent = msgContent;
			string str = msg.SenderId + "  " + msg.MsgContent + "\n";
			cout << str;
		};

		auto i = 16;
		while (i > 0) {
			auto t1 = thread(setMsg, "sender" + to_string(i), "content" + to_string(i));
			t1.detach();
			i -= 1;
		}
		auto c = getchar(); // 没有这个，循环完后程序就会退出，看不到线程执行。
	}

	void test05() {
		mutex locker;
		auto readMsgList = [&]() {
			unique_lock guard(locker);
			this_thread::sleep_for(chrono::seconds(1)); // 此处只为了模拟耗时
			string str = "读消息容器\n";
			cout << str;
		};
		auto writeMsgList = [&]() {
			unique_lock guard(locker);
			this_thread::sleep_for(chrono::seconds(2));
			string str = "写消息容器\n";
			cout << str;
		};
		auto i = 16;
		while (i > 0) {
			if (i % 2 == 0) {
				auto t1 = thread(readMsgList);
				t1.detach();
			} else {
				auto t1 = thread(writeMsgList);
				t1.detach();
			}
			i -= 1;
		}
		auto c = getchar();
	}

	void test06() {
		mutex locker1;
		mutex locker2;
		auto readMsgList = [&]() {
			scoped_lock guard(locker1, locker2); // 同时锁住两个互斥体，避免死锁
			this_thread::sleep_for(chrono::seconds(1));
			string str = "读消息容器\n";
			cout << str;
		};
		auto writeMsgList = [&]() {
			scoped_lock guard(locker1, locker2); // 同时锁住两个互斥体，避免死锁
			this_thread::sleep_for(chrono::seconds(2));
			string str = "写消息容器\n";
			cout << str;
		};
		auto i = 16;
		while (i > 0) {
			if (i % 2 == 0) {
				auto t1 = thread(readMsgList);
				t1.detach();
			} else {
				auto t1 = thread(writeMsgList);
				t1.detach();
			}
			i -= 1;
		}
		auto c = ::getchar();
	}

	void test07() {
		mutex locker;
		condition_variable cv;
		auto func = [&]() {
			unique_lock guard(locker);
			cv.wait(guard);
			cout << "thread start" << endl;
			// 等待3秒后再通知主线程 让主线程继续执行
			this_thread::sleep_for(chrono::seconds(3));
			// 必须再通知主线程之前，释放锁，以避免唤醒等待的主线程之后，主线程再次阻塞
			guard.unlock();
			cv.notify_one();
			this_thread::sleep_for(chrono::seconds(3));
			cout << "thread end" << endl;
		};
		cout << "main start" << endl;
		thread t(func);
		t.detach();
		this_thread::sleep_for(chrono::seconds(3)); // 等3秒后再通知子线程开始执行
		cv.notify_one();
		unique_lock guard(locker);
		cv.wait(guard);
		guard.unlock();
		cout << "main end" << endl;
		auto c = getchar();
	}

	void func(promise<int> promiseObj) {
		// thread id会立即输出
		cout << "当前thread id：" << this_thread::get_id() << endl;
		this_thread::sleep_for(chrono::seconds(6));
		// 设置线程的返回值
		promiseObj.set_value(35);
		this_thread::sleep_for(chrono::seconds(6));
		cout << "线程执行完毕" << endl;
	}

	void test08() {
		// 设置一个接受返回值的对象，类型为：promise<int>
		promise<int> promiseObj;
		// 得到一个可以获取返回值的工具对象，类型为future<int>
		future<int> futureObj = promiseObj.get_future();
		// 开启线程，并把接受返回值的对象传递给线程函数
		thread t(func, move(promiseObj));
		// 获得返回值，get()方法会导致线程阻塞，直到返回值可用为止
		cout << futureObj.get() << endl;
		t.join();
	}

	void main() {
//		test01();
//		test02();
//		test03();
//		test04();
//		test05();
//		test06();
//		test07();
		test08();
	}
}
