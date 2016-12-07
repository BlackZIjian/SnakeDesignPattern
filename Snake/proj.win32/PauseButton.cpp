#include "PauseButton.h"
#include "ButtonSubject.h"

PauseButton::PauseButton(ButtonSubject subject, string name)
{
	this.subject = subject;
	this.name = name;
}

override void PauseButton::updateThis()
{
	int state;
	state = subject.SubjectState;

	if (state == 0)
	{
		Button *pauseBTN = Button::create(
			"pause.png",
			CC_CALLBACK_1(HelloWorld::menuItemSettingCallback, this));
	}

	if (state == -1) 
	{
		Button::remove(this.pauseBTN);
	}
}