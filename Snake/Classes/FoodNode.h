#ifndef _FOOD_NODE_H_
#define _FOOD_NODE_H_
#include "cocos2d.h"
USING_NS_CC;
class FoodNode :public Node{
public:
	FoodNode();
	~FoodNode();
	virtual bool init();
	CREATE_FUNC(FoodNode);
	int ranx;
	int rany;
};
#endif