#include "BackButton.h"
#include "ButtonSubject.h"

BackButton::BackButton(ButtonSubject subject, string name)
{
	this.subject = subject;
	this.name = name;
}

override void BackButton::updateThis()
{
	int state;
	state = subject.SubjectState;

	if (state == 0)
	{
		Button *backBTN = Button::create(
			"back.png",
			CC_CALLBACK_1(HelloWorld::menuItemSettingCallback, this));
	}

	if (state == -1)
	{
		Button::remove(this.backBTN);
	}
}