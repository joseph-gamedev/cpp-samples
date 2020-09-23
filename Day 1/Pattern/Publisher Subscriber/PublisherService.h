#pragma once

#include <map>
#include <vector>

enum  class TMsgType;
class Message;
class Subscriber;

class PublisherService
{
public:
	~PublisherService();
	void AddMessage(Message* msg);
	void AddSubscriber(TMsgType msgType, Subscriber* subscriber);
	void RemoveSubscriber(TMsgType msgType, Subscriber* subscriber);
	void BroadCast();
	void ClearAllMessages();
private:

	std::map<TMsgType, std::vector<Subscriber*>> m_subscriberMap;
	std::vector<Message*> m_messages;
};

