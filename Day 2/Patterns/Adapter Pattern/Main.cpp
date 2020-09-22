#include <iostream>
#include "IOldRenderer.h"
#include "INewRenderer.h"
#include "RendererAdapter.h"

class OldRenderer : public IOldRenderer
{
public:
	virtual void Init() override
	{
		std::cout << "Init()" << std::endl;
	}

	virtual void Step(float deltaTime) override
	{
		std::cout << "Step(float deltaTime)" << std::endl;
	}

	virtual void Shutdown() override
	{
		std::cout << "Shutdown()" << std::endl;
	}

};

int main()
{
	IOldRenderer* oldRenderer = new OldRenderer();
	INewRenderer* newRenderer = new RendererAdapter(*oldRenderer);

	newRenderer->Awake();
	newRenderer->Start();
	newRenderer->Update(0);
	newRenderer->PostUpdate(0);
	newRenderer->Stop();

	delete oldRenderer;
	delete newRenderer;
	std::cin.get();

}