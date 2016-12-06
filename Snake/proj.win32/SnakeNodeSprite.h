#ifndef __TOTAL_SNAKE_H__
#define __TOTAL_SNAKE_H__

#include "cocos2d.h"


class SnakeNodeSprite : public cocos2d::Sprite
{
public:
	SnakeNodeSprite();
	~SnakeNodeSprite();
	virtual bool init();
	static SnakeNodeSprite* create(const char* filename,int pos_x, int pos_y, int count,int direction) {
		SnakeNodeSprite* sprite = new SnakeNodeSprite();
		if (sprite && sprite->initWithFile(filename)) {
			sprite->autorelease();
			sprite->pos_x = pos_x;
			sprite->pos_y = pos_y;
			sprite->count = count;
			sprite->direction = direction;
			return sprite;
		}
		CC_SAFE_DELETE(sprite);

		return nullptr;
	}
	void Move(int speed,SnakeNodeSprite* front,float delta_time);
	int pos_x;
	int pos_y;
	int count;
	int direction;
private:
	void MoveOnePoint(SnakeNodeSprite* front);
};




#endif
