#pragma once

//! Command interface 
class ICommand
{
public:

	//! virtual destructor
	virtual ~ICommand() {}

	//! Override this method for executing action
	virtual void Execute() = 0;

	//! Override this for undo the actions executed
	virtual void Undo() = 0;
};