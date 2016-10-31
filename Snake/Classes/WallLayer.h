#ifndef _WALL_LAYER_H_
#define _WALL_LAYER_H_
#include "cocos2d.h"
USING_NS_CC;
class WallLayer : public Layer {
public:
	WallLayer();
	~WallLayer();
	virtual bool init();
	CREATE_FUNC(WallLayer);
	CCArray* wallarray;
	bool creatWall(int num);
};
#endif