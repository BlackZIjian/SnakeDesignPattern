#ifndef __BACK_BUTTON_H__
#define __BACK_BUTTON_H__
#include "cocos2d.h"
#include "cocos-ext.h"
#include "ui/CocosGUI.h"
#include "cocos-ext.h"
#include "ButtonSubject.h"

USING_NS_CC;
using namespace extension;
using namespace ui;
class BackButton {
public:
	BackButton(ButtonSubject subject, string name);
	~BackButton();
	void updateThis(int ago, int now);
	string name;
	ButtonSubject subject;
};
#endif