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
	CREATE_FUNC(SnakeLayer);
	void callback_move_finished();
private:
	void update(float delta_time);
	vector<SnakeNodeSprite*> nodes;
};
#endif
