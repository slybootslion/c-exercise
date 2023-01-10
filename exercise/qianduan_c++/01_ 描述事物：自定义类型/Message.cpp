#include <iostream>
#include <random>
#include "Message.h"

namespace Message1
{
	Message::Message(int fromUserId, int toUserId, string& messageContent) :
			FromUserId{ fromUserId },
			ToUserId{ toUserId },
			MessageContent{ messageContent },
			MessageId{ createMessageId() } {
		MsgCount += 1;
	}

	void Message::SendMessage() {
		cout << "From: " << FromUserId << endl
			 << "To: " << ToUserId << endl
			 << "Message: " << MessageContent << endl
			 << "MessageId: " << MessageId << endl;
	}

	int Message::createMessageId() {
		std::random_device dev;
		return 0;
	}

	void main() {
		string msgContent{ "明天下午3点有个会" };
		Message* msg{ new Message(12, 34, msgContent) };
		msg->SendMessage();
		delete msg;
	}
}

namespace Message2
{
	class Message
	{
	public:
		Message(const Message& msg) = delete;

		void operator=(const Message& msg) = delete;

		unsigned int MessageId;

		~Message() {
			instance = nullptr;
		}

		static Message* getInstance() {
			if (instance == nullptr) {
				instance = new Message();
			}
			return instance;
		}

	private:
		Message() : MessageId{ createMessageId() } {
		}

		static unsigned int createMessageId() {
			random_device dev;
			return dev();
		}

		inline static Message* instance{ nullptr };
	};

	void main() {
		auto msg1 = Message::getInstance();
		auto msg2 = Message::getInstance();
		cout << "msg1->MessageId: " << msg1->MessageId << endl
			 << "msg2->MessageId: " << msg2->MessageId << endl;
		delete msg2;

		auto msg3 = Message::getInstance();
		cout << "msg3->MessageId: " << msg3->MessageId << endl;
	}
}
