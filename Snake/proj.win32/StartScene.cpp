#include "StartScene.h"
#include "LoadingScene.h"
USING_NS_CC;

Scene* StartScene::createScene() {
	Scene* scene = Scene::create();

	return scene;
}
void StartScene::callback_start(int mode) {
	Scene* loading_scene = LoadingScene::createScene(mode);
	
	director->replaceScene(loading_scene);
}