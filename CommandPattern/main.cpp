#include <iostream>
#include "command.h"


int main()
{
	JumpCommand jumpCommand1;
	JumpCommand jumpCommand2;
	DuckCommand duckCommand;
	FireCommand fireCommand;

	auto inputHandler = std::make_unique<CommandHandler>();
	// ...
	// certain actions lead to inputs that each one will call exactly one of these methods:
	inputHandler->executeCommand( jumpCommand1 );
	inputHandler->executeCommand( jumpCommand2 );
	inputHandler->executeCommand( duckCommand );
	inputHandler->executeCommand( fireCommand );

	//std::cout << "sizeof(Command<JumpCommand>)="
	//	<< sizeof( Command<JumpCommand> ) << '\n'
	//	<< "sizeof(JumpCommand)=" << sizeof( JumpCommand ) << '\n'
	//	<< "sizeof(JumpCommand)=" << sizeof( DuckCommand ) << '\n'
	//	<< "sizeof(JumpCommand)=" << sizeof( FireCommand ) << '\n'
	//	<< "sizeof(CommandHandler)=" << sizeof( CommandHandler ) << '\n'
	//	<< "sizeof(inputHandler)=" << sizeof( inputHandler ) << '\n'
	//	<< "sizeof(*inputHandler)=" << sizeof( *inputHandler ) << '\n';
	
	// Undoable Operations
	std::cout << "undoing stuff" << '\n';
	inputHandler->undoCommand( jumpCommand1 );
	inputHandler->undoCommand( jumpCommand2 );
	inputHandler->undoCommand( duckCommand );
	inputHandler->undoCommand( fireCommand );

	std::cout << "redoing stuff" << '\n';
	inputHandler->redoCommand( jumpCommand1 );
	inputHandler->redoCommand( jumpCommand2 );
	inputHandler->redoCommand( duckCommand );
	inputHandler->redoCommand( fireCommand );

	#if defined _DEBUG && !defined NDEBUG
		while ( !getchar() );
	#endif
		return EXIT_SUCCESS;
}