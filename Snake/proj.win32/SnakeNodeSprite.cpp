#include"SnakeNodeSprite.h"
#include "StartScene.h"
#include "SnakeLayer.h"

void SnakeNodeSprite::MoveOnePoint(SnakeNodeSprite* front) {
	SnakeLayer* parent = (SnakeLayer*)getParent();
	parent->callback_move_before(count);
	float delta_x = StartScene::delta_x;
	float delta_y = StartScene::delta_y;

	float new_pos_y = pos_y;
	float new_pos_x = pos_x;
	if (direction == UP) {
		new_pos_y += delta_y;
	}
	else if(direction == DOWN)
	{
		new_pos_y -= delta_y;
	}
	else if(direction == LEFT)
	{
		new_pos_x -= delta_x;
	}
	else if(direction == RIGHT)
	{
		new_pos_x += delta_x;
	}
	setPosition(new_pos_x, new_pos_y);
	if (front != NULL) {
		direction = front->direction;
	}
		
		parent->callback_move_finished(count);
	
}

void SnakeNodeSprite::Move(int speed, SnakeNodeSprite* front,float delta_time) {
	for (int i = 0; i < speed * delta_time; i++) {
		
		MoveOnePoint(front);
	}
}