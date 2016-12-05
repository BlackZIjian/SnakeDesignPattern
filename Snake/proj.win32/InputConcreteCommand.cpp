#include "InputConcreteCommand.h"

void MoveUpCommand::execute(int count) {
	SnakeLayer* snake = allSnakes.at(count);
	snake->move(UP);
}

void MoveDownCommand::execute(int count) {
	SnakeLayer* snake = allSnakes.at(count);
	snake->move(DOWN);
}

void MoveLeftCommand::execute(int count) {
	SnakeLayer* snake = allSnakes.at(count);
	snake->move(LEFT);
}

void MoveRightCommand::execute(int count) {
	SnakeLayer* snake = allSnakes.at(count);
	snake->move(RIGHT);
}