#include <memory>
#include "Message.h"

namespace Message4
{
	class Message
	{
	public:
		Message() : val{ "this is long length string" } {
		}

		~Message() = default;

		void SendMessage() {
			cout << val << endl;
		}

		string val;
	};

	class MessageRAII
	{
	public:
		MessageRAII() : msgObj{ new Message() } {
		};

		Message* get() {
			return msgObj;
		}

		~MessageRAII() {
			delete msgObj;
		}

		Message* msgObj;
	};

	class MyClass
	{
	public:
		MyClass() {
			val = 123;
		}

		~MyClass() = default;

		int val;
	};

	void shared_ptr_main() {
		shared_ptr<MyClass> myClass0 = make_shared<MyClass>();
		cout << "myClass0 useCount: " << myClass0.use_count() << endl;
		{
			shared_ptr<MyClass> myClass1{ myClass0 };
			cout << "myClass0 useCount: " << myClass0.use_count() << endl;
			cout << "myClass1 useCount: " << myClass1.use_count() << endl;
			{
				shared_ptr<MyClass> myClass2{ myClass1 };
				cout << "myClass1 useCount: " << myClass1.use_count() << endl;
				cout << "myClass2 useCount: " << myClass2.use_count() << endl;
			}
		}
		cout << "myClass0 useCount: " << myClass0.use_count() << endl;
	}

	void unique_ptr_main() {
		unique_ptr<MyClass> myClass = make_unique<MyClass>();
		myClass = make_unique<MyClass>(); // 独占指针可以被重新赋值，一旦被重新赋值，之前关联的堆空间立即被释放
		cout << "myClass->val: " << myClass->val << endl;
	}

	void main() {
//		MessageRAII msgRAIIobj;
//		msgRAIIobj.get()->SendMessage();
//		shared_ptr_main();
		unique_ptr_main();
	}


}
