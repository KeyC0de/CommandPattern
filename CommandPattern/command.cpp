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

CommandHandler::CommandHandler()
	:
	m_pJumpCommand{std::make_unique<JumpCommand>()},
	m_pDuckCommand{std::make_unique<DuckCommand>()},
	m_pFireCommand{std::make_unique<FireCommand>()}
{

}

CommandHandler::CommandHandler( JumpCommand* jmpCmd,
	DuckCommand* duckCmd,
	FireCommand* fireCmd )
	:
	m_pJumpCommand{jmpCmd},
	m_pDuckCommand{duckCmd},
	m_pFireCommand{fireCmd}
{

}

CommandHandler::CommandHandler( CommandHandler&& rhs ) noexcept
	:
	m_pJumpCommand{std::move( rhs.m_pJumpCommand )},
	m_pDuckCommand{std::move( rhs.m_pDuckCommand )},
	m_pFireCommand{std::move( rhs.m_pFireCommand )}
{

}

CommandHandler& CommandHandler::operator=( CommandHandler&& rhs ) noexcept
{
	std::swap( this->m_pJumpCommand, rhs.m_pJumpCommand );
	std::swap( this->m_pDuckCommand, rhs.m_pDuckCommand );
	std::swap( this->m_pFireCommand, rhs.m_pFireCommand );
	return *this;
}
