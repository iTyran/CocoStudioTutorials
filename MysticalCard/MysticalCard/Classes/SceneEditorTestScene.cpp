#include "SceneEditorTestScene.h"
#include "CocostudioReader/CCJsonReader.h"

using namespace cocos2d;
using namespace cocos2d::extension;

SceneEditorTestLayer::~SceneEditorTestLayer()
{
}

SceneEditorTestLayer::SceneEditorTestLayer()
{
	m_pCurNode = NULL;
}

CCScene* SceneEditorTestLayer::scene()
{
	CCScene * scene = NULL;
	do 
	{
		// 'scene' is an autorelease object
		scene = CCScene::create();
		CC_BREAK_IF(! scene);

		// 'layer' is an autorelease object
		SceneEditorTestLayer *layer = SceneEditorTestLayer::create();
		CC_BREAK_IF(! layer);

		// add layer as a child to scene
		scene->addChild(layer);
	} while (0);

	// return the scene
	return scene;
}

// on "init" you need to initialize your instance
bool SceneEditorTestLayer::init()
{
	bool bRet = false;
	do 
	{
        CC_BREAK_IF(! CCLayerColor::initWithColor( ccc4(0,0,0,255) ) );
        
//        CCSize winSize = CCDirector::sharedDirector()->getWinSize();
//        CCPoint pointCenter = ccp(winSize.width /2, winSize.height / 2);
        
        CCNode *root = createGameScene();
        CC_BREAK_IF(!root);
        root->setPosition(ccp(0, (540 - 480) / 2));
        this->addChild(root, 0, 1);

		bRet = true;
	} while (0);

	return bRet;
}

cocos2d::CCNode* SceneEditorTestLayer::createGameScene()
{
    CCNode *pNode = CCJsonReader::sharedJsonReader()->createNodeWithJsonFile("McScene.json");
	if (pNode == NULL)
	{
		return NULL;
	}
	m_pCurNode = pNode;
    
    CCComRender *pLoadRender = (CCComRender*)(m_pCurNode->getChildByTag(1)->getChildByTag(1)->getComponent("CCArmature"));
    CCArmature* armLoad = (CCArmature*)(pLoadRender->getRender());
    armLoad->getAnimation()->playByIndex(0, -1, -1, 1);

	//play back music
//    CCComAudio *pAudio = (CCComAudio*)(pNode->getComponent("Audio"));
//	pAudio->playBackgroundMusic(pAudio->getFile(), pAudio->getIsLoop());
//
//	//fishes
//	CCArmature *pBlowFish = getFish(5, "blowFish");
//	CCArmature *pButterFlyFish = getFish(6, "butterFlyFish");
//	pBlowFish->getAnimation()->playByIndex(0);
//	pButterFlyFish->getAnimation()->playByIndex(0);
//
//    CCMenuItemFont *itemBack = CCMenuItemFont::create("Back", this, menu_selector(SceneEditorTestLayer::toExtensionsMainLayer));
//        itemBack->setColor(ccc3(255, 255, 255));
//        itemBack->setPosition(ccp(VisibleRect::rightBottom().x - 50, VisibleRect::rightBottom().y + 25));
//        CCMenu *menuBack = CCMenu::create(itemBack, NULL);
//        menuBack->setPosition(CCPointZero);
//		menuBack->setZOrder(4);
//
//    pNode->addChild(menuBack);
    
	//ui action
//	cocos2d::extension::UIActionManager::shareManager()->PlayActionByName("Animation1");

    return pNode;
}

void SceneEditorTestLayer::toExtensionsMainLayer(cocos2d::CCObject *sender)
{
    
}


void runSceneEditorTestLayer()
{
}

CCArmature* SceneEditorTestLayer::getFish(int nTag, const char *pszName)
{
}
