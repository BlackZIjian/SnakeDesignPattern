#include "EndLayer.h"

EndLayer::EndLayer() {


}

EndLayer::~EndLayer() {


}

bool EndLayer::init() {
	bool judge = false;
	do{
		CC_BREAK_IF(!Layer::init());
		Sprite* sp = Sprite::create("HelloWorld.png");
		sp->setPosition(500, 500);
		this->addChild(sp);
		CCActionInterval * shatteredTiles3D = CCShatteredTiles3D::create(25, Size(100,100), 4, false);
		sp->runAction(shatteredTiles3D);
		judge = true;
	} while (0);
	return judge;
}
