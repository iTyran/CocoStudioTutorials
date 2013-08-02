//
//  ChaosFight.cpp
//  TestCpp
//
//  Created by leafsoar on 7/23/13.
//
//

#include "ChaosFight.h"

CCScene* ChaosFightUI::scene(){
    CCScene* scene = CCScene::create();
    CCLayer* layer = ChaosFightUI::create();
    scene->addChild(layer);
    return scene;
}

bool ChaosFightUI::init(){
    bool bRef = false;
    
    do{
        CC_BREAK_IF(! CCLayer::init());
        
        ul = UILayer::create();
        // 设置 UI 层的tag
        this->addChild(ul, 0, 100);
        ul->addWidget(CCUIHELPER->createWidgetFromJsonFile("ChaosFight_1/ChaosFight_1.json"));
        
        // 获得各个控件，并添加点击事件
        UITextButton* tbChangePwd = dynamic_cast<UITextButton*>(ul->getWidgetByName("tbChangePwd"));
        UITextButton* tbBindingEmail = dynamic_cast<UITextButton*>(ul->getWidgetByName("tbBindingEmail"));
        UITextButton* tbChangeRole = dynamic_cast<UITextButton*>(ul->getWidgetByName("tbChangeRole"));
        UITextButton* tbLogout = dynamic_cast<UITextButton*>(ul->getWidgetByName("tbLogout"));
        
        
        UIButton* btnSoundEffect = dynamic_cast<UIButton*>(ul->getWidgetByName("btnSoundEffect"));
        UIButton* btnMusic = dynamic_cast<UIButton*>(ul->getWidgetByName("btnMusic"));
        UIButton* btnSavingElectricity = dynamic_cast<UIButton*>(ul->getWidgetByName("btnSavingElectricity"));
        UIButton* btnVideo = dynamic_cast<UIButton*>(ul->getWidgetByName("btnVideo"));
        
        UITextButton* tbAbout = dynamic_cast<UITextButton*>(ul->getWidgetByName("tbAbout"));
        UITextButton* tbClearCache = dynamic_cast<UITextButton*>(ul->getWidgetByName("tbClearCache"));
        
        // 设置字体颜色
        tbChangePwd->setTextColor(0, 0, 0);
        tbBindingEmail->setTextColor(0, 0, 0);
        tbChangeRole->setTextColor(0, 0, 0);
        tbLogout->setTextColor(0, 0, 0);
        
        tbAbout->setTextColor(0, 0, 0);
        tbClearCache->setTextColor(0, 0, 0);
        
        // 为控件添加处理事件
        tbChangePwd->addReleaseEvent(this, coco_releaseselector(ChaosFightUI::tbChangePwdCallback));
        tbBindingEmail->addReleaseEvent(this, coco_releaseselector(ChaosFightUI::tbBindingEmailCallback));
        tbChangeRole->addReleaseEvent(this, coco_releaseselector(ChaosFightUI::tbChangeRoleCallback));
        tbLogout->addReleaseEvent(this, coco_releaseselector(ChaosFightUI::tbLogoutCallback));

        btnSoundEffect->addReleaseEvent(this, coco_releaseselector(ChaosFightUI::btnSoundEffectCallback));
        btnMusic->addReleaseEvent(this, coco_releaseselector(ChaosFightUI::btnMusicEffectCallback));
        btnSavingElectricity->addReleaseEvent(this, coco_releaseselector(ChaosFightUI::btnSavingElectricityCallback));
        btnVideo->addReleaseEvent(this, coco_releaseselector(ChaosFightUI::btnVideoCallback));

        tbAbout->addReleaseEvent(this, coco_releaseselector(ChaosFightUI::tbAboutCallback));
        tbClearCache->addReleaseEvent(this, coco_releaseselector(ChaosFightUI::tbClearCacheCallback));
        
        
        bRef = true;
    }while(0);
    return bRef;
}

void ChaosFightUI::tbChangePwdCallback(cocos2d::CCObject *pSender){
    // 加载修改密码界面
    
    ulPwd = UILayer::create();
    ulPwd->addWidget(CCUIHELPER->createWidgetFromJsonFile("ChaosFightPassword_1/ChaosFightPassword_1.json"));
    this->addChild(ulPwd);
    ulPwd->setAnchorPoint(CCPoint(0.5,0.5));
    CCSize winSize = CCDirector::sharedDirector()->getWinSize();
    ulPwd->setPosition(CCPoint(winSize.width / 2 - 250, winSize.height / 2 - 180));
    
    // 获取点击确定按钮
    tbOk = dynamic_cast<UITextButton*>(ulPwd->getWidgetByName("tbOk"));
    tbOk->addReleaseEvent(this, coco_releaseselector(ChaosFightUI::tbOkCallback));
    tbOk->setTextColor(0, 0, 0);
    
    tfOldPwd = dynamic_cast<UITextField*>(ulPwd->getWidgetByName("tfOldPwd"));
    tfNewPwd = dynamic_cast<UITextField*>(ulPwd->getWidgetByName("tfNewPwd"));
    tfNewPwdConfirm = dynamic_cast<UITextField*>(ulPwd->getWidgetByName("tfNewPwdConfirm"));
    
    tfOldPwd->setColor(ccc3(0, 0, 0));
    tfNewPwd->setColor(ccc3(0, 0, 0));
    tfNewPwdConfirm->setColor(ccc3(0, 0, 0));
    

    ul->setTouchEnabled(false);

}

void ChaosFightUI::tbBindingEmailCallback(cocos2d::CCObject *pSender){
    CCMessageBox("绑定邮箱", "title");
}

void ChaosFightUI::tbChangeRoleCallback(cocos2d::CCObject* pSender){
    CCMessageBox("切换角色", "title");
}

void ChaosFightUI::tbLogoutCallback(cocos2d::CCObject *pSender){
    CCMessageBox("注销", "title");
}

void ChaosFightUI::btnSoundEffectCallback(cocos2d::CCObject *pSender){
    CCMessageBox("音效", "title");
}

void ChaosFightUI::btnMusicEffectCallback(cocos2d::CCObject *pSender){
    CCMessageBox("音乐", "title");
}

void ChaosFightUI::btnSavingElectricityCallback(cocos2d::CCObject *pSender){
    CCMessageBox("省电", "title");
}

void ChaosFightUI::btnVideoCallback(cocos2d::CCObject *pSender){
    CCMessageBox("片头", "title");
}

void ChaosFightUI::tbAboutCallback(cocos2d::CCObject *pSender){
    CCMessageBox("关于", "title");
}

void ChaosFightUI::tbClearCacheCallback(cocos2d::CCObject *pSender){
    CCMessageBox("清楚缓存", "title");
}

void ChaosFightUI::btnXCallback(cocos2d::CCObject *pSender){
    CCMessageBox("btnX", "title");
}

void ChaosFightUI::tbOkCallback(cocos2d::CCObject *pSender){
    // 获取文本框值，并且打印
    const char* value = tfOldPwd->getStringValue();
    CCLog(value);
    ul->setTouchEnabled(true);
    this->removeChild(ulPwd);
}

