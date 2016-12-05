#include "InputManager.h"
void InputManager::onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event) {
	keyState[(int)keyCode] = true;
	
}

void InputManager::onKeyReleased(EventKeyboard::KeyCode keyCode, Event* event) {
	keyState[(int)keyCode] = false;
}

void InputManager::updateCheck(float dt) {
	for (int i = 0; i < allInputKeys.size; i++) {
		InputKeys item = allInputKeys.at(i);
		if (keyState[(int)item.up]) {
			up_command->execute(i);
		}
		if (keyState[(int)item.down]) {
			down_command->execute(i);
		}
		if (keyState[(int)item.left])
		{
			left_command->execute(i);
		}
		if (keyState[(int)item.right]) {
			right_command->execute(i);
		}
	}
}
