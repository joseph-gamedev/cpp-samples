#pragma once

class IOldRenderer
{
public:
	virtual ~IOldRenderer() {}

	virtual void Init() = 0;
	virtual void Step(float deltaTime) = 0;
	virtual void Shutdown() = 0;
};