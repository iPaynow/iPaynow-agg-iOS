//
//  SAPIInterfaceFactory.h
//  SAPILib
//
//  Created by Vinson.D.Warm on 13-9-6.
//  Copyright (c) 2013年 baidu. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface SAPIInterfaceFactory : NSObject

@property (nonatomic, strong) NSString *qrCodeLoginInterface;

@property (nonatomic, copy) NSString* oauth_url;
@property (nonatomic, copy) NSString* qrcodeLoginApp2PcUrl;
@property (nonatomic, copy) NSString* qrcodeLoginPc2AppUrl;
@property (nonatomic, copy) NSString* smsGetLoginUrl;
@property (nonatomic, copy) NSString* deviceIdRegUrl;
@property (nonatomic, copy) NSString* deviceIdForceRegUrl;
@property (nonatomic, copy) NSString* deviceIdLoginUrl;
@property (nonatomic, copy) NSString* deviceIdInfoUrl;
@property (nonatomic, copy) NSString* sinaSSOLoginUrl;
@property (nonatomic, copy) NSString* dynamicPassUrl;
@property (nonatomic, copy) NSString* uploadPortraitUrl;
@property (nonatomic, copy) NSString* getPortraitUrl;
@property (nonatomic, copy) NSString* fillUnameUrl;
@property (nonatomic, copy) NSString* bindTelephoneUrl;
@property (nonatomic, copy) NSString* reloginUrl;
@property (nonatomic, copy) NSString* dypassLoginUrl;
@property (nonatomic, copy) NSString* fillAccountDomain;
@property (nonatomic, copy) NSString* fillaccount_url;
@property (nonatomic, copy) NSString* forgetPwdUrl;
@property (nonatomic, copy) NSString* getVoiceIdUrl;
@property (nonatomic, copy) NSString* voiceLoginUrl;
@property (nonatomic, copy) NSString* voiceSignUpUrl;
@property (nonatomic, copy) NSString* getUinfoUrl;
@property (nonatomic, copy) NSString* c2bSyncLoginUrl;
@property (nonatomic, copy) NSString* getHistoricalAvatarUrl;
@property (nonatomic, copy) NSString* getHotAvatarListUrl;
@property (nonatomic, copy) NSString* setHotAvatarUrl;
@property (nonatomic, copy) NSString* updateVoiceLuckNumberUrl;
@property (nonatomic, copy) NSString* faceRegisterUrl;
@property (nonatomic, copy) NSString* getFaceIdUrl;
@property (nonatomic, copy) NSString* faceLoginUrl;
@property (nonatomic, copy) NSString* updateFaceUrl;
@property (nonatomic, copy) NSString* deleteFaceUrl;

// 获取登录界面验证码地址
@property (nonatomic, copy) NSString* getCaptchaUrl;
// 获取注册时的验证码地址 sdk_veriosn: v3
@property (nonatomic, copy) NSString* applyRegCodeUrl;
// 提交注册信息 sdk_veriosn: v3
@property (nonatomic, copy) NSString* phoneRegVerifyUrl;
// 快推帐号注册 sdk_veriosn: v3
@property (nonatomic, copy) NSString* regQuickUrl;
// 帐号正常化 6.8.2新增
@property (nonatomic, copy) NSString* accountNormalizationUrl;

+ (SAPIInterfaceFactory *)factory;

+ (NSString *)enhancedReloginURLString;

#pragma mark Utility Interface
/**
 * 设置声纹开关url
 */
+ (NSString *)urlStringForSetVoiceOpened;

/**
 *  声纹验证url
 */
+ (NSString *)urlStringForVerifyVoice;

+ (NSString *)setSSOChannelInfoUrlString;

+ (NSString *)bdussExchangeAccessTokenUrlString;

+ (NSString *)getStokenURLString;

@end
