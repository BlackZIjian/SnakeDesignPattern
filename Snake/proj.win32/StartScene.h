#ifndef __START_SCENE_H__
#define __START_SCENE_H__
#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3
#define WIDTH 100
#define HEIGHT 100
#include "cocos2d.h"


class StartScene : public cocos2d::Layer 
{
public:
	StartScene();
	~StartScene();
	virtual bool init();
	CREATE_FUNC(StartScene);
	static Scene* createScene();
	static float delta_x;
	static float delta_y;
	static float move_speed;
	void callback_start(int mode);
private:
	Director* director;
};




#endif
