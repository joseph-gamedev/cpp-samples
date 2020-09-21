#pragma once

class Message;
class SubscriberService;

class Publisher
{
public:
	void PublishMessage(Message* msg, SubscriberService* subsriberService);
};