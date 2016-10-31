#ifndef _SNAKE2_NODE_H_
#define _SNAKE2_NODE_H_
#define DRIGHT 4
#define DLEFT 3
#define DUP 1
#define DDOWN 2
#define PIXEL 10
#include "cocos2d.h"
USING_NS_CC;
class Snake2Node :public Node {
public:
	Snake2Node();
	~Snake2Node();
	virtual bool init();
	CREATE_FUNC(Snake2Node);
	int direction;
	float vp;
};
#endif