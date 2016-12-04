#include "EndLayer.h"

EndLayer::EndLayer() {


}

EndLayer::~EndLayer() {


}

bool EndLayer::init() {
	bool judge = false;
	do{
		CC_BREAK_IF(!Layer::init());
		Sprite* sp = Sprite::create("Win.png");
		sp->setPosition(500, 1000);
		sp->setScale(0.2);
		this->addChild(sp);
		CCAction* action = CCMoveTo::create(0.5, ccp(500,500));
		sp->runAction(action);
		judge = true;
	} while (0);
	return judge;
}

void EndLayer::who(int w) {
	if (w == 1) {
		Sprite* one = Sprite::create("1di.png");
		one->setPosition(ccp(500, 0));
		this->addChild(one);
	}
	else if (w == 2) {
		Sprite* two = Sprite::create("2di.png");
		two->setPosition(ccp(500, 0));
		this->addChild(two);
	}
}
