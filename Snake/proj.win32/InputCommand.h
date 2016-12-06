#include "cocos2d.h"
#include "SnakeLayer.h"
#include "SingleScene.h"
USING_NS_CC;
using namespace std;
struct InputKeys
{
public:
	int snake_count = -1;
	EventKeyboard::KeyCode up;
	EventKeyboard::KeyCode down;
	EventKeyboard::KeyCode left;
	EventKeyboard::KeyCode right;
};
class InputCommand {
public:
	virtual void execute(int count);
	virtual void execute(vector<InputKeys> &allInputKeys,InputKeys fourKeys);
	virtual void execute(EventKeyboard::KeyCode &target, EventKeyboard::KeyCode new_key);
	InputCommand() {
		
		SingleScene* gameLayer = (SingleScene*)Director::getInstance()->getRunningScene()->getChildByName("gameLayer");
		if (gameLayer != NULL) {
			for (int i = 0; i < gameLayer->snake_num; i++) {
				char temp[12];
				itoa(i, temp, 10);
				string ss = temp;
				SnakeLayer* snake = (SnakeLayer*)gameLayer->getChildByName("snake" + ss);
				allSnakes.push_back(snake);
			}
		}
	}
private:
	
protected:
	vector<SnakeLayer*> allSnakes;
};