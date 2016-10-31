#ifndef _START_LAYER_H_
#define _START_LAYER_H_
#include "cocos2d.h"
USING_NS_CC;
class StartLayer :public Layer {
public:
	StartLayer();
	~StartLayer();
	virtual bool init();
	CREATE_FUNC(StartLayer);
private:
	void callback(Object* pSender);
};

#endif