#include "FoodNode.h"

FoodNode::FoodNode() {

}

FoodNode::~FoodNode() {

}

bool FoodNode::init() {
	bool judge = false;
	do{
		CC_BREAK_IF(!Node::init());
		Sprite* food = Sprite::create("Food.png");
		Size mysize;
		mysize.width = 40;
		mysize.height = 40;
		food->setScale(1);
		this->addChild(food);
		//srand(time(NULL));
		Size size = Director::getInstance()->getVisibleSize();
		int x = 90;
		int y = 40;
		ranx = CCRANDOM_0_1()*x;
		rany = CCRANDOM_0_1()*y;
		judge = true;
	} while (0);
	return judge;
}