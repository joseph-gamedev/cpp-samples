#pragma once

#include <memory>

class Application
{
	public:
	
		virtual ~Application(){}
		
		bool Start(){ return true; }
		void Update(){}
		void End(){}
		
		bool IsRunning(){ return true; }
		
protected:

		virtual void BeginLoading() {}
		virtual void OnLoadingCompleted() {}
		virtual bool Init(){ return true; }
		virtual void Update(float deltaTime) {}
		virtual void Shutdown() {}
};

extern std::unique_ptr<Application> CreateApplication();