#ifndef _GAME_LAYER_H_
#define _GAME_LAYER_H_
#include "cocos2d.h"
#include "BackGroundLayer.h"
#include "SnakeNode.h"
#include "Snake2Node.h"
#include "FoodNode.h"
#include "EndLayer.h"
#include "WallLayer.h"
#include <vector>
#include "SimpleAudioEngine.h"
USING_NS_CC;
using namespace std;
using namespace CocosDenshion;
class GameLayer :public Layer{
public:
	GameLayer();
	~GameLayer();
	virtual bool init();
	CREATE_FUNC(GameLayer);
	bool gameover;
private:
	void update(float delta);
	void myupdate(float delta);
	void myupdate2(float delta);
	void makefood();
	void notup(float delta);
	void notup2(float delta);
	void outfood(float delta);
	void who(int w);
	SnakeNode* snakehead;
	Snake2Node* snake2head;
	void GameLayer::onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event);
	void GameLayer::onKeyReleased(EventKeyboard::KeyCode keyCode, Event* event);
	int pressdirection;
	int pressdirection2;
	int releasedirection;
	int releasedirection2;
	Sprite* food;
	int _vp;
	int _vp2;
	CCArray* snakebody;
	CCArray* snake2body;
	SnakeNode* body;
	Snake2Node* body2;
	SnakeNode* lastbody;
	SnakeNode* tempbody;
	Snake2Node* temp2body;
	WallLayer* wall;
	CCPoint turnpoi;
	CCPoint temppoi;
	CCRect snakeheadrect;
	CCRect snakehead2rect;
	CCRect snakebodyrect;
	CCRect foodrect;
	bool isBounding;
	bool eatfood;
	bool havefood;
};
#endif