#include "StartLayer.h"

StartLayer::StartLayer() {

}

StartLayer::~StartLayer() {

}

bool StartLayer::init() {
	bool judge = false;
	do {
		CC_BREAK_IF(!Layer::init());
		auto startmenu = MenuItemImage::create("BackGround.png", "BackGround.png", CC_CALLBACK_1(StartLayer::callback, this));
		auto starMenu = Menu::create(startmenu, NULL);
		this->addChild(starMenu);
		judge = true;
	} while (0);
	return judge;
}

void StartLayer::callback(Object* pSender) {
	Director::getInstance()->replaceScene()
}