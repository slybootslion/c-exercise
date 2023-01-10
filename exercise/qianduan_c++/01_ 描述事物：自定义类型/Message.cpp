#include <iostream>
#include <random>
#include "Message.h"

namespace Message {
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
