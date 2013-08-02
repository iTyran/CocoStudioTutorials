#include "AppDelegate.h"

#include "cocos2d.h"
#include "SimpleAudioEngine.h"
#include "cocos-ext.h"
#include "SceneEditorTestScene.h"

USING_NS_CC;
using namespace CocosDenshion;

AppDelegate::AppDelegate()
{
}

AppDelegate::~AppDelegate()
{
//    SimpleAudioEngine::end();
	cocos2d::extension::CCArmatureDataManager::purgeArmatureSystem();
}

bool AppDelegate::applicationDidFinishLaunching()
{
	// As an example, load config file
	// XXX: This should be loaded before the Director is initialized,
	// XXX: but at this point, the director is already initialized
	CCConfiguration::sharedConfiguration()->loadConfigFile("configs/config-example.plist");

    // initialize director
    CCDirector *pDirector = CCDirector::sharedDirector();
    pDirector->setOpenGLView(CCEGLView::sharedOpenGLView());

//    CCSize screenSize = CCEGLView::sharedOpenGLView()->getFrameSize();

    CCSize designSize = CCSizeMake(720, 540);
    
    CCLog("winSize: %f  %f", pDirector->getWinSize().width, pDirector->getWinSize().height );


//    if (screenSize.height > 320)
//    {
//        CCSize resourceSize = CCSizeMake(960, 640);
//        std::vector<std::string> searchPaths;
//        searchPaths.push_back("hd");
//        pFileUtils->setSearchPaths(searchPaths);
//        pDirector->setContentScaleFactor(resourceSize.height/designSize.height);
//    }

    CCEGLView::sharedOpenGLView()->setDesignResolutionSize(designSize.width, designSize.height, kResolutionNoBorder);

//    CCScene * pScene = CCScene::create();
//    CCLayer * pLayer = new TestController();
    
//    pLayer->autorelease();

//    pScene->addChild(pLayer);
    
//    CCScene* pScene = CCScene::create();
    CCScene* pScene = SceneEditorTestLayer::scene();
    pDirector->runWithScene(pScene);

    pDirector->setDisplayStats(false);
    return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground()
{
    CCDirector::sharedDirector()->stopAnimation();
    SimpleAudioEngine::sharedEngine()->pauseBackgroundMusic();
    SimpleAudioEngine::sharedEngine()->pauseAllEffects();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground()
{
    CCDirector::sharedDirector()->startAnimation();
    SimpleAudioEngine::sharedEngine()->resumeBackgroundMusic();
    SimpleAudioEngine::sharedEngine()->resumeAllEffects();
}
