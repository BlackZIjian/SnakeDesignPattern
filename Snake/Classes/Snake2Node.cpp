#include "Snake2Node.h"

Snake2Node::Snake2Node() {

}

Snake2Node::~Snake2Node() {

}

bool Snake2Node::init() {
	bool judge = false;
	do{
		CC_BREAK_IF(!Node::init());
		direction = DLEFT;
		Sprite* snake = Sprite::create("Snake2.png");
		snake->setScaleX(PIXEL / snake->getContentSize().width);
		snake->setScaleY(PIXEL / snake->getContentSize().height);
		vp = 1;
		this->addChild(snake);
		judge = true;
	} while (0);
	return judge;
}