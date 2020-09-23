#pragma once

class Message;
class PublisherService;

class Publisher
{
public:
	void PublishMessage(Message* msg, PublisherService* publisherService);
};