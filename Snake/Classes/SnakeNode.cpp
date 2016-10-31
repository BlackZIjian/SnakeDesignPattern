#include "SnakeNode.h"

SnakeNode::SnakeNode() {

}

SnakeNode::~SnakeNode() {

}

bool SnakeNode::init() {
	bool judge = false;
	do{
		CC_BREAK_IF(!Node::init());
		direction = DRIGHT;
		Sprite* snake = Sprite::create("Snake.png");
		snake->setScaleX(PIXEL / snake->getContentSize().width);
		snake->setScaleY(PIXEL / snake->getContentSize().height);
		vp = 1;
		this->addChild(snake);
		judge = true;
	} while (0);
	return judge;
}