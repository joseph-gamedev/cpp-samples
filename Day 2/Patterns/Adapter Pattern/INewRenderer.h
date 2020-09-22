#pragma once

class INewRenderer
{
public:
	virtual ~INewRenderer() {}

	virtual void Awake() = 0;
	virtual void Start() = 0;
	virtual void Update(float deltaTime) = 0;
	virtual void PostUpdate(float deltaTime) = 0;
	virtual void Stop() = 0;
};