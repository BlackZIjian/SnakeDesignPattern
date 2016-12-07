#include "HelpButton.h"
#include "ButtonSubject.h"

HelpButton::HelpButton(ButtonSubject subject, string name)
{
	this.subject = subject;
	this.name = name;
}

override void HelpButton::updateThis()
{
	int state;
	state = subject.SubjectState;

	if (state == 0)
	{
		Button *helpBTN = Button::create(
			"help.png",
			CC_CALLBACK_1(HelloWorld::menuItemSettingCallback, this));
	}

	if (state == -1) 
	{
		Button::remove(this.helpBTN);
	}
}