#ifndef _END_LAYER_H_
#define _END_LAYER_H_
#include "cocos2d.h"
USING_NS_CC;
class EndLayer :public Layer {
public:
	EndLayer();
	~EndLayer();
	virtual bool init();
	CREATE_FUNC(EndLayer);
	void EndLayer::who(int w);
};
#endif