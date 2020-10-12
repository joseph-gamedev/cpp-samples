#pragma once

#include <Application.h>
#include <memory>

class SandBoxApp : public Application
{
	public:
		virtual void BeginLoading() override {}
		virtual void OnLoadingCompleted() override {}
		virtual bool Init() override { return true; }
		virtual void Update(float deltaTime) override {}
		virtual void Shutdown() override {}
	
};

std::unique_ptr<Application> CreateApplication()
{
	return std::make_unique<SandBoxApp>();
}