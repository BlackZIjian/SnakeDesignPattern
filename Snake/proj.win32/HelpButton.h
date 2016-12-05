#ifndef __HELP_BUTTON_H__
#define __HELP_BUTTON_H__
#include "cocos2d.h"
#include "cocos-ext.h"
#include "ui/CocosGUI.h"
#include "cocos-ext.h"
#include "ButtonSubject.h"

USING_NS_CC;
using namespace extension;
using namespace ui;
class HelpButton {
public:
	HelpButton(ButtonSubject subject, string name);
	~HelpButton();
	void updateThis(int ago, int now);
	string name;
	ButtonSubject subject;
};
#endif
