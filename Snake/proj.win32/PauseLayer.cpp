#include "PauseLayer.h"

PauseLayer::PauseLayer() {

}

PauseLayer::~PauseLayer() {

}

bool PauseLayer::init() {
	bool judge = false;
	do{
		CC_BREAK_IF(!Layer::init());

	} while (0);
	return judge;
}