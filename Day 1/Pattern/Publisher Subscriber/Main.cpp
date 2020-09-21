#include <iostream>
#include "Publisher.h"
#include "Subscriber.h"
#include "Message.h"
#include "SubscriberService.h"

using namespace std;

class TestPublisher : public Publisher
{


};

class TestSubscriber : Subscriber
{

public:
	void OnMessageRecieved(Message* message) override
	{
		std::cout << "TestSubscriber msg received" << endl;
	}

};

class TestMsg : public Message
{
public:
	TestMsg()
	: Message(TMsgType::kTestMsg)
	{
	
	}
};


int main()
{	
	TestSubscriber subscriber;
	SubscriberService subscriberService;
	subscriberService.AddSubscriber(TMsgType::kTestMsg, (Subscriber*)&subscriber);

	TestPublisher publisher;
	TestMsg* msg = new TestMsg();
	publisher.PublishMessage(msg, &subscriberService);
	subscriberService.BroadCast();
	subscriberService.ClearAllMessages();

	return 0;
}