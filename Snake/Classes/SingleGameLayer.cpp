#include "SingleGameLayer.h"

SingleGameLayer::SingleGameLayer() {

}

SingleGameLayer::~SingleGameLayer() {

}

bool SingleGameLayer::init() {
	bool judge = false;
	do{
		CC_BREAK_IF(!Layer::init());
		pressdirection = DRIGHT;
		_vp = 1;
		body = 0;
		time = 0;
		lastbody = 0;
		havefood = false;
		vup = false;
		ifvup = false;
		BackGroundLayer* background = BackGroundLayer::create();
		this->addChild(background);
		wall = WallLayer::create();
		int wallx = CCRANDOM_0_1() * 4;
		wall->creatWall(wallx+1);
		this->addChild(wall);
		wall->setTag(10);
		snakehead = SnakeNode::create();
		this->addChild(snakehead);
		snakehead->setPosition(300, 300);
		snakehead->vp = snakehead->vp*_vp;
		snakebody = CCArray::createWithCapacity(50);
		snakebody->retain();
		tempbody = 0;
		lastbody = 0;
		tempbody = SnakeNode::create();
		this->addChild(tempbody);
		tempbody->setPosition(ccpAdd(snakehead->getPosition(), ccp(-PIXEL, 0)));
		tempbody->direction = DRIGHT;
		snakebody->addObject(tempbody);
		tempbody = 0;
		for (int i = 1; i < 15; i++) {
		tempbody = SnakeNode::create();
		this->addChild(tempbody);
		lastbody = (SnakeNode*)snakebody->objectAtIndex(i - 1);
		tempbody->setPosition(ccpAdd(lastbody->getPosition(), ccp(-PIXEL, 0)));
		tempbody->direction = DRIGHT;
		snakebody->addObject(tempbody);
		tempbody = 0;
		lastbody = 0;
		}
		food = Sprite::create("Food.png");
		this->addChild(food);
		SingleGameLayer::makefood();
		this->scheduleUpdate();
		auto listener = EventListenerKeyboard::create();
		listener->onKeyPressed = CC_CALLBACK_2(SingleGameLayer::onKeyPressed, this);
		listener->onKeyReleased = CC_CALLBACK_2(SingleGameLayer::onKeyReleased, this);
		_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
		judge = true;
	} while (0);
	return judge;
}
void SingleGameLayer::update(float delta) {
	this->schedule(schedule_selector(SingleGameLayer::myupdate), snakehead->vp*_vp*0.08f);
	time = time + 1;
}

void SingleGameLayer::notup(float delta) {
	_vp = 1;
}
void SingleGameLayer::myupdate(float delta) {
	if (snakehead->direction == DUP) {
		snakehead->setPosition(ccpAdd(snakehead->getPosition(), ccp(0, 1*PIXEL)));
	}
	else if (snakehead->direction == DDOWN) {
		snakehead->setPosition(ccpAdd(snakehead->getPosition(), ccp(0, -1*PIXEL)));
	}
	else if (snakehead->direction == DRIGHT) {
		snakehead->setPosition(ccpAdd(snakehead->getPosition(), ccp(1*PIXEL, 0)));
	}
	else if (snakehead->direction == DLEFT) {
		snakehead->setPosition(ccpAdd(snakehead->getPosition(), ccp(-1*PIXEL, 0)));
	}
	for (int i = 0; i < snakebody->count(); i++) {
		body = (SnakeNode*)snakebody->objectAtIndex(i);
		if (body->direction == DUP) {
			body->setPosition(ccpAdd(body->getPosition(), ccp(0, 1*PIXEL)));
		}
		else if (body->direction == DDOWN) {
			body->setPosition(ccpAdd(body->getPosition(), ccp(0, -1*PIXEL)));
		}
		else if (body->direction == DRIGHT) {
			body->setPosition(ccpAdd(body->getPosition(), ccp(1*PIXEL, 0)));
		}
		else if (body->direction == DLEFT) {
			body->setPosition(ccpAdd(body->getPosition(), ccp(-1*PIXEL, 0)));
		}
		body = 0;
	}
	for (int i = snakebody->count() - 1; i > 0; i--) {
		body = (SnakeNode*)snakebody->objectAtIndex(i);
		lastbody = (SnakeNode*)snakebody->objectAtIndex(i - 1);
		for (unsigned int j = 0; j < turnpoi.size(); j++) {
			if (body->getPosition() == turnpoi[j]) {
				body->direction = lastbody->direction;
				body->vp = snakehead->vp;
				if (i == snakebody->count() - 1){
					turnpoi.erase(turnpoi.begin() + j);
				}
			}
		}
		body = 0;
		lastbody = 0;
	}
	body = (SnakeNode*)snakebody->objectAtIndex(0);
	for (unsigned int j = 0; j < turnpoi.size(); j++) {
		if (body->getPosition() == turnpoi[j]) {
			body->direction = snakehead->direction;
			body->vp = snakehead->vp;
		}
	}
	body = 0;
	snakeheadrect = snakehead->getBoundingBox();
	for (int i = 0; i < snakebody->count(); i++) {
		body = (SnakeNode*)snakebody->objectAtIndex(i);
		snakebodyrect = body->getBoundingBox();
		isBounding = snakeheadrect.intersectsRect(snakebodyrect);
		if (isBounding == true) {
			EndLayer* end = EndLayer::create();
			this->addChild(end);
			this->outscore(time);
			this->unscheduleAllSelectors();
		}
	}
	CCRect wallrect;
	Sprite* tempwall;
	for (int i = 0; i < wall->wallarray->count(); i++) {
		tempwall = (Sprite*)wall->wallarray->objectAtIndex(i);
		wallrect = tempwall->getBoundingBox();
		isBounding = snakeheadrect.intersectsRect(wallrect);
		if (isBounding == true) {
			EndLayer* end = EndLayer::create();
			this->addChild(end);
			this->outscore(time);
			this->unscheduleAllSelectors();
		}
	}
	if (havefood == true) {
		foodrect = this->getChildByTag(1)->getBoundingBox();
		eatfood = foodrect.intersectsRect(snakeheadrect);
		if (eatfood == true) {
			for (int i = 0; i < 3; i++) {
				tempbody = SnakeNode::create();
				this->addChild(tempbody);
				lastbody = (SnakeNode*)snakebody->lastObject();
				if (lastbody->direction == DRIGHT) {
					tempbody->setPosition(ccpAdd(lastbody->getPosition(), ccp(-PIXEL, 0)));
					tempbody->direction = DRIGHT;
				}
				if (lastbody->direction == DLEFT) {
					tempbody->setPosition(ccpAdd(lastbody->getPosition(), ccp(PIXEL, 0)));
					tempbody->direction = DLEFT;
				}
				if (lastbody->direction == DUP) {
					tempbody->setPosition(ccpAdd(lastbody->getPosition(), ccp(0, -PIXEL)));
					tempbody->direction = DUP;
				}
				if (lastbody->direction == DDOWN) {
					tempbody->setPosition(ccpAdd(lastbody->getPosition(), ccp(0, PIXEL)));
					tempbody->direction = DDOWN;
				}
				snakebody->addObject(tempbody);
				tempbody = 0;
				lastbody = 0;
			}
			SingleGameLayer::makefood();
			time = time + 50;
			int random = CCRANDOM_0_1() * 100;
			if (random >= 50) {
				_vp = 0.5;
				SimpleAudioEngine::sharedEngine()->playEffect("Food.mp3", false);
				this->scheduleOnce(schedule_selector(SingleGameLayer::notup), 5.f);
			}
		}

	}
}

void SingleGameLayer::makefood() {
Size size = Director::getInstance()->getVisibleSize();
	int ranx = CCRANDOM_0_1() * size.width / PIXEL;
	int rany = CCRANDOM_0_1() * size.height / PIXEL;
	CCPoint foodpoi = ccpClamp(ccpAdd(ccp(100, 100), ccp(PIXEL*ranx, PIXEL*rany)), ccp(40, 40), ccp(size.width - 40, size.height - 40));
	food->setPosition(foodpoi);
	food->setScaleX(PIXEL * 2 / food->getContentSize().width);
	food->setScaleY(PIXEL * 2 / food->getContentSize().height);
	food->setTag(1);
	this->havefood = true;
	bool inWall = false;
	CCRect tempfoodrect = food->getBoundingBox();
	CCRect tempwallrect;
	Sprite* tempwallsp;
	for (int i = 0; i < wall->wallarray->count(); i++) {
		tempwallsp = (Sprite*)wall->wallarray->objectAtIndex(i);
		tempwallrect = tempwallsp->getBoundingBox();
		inWall = tempfoodrect.intersectsRect(tempwallrect);
		if (inWall == true) {

			SingleGameLayer::makefood();
			break;
		}
	}
		return;
	
}

void SingleGameLayer::outfood(float delta) {
if (this->havefood == true) {
this->removeChildByTag(1, true);
this->havefood = false;
}
}

void SingleGameLayer::onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event) {
	if (keyCode == EventKeyboard::KeyCode::KEY_D) {
		pressdirection = DRIGHT;
	}
	else if (keyCode == EventKeyboard::KeyCode::KEY_W) {
		pressdirection = DUP;
	}
	else if (keyCode == EventKeyboard::KeyCode::KEY_S) {
		pressdirection = DDOWN;
	}
	else if (keyCode == EventKeyboard::KeyCode::KEY_A) {
		pressdirection = DLEFT;
	}
	if (((pressdirection + snakehead->direction) != 3) && (pressdirection + snakehead->direction) != 7 && (pressdirection != snakehead->direction)) {
		snakehead->direction = pressdirection;
		temppoi =  snakehead->getPosition();
		turnpoi.push_back(temppoi);
	}
	else if (pressdirection == snakehead->direction) {
		snakehead->vp = 0.5;
	}
}

void SingleGameLayer::onKeyReleased(EventKeyboard::KeyCode keyCode, Event* event) {
	if (keyCode == EventKeyboard::KeyCode::KEY_D) {
		releasedirection = DRIGHT;
	}
	else if (keyCode == EventKeyboard::KeyCode::KEY_W) {
		releasedirection = DUP;
	}
	else if (keyCode == EventKeyboard::KeyCode::KEY_S) {
		releasedirection = DDOWN;
	}
	else if (keyCode == EventKeyboard::KeyCode::KEY_A) {
		releasedirection = DLEFT;
	}
	if (releasedirection == snakehead->direction) {
		snakehead->vp = 1;
	}
}

void SingleGameLayer::outscore(int a) {
	char f[10];
	sprintf(f, "%d", a);
	string sc = f;
	LabelTTF* label = LabelTTF::create(sc, "Conlolas", 40);
	label->setColor(Color3B::BLACK);
	label->setPosition(Director::getInstance()->getVisibleSize().width / 2, Director::getInstance()->getVisibleSize().height / 2);
	this->addChild(label);
	CCAction* action = CCMoveTo::create(0.5, ccp(500, 500));
	label->runAction(action);
}