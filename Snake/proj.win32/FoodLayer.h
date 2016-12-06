#ifndef _FOOD_LAYER_H_
#define _FOOD_LAYER_H_
#include "cocos2d.h"
USING_NS_CC;
class FoodLayer : public Layer {
public:
	FoodLayer();
	~FoodLayer();
	virtual bool init();
	CREATE_FUNC(FoodLayer);
};
#endif
