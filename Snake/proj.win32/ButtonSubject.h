#ifndef __BUTTON_SUBJECT_H__
#define __BUTTON_SUBJECT_H__
#include "cocos2d.h"
#include "Subject.h"


class ButtonSubject : Subject
{
public:
	ButtonSubject();
	~ButtonSubject();
	void Notify();
	string SubjectState;
private:
	string subjectState;
};


#endif
