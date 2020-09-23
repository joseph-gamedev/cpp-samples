#include "Subscriber.h"
#include "Message.h"
#include "PublisherService.h"

void Subscriber::Subscribe(TMsgType msgType, PublisherService* publisherService)
{
	publisherService->AddSubscriber(msgType, this);
}

void Subscriber::UnSubscribe(TMsgType msgType, PublisherService* publisherService)
{
	publisherService->RemoveSubscriber(msgType, this);
}
