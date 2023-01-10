#include "Message.h"

namespace Message3
{
	class Message
	{
	public:
		Message() : MessageId{ createMessageId() } {
		}

		const unsigned int MessageId;

		virtual void SendMessage() = 0;

	private:
		static unsigned int createMessageId() {
			random_device dev;
			return dev();
		}
	};

	class TextMessage : public Message
	{
	public:
		TextMessage() : Message() {
		}

		void SendMessage() override {
			cout << "send text message: " << MessageId << ":" << Text << endl;
		}

		string Text;
	};

	class FileMessage : public Message
	{
	public:
		FileMessage() : Message() {
		}

		void SendMessage() override {
			cout << "send file message：" << MessageId << ":" << FilePath << endl;
		}

		string FilePath;
	};

	void Send(Message& msg) {
		msg.SendMessage();
	}

	void main() {
		{
			TextMessage txtMsg;
			txtMsg.Text = "明天下午有个会";
			Send(txtMsg);
		}
		{
			FileMessage fileMsg;
			fileMsg.FilePath = "c://hello.png";
			Send(fileMsg);
		}
	}
}
