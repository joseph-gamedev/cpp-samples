#include "CommandController.h"
#include "ICommand.h"

void CommandController::Execute(ICommand* command)
{
	command->Execute();
	m_undoStack.push(command);
}

void CommandController::Undo()
{
	ICommand* command = m_undoStack.top();
	if (command)
	{
		command->Undo();
	}
	m_undoStack.pop();
	m_redoStack.push(command);
}

void CommandController::Redo()
{
	ICommand* command = m_redoStack.top();
	if (command)
	{
		command->Execute();
	}
	m_redoStack.pop();
	m_undoStack.push(command);
}

void CommandController::Clear()
{
	while (!m_undoStack.empty())
	{
		ICommand* command = m_undoStack.top();
		if (command)
		{
			delete command;
			command = nullptr;
		}
		m_undoStack.pop();
	}
	while (!m_redoStack.empty())
	{
		ICommand* command = m_redoStack.top();
		if (command)
		{
			delete command;
			command = nullptr;
		}
		m_redoStack.pop();
	}
}
