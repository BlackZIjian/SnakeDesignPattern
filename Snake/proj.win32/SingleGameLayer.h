#ifndef _GAME_LAYER_H_
#define _GAME_LAYER_H_
#include "cocos2d.h"
#include "BackGroundLayer.h"
#include "SnakeNode.h"
//#include "Snake2Node.h"
#include "FoodNode.h"
#include <vector>
USING_NS_CC;
using namespace std;
class GameLayer :public Layer{
public:
	GameLayer();
	~GameLayer();
	virtual bool init();
	CREATE_FUNC(GameLayer);
private:
	void update(float delta);
	void makefood(float delta);
	void outfood(float delta);
	SnakeNode* snakehead;
	//Snake2Node* snake2head;
	void GameLayer::onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event);
	int pressdirection;
	//int pressdirection2;
	CCArray* snakebody;
	//CCArray* snake2body;
	SnakeNode* body;
	//Snake2Node* body2;
	SnakeNode* lastbody;
	SnakeNode* tempbody;
	//Snake2Node* temp2body;
	vector<CCPoint> turnpoi;
	//CCPoint turnpoi;
	CCPoint temppoi;
	CCRect snakeheadrect;
	CCRect snakebodyrect;
	CCRect foodrect;
	bool isBounding;
	bool eatfood;
	bool havefood;
};
#endif