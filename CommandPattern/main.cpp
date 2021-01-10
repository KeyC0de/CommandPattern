#include <iostream>
#include "command.h"


int main()
{
	JumpCommand jumpCommand1;
	JumpCommand jumpCommand2;
	std::cout << "jumpCommand1 type id = "
		<< jumpCommand1.getTypeId() << '\n';
	std::cout << "jumpCommand2 type id = "
		<< jumpCommand2.getTypeId() << '\n';

	DuckCommand duckCommand;
	FireCommand fireCommand;
	std::cout << "duckCommand type id = " << duckCommand.getTypeId() << '\n';
	std::cout << "fireCommand type id = " << fireCommand.getTypeId() << '\n';

	auto inputHandler = std::make_unique<CommandHandler>();
	// ...
	// certain actions lead to inputs that each one will call exactly one of these methods:
	inputHandler->executeCommand( jumpCommand1 );
	inputHandler->executeCommand( jumpCommand2 );
	inputHandler->executeCommand( duckCommand );
	inputHandler->executeCommand( fireCommand );

	std::cout << "sizeof(Command<JumpCommand>)="
		<< sizeof( Command<JumpCommand> ) << '\n'
		<< "sizeof(JumpCommand)=" << sizeof( JumpCommand ) << '\n'
		<< "sizeof(JumpCommand)=" << sizeof( DuckCommand ) << '\n'
		<< "sizeof(JumpCommand)=" << sizeof( FireCommand ) << '\n'
		<< "sizeof(CommandHandler)=" << sizeof( CommandHandler ) << '\n'
		<< "sizeof(inputHandler)=" << sizeof( inputHandler ) << '\n'
		<< "sizeof(*inputHandler)=" << sizeof( *inputHandler ) << '\n';
	
	// Undoable Operations
	std::cout << "undoing stuff" << '\n';
	jumpCommand1.undo();
	jumpCommand2.undo();
	duckCommand.undo();
	fireCommand.undo();

	std::cout << "redoing stuff" << '\n';
	jumpCommand1.redo();
	jumpCommand2.redo();
	duckCommand.redo();
	fireCommand.redo();

	system( "pause" );
	return 0;
}
