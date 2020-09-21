#pragma once

#include <vector>

enum class TMsgType;
class Message;
class SubscriberService;

class Subscriber
{
public:

	virtual void OnMessageRecieved(Message* message) = 0;

	void Subscribe(TMsgType msgType, SubscriberService* subscriberService);
	void UnSubscribe(TMsgType msgType, SubscriberService* subscriberService);
	std::vector<Message*> GetMessagesOfType(TMsgType msgType);
	
private:

};