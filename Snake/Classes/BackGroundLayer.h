#ifndef _BACKGROUND_LAYER_H_
#define _BACKGROUND_LAYER_H_
#include "cocos2d.h"
USING_NS_CC;
class BackGroundLayer : public Layer {
public:
	BackGroundLayer();
	~BackGroundLayer();
	virtual bool init();
	CREATE_FUNC(BackGroundLayer);
};
#endif