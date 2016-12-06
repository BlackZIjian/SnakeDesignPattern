
#include"SingleScene.h"
#include"SnakeLayer.h"
#include"FoodLayer.h"
#include"WallLayer.h"

USING_NS_CC;

bool SingleScene::init() {
	SnakeLayer* m_snake_layer = SnakeLayer::create();
	FoodLayer* m_food_layer = FoodLayer::create();
	WallLayer* m_wall_layer = WallLayer::create();
	this->addChild(m_food_layer);
	this->addChild(m_snake_layer);
	this->addChild(m_wall_layer);
}

Scene* SingleScene::createScene() {
	Scene* scene = Scene::create();
	SingleScene* layer = SingleScene::create();
	SnakeLayer* snake = SnakeLayer::create(1);

	scene->addChild(layer);
	scene->addChild(snake);
	instance = layer;
	return scene;
}

void SingleScene::callback_head_move_finished(SnakeNodeSprite* head,SnakeLayer* snake) {
	int x = head->pos_x;
	int y = head->pos_y;
	int ago_value = pixel[x][y];
	if (ago_value == NONE_IN_PIXEL) {
		pixel[x][y] = snake->snake_count;
	}
	else
	{
		//ײǽ
	}
}

void SingleScene::callback_head_move_before(SnakeNodeSprite* end, SnakeLayer* snake) {
	int x = end->pos_x;
	int y = end->pos_y;
	pixel[x][y] = NONE_IN_PIXEL;
}

int SingleScene::AddNewSnake() {
	snake_num++;
	SnakeLayer* snake = SnakeLayer::create(snake_num - 1);
	this->addChild(snake);
	return snake_num - 1;
}

