#include "GameLayer.h"

GameLayer::GameLayer() {

}

GameLayer::~GameLayer() {

}

bool GameLayer::init() {
	bool judge = false;
	do{
		CC_BREAK_IF(!Layer::init());
		pressdirection = DRIGHT;
		pressdirection2 = DLEFT;
		_vp = 1;
		_vp2 = 1;
		body = 0;
		lastbody = 0;
		havefood = false;
		BackGroundLayer* background = BackGroundLayer::create();
		this->addChild(background);
		wall = WallLayer::create();
		this->addChild(wall);
		wall->setTag(10);
		snakehead = SnakeNode::create();
		snake2head = Snake2Node::create();
		this->addChild(snake2head);
		this->addChild(snakehead);
		snakehead->setPosition(300, 300);
		snake2head->setPosition(500, 500);
		snakebody = CCArray::createWithCapacity(50);
		snakebody->retain();
		snake2body = CCArray::createWithCapacity(50);
		snake2body->retain();
		tempbody = 0;
		lastbody = 0;
		tempbody = SnakeNode::create();
		this->addChild(tempbody);
		tempbody->setPosition(ccpAdd(snakehead->getPosition(), ccp(-PIXEL, 0)));
		tempbody->direction = DRIGHT;
		snakebody->addObject(tempbody);
		tempbody = 0;
		temp2body = Snake2Node::create();
		this->addChild(temp2body);
		temp2body->setPosition(ccpAdd(snake2head->getPosition(), ccp(PIXEL, 0)));
		temp2body->direction = DLEFT;
		snake2body->addObject(temp2body);
		temp2body = 0;
		food = Sprite::create("Food.png");
		this->addChild(food);
		GameLayer::makefood();
		this->scheduleUpdate();
		auto listener = EventListenerKeyboard::create();
		listener->onKeyPressed = CC_CALLBACK_2(GameLayer::onKeyPressed, this);
		listener->onKeyReleased = CC_CALLBACK_2(GameLayer::onKeyReleased, this);
		_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
		gameover = false;
		judge = true;
	} while (0);
	return judge;
}
void GameLayer::update(float delta) {
	this->schedule(schedule_selector(GameLayer::myupdate), snakehead->vp*_vp*0.05f);
	this->schedule(schedule_selector(GameLayer::myupdate2), snake2head->vp*_vp2*0.05f);
}

void GameLayer::notup(float delta) {
	_vp = 1;
}

void GameLayer::notup2(float delta) {
	_vp2 = 1;
}

void GameLayer::myupdate(float delta) {
	tempbody = SnakeNode::create();
	tempbody->setPosition(snakehead->getPosition());
	this->addChild(tempbody);
	snakebody->addObject(tempbody);
	tempbody = 0;
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
	body = 0;
	snakeheadrect = snakehead->getBoundingBox();
	for (int i = 0; i < snakebody->count(); i++) {
		body = (SnakeNode*)snakebody->objectAtIndex(i);
		snakebodyrect = body->getBoundingBox();
		isBounding = snakeheadrect.intersectsRect(snakebodyrect);
		if (isBounding == true) {
			EndLayer* end = EndLayer::create();
			this->addChild(end);
			this->who(1);
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
			this->who(1);
			this->unscheduleAllSelectors();
		}
	}
	body2 = 0;
	for (int i = 0; i < snake2body->count(); i++) {
		body2 = (Snake2Node*)snake2body->objectAtIndex(i);
		snakebodyrect = body2->getBoundingBox();
		isBounding = snakeheadrect.intersectsRect(snakebodyrect);
		if (isBounding == true) {
			EndLayer* end = EndLayer::create();
			this->addChild(end);
			this->who(1);
			this->unscheduleAllSelectors();
		}
	}
	snakehead2rect = snake2head->getBoundingBox();
	for (int i = 0; i < wall->wallarray->count(); i++) {
		tempwall = (Sprite*)wall->wallarray->objectAtIndex(i);
		wallrect = tempwall->getBoundingBox();
		isBounding = snakehead2rect.intersectsRect(wallrect);
		if (isBounding == true) {
			EndLayer* end = EndLayer::create();
			this->addChild(end);
			this->who(2);
			this->unscheduleAllSelectors();
		}
	}
	body = 0;
	snakehead2rect = snake2head->getBoundingBox();
	for (int i = 0; i < snakebody->count(); i++) {
		body = (SnakeNode*)snakebody->objectAtIndex(i);
		snakebodyrect = body->getBoundingBox();
		isBounding = snakehead2rect.intersectsRect(snakebodyrect);
		if (isBounding == true) {
			EndLayer* end = EndLayer::create();
			this->addChild(end);
			this->who(2);
			this->unscheduleAllSelectors();
		}
	}
	body2 = 0;
	for (int i = 0; i < snakebody->count(); i++) {
		for (int j = 0; j < snake2body->count(); j++) {
			body = (SnakeNode*)snakebody->objectAtIndex(i);
			snakebodyrect = body->getBoundingBox();
			Snake2Node* body2 = (Snake2Node*)snake2body->objectAtIndex(j);
			CCRect snake2bodyrect = body2->getBoundingBox();
			isBounding = snake2bodyrect.intersectsRect(snakebodyrect);
			if (isBounding == true) {
				EndLayer* end = EndLayer::create();
				this->addChild(end);
				this->unscheduleAllSelectors();
			}
		}
	}
	if (havefood == true) {
		foodrect = this->getChildByTag(1)->getBoundingBox();
		eatfood = foodrect.intersectsRect(snakeheadrect);
		if (eatfood == true) {
			GameLayer::makefood();
			int random = CCRANDOM_0_1() * 100;
			if (random >= 30 && random <= 60) {
				_vp = 0.5;
				SimpleAudioEngine::sharedEngine()->playEffect("Food.mp3", false);
				this->scheduleOnce(schedule_selector(GameLayer::notup), 5.f);
			}
			else if(random >=60){
				_vp2 = 0.5;
				SimpleAudioEngine::sharedEngine()->playEffect("Food.mp3", false);
				this->scheduleOnce(schedule_selector(GameLayer::notup2), 5.f);
			}
		}

	}
}

void GameLayer::myupdate2(float delta) {
	temp2body = Snake2Node::create();
	temp2body->setPosition(snake2head->getPosition());
	this->addChild(temp2body);
	snake2body->addObject(temp2body);
	temp2body = 0;
	if (snake2head->direction == DUP) {
		snake2head->setPosition(ccpAdd(snake2head->getPosition(), ccp(0, 1 * PIXEL)));
	}
	else if (snake2head->direction == DDOWN) {
		snake2head->setPosition(ccpAdd(snake2head->getPosition(), ccp(0, -1 * PIXEL)));
	}
	else if (snake2head->direction == DRIGHT) {
		snake2head->setPosition(ccpAdd(snake2head->getPosition(), ccp(1 * PIXEL, 0)));
	}
	else if (snake2head->direction == DLEFT) {
		snake2head->setPosition(ccpAdd(snake2head->getPosition(), ccp(-1 * PIXEL, 0)));
	}
	snakehead2rect = snake2head->getBoundingBox();
	for (int i = 0; i < snake2body->count(); i++) {
		body2 = (Snake2Node*)snake2body->objectAtIndex(i);
		snakebodyrect = body2->getBoundingBox();
		isBounding = snakehead2rect.intersectsRect(snakebodyrect);
		if (isBounding == true) {
			EndLayer* end = EndLayer::create();
			this->addChild(end);
			this->who(2);
			this->unscheduleAllSelectors();
		}
	}
	if (havefood == true) {
		foodrect = this->getChildByTag(1)->getBoundingBox();
		eatfood = foodrect.intersectsRect(snakehead2rect);
		if (eatfood == true) {
			GameLayer::makefood();
			int random = CCRANDOM_0_1() * 100;
			if (random >= 30 && random<=60) {
				_vp2 = 0.5;
				SimpleAudioEngine::sharedEngine()->playEffect("Food.mp3", false);
				this->scheduleOnce(schedule_selector(GameLayer::notup2), 5.f);
			}
			else if (random >= 60) {
				_vp = 0.5;
				SimpleAudioEngine::sharedEngine()->playEffect("Food.mp3", false);
				this->scheduleOnce(schedule_selector(GameLayer::notup), 5.f);
			}
		}

	}
}

void GameLayer::makefood() {
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
		bool inBody = false;
		CCRect tempfoodrect = food->getBoundingBox();
		CCRect tempwallrect;
		CCRect tempbodyrect;
		Sprite* tempwallsp;
		Sprite* tempbodysp;
		for (int i = 0; i < wall->wallarray->count(); i++) {
			tempwallsp = (Sprite*)wall->wallarray->objectAtIndex(i);
			tempwallrect = tempwallsp->getBoundingBox();
			inWall = tempfoodrect.intersectsRect(tempwallrect);
			if (inWall == true) {

				GameLayer::makefood();
				break;
			}
		}
		for (int i = 0; i < snakebody->count(); i++) {
			tempbodysp = (Sprite*)snakebody->objectAtIndex(i);
			tempbodyrect = tempbodysp->getBoundingBox();
			inBody = tempbodyrect.intersectsRect(tempfoodrect);
			if (inBody == true) {
				GameLayer::makefood();
				break;
			}
		}
		for (int i = 0; i < snake2body->count(); i++) {
			tempbodysp = (Sprite*)snake2body->objectAtIndex(i);
			tempbodyrect = tempbodysp->getBoundingBox();
			inBody = tempbodyrect.intersectsRect(tempfoodrect);
			if (inBody == true) {
				GameLayer::makefood();
				break;
			}
		}
		return;

	}


void GameLayer::onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event) {
	pressdirection = 100;
	pressdirection2 = 100;
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
	if (keyCode == EventKeyboard::KeyCode::KEY_L) {
		pressdirection2 = DRIGHT;
	}
	else if (keyCode == EventKeyboard::KeyCode::KEY_I) {
		pressdirection2 = DUP;
	}
	else if (keyCode == EventKeyboard::KeyCode::KEY_K) {
		pressdirection2 = DDOWN;
	}
	else if (keyCode == EventKeyboard::KeyCode::KEY_J) {
		pressdirection2 = DLEFT;
	}if (pressdirection == snakehead->direction) {
		snakehead->vp = 0.5;
	}
	if (pressdirection2 == snake2head->direction) {
		snake2head->vp = 0.5;
	}
	if (pressdirection != 100 && ((pressdirection + snakehead->direction) != 3) && (pressdirection + snakehead->direction) != 7 && (pressdirection != snakehead->direction)) {
		snakehead->direction = pressdirection;
	}
	if (pressdirection2 != 100 && ((pressdirection2 + snake2head->direction) != 3) && (pressdirection2 + snake2head->direction) != 7 && (pressdirection2 != snake2head->direction)) {
		snake2head->direction = pressdirection2;
	}
	
	
}
void GameLayer::onKeyReleased(EventKeyboard::KeyCode keyCode, Event* event) {
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
	if (keyCode == EventKeyboard::KeyCode::KEY_L) {
		releasedirection2 = DRIGHT;
	}
	else if (keyCode == EventKeyboard::KeyCode::KEY_I) {
		releasedirection2 = DUP;
	}
	else if (keyCode == EventKeyboard::KeyCode::KEY_K) {
		releasedirection2 = DDOWN;
	}
	else if (keyCode == EventKeyboard::KeyCode::KEY_J) {
		releasedirection2 = DLEFT;
	}
	if (releasedirection2 == snake2head->direction) {
		snake2head->vp = 1;

	}
}

void GameLayer::who(int w) {
	Size size = Director::getInstance()->getVisibleSize();
	if (w == 1) {
		Sprite* one = Sprite::create("1di.png");
		one->setPosition(size.width/2,size.height/2);
		this->addChild(one);
		CCAction* action = CCMoveTo::create(0.5, ccp(500, 500));
		one->runAction(action);
	}
	else if (w == 2) {
		Sprite* two = Sprite::create("2di.png");
		two->setPosition(size.width/2, size.height/2);
		this->addChild(two);
		CCAction* action = CCMoveTo::create(0.5, ccp(500, 500));
		two->runAction(action);
	}
	gameover = true;
}