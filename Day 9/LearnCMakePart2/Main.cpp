#include <iostream>
#include <Application.h>
#include <memory>

int main ()
{
	std::unique_ptr<Application> application = CreateApplication();

	//Initalize app
	if(!application->Start())
	{	
		std::cout <<"Application failed to start" <<std::endl;
		return 1;
	}
	
	//Game loop
	while(application->IsRunning())
	{
		application->Update();
	}
	
	//Clean up before closing application
	application->End();
	
	std::cout <<"CMake Lesson 2" <<std::endl;
}