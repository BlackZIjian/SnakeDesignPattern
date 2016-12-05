#ifndef _SNAKE_LAYER_H_
#define _SNAKE_LAYER_H_
#include "cocos2d.h"
#include "vector"
#include "SnakeNodeSprite.h"
USING_NS_CC;
using namespace std;
class SnakeLayer : public Layer {
public:
	SnakeLayer();
	~SnakeLayer();
	virtual bool init();
	virtual bool init(int count);
	CREATE_FUNC(SnakeLayer);
	void callback_move_finished(int count);
	void callback_move_before(int count);
	void setSpeedScale(float scale);
	int snake_count;
	static SnakeLayer* create(int count) {
		SnakeLayer* layer = new SnakeLayer();
		if (layer && layer->init(count)) {
			layer->autorelease();
			
			return layer;
		}
		CC_SAFE_DELETE(layer);

		return nullptr;
	}
	void move(int direction);
private:
	void update(float delta_time);
	vector<SnakeNodeSprite*> nodes;
	float speed = StartScene::move_speed;
};
#endif
