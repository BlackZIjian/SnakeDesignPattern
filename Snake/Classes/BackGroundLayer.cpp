#include "BackGroundLayer.h"

BackGroundLayer::BackGroundLayer() {

}

BackGroundLayer::~BackGroundLayer() {

}

bool BackGroundLayer::init() {
	bool judge = false;
	do {
		CC_BREAK_IF(!Layer::init());
		Size size = Director::getInstance()->getVisibleSize();
		Sprite* background = Sprite::create("BackGround.png");
		background->setPosition(size.width / 2, size.height / 2);
		background->setScaleX( size.width / background->getContentSize().width);
		background->setScaleY(size.height / background->getContentSize().height);
		this->addChild(background);
		judge = true;
	} while (0);
	return judge;
}