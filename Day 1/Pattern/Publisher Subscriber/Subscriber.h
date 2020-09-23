#pragma once

#include <vector>

enum class TMsgType;
class Message;
class PublisherService;

class Subscriber
{
public:

	virtual void OnMessageRecieved(Message* message) = 0;

	void Subscribe(TMsgType msgType, PublisherService* publisherService);
	void UnSubscribe(TMsgType msgType, PublisherService* publisherService);
	std::vector<Message*> GetMessagesOfType(TMsgType msgType);
	
private:

};