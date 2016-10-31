#include "HelloWorldScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#define MENULAYER 1
#define GAME 3
#define PAUSEMENU 5
#define DOUBLEGAME 4
#define PAUSELAYER 6
#define MYRETURN 7
#define HELPMENU 8


USING_NS_CC;

using namespace cocostudio::timeline;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

	layer->setTag(0);

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    //auto rootNode = CSLoader::createNode("MainScene.csb");

//    addChild(rootNode);

	MenuItem* startMenu = MenuItemImage::create("SingleAgo.png", "Single.png", this,menu_selector(HelloWorld::callback));

	MenuItem* DoubleMenu = MenuItemImage::create("DoubleAgo.png", "Double.png", this, menu_selector(HelloWorld::callback2));

	MenuItem* HelpMenu = MenuItemImage::create("HelpM.png", "HelpN.png", this, menu_selector(HelloWorld::callbackhelp));

	Menu* helpmenu = Menu::create(HelpMenu, 0);

	helpmenu->setPosition(800, 50);

	this->addChild(helpmenu);

	helpmenu->setTag(HELPMENU);

	Size size = Director::getInstance()->getVisibleSize();

	auto start = Menu::create(startMenu,0);
	start->setPosition(size.width/2, size.height/2+200);

	auto startdouble = Menu::create(DoubleMenu, 0);
	startdouble->setPosition(size.width / 2, size.height / 2 - 200);

	menulayer = Layer::create();
	menulayer->addChild(start);
	menulayer->addChild(startdouble);
	this->addChild(menulayer);
	menulayer->setTag(MENULAYER);
	auto listener = EventListenerKeyboard::create();
	listener->onKeyPressed = CC_CALLBACK_2(HelloWorld::onKeyPressed, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
	
	SimpleAudioEngine::sharedEngine()->preloadBackgroundMusic("BackGround.mp3");
	SimpleAudioEngine::sharedEngine()->setBackgroundMusicVolume(1);
	SimpleAudioEngine::sharedEngine()->preloadEffect("Food.mp3");
	SimpleAudioEngine::sharedEngine()->setEffectsVolume(1);
    return true;
}

void HelloWorld::callback(Object* pSender) {
	SingleGameLayer* game = SingleGameLayer::create();
	this->addChild(game);
	game->setTag(GAME);
	this->removeChildByTag(MENULAYER,true);
	this->removeChildByTag(PAUSEMENU, true);
	this->removeChildByTag(HELPMENU, true);
	MenuItem* pause = MenuItemImage::create("PauseAgo.png", "Pause.png", this, menu_selector(HelloWorld::callbackpause));

	Menu* pausemenu = Menu::create(pause, 0);

	pausemenu->setPosition(800, 50);
	SimpleAudioEngine::sharedEngine()->playBackgroundMusic("BackGround.mp3", true);
	this->addChild(pausemenu);
	pausemenu->setTag(PAUSEMENU);
}

void HelloWorld::callback2(Object* pSender) {
	this->removeChildByTag(0);
	Dgame = GameLayer::create();
	this->addChild(Dgame);
	Dgame->setTag(DOUBLEGAME);
	this->removeChildByTag(MENULAYER,true);
	this->removeChildByTag(PAUSEMENU, true);
	this->removeChildByTag(HELPMENU, true);
	MenuItem* pause = MenuItemImage::create("PauseAgo.png", "Pause.png", this, menu_selector(HelloWorld::callbackpause));

	Menu* pausemenu = Menu::create(pause, 0);

	pausemenu->setPosition(800, 50);
	SimpleAudioEngine::sharedEngine()->playBackgroundMusic("BackGround.mp3", true);
	this->addChild(pausemenu);
	pausemenu->setTag(PAUSEMENU);
}

void HelloWorld::callbackreturn(Object* pSender) {
	auto gamescene = HelloWorld::createScene();
	Director::getInstance()->replaceScene(gamescene);
	SimpleAudioEngine::sharedEngine()->stopBackgroundMusic(true);
}

void HelloWorld::callbackpause(Object* pSender) {
	SimpleAudioEngine::sharedEngine()->pauseBackgroundMusic();
	if (this->getChildByTag(GAME) != 0) {
		this->getChildByTag(GAME)->unscheduleAllSelectors();
	}
	else if (this->getChildByTag(DOUBLEGAME) != 0) {
		this->getChildByTag(DOUBLEGAME)->unscheduleAllSelectors();
	}
	MenuItem* myreturn = MenuItemImage::create("ReturnAgo.png", "Return.png", this, menu_selector(HelloWorld::callbackreturn));
	Menu* myreturnmenu = Menu::create(myreturn, 0);
	myreturnmenu->setPosition(300, 500);
	MenuItem* mycontinue = MenuItemImage::create("ContinueAgo.png", "Continue.png", this, menu_selector(HelloWorld::callbackcontinue));
	Menu* mycontinuemenu = Menu::create(mycontinue, 0);
	mycontinuemenu->setPosition(700, 500);
	Layer* pauselayer = Layer::create();
	pauselayer->addChild(myreturnmenu);
	pauselayer->addChild(mycontinuemenu);
	this->addChild(pauselayer);
	pauselayer->setTag(PAUSELAYER);
}

void HelloWorld::callbackcontinue(Object* pSender) {
	SimpleAudioEngine::sharedEngine()->resumeBackgroundMusic();
	if (this->getChildByTag(GAME) != 0) {
		this->getChildByTag(GAME)->scheduleUpdate();
	}
	else if (this->getChildByTag(DOUBLEGAME) != 0) {
		this->getChildByTag(DOUBLEGAME)->scheduleUpdate();
	}
	this->removeChildByTag(PAUSELAYER);
}

void HelloWorld::onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event) {
	if (keyCode == EventKeyboard::KeyCode::KEY_F5) {
		auto gamescene = HelloWorld::createScene();
		Director::getInstance()->replaceScene(gamescene);
		SimpleAudioEngine::sharedEngine()->stopBackgroundMusic(true);
	}
}

void HelloWorld::callbackhelp(Object* pSender) {
	this->removeChildByTag(MENULAYER, true);
	this->removeChildByTag(PAUSEMENU, true);
	this->removeChildByTag(HELPMENU, true);
	MenuItem* myreturn = MenuItemImage::create("ReturnAgo.png", "Return.png", this, menu_selector(HelloWorld::callbackreturn));
	Menu* myreturnmenu = Menu::create(myreturn, 0);
	myreturnmenu->setPosition(800, 50);
	this->addChild(myreturnmenu);
	Sprite* muhelp = Sprite::create("Help.png");
	muhelp->setScale(0.2);
	muhelp->setPosition(ccp(500, 500));
	this->addChild(muhelp);
}
