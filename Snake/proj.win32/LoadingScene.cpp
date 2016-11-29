#include"LoadingScene.h"
#include"WallLayer.h"
#include"SingleScene.h"
#include"DoubleScene.h"

USING_NS_CC;

bool LoadingScene::init() {
	return LoadFile();
}

bool LoadingScene::LoadFile() {
	this->setName("LoadingLayer");
	director = Director::getInstance();

	std::string jsStr = FileUtils::getInstance()->getStringFromFile(scene_info_path);
	doc.Parse<0>(jsStr.c_str());
	if (doc.HasMember("TextureNum")) {
		const rapidjson::Value& num_value = doc["TextureNum"];

		total_resources_num = num_value.GetInt();
	}
	if (doc.HasMember("TextureNames")) {
		const rapidjson::Value& names_value = doc["TextureNames"];
		if (names_value.IsArray() && names_value.Size() > 0) {
			int count = names_value.Size();
			for (int i = 0; i < count; i++) {
				const rapidjson::Value& name_value = names_value[i];
				if (names_value.IsString()) {
					texture_names.pushBack(names_value.GetString());
				}
			}
		}
	}
	return loading();
}

bool LoadingScene::loading() {
	for (int i = 0; i < texture_names.size; i++) {
		CCTextureCache::sharedTextureCache()->addImageAsync(texture_names.at(i), callfunc_selector(LoadingScene::loaded_callback));
	}
	return true;
}

void LoadingScene::loaded_callback() {
	now_loaded_num++;
	if (now_loaded_num == total_resources_num) {
		Scene* game_scene;
		if (mode == 1) {
			game_scene = SingleScene::createScene();
		}
		else
		{
			game_scene = DoubleScene::create();
		}
		director->replaceScene(game_scene);
	}
}

Scene* LoadingScene::createScene(int mode) {
	Scene* scene = Scene::create();
	LoadingScene* layer = LoadingScene::create();
	layer->mode = mode;
	scene->addChild(layer);
	return scene;
}