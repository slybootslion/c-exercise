#include <iostream>
#include <random>
#include "Message.h"

Message::Message(int fromUserId, int toUserId, string &messageContent) :
	FromUserId{fromUserId},
	ToUserId{toUserId},
	MessageContent{messageContent},
	MessageId{createMessageId()} {
  MsgCount += 1;
}

void Message::SendMessage() {

}

[[maybe_unused]] int Message::createMessageId() {
  return 0;
}
