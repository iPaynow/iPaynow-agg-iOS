//
//  SAPIVoiceModel.h
//  SAPILib
//
//  Created by jiangzhenjie on 15/4/20.
//  Copyright (c) 2015年 baidu. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface SAPIVoiceInfo : NSObject

/**
 * 用户名
 */
@property (nonatomic, strong) NSString *voiceDisplayname;

/**
 * 用户uid
 */
@property (nonatomic, strong) NSString *voiceUid;

/**
 * 用户加密uid
 */
@property (nonatomic, strong) NSString *voiceEncryptedUid;

/**
 * 声纹授权id
 */
@property (nonatomic, strong) NSString *voiceAuthsid;

/**
 * token，需要认证用户时用到
 */
@property (nonatomic, strong) NSString *voiceToken;

/**
 * 是否需要安全认证，1需要，0不需要
 */
@property (nonatomic, assign) BOOL voiceNeedVerify;

/**
 * 用户是否是声纹用户，1是，0不是
 */
@property (nonatomic, assign) BOOL isVoiceUser;

/**
 *  密保数字
 */
@property (nonatomic, assign) NSInteger luckNumber;

/**
 *  是否开启声纹
 *  注意：该字段的设置不影响声纹的其他逻辑，只作为标志位，产品线可以自定义使用。
 */
@property (nonatomic, assign) BOOL voiceOpened;

- (instancetype)initWithDictionary:(NSDictionary *)dictionary;

- (NSDictionary *)toDictionary;

@end
