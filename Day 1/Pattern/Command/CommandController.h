#pragma once

#include <stack>

//!Forward declarations
class ICommand;

//! \class CommandController 
//! \brief Manages commands
class CommandController
{
public:

    //!Singleton instance
    static CommandController* Instance()
    {
        static CommandController instance;
        return &instance;
    }

    //! Method for executing commands
    /*!
      \param ICommand a command argument.
    */
    void Execute(ICommand* command);

    //! Method for undo commands
    void Undo();

	//! Method for redo commands
	void Redo();

    //! Method for clearing command history
    void Clear();

private:

    //! Stack for storing commands to undo
    std::stack<ICommand*> m_undoStack;

    //! Stack for storing commands to redo
    std::stack<ICommand*> m_redoStack;
};

