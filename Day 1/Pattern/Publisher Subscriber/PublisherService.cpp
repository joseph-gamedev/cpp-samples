#include "PublisherService.h"
#include "Message.h"
#include "Subscriber.h"

PublisherService::~PublisherService()
{
	m_messages.clear();
	m_subscriberMap.clear();
}

void PublisherService::AddMessage(Message* msg)
{
	m_messages.push_back(msg);
}

void PublisherService::AddSubscriber(TMsgType msgType, Subscriber* subscriber)
{
	m_subscriberMap[msgType].push_back(subscriber);
}

void PublisherService::RemoveSubscriber(TMsgType msgType, Subscriber* subscriber)
{
	m_subscriberMap.erase(msgType);
}

void PublisherService::BroadCast()
{
	for (int count = 0; count < m_messages.size(); count++)
	{
		Message* msg = m_messages[count];
		if (msg)
		{
			auto& subscriberList = m_subscriberMap[msg->GetType()];
			for (auto subscriber : subscriberList)
			{
				subscriber->OnMessageRecieved(msg);
			}
		}
	}
}

void PublisherService::ClearAllMessages()
{
	for (auto msg : m_messages)
	{
		if (msg)
		{
			delete msg;
			msg = nullptr;
		}
	}
	m_messages.clear();
}
