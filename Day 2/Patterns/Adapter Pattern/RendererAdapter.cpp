#include "RendererAdapter.h"
#include "IOldRenderer.h"

RendererAdapter::RendererAdapter(IOldRenderer& oldRenderer)
	: m_OldRenderer(&oldRenderer)
{

}

void RendererAdapter::Start()
{
	m_OldRenderer->Init();
}

void RendererAdapter::Update(float deltaTime)
{
	m_OldRenderer->Step(deltaTime);
}

void RendererAdapter::Stop()
{
	m_OldRenderer->Shutdown();
}
