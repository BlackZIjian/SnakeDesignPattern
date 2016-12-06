
#include "InputManager.h"

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

void RegisterNewSnakeCommand::execute(InputKeys &fourKeys) {
	SingleScene* m_game_since = SingleScene::instance;
	int snake_count = m_game_since->AddNewSnake();
	fourKeys.snake_count = snake_count;
}

void SetNewKeyCommand::execute(EventKeyboard::KeyCode &target, EventKeyboard::KeyCode new_key) {
	target = new_key;
}