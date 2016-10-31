#include "SingleGameLayer.h"

GameLayer::GameLayer() {

}

GameLayer::~GameLayer() {

}

bool GameLayer::init() {
	bool judge = false;
	do{
		CC_BREAK_IF(!Layer::init());
		pressdirection = DRIGHT;
//		pressdirection2 = DLEFT;
		body = 0;
		lastbody = 0;
		havefood = false;
		BackGroundLayer* background = BackGroundLayer::create();
		this->addChild(background);
		snakehead = SnakeNode::create();
	//	snake2head = Snake2Node::create();
		//this->addChild(snake2head);
		this->addChild(snakehead);
		snakehead->setPosition(300, 300);
		//snake2head->setPosition(500, 500);
		snakebody = CCArray::createWithCapacity(50);
		snakebody->retain();
		//snake2body = CCArray::createWithCapacity(50);
		//snake2body->retain();
		tempbody = 0;
		lastbody = 0;
		tempbody = SnakeNode::create();
		this->addChild(tempbody);
		tempbody->setPosition(ccpAdd(snakehead->getPosition(), ccp(-PIXEL, 0)));
		tempbody->direction = DRIGHT;
		snakebody->addObject(tempbody);
		tempbody = 0;
		/*temp2body = Snake2Node::create();
		this->addChild(temp2body);
		temp2body->setPosition(ccpAdd(snake2head->getPosition(), ccp(PIXEL, 0)));
		temp2body->direction = DLEFT;
		snake2body->addObject(temp2body);
		temp2body = 0;*/
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
		this->scheduleUpdate();
		this->schedule(schedule_selector(GameLayer::makefood), 10.f);
		auto listener = EventListenerKeyboard::create();
		listener->onKeyPressed = CC_CALLBACK_2(GameLayer::onKeyPressed, this);
		_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
		judge = true;
	} while (0);
	return judge;
}

void GameLayer::update(float delta) {
	tempbody = SnakeNode::create();
	tempbody->setPosition(snakehead->getPosition());
	this->addChild(tempbody);
	snakebody->addObject(tempbody);
	tempbody = 0;
	/*temp2body = Snake2Node::create();
	temp2body->setPosition(snake2head->getPosition());
	this->addChild(temp2body);
	snake2body->addObject(temp2body);
	temp2body = 0;*/
	if (snakehead->direction == DUP) {
		snakehead->setPosition(ccpAdd(snakehead->getPosition(), ccp(0, 0.5*PIXEL)));
	}
	else if (snakehead->direction == DDOWN) {
		snakehead->setPosition(ccpAdd(snakehead->getPosition(), ccp(0, -0.5*PIXEL)));
	}
	else if (snakehead->direction == DRIGHT) {
		snakehead->setPosition(ccpAdd(snakehead->getPosition(), ccp(0.5*PIXEL, 0)));
	}
	else if (snakehead->direction == DLEFT) {
		snakehead->setPosition(ccpAdd(snakehead->getPosition(), ccp(-0.5*PIXEL, 0)));
	}
	/*if (snake2head->direction == DUP) {
		snake2head->setPosition(ccpAdd(snake2head->getPosition(), ccp(0, 0.5*PIXEL)));
	}
	else if (snake2head->direction == DDOWN) {
		snake2head->setPosition(ccpAdd(snake2head->getPosition(), ccp(0, -0.5*PIXEL)));
	}
	else if (snake2head->direction == DRIGHT) {
		snake2head->setPosition(ccpAdd(snake2head->getPosition(), ccp(0.5*PIXEL, 0)));
	}
	else if (snake2head->direction == DLEFT) {
		snake2head->setPosition(ccpAdd(snake2head->getPosition(), ccp(-0.5*PIXEL, 0)));
	}*/
	for (int i = 0; i < snakebody->count(); i++) {
	body = (SnakeNode*)snakebody->objectAtIndex(i);
	if (body->direction == DUP) {
	body->setPosition(ccpAdd(body->getPosition(), ccp(0, 0.5*PIXEL)));
	}
	else if (body->direction == DDOWN) {
	body->setPosition(ccpAdd(body->getPosition(), ccp(0, -0.5*PIXEL)));
	}
	else if (body->direction == DRIGHT) {
	body->setPosition(ccpAdd(body->getPosition(), ccp(0.5*PIXEL, 0)));
	}
	else if (body->direction == DLEFT) {
	body->setPosition(ccpAdd(body->getPosition(), ccp(-0.5*PIXEL, 0)));
	}
	body = 0;
	}
	for (int i = snakebody->count() - 1; i > 0; i--) {
	body = (SnakeNode*)snakebody->objectAtIndex(i);
	lastbody = (SnakeNode*)snakebody->objectAtIndex(i - 1);
	for (unsigned int j = 0; j < turnpoi.size(); j++) {
	if (body->getPosition() == turnpoi[j]) {
	body->direction = lastbody->direction;
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
	}
	}
	body = 0;
	snakeheadrect = snakehead->getBoundingBox();
	for (int i = 0; i < snakebody->count(); i++) {
		body = (SnakeNode*)snakebody->objectAtIndex(i);
		snakebodyrect = body->getBoundingBox();
		isBounding = snakeheadrect.intersectsRect(snakebodyrect);
		if (isBounding == true) {
			this->unscheduleAllSelectors();
		}
	}
	/*body2 = 0;
	for (int i = 0; i < snake2body->count(); i++) {
		body2 = (Snake2Node*)snake2body->objectAtIndex(i);
		snakebodyrect = body2->getBoundingBox();
		isBounding = snakeheadrect.intersectsRect(snakebodyrect);
		if (isBounding == true) {
			this->unscheduleAllSelectors();
		}
	}
	body = 0;
	snakeheadrect = snake2head->getBoundingBox();
	for (int i = 0; i < snakebody->count(); i++) {
		body = (SnakeNode*)snakebody->objectAtIndex(i);
		snakebodyrect = body->getBoundingBox();
		isBounding = snakeheadrect.intersectsRect(snakebodyrect);
		if (isBounding == true) {
			this->unscheduleAllSelectors();
		}
	}
	body2 = 0;
	snakeheadrect = snake2head->getBoundingBox();
	for (int i = 0; i < snake2body->count(); i++) {
		body2 = (Snake2Node*)snake2body->objectAtIndex(i);
		snakebodyrect = body2->getBoundingBox();
		isBounding = snakeheadrect.intersectsRect(snakebodyrect);
		if (isBounding == true) {
			this->unscheduleAllSelectors();
		}
	}*/
	if (havefood == true) {
	foodrect = this->getChildByTag(1)->getBoundingBox();
	eatfood = foodrect.intersectsRect(snakeheadrect);
	if (eatfood == true) {
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
	tempbody->setPosition(ccpAdd(lastbody->getPosition(), ccp(0,-PIXEL)));
	tempbody->direction = DUP;
	}
	if (lastbody->direction == DDOWN) {
	tempbody->setPosition(ccpAdd(lastbody->getPosition(), ccp(0,PIXEL)));
	tempbody->direction = DDOWN;
	}
	snakebody->addObject(tempbody);
	tempbody = 0;
	lastbody = 0;
		this->removeChildByTag(1, true);
	this->havefood = false;

}
}
}

void GameLayer::makefood(float delta) {
FoodNode* food = FoodNode::create();
this->addChild(food);
food->setPosition(ccpAdd(ccp(100,100),ccp(PIXEL*food->ranx, PIXEL*food->rany)));
food->setTag(1);
this->havefood = true;
this->scheduleOnce(schedule_selector(GameLayer::outfood), 5.f);
//CCLOG("YES");
}

void GameLayer::outfood(float delta) {
if (this->havefood == true) {
this->removeChildByTag(1, true);
this->havefood = false;
}
}

void GameLayer::onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event) {
	if (keyCode == EventKeyboard::KeyCode::KEY_D) {
		pressdirection = DRIGHT;
		//CCLOG("%d",hero->goForward);
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
	/*if (keyCode == EventKeyboard::KeyCode::KEY_L) {
		pressdirection2 = DRIGHT;
		//CCLOG("%d",hero->goForward);
	}
	else if (keyCode == EventKeyboard::KeyCode::KEY_I) {
		pressdirection2 = DUP;
	}
	else if (keyCode == EventKeyboard::KeyCode::KEY_K) {
		pressdirection2 = DDOWN;
	}
	else if (keyCode == EventKeyboard::KeyCode::KEY_J) {
		pressdirection2 = DLEFT;
	}*/
	if (((pressdirection + snakehead->direction) != 3) && (pressdirection + snakehead->direction) != 7 && (pressdirection != snakehead->direction)) {
		snakehead->direction = pressdirection;
		temppoi =  snakehead->getPosition();
		turnpoi.push_back(temppoi);
	}
	/*if (((pressdirection2 + snake2head->direction) != 3) && (pressdirection2 + snake2head->direction) != 7 && (pressdirection2 != snake2head->direction)) {
		snake2head->direction = pressdirection2;
		turnpoi = snakehead->getPosition();;
	}*/
}