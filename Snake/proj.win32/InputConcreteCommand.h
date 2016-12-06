#include "InputCommand.h"

class MoveUpCommand : InputCommand {
public:
	void execute(int count);
};

class MoveDownCommand : InputCommand {
public:
	void execute(int count);
};

class MoveLeftCommand : InputCommand {
public:
	void execute(int count);
};

class MoveRightCommand : InputCommand {
public:
	void execute(int count);
};

class RegisterNewSnakeCommand : InputCommand {
public:
	void execute(InputKeys &fourKeys);
};

class SetNewKeyCommand : InputCommand {
public:
	void execute(EventKeyboard::KeyCode &target, EventKeyboard::KeyCode new_key);
};