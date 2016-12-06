#ifndef _UI_OBSERVER_H_
#define _UI_OBSERVER_H_

#include "cocos2d.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "cocos-ext.h"

USING_NS_CC;
using namespace extension;
using namespace ui;
class UIObserver{
public:
	UIObserver();
	~UIObserver();
	virtual void updateThis(int ago, int now);
	
};



#endif