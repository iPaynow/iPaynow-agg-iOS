//
//  SAPIDefine.h
//  SAPILib
//
//  Created by Vinson.D.Warm on 13-9-5.
//  Copyright (c) 2013年 baidu. All rights reserved.
//

#ifndef SAPILib_SAPIDefine_h
#define SAPILib_SAPIDefine_h

/**
 登录模式
 */
typedef enum {
    SAPISilenceShareLoginMode = 2,
    SAPIChoiceShareLoginMode
} SAPILoginShareMode;

/**
 第三方帐号与百度帐号的绑定方式
 */
typedef enum {
    SAPIShareBindMobileBindMode, // 强制绑定手机号 - 在注册（首次登录）时，强制绑定手机号，推荐产品线使用该方式
    SAPIShareExplicitBindMode, // 明绑
    SAPIShareSMSBindMode, // 明绑且只支持通过手机号绑定
} SAPIShareBindMode;

/**
 快速登录选项
 */
typedef enum {
    SAPILoginOptionTSina = 0,
    SAPILoginOptionTSinaSSO,  //notice: 由于新浪微博不支持迁移appid，目前产品线无法新接入新浪微博SSO登录。
    SAPILoginOptionTQQ,
    SAPILoginOptionQzone,
    SAPILoginOptionQRCode,
    SAPILoginOptionDeviceLogin,
    SAPILoginOptionNuoMi,
    SAPILoginOptionVoicePrint,
    SAPILoginOptionWeiXinSSO,
    SAPILoginOptionFFan,
    SAPILoginOptionChuanke,   // 传课登录方式
} SAPILoginOptionType;

/**
 环境配置
 */
typedef enum ESapiEnvironmentType
{
    SapiEnvironment_Online = 1,
    SapiEnvironment_RD,
    SapiEnvironment_QA
} SapiEnvironmentType;

/**
 第3方登录相关操作返回errorcode信息
 */
typedef enum
{
    //登录返回errorcode
    Oauth_TypeNotAvailable = 10,
    Oauth_InvalidOsuid = 17,
    Oauth_InvalidAct = 18,
    Oauth_InvalidAccessToken = 19,
    Oauth_AccessCancel = 501,
    Oauth_NoUserInfo = 502,
    Oauth_PassLoginFail = 401,
    Oauth_BindError = 901,
    Oauth_OtherError = -1,
    
    //帐号正常化返回errorcode
    Oauth_UserNoLogin = 119990
}TOauthErrorCode;

/**
 *  登录类型
 */
typedef NS_ENUM(NSInteger, SAPILoginType){
    /**
     *  普通登录
     */
    SAPILoginTypeDefault,
    /**
     *  短信登录
     */
    SAPILoginTypeSMS,
};

/**
 *  登录帐号类型，用在确认用户输入的登录帐号是手机还是用户名
 */
typedef NS_ENUM(NSInteger, SAPILoginAccountType){
    /**
     *  默认情况
     */
    SAPILoginAccountTypeDefault = 0,
    /**
     *  用户输入的登录帐号为手机号
     */
    SAPILoginAccountTypeMobile = 1,
    /**
     *  用户输入的登录帐号为用户名
     */
    SAPILoginAccountTypeUsername = 2,
};

/**
 *  绑定控件类型
 */
typedef NS_ENUM(NSUInteger, SAPIBindWidgetType){
    /**
     *  绑定手机
     */
    SAPIBindWidgetTypeBindMobile,
    /**
     *  换绑手机
     */
    SAPIBindWidgetTypeRebindMobile,
    /**
     *  解绑手机
     */
    SAPIBindWidgetTypeUnbindMobile,
    /**
     *  绑定邮箱
     */
    SAPIBindWidgetTypeBindEmail,
    /**
     *  换绑邮箱
     */
    SAPIBindWidgetTypeRebindEmail,
    /**
     *  解绑邮箱
     */
    SAPIBindWidgetTypeUnbindEmail,
};

/**
 *  用户帐号类型
 */
typedef NS_ENUM(NSUInteger, SAPIUserCompleteType) {
    /**
     *  完整帐号
     */
    SAPIUserCompleteTypeNormalUser,
    /**
     *  半帐号
     */
    SAPIUserCompleteTypeIncompleteUser,
    /**
     *  未知类型，产品线需要自行查询
     */
    SAPIUserCompleteTypeUnknown,
};

/**
 *  NA与H5登录态同步策略
 *  当NA Bduss和H5 Bduss出现不一致时，根据以下策略决定最终登录状态<br/>
 *  1.SAPINativeH5SyncStrategyNativePriority —— NA优先，直接使用NA登录态覆盖H5登录态<br/>
 *  2.SAPINativeH5SyncStrategyH5Priority —— H5优先，亦即最后一次登录的帐号优先，将H5登录状态同步到NA<br/>
 */
typedef NS_ENUM(NSUInteger, SAPINativeH5SyncStrategy) {
    SAPINativeH5SyncStrategyNativePriority,
    SAPINativeH5SyncStrategyH5Priority,
};

//Service方法回调
typedef void (^SAPIRequestCompletionBlock)(NSDictionary *info);
typedef void (^SAPIRequestErrorBlock)(NSDictionary *errorInfo);

//登录相关Notification
// SAPI中相关行为所产生的Notification

/**
 *  支持互通帐号登陆成功消息 notification中的userInfo中会有登录成功后的json字典
 */
#define kLoginSucceedNotification        @"kLoginSucceedNotification"

/**
 *  不支持互通帐号登陆成功消息 notification中的userInfo中会有登录成功后的json字典
 */
#define kUnsharedLoginSucceedNotification @"kUnsharedLoginSucceedNotification"

/**
 *  登陆失败消息
 */
#define kLoginFailNotification           @"kLoginFailNotification"

/**
 *  注册验证成功消息 notification中的userInfo中会有注册成功后的json字典
 */
#define kRegistVerifiedNotification      @"kRegistVerifiedNotification"

/**
 *  补填用户名成功消息 notification中的userInfo中会有注册成功后的json字典
 */
#define kFillUnameSucceedNotification    @"kFillUnameSucceedNotification"

/**
 *  第3方页面登录返回信息
 */
#define kOauthLoginNotification          @"kOauthLoginNotification"

/**
 *  帐号完整化返回信息
 */
#define kFillAccountNotification         @"kFillAccountNotification"

/**
 *  退出返回信息
 */
#define kLogOutNotification              @"kLogOutNotification"

// Login Extra Info Key
static NSString * const SAPILoginExtraInfoIncompleteUserKey = @"incomplete_user";
static NSString * const SAPILoginExtraInfoSourceKey = @"sapi_login_extra_info_source_key";

// Login Extra Info Value
static NSString * const SAPILoginExtraInfoSourceFromH5LoginValue = @"sapi_login_extra_info_login_from_h5";

#endif
