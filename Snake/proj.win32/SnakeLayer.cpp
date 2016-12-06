#include"SnakeLayer.h"
#include"StartScene.h"
#include "SingleScene.h"

USING_NS_CC;

bool SnakeLayer::init() {
	snake_count = 1;
}

bool SnakeLayer::init(int count, int length, float x, float y, float width, float height) {
	this->snake_count = count;
	Texture2D* snake_texture = Director::getInstance()->getTextureCache()->addImage(texture_path);
	
	for (int i = 0; i < length; i++) {
		Rect* rect = new Rect(x - width * i, y, width, height);
		SnakeNodeSprite* node = (SnakeNodeSprite*)SnakeNodeSprite::createWithTexture(snake_texture, *rect, false);
		nodes.push_back(node);
	}
}

void SnakeLayer::setSpeedScale(float scale) {
	speed *= scale;
}
void SnakeLayer::update(float delta_time) {
	
	for (int i = 0; i < nodes.size(); i++) {
		if (i == 0) {
			nodes.at(i)->Move(speed, NULL, delta_time);
		}
		else
		{
			nodes.at(i)->Move(speed, nodes[i - 1], delta_time);
		}
	}
}

void SnakeLayer::callback_move_before(int count) {
	if (count == nodes.size() - 1) {
		((SingleScene*)getParent())->callback_end_move_before(nodes.at(count), this);
	}
}

void SnakeLayer::callback_move_finished(int count) {
	if (count == 0) {
		((SingleScene*)getParent())->callback_head_move_finished(nodes.at(count), this);
	}
}

void SnakeLayer::move(int direction) {
	int now_direction = nodes.at(0)->direction;
	if (now_direction == UP || now_direction == DOWN) {
		if (direction == LEFT || direction == RIGHT) {
			nodes.at(0)->direction = direction;
		}
	}
	else if (now_direction == LEFT || now_direction == RIGHT) {
		if (direction == UP || direction == DOWN) {
			nodes.at(0)->direction = direction;
		}
	}
}