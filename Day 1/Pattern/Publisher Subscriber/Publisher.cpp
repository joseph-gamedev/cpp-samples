#include "Publisher.h"
#include "SubscriberService.h"

void Publisher::PublishMessage(Message* msg, SubscriberService* subsriberService)
{
	subsriberService->AddMessage(msg);
}
