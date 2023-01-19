#include "thread.h"

namespace thread_ex
{
	void test01() {
		//定义线程函数（匿名函数），此函数接收两个参数
		auto func = [](int tId, int num)
		{
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
		auto func = [](int i)
		{
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

	void main() {
//		test01();
//		test02();
		test03();

	}
}
