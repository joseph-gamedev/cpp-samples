#include "Publisher.h"
#include "PublisherService.h"

void Publisher::PublishMessage(Message* msg, PublisherService* publisherService)
{
	publisherService->AddMessage(msg);
}
