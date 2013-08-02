//
//  ChaosFight.h
//  TestCpp
//
//  Created by leafsoar on 7/23/13.
//
//

#ifndef TestCpp_ChaosFight_h
#define TestCpp_ChaosFight_h

#include "cocos2d.h"
#include "CocosGUI.h"

USING_NS_CC;
USING_NS_CC_EXT;

class ChaosFightUI: public CCLayer{
public:
    static CCScene* scene();
    virtual bool init();
    CREATE_FUNC(ChaosFightUI);
    
    void tbChangePwdCallback(CCObject* pSender);
    void tbBindingEmailCallback(CCObject* pSender);
    void tbChangeRoleCallback(CCObject* pSender);
    void tbLogoutCallback(CCObject* pSender);
    
    void btnSoundEffectCallback(CCObject* pSender);
    void btnMusicEffectCallback(CCObject* pSender);
    void btnSavingElectricityCallback(CCObject* pSender);
    void btnVideoCallback(CCObject* pSender);
    
    void tbAboutCallback(CCObject* pSender);
    void tbClearCacheCallback(CCObject* pSender);
    
    
    void btnXCallback(CCObject* pSender);
    void tbOkCallback(CCObject* pSender);

private:
    UILayer* ul;
    
    
    UILayer* ulPwd;
    
    UIButton* btnX;
    UITextButton* tbOk;
    
    UITextField* tfOldPwd;
    UITextField* tfNewPwd;
    UITextField* tfNewPwdConfirm;
    
};


#endif
