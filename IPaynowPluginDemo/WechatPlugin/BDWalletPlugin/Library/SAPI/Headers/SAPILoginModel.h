//
//  SAPILoginModel.h
//  SAPILib
//
//  Created by Vinson.D.Warm on 13-9-5.
//  Copyright (c) 2013年 baidu. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SAPIDefine.h"

@interface SAPILoginModel : NSObject <NSCopying>

/**
 *  用户自行设置的用户名，可能为nil或空字符串
 */
@property(nonatomic, copy) NSString* uname;

/**
 *  登录后得到的bduss (必须)，不能为nil或空字符串
 */
@property(nonatomic, copy) NSString* bduss;

/**
 *  用于显示用途的显示用户名。 <br/> 
 *  当用户设置了用户名时，为设置的用户名；没有设置用户名时为打码后的手机或邮箱。 <br/>
 *  不能为nil或空字符串
 */
@property(nonatomic, copy) NSString* displayname;

/**
 *  userid (必须)，不能为nil或空字符串。如果有转换成整型需求，请务必使用long long类型。
 */
@property(nonatomic, copy) NSString* uid;

/**
 *  第3方登录端typeid
 *  
 *  1 => 人人登录 Web <br/>
 *  2 => 新浪微博 Web <br/>
 *  4 => 腾讯微博 Web <br/>
 *  15 => Qzone登录 Web <br/>
 *  42 => 微信登录 <br/>
 */
@property(nonatomic, copy) NSString* oauthType;

/**
 *  帐号登录来源，一般为来源app的名称
 */
@property(nonatomic, copy) NSString* app;

/**
 *  第三方登录用户头像地址
 */
@property (nonatomic, copy) NSString *os_headImgURLString;

/**
 *  根据传入参数生成SAPILoginModel实例
 *
 *  @param loginSharedInfo 传入参数
 *
 *  @return SAPILoginModel实例
 */
- (instancetype)initWithDictionary:(NSDictionary *)loginSharedInfo;

/**
 *  将SAPILoginModel实例转换为键值对
 *
 *  @return 键值对
 */
- (NSDictionary *)toDictionary;

/**
 *  判断Model是否有效。注意：Model有效仅指bduss、uid、displayname是否不为空，并不代表bduss有效，bduss是否有效由服务端决定。
 *
 *  @return 当bduss、uid、displayname均不为nil或空字符串时返回YES，其他返回NO
 */
- (BOOL)isValid;

@end
