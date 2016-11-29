
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
	
	
	scene->addChild(layer);
	return scene;
}