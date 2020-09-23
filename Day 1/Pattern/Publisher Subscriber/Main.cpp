#include <iostream>
#include "Publisher.h"
#include "Subscriber.h"
#include "Message.h"
#include "PublisherService.h"

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
	PublisherService publisherService;
	publisherService.AddSubscriber(TMsgType::kTestMsg, (Subscriber*)&subscriber);

	TestPublisher publisher;
	TestMsg* msg = new TestMsg();
	publisher.PublishMessage(msg, &publisherService);
	publisherService.BroadCast();
	publisherService.ClearAllMessages();

	return 0;
}