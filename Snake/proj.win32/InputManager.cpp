#include "InputManager.h"
void InputManager::onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event) {
	if (state == "changing" && temp_snake_count >= 0 && temp_snake_count < allInputKeys.size()) {
		if (temp_changing_key == "up") {
			set_command->execute(allInputKeys.at(temp_snake_count).up, keyCode);
		}
		else if(temp_changing_key == "down")
		{
			set_command->execute(allInputKeys.at(temp_snake_count).down, keyCode);
		}
		else if (temp_changing_key == "left")
		{
			set_command->execute(allInputKeys.at(temp_snake_count).left, keyCode);
		}
		else if (temp_changing_key == "right")
		{
			set_command->execute(allInputKeys.at(temp_snake_count).right, keyCode);
		}
		return;
	}
	keyState[(int)keyCode] = true;
	
}

void InputManager::onKeyReleased(EventKeyboard::KeyCode keyCode, Event* event) {
	keyState[(int)keyCode] = false;
}

void InputManager::updateCheck(float dt) {
	if (state == "gaming") {


		for (int i = 0; i < allInputKeys.size; i++) {
			InputKeys item = allInputKeys.at(i);
			if (item.snake_count >= 0) {
				if (keyState[(int)item.up]) {
					up_command->execute(item.snake_count);
				}
				if (keyState[(int)item.down]) {
					down_command->execute(item.snake_count);
				}
				if (keyState[(int)item.left])
				{
					left_command->execute(item.snake_count);
				}
				if (keyState[(int)item.right]) {
					right_command->execute(item.snake_count);
				}
			}
			else if (keyState[(int)item.up] || keyState[(int)item.down] || keyState[(int)item.left] || keyState[(int)item.right]) {
				register_command->execute(allInputKeys.at(i));
			}
		}
	}
	
}
