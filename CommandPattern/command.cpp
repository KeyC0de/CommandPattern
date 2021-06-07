#include <iostream>
#include "command.h"


JumpCommand::JumpCommand()
	:
	Command<JumpCommand>( 0,
		0,
		0 )
{}

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
	Command( 0,
		0,
		0 )
{}

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
	Command( 0, 0, 0 )
{}

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
	m_jumpCommand( std::make_unique<JumpCommand>() ),
	m_duckCommand( std::make_unique<DuckCommand>() ),
	m_fireCommand( std::make_unique<FireCommand>() )
{}

CommandHandler::CommandHandler( CommandHandler&& rhs ) noexcept
	:
	m_jumpCommand{ std::move( rhs.m_jumpCommand ) },
	m_duckCommand{ std::move( rhs.m_duckCommand ) },
	m_fireCommand{ std::move( rhs.m_fireCommand ) }
{}

CommandHandler& CommandHandler::operator=( CommandHandler&& rhs ) noexcept
{
	if ( this != &rhs )
	{
		std::swap( this->m_jumpCommand, rhs.m_jumpCommand );
		std::swap( this->m_duckCommand, rhs.m_duckCommand );
		std::swap( this->m_fireCommand, rhs.m_fireCommand );
	}
	return *this;
}
