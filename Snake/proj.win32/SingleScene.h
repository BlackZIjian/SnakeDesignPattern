#ifndef __SINGLE_SCENE_H__
#define __SINGLE_SCENE_H__

#include "cocos2d.h"

class SingleScene : public cocos2d::Layer
{
public:
	SingleScene();
	~SingleScene();
	virtual bool init();
	CREATE_FUNC(SingleScene);
	static Scene* createScene();
};




#endif
