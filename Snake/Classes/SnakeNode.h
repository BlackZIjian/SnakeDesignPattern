#ifndef _SNAKE_NODE_H_
#define _SNAKE_NODE_H_
#define DRIGHT 4
#define DLEFT 3
#define DUP 1
#define DDOWN 2
#define PIXEL 10
#include "cocos2d.h"
USING_NS_CC;
class SnakeNode :public Node {
public:
	SnakeNode();
	~SnakeNode();
	virtual bool init();
	CREATE_FUNC(SnakeNode);
	int direction;
	float vp;
};
#endif