#include "ContinueButton.h"
#include "ButtonSubject.h"

ContinueButton::ContinueButton(ButtonSubject subject, string name)
{
	this.subject = subject;
	this.name = name;
}

override void ContinueButton::updateThis()
{
	int state;
	state = subject.SubjectState;

	if (state == 0)
	{
		Button *continueBTN = Button::create(
			"continue.png",
			CC_CALLBACK_1(HelloWorld::menuItemSettingCallback, this));
	}

	if (state == -1)
	{
		Button::remove(this.continueBTN);
	}
}