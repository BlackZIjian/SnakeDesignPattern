#ifndef _STATE_MANAGER_H_
#define _STATE_MANAGER_H_

#include "cocos2d.h"
#include "UIObserver.h"
USING_NS_CC;
using namespace std;
class StateManager : Layer{
public:
	//����ģʽ����ȡʵ��
	static StateManager* getInstance() {
		if (instance == NULL) {
			instance = new StateManager();
			
		}
		return instance;
	}
	//����״̬
	void setState(int State);
	int getState();

	void addObserver(UIObserver* observer);
	void delObserver(string observer_name);

private:
	int state;
	//�۲����б�
	vector<UIObserver> observers;
	static StateManager* instance;
	StateManager();
};



#endif
