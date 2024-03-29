#pragma once

#include <string>

using namespace std;

namespace Message1
{
	class Message
	{
	public:
		Message(int fromUserId, int toUserId, string& messageContent);

		void SendMessage();

		const int MessageId;
		const int ToUserId;
		const int FromUserId;
		const string& MessageContent;
		static inline int MsgCount{ 0 };
	private:
		int createMessageId();
	};

	void main();
}

namespace Message2
{
	void main();
}

