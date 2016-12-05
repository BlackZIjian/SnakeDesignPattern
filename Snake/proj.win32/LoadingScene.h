#ifndef __LOADING_SCENE_H__
#define __LOADING_SCENE_H__

#include "cocos2d.h"
#include "json/document.h"
#include "json/stringbuffer.h"
#include "json/writer.h"


class LoadingScene : public cocos2d::Layer
{
public:
	LoadingScene();
	~LoadingScene();
	int mode;
	virtual bool init();
	CREATE_FUNC(LoadingScene);
	static Scene* createScene(int mode);
	
private:
	bool LoadFile();
	int total_resources_num = 0;
	int now_loaded_num = 0;
	Director* director;
	std::string scene_info_path;
	rapidjson::Document doc;
	bool loading();
	void loaded_callback();
	Vector<std::string> texture_names;
};




#endif
