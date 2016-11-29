#include"SnakeLayer.h"
#include"StartScene.h"

USING_NS_CC;

bool SnakeLayer::init() {

}

void SnakeLayer::update(float delta_time) {
	float speed = StartScene::move_speed;
	for (int i = 0; i < nodes.size; i++) {
		if (i == 0) {
			nodes.at(i)->Move(speed, NULL, delta_time);
		}
		else
		{


			nodes.at(i)->Move(speed, nodes[i - 1], delta_time);
		}
	}
}