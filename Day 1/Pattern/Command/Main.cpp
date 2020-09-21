#include <iostream>
#include "CommandController.h"
#include "ICommand.h"

using namespace std;

class TestCommand : public ICommand
{
public:

	void Execute() override
	{
		std::cout << "Test Command Execute" << std::endl;
	}

	void Undo() override
	{
		std::cout << "Test Command Undo" << std::endl;
	}
};


int main()
{
	CommandController::Instance()->Execute(new TestCommand());
	CommandController::Instance()->Undo();
	CommandController::Instance()->Clear();
	std::cin.get();
	return 0;
}