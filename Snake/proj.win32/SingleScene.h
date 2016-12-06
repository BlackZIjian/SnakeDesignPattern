#ifndef __SINGLE_SCENE_H__
#define __SINGLE_SCENE_H__

#include "cocos2d.h"
#include "SnakeLayer.h"
#include "StartScene.h"
#define NONE_IN_PIXEL 0
#define SNAKE1_HEAD_IN_PIXEL 1
#define SNAKE2_HEAD_IN_PIXEL 2
#define SNAKE_BODY_IN_PIXEL 3
#define WALL_IN_PIXEL 4
class SingleScene : public cocos2d::Layer
{
public:
	SingleScene();
	~SingleScene();
	virtual bool init();
	CREATE_FUNC(SingleScene);
	static SingleScene* instance;
	static Scene* createScene();

	void callback_head_move_finished(SnakeNodeSprite* head, SnakeLayer* snake);
	void callback_end_move_finished(SnakeNodeSprite* end, SnakeLayer* snake);
	void callback_head_move_before(SnakeNodeSprite* head, SnakeLayer* snake);
	void callback_end_move_before(SnakeNodeSprite* end, SnakeLayer* snake);
	int AddNewSnake();
	int snake_num;
private:
	int pixel[WIDTH][HEIGHT] = { 0 };

};




#endif
