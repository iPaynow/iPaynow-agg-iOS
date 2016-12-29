//
//  SapiError.h
//  SAPIDemo
//
//  Created by leon xia on 12-5-29.
//  Copyright (c) 2012年 baidu. All rights reserved.
//

#import <Foundation/Foundation.h>

// 定义ErrorCode
typedef enum ESapiEvent
{
    SapiErrCode_Succeed                   = 0, /**	注册成功	110000 登录成功	0*/
    SapiErrCode_UsernameFormatError       = 1, /*注册用户名格式错误	110002 登录用户名格式错误	1*/
    SapiErrCode_UsernameNotExist          = 2, /**用户名不存在*/
    SapiErrCode_DpassNotExistOrInvalid    = 3, /*动态密码不存在或已过期*/
    SapiErrCode_PasswordWrong             = 4, /*登录密码错误*/
    SapiErrCode_VerifyCodeNotMatch        = 6, /*登录验证码不匹配，请重新输入验证码*/
    SapiErrCode_CannotLogin               = 16, /*对不起，您现在无法登陆(被强反作弊策略直接拒绝)*/
    SapiErrCode_LoginProtection           = 17, /*登录保护*/
    SapiErrCode_PasswordFormatError       = 120013, /*登陆密码格式错误*/
    SapiErrCode_NeedActivateEmail         = 110024, /*请激活邮箱*/
    SapiErrCode_PlsInputVerifyCode        = 257, /*登录请输入验证码 257 注册请输入图片验证码，	110032*/
    SapiErrCode_UsernameExist             = 110003, /*用户名已存在*/
    SapiErrCode_WeakPwd                   = 110012, /*密码是极弱密码*/
    SapiErrCode_PwdFormatError            = 110013, /*密码格式错误*/
    SapiErrCode_VerifyCodeInputErr        = 110031, /**注册图片验证码输入错误，则bundle中会含有vcodestr的key可以取到验证码凭据 */
    SapiErrCode_Cheat                     = 130001, /*命中反作弊(同一手机校验请求频度过快)*/
    SapiErrCode_SmsVerifyCodeWrong        = 130003, /*短信验证码输入错误*/
    SapiErrCode_SmsVerifyCodeExpired      = 130004, /*短信验证码已过期*/
    SapiErrCode_UsernameEmpty             = 130005, /*用户名为空*/
    SapiErrCode_UsernameCannotUse         = 130007, /*用户名不可用*/
    SapiErrCode_PwdEmpty                  = 130010, /*密码为空*/
    SapiErrCode_BugetBreak                = 130016, /**产品线申请下发的短信条数超出预算*/
    SapiErrCode_SmsCheat                  = 130017, /**命中反作弊(同一手机申请下发短信次数过多)*/
    SapiErrCode_PhoneNumNull              = 130018, /**手机号为空*/
    SapiErrCode_PhoneFormatErr            = 130019, /**手机号格式错误*/
    SapiErrCode_PhoneNumBinded            = 130020, /**手机号已被绑定*/
    SapiErrCode_SmsVerifyCodeNull         = 130021, /*短信验证码为空*/
    SapiErrCode_PlsGetSmsVerifyCode       = 130022, /*请申请下发短信验证码*/
    SapiErrCode_NeedRequiredItems         = 130025, /*必填项填写不完整*/
    SapiErrCode_SetPortraitSuccess        = 140001, /*上传头像成功*/
    SapiErrCode_SignatureError            = 140003, /*签名错误*/
    SapiErrCode_TplOrAppidError           = 140004, /*tpl或appid错误*/
    SapiErrCode_IpAuthorityError          = 140005, /*ip授权错误(目前未使用)*/
    SapiErrCode_InterfaceTooOld           = 140008, /*接口版本太老，需要升级至新版接口*/
    SapiErrCode_DBGateCommunicationError  = 100001, /**DBGate通信错误*/
    SapiErrCode_AntiifCommunicateError    = 100002, /**antiif通信错误(格式检查失败)*/
    SapiErrCode_AdminDBCommunicateError   = 100003, /*adminDB通信错误*/
    SapiErrCode_SessionCommunicateError   = 100005, /*session通信错误(请手动登陆)*/
    SapiErrCode_AntiCheatCommunicateError = 100008, /*反作弊模块通信错误*/
    SapiErrCode_SmsCommunicateError       = 100014, /*sms通信错误*/
	//Loga错误码
    SapiErrCode_TplNotPermit              = 210000, /*TPL未授权或者TPL与产品线不匹配*/
    SapiErrCode_LoginFailOverLimit        = 210001, /*安全认证登陆失败次数超过上限*/
    SapiErrCode_TokenCheckFail            = 210002, /*安全token校验失败（ptoken错误）*/
    SapiErrCode_OtherParamError           = 210003, /*其他参数错误*/
    SapiErrCode_VersionTooOld             = 140008, /*接口版本太老，需要升级至新版接口*/
	//fillUname错误码
    SapiErrCode_BdussIsEmpty              = 160102, /*bduss为空*/
    SapiErrCode_UserIsNotOnline           = 160103, /*用户不在线*/
    SapiErrCode_UserDoHaveName            = 160104, /*用户已有用户名*/
    SapiErrCode_FillUnameCannotBeUse      = 160105, /*补填用户的用户名不可用*/
    SapiErrCode_FillUnameSucceed          = 110000, /*补填用户名成功*/
    SapiErrCode_ForceOfflineFailed        = 160106, /*强制下线失败（补填用户名成功，需要用户主动登陆）*/
    SapiErrCode_ReLoginFailed             = 160107, /*重新登陆失败（补填用户名成功，需要用户主动登陆）*/
    SapiErrCode_FillUnameIsEmpty          = 160100, /*补填用户名为空*/
    SapiErrCode_FillUnameFormatError      = 160110, /*补填用户名格式错误*/
    SapiErrCode_FillUnameIsExist          = 160111, /*补填用户名已被占用*/
    // 上传头像错误码
    SapiErrCode_PortraitParameterError    = 1605001, /*上传头像参数错误*/
    SapiErrCode_PortraitSysError          = 1605002, /*上传头像系统错误*/
    SapiErrCode_PortraitUserInfoError     = 1605003, /*上传头像用户信息错误*/
    //Logout错误码
    SapiErrCode_UserNotLogin              = -301, /*用户未登录*/
    SapiErrCode_BdstokenFailed            = -302, /*bdstoken校验失败*/
    SapiErrCode_PtokenInvalid             = -303, /*ptoken无效*/
    SapiErrCode_PtokenEmpty               = -304, /*ptoken缺失*/
    SapiErrCode_LoginInterfaceParamError  = -1, /*登录接口参数错误*/
    SapiErrCode_LoginSignatureError       = -2, /*登录签名错误*/
    SapiErrCode_TplAppidGroupNotFound     = -3, /*未找到的tpl+appid组合*/
    SapiErrCode_IpHasNoAuthority          = -4, /*访问方IP未授权*/
    /*指定的cert_id不存在*/
    SapiErrCode_CertOverTime              = -5, /*证书失效*/
    SapiErrCode_Cer_idNotExist            = -6, /*证书Cer_id不存在*/
    SapiErrCode_SentSucceed               = -101, /**成功发送请求*/
    SapiErrCode_NotInit                   = -102, /**< 组件未被init过 */
    SapiErrCode_InvalidArg                = -103, /**< 参数不合法 */
    SapiErrCode_GettingCert               = -104, /**正在获取证书*/
    SapiErrCode_GetCertFail               = -105, /**获取证书失败*/
    SapiErrCode_SaveCertFail              = -106, /**存储证书失败*/
    SapiErrCode_ImageSizeOverFlow         = -107, /**头像图片太大**/
    SapiErrCode_Network_Failed            = -200, /**网络超时或失败*/
    SapiErrCode_ErrorUnknown              = -100, /*未知错误*/
    /* 头像系统增加的错误码 */
    SapiErrCode_UserNotOnline             = 400021, /* 用户不在线 */
    SapiErrCode_OtherError                = 170000, /* 其他错误 */
    // HTTPS错误
    SapiErrCode_CertExpired               = errSSLCertExpired,   /* 因设备时间不对导致HTTPS证书过期*/
} TSapiEventCode;

@interface SapiError : NSObject

+(NSString*)getErrorStrWithCode:(NSInteger) errCode;

+(NSString*)getOauthErrorStrWithCode:(NSInteger) errCode;

+(NSString*)getSmsRegErrorStrWithCode:(NSInteger) errCode;

@end
