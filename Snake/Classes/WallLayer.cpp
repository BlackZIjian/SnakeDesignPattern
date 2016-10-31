#include "WallLayer.h"

WallLayer::WallLayer() {

}

WallLayer::~WallLayer() {

}

bool WallLayer::init() {
	bool judge = false;
	do{
		CC_BREAK_IF(!Layer::init());
		wallarray = CCArray::create();
		wallarray->retain();
		Sprite* wall = Sprite::create("Wall.png");
		Size size = Director::getInstance()->getVisibleSize();
		wall->setPosition(20, size.height / 2);
		wall->setScaleY((size.height ) / wall->getContentSize().height);
		wallarray->addObject(wall);
		this->addChild(wall);
		wall = Sprite::create("Wall.png");
		wall->setPosition(size.width-20, size.height / 2);
		wall->setScaleY((size.height ) / wall->getContentSize().height);
		wallarray->addObject(wall);
		this->addChild(wall);
		wall = Sprite::create("WallX.png");
		wall->setPosition(size.width/2, 20);
		wall->setScaleX((size.width ) / wall->getContentSize().width);
		wallarray->addObject(wall);
		this->addChild(wall);
		wall = Sprite::create("WallX.png");
		wall->setPosition(size.width / 2, size.height-20);
		wall->setScaleX((size.width ) / wall->getContentSize().width);
		wallarray->addObject(wall);
		this->addChild(wall);
		judge = true;
	} while (0);
	return judge;
}

bool WallLayer::creatWall(int num) {
	bool judge = false;
	do {
		if (num == 1) {
			Sprite* wall = Sprite::create("Wall.png");
			Size size = Director::getInstance()->getVisibleSize();
			wall->setPosition(size.width / 2, size.height * 3 / 4);
			wall->setScaleY((size.height / 2 - 30) / wall->getContentSize().height);
			wallarray->addObject(wall);
			this->addChild(wall);
			wall = Sprite::create("Wall.png");
			wall->setPosition(size.width / 2, size.height / 4);
			wall->setScaleY((size.height / 2 - 30) / wall->getContentSize().height);
			wallarray->addObject(wall);
			this->addChild(wall);
		}
		else if (num == 2) {
			Sprite* wall = Sprite::create("Wall.png");
			Size size = Director::getInstance()->getVisibleSize();
			wall->setPosition(size.width / 2, size.height * 3 / 4);
			wall->setScaleY((size.height / 2 - 30) / wall->getContentSize().height);
			wallarray->addObject(wall);
			this->addChild(wall);
			wall = Sprite::create("Wall.png");
			wall->setPosition(size.width / 2, size.height / 4);
			wall->setScaleY((size.height / 2 - 30) / wall->getContentSize().height);
			wallarray->addObject(wall);
			this->addChild(wall);
			wall = Sprite::create("WallX.png");
			wall->setPosition(size.width / 4-50, size.height / 2);
			wall->setScaleX((size.width / 2 - 60) / wall->getContentSize().width);
			wallarray->addObject(wall);
			this->addChild(wall);
			wall = Sprite::create("WallX.png");
			wall->setPosition(size.width *3/ 4 + 50, size.height / 2);
			wall->setScaleX((size.width / 2 - 60) / wall->getContentSize().width);
			wallarray->addObject(wall);
			this->addChild(wall);
		}
		else if (num == 3) {
			Sprite* wall = Sprite::create("Wall.png");
			Size size = Director::getInstance()->getVisibleSize();
			wall->setPosition(size.width / 2 - 100, size.height * 3 / 4);
			wall->setScaleY((size.height / 2 - 30) / wall->getContentSize().height);
			wallarray->addObject(wall);
			this->addChild(wall);
			wall = Sprite::create("Wall.png");
			wall->setPosition(size.width / 2 + 100, size.height / 4);
			wall->setScaleY((size.height / 2 - 30) / wall->getContentSize().height);
			wallarray->addObject(wall);
			this->addChild(wall);
			wall = Sprite::create("WallX.png");
			wall->setPosition(size.width / 4 - 100, size.height / 2-50);
			wall->setScaleX((size.width / 2 - 60) / wall->getContentSize().width);
			wallarray->addObject(wall);
			this->addChild(wall);
			wall = Sprite::create("WallX.png");
			wall->setPosition(size.width * 3 / 4 + 100, size.height / 2+50);
			wall->setScaleX((size.width / 2 - 60) / wall->getContentSize().width);
			wallarray->addObject(wall);
			this->addChild(wall);
		}
		else if (num == 4) {
			Sprite* wall = Sprite::create("WallX.png");
			Size size = Director::getInstance()->getVisibleSize();
			wall->setPosition(50, size.height - 100);
			wall->setScaleX(200 / wall->getContentSize().width);
			wallarray->addObject(wall);
			this->addChild(wall);
			wall = Sprite::create("WallX.png");
			wall->setPosition(100, size.height - 200);
			wall->setScaleX(500 / wall->getContentSize().width);
			wallarray->addObject(wall);
			this->addChild(wall);
			wall = Sprite::create("WallX.png");
			wall->setPosition(400, size.height - 300);
			wall->setScaleX(800 / wall->getContentSize().width);
			wallarray->addObject(wall);
			this->addChild(wall);
			wall = Sprite::create("WallX.png");
			wall->setPosition(400, size.height - 400);
			wall->setScaleX(900 / wall->getContentSize().width);
			wallarray->addObject(wall);
			this->addChild(wall);
			wall = Sprite::create("WallX.png");
			wall->setPosition(400, size.height - 600);
			wall->setScaleX(800 / wall->getContentSize().width);
			wallarray->addObject(wall);
			this->addChild(wall);
			wall = Sprite::create("WallX.png");
			wall->setPosition(100, size.height - 680);
			wall->setScaleX(500 / wall->getContentSize().width);
			wallarray->addObject(wall);
			this->addChild(wall);
		}
		judge = true;
	} while (0);
	return judge;
}