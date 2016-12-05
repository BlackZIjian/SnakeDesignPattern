#ifndef _PAUSE_LAYER_H_
#define _PAUSE_LAYER_H_
#include "cocos2d.h"
USING_NS_CC;
class PauseLayer : public Layer{
public:
	PauseLayer();
	~PauseLayer();
	virtual bool init();
	CREATE_FUNC(PauseLayer);
};
#endif