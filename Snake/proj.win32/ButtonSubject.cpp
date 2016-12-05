#include "ButtonSubject.h"

string ButtonSubject::SubjectState
{
	get{ return subjectState; }
    set{ subjectState = value; }
}

void ButtonSubject::Notify()
{
	foreach(JobStation o in observers)
	{
		o.updateThis();
	}
}