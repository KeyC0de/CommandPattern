#pragma once

#include <memory>


namespace
{

enum class CommandId
{
	JUMP = 1,
	DUCK,
	FIRE
};

inline std::size_t getNextUniqueTypeId()
{
	static std::size_t id = 0;
	std::size_t result = id;
	++id;
	return result;
}

template<typename T>
constexpr std::size_t type_id()
{
	static std::size_t typeId = getNextUniqueTypeId();
	return typeId;
}

}

template<typename T>
class Command
{
	int m_state;		// sample object state that represents the command request content
	int m_previousState;// extra state to support undoable operations
	int m_nextState;	// extra state to support redoable operations
	// eg. state could be x, y, z vars and previousState could be xBefore, yBefore, zBefore
	//      thus support for undoable operations comes with the doubling of memory required per a Command object (n levels on undo means * n amount of storage required)
	//template<typename T>
	//std::stack<Command<T>> m_commands;
	static inline int typeId;
protected:
	explicit Command( int state,
		int previousState,
		int nextState )
		:
		m_state(state),
		m_previousState(previousState),
		m_nextState(nextState)
	{
		static_assert( std::is_base_of_v<Command, T>,
			"Derived class doesn't inherit from Command! Exiting.." );
	}
public:
	constexpr int getTypeId()
	{
		typeId = static_cast<int>( type_id<Command<T>>() );
		return typeId;
	}

	Command( const Command& rhs ) = delete;
	Command& operator=( const Command& rhs ) = delete;

	Command( Command&& rhs ) noexcept
		:
		m_state{std::move( rhs.m_state )},
		m_previousState{std::move( rhs.m_previousState )},
		m_nextState{std::move( rhs.m_nextState )}
	{
		typeId = type_id<Command<T>>();
	}
	
	Command& operator=( Command&& rhs ) noexcept
	{
		std::swap( m_state, rhs.m_state );
		std::swap( m_previousState, rhs.m_previousState );
		std::swap( m_nextState, rhs.m_nextState );
		return *this;
	}

	//===================================================
	//	\function	execute
	//	\brief  executes the command
	//	\date	2020/11/04 0:32
	void execute()
	{
		static_cast<T*>( this )->execute();
	}

	//===================================================
	//	\function	undo
	//	\brief  revert to previous state
	//	\date	2020/11/04 0:31
	void undo()
	{
		m_nextState = m_state;
		m_state = m_previousState;
		static_cast<T*>( this )->undo();
		std::cout << "Undoing previous Command as requested\n";
	}

	void redo()
	{
		std::cout << "Redoing previous Command as requested\n";
		m_previousState = m_state;
		m_state = m_nextState;
		static_cast<T*>( this )->redo();
	}
};
 
class JumpCommand final
	: public Command<JumpCommand>
{
	// each command can have other state here
public:
	JumpCommand();
	void execute();
	void undo();
	void redo();
};

class DuckCommand final
	: public Command<DuckCommand>
{
public:
	DuckCommand();
	void execute();
	void undo();
	void redo();
};

class FireCommand final
	: public Command<FireCommand>
{
public:
	FireCommand();
	void execute();
	void undo();
	void redo();
};


//============================================================
//	\class	CommandHandler
//
//	\author	KeyC0de
//	\date	2020/11/04 0:25
//
//	\brief	owns and handles the commands
//=============================================================
class CommandHandler final
{
private:
	std::unique_ptr<JumpCommand> m_pJumpCommand;
	std::unique_ptr<DuckCommand> m_pDuckCommand;
	std::unique_ptr<FireCommand> m_pFireCommand;
public:
	explicit CommandHandler();
	CommandHandler( JumpCommand* jmpCmd, DuckCommand* duckCmd, FireCommand* fireCmd );
	~CommandHandler() = default;

	CommandHandler( const CommandHandler& ) = delete;
	CommandHandler& operator=( const CommandHandler& ) = delete;
	CommandHandler( CommandHandler&& rhs ) noexcept;
	CommandHandler& operator=( CommandHandler&& rhs ) noexcept;
	
	//===================================================
	//	\function	executeCommand
	//	\brief  dispatches commands
	//	\date	2020/11/04 0:26
	template<typename T>
	void executeCommand( Command<T>& command )
	{
		switch( command.getTypeId() )
		{
		case static_cast<int>( CommandId::JUMP ):
			command.execute();
			break;
		case static_cast<int>( CommandId::DUCK ):
			command.execute();
			break;
		case static_cast<int>( CommandId::FIRE ):
			command.execute();
			break;
		default:
			break;
		}
	}
};
