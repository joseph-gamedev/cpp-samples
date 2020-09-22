#pragma once

#include "INewRenderer.h"

class IOldRenderer;

class RendererAdapter : public INewRenderer
{
public:
	RendererAdapter(IOldRenderer& oldRenderer);

	virtual void Awake() override {}
	virtual void Start() override;
	virtual void Update(float deltaTime) override;
	virtual void PostUpdate(float deltaTime)  override  {}
	virtual void Stop() override;

private:
	IOldRenderer* m_OldRenderer;
};

