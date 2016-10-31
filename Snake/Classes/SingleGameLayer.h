#ifndef _SINGLEGAME_LAYER_H_
#define _SINGLEGAME_LAYER_H_
#include "cocos2d.h"
#include "BackGroundLayer.h"
#include "SnakeNode.h"
#include "FoodNode.h"
#include "WallLayer.h"
#include "EndLayer.h"
#include <vector>
#include "SimpleAudioEngine.h"
USING_NS_CC;
using namespace std;
using namespace CocosDenshion;
class SingleGameLayer :public Layer{
public:
	SingleGameLayer();
	~SingleGameLayer();
	virtual bool init();
	CREATE_FUNC(SingleGameLayer);
private:
	void myupdate(float delta);
	void update(float delta);
	void makefood();
	void outfood(float delta);
	void notup(float delta);
	void outscore(int a);
	SnakeNode* snakehead;
	void SingleGameLayer::onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event);
	void SingleGameLayer::onKeyReleased(EventKeyboard::KeyCode keyCode, Event* event);
	int pressdirection;
	int releasedirection;
	CCArray* snakebody;
	Sprite* food;
	SnakeNode* body;
	SnakeNode* lastbody;
	SnakeNode* tempbody;
	vector<CCPoint> turnpoi;
	WallLayer* wall;
	CCPoint temppoi;
	CCRect snakeheadrect;
	CCRect snakebodyrect;
	CCRect foodrect;
	int _vp;
	int time;
	bool isBounding;
	bool eatfood;
	bool havefood;
	bool vup;
	bool ifvup;
};
#endif