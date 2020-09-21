#include "Subscriber.h"
#include "Message.h"
#include "SubscriberService.h"

void Subscriber::Subscribe(TMsgType msgType, SubscriberService* subscriberService)
{
	subscriberService->AddSubscriber(msgType, this);
}

void Subscriber::UnSubscribe(TMsgType msgType, SubscriberService* subscriberService)
{
	subscriberService->RemoveSubscriber(msgType, this);
}
