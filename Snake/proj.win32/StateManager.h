#ifndef _STATE_MANAGER_H_
#define _STATE_MANAGER_H_

#include "cocos2d.h"
#include "UIObserver.h"
USING_NS_CC;
using namespace std;
class StateManager : Layer{
public:
	//单例模式，获取实例
	static StateManager* getInstance() {
		if (instance == NULL) {
			instance = new StateManager();
			
		}
		return instance;
	}
	//设置状态
	void setState(int State);
	int getState();

	void addObserver(UIObserver* observer);
	void delObserver(string observer_name);

private:
	int state;
	//观察者列表
	vector<UIObserver> observers;
	static StateManager* instance;
	StateManager();
};



#endif
