#include <iostream>
#include "command.h"


JumpCommand::JumpCommand()
	:
	Command<JumpCommand>{0, 0, 0}
{

}

void JumpCommand::execute()
{
	std::cout << "Jump around! Jump around! Jump up, jump up and get down!"
		"\n Jump Jump Jump!\n";
}

void JumpCommand::undo()
{

}

void JumpCommand::redo()
{

}

DuckCommand::DuckCommand()
	:
	Command{0, 0, 0}
{

}

void DuckCommand::execute()
{
	std::cout << "Duck! The DUck!\n";
}

void DuckCommand::undo()
{

}

void DuckCommand::redo()
{

}

FireCommand::FireCommand()
	:
	Command{0, 0, 0}
{

}

void FireCommand::execute()
{
	std::cout << "Fire all missiles!\n";
}

void FireCommand::undo()
{

}

void FireCommand::redo()
{

}