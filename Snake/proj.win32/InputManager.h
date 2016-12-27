#ifndef _INPUT_MANAGER_H_
#define _INOUT_MANAGER_H_
#include "cocos2d.h"
#include "InputConcreteCommand.h"

USING_NS_CC;
using namespace std;

struct InputKeys
{
public:
	EventKeyboard::KeyCode up;
	EventKeyboard::KeyCode down;
	EventKeyboard::KeyCode left;
	EventKeyboard::KeyCode right;
};
class InputManager : Layer{
public:
	static InputManager* getInstance() {
		if (instance != NULL) {
			instance = new InputManager();
		}
		return instance;
	}
	~InputManager();
private:
	static InputManager* instance;
	InputManager() {
		schedule(schedule_selector(InputManager::updateCheck), 1.0f);
		listenerkeyPad = EventListenerKeyboard::create();
		listenerkeyPad->setEnabled(true);
		listenerkeyPad->onKeyPressed = CC_CALLBACK_2(InputManager::onKeyPressed, this);
		listenerkeyPad->onKeyReleased = CC_CALLBACK_2(InputManager::onKeyReleased, this);
		_eventDispatcher->addEventListenerWithSceneGraphPriority(listenerkeyPad, this);
	}
	EventListenerKeyboard* listenerkeyPad;
	void onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event);
	void onKeyReleased(EventKeyboard::KeyCode keyCode, Event* event);
	bool keyState[170];//“‘KeyCode∂®Œª
	vector<InputKeys> allInputKeys;
	MoveUpCommand* up_command;
	MoveDownCommand* down_command;
	MoveLeftCommand* left_command;
	MoveRightCommand* right_command;
	void updateCheck(float dt);
};




#endif // !_INPUT_MANAGER_H_

