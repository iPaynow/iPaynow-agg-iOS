//
//  SAPIWebView.h
//  SAPIBridge
//
//  Created by Vinson.D.Warm on 9/3/13.
//  Copyright (c) 2013 SAPI. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "SAPIPlugin.h"
#import "SAPIDefine.h"

@class SAPIWebView;
@class SAPILoginModel;

@protocol SAPIWebViewDelegate <NSObject>

@optional
- (BOOL)sapiWebView:(SAPIWebView *)webView shouldStartLoadWithRequest:(NSURLRequest *)request navigationType:(UIWebViewNavigationType)navigationType;
- (void)sapiWebViewDidStartLoad:(SAPIWebView *)webView;
- (void)sapiWebViewDidFinishLoad:(SAPIWebView *)webView;
- (void)sapiWebView:(SAPIWebView *)webView didFailLoadWithError:(NSError *)error;

@end

@interface SAPIWebView : UIWebView

@property (nonatomic, strong) SAPIPlugin *plugin;

@property (nonatomic, strong) NSMutableArray *plugins;

@property (nonatomic, weak) id<SAPIWebViewDelegate> webViewDelegate;

- (id)initWithPlugin:(SAPIPlugin *)plugin;

- (void)load:(NSURL *)url;

- (void)load:(NSURL *)url cookies:(NSArray *)cookies;

- (void)addPlugin:(SAPIPlugin *)plugin;

- (BOOL)historyBack;

- (NSURL *)currentURL;

- (void)addBlackListModule:(NSURL *)url;

- (void)clean;

/**
 *  在注册、登录界面采用native导航栏时，如果需要回退到上一个webview页面时可调用此方法
 *
 *  v6.7.10新增
 *
 *  调用时有以下两种情况：
 *  1.如果webview可以回退，则会回退到上一个页面；
 *  2.如果不能回退，则会调用注册到webview的SAPIControlPlugin中的finish:方法来关闭整个视图控制器（或执行其他操作）
 */
- (void)sapiWebViewGoBackIfPossible;

@end

@interface SAPIWebView (SAPIWebViewLoadAddition)

- (void)loadLoginVerifyWithURLString:(NSString *)urlString;

/**
 *  对半帐号进行正常化
 *
 *  @param bduss    需要正常化帐号的bduss
 *  @param callback 正常化以后的回调。正常化成功时会回传一个SAPILoginModel实例；失败时会回传一个NSError实例
 */
- (void)loadAccountNormalizationURLWithBduss:(NSString *)bduss callback:(void(^)(SAPILoginModel *model, NSError *error))callback;

/**
 *  对半帐号进行正常化
 *
 *  @param bduss      需要正常化帐号的bduss
 *  @param input      正常化时是否需要输入密码：YES表示需要输入密码；NO表示不需要输入密码
 *  @param callback   正常化以后的回调。正常化成功时会回传一个SAPILoginModel实例；失败时会回传一个NSError实例
 */
- (void)loadAccountNormalizationURLWithBduss:(NSString *)bduss shouldInputPassword:(BOOL)input callback:(void(^)(SAPILoginModel *model, NSError *error))callback;

/**
 *  修改密码
 *
 *  @param bduss      需要修改密码的bduss
 *  @param callback   修改密码回调。error为空，表明修改密码成功，否则修改密码失败。loginModel不为空，表明更新当前登录模型成功，否则更新当前登录模型失败。
 */
- (void)loadModifyPasswordURLWithBduss:(NSString *)bduss callback:(void (^)(SAPILoginModel *loginModel, NSError *error))callback;

/**
 *  操作记录
 *
 *  @param bduss bduss
 */
- (void)loadRecordIndexURLWithBduss:(NSString *)bduss;

@end

@interface SAPIWebView (SAPIWebViewLoadBindManageAddition)

/**
 *  加载绑定控件
 *
 *  @param type     绑定控件类型
 *  @param bduss    bduss
 *  @param callback 回调
 */
- (void)loadBindWidgetURLWithType:(SAPIBindWidgetType)type
                            bduss:(NSString *)bduss
                         callback:(void (^)(NSError *error))callback;

/**
 *  绑定手机时，如果该手机已被绑定，同时配置[SAPIMainManager sharedManager].handleBindMobileConflict为YES，
 *  在用户点击“手机号登录”选项时则会回调此代码块。
 *
 *  @param bindConflictBlock 回调代码块，当配置[SAPIMainManager sharedManager].handleBindMobileConflict为YES时，bindConflictBlock必须不能为空。
 */
- (void)setHandleBindConflictBlock:(void(^)(NSDictionary *params))bindConflictBlock;

@end

@interface SAPIWebView (SAPIWebViewDeprecatedCategory)

- (void)load:(NSURL *)url cookies:(NSArray *)cookies persistentBduss:(BOOL)persistent DEPRECATED_MSG_ATTRIBUTE("Use load:cookies: instead");

- (void)loadAccountNormalizationURLWithBduss:(NSString *)bduss persistentBduss:(BOOL)persistent callback:(void(^)(SAPILoginModel *model, NSError *error))callback DEPRECATED_MSG_ATTRIBUTE("Use loadAccountNormalizationURLWithBduss:callback: instead");

- (void)loadAccountNormalizationURLWithBduss:(NSString *)bduss persistentBduss:(BOOL)persistent shouldInputPassword:(BOOL)input callback:(void(^)(SAPILoginModel *model, NSError *error))callback DEPRECATED_MSG_ATTRIBUTE("Use loadAccountNormalizationURLWithBduss:shouldInputPassword:callback: instead");

- (void)loadModifyPasswordURLWithBduss:(NSString *)bduss persistentBduss:(BOOL)persistent callback:(void (^)(SAPILoginModel *loginModel, NSError *error))callback DEPRECATED_MSG_ATTRIBUTE("Use loadModifyPasswordURLWithBduss:callback: instead");

- (void)loadBindMobileURLWithBduss:(NSString *)bduss persistentBduss:(BOOL)persistent callback:(void (^)(NSError *error))callback DEPRECATED_MSG_ATTRIBUTE("Use loadBindWidgetURLWithType:bduss:callback: instead");

- (void)loadRebindMobileURLWithBduss:(NSString *)bduss persistentBduss:(BOOL)persistent callback:(void (^)(NSError *error))callback DEPRECATED_MSG_ATTRIBUTE("Use loadBindWidgetURLWithType:bduss:callback: instead");

- (void)loadUnbindMobileURLWithBduss:(NSString *)bduss persistentBduss:(BOOL)persistent callback:(void (^)(NSError *error))callback DEPRECATED_MSG_ATTRIBUTE("Use loadBindWidgetURLWithType:bduss:callback: instead");

- (void)loadBindEmailURLWithBduss:(NSString *)bduss persistentBduss:(BOOL)persistent callback:(void (^)(NSError *error))callback DEPRECATED_MSG_ATTRIBUTE("Use loadBindWidgetURLWithType:bduss:callback: instead");

- (void)loadRebindEmailURLWithBduss:(NSString *)bduss persistentBduss:(BOOL)persistent callback:(void (^)(NSError *error))callback DEPRECATED_MSG_ATTRIBUTE("Use loadBindWidgetURLWithType:bduss:callback: instead");

- (void)loadUnbindEmailURLWithBduss:(NSString *)bduss persistentBduss:(BOOL)persistent callback:(void (^)(NSError *error))callback DEPRECATED_MSG_ATTRIBUTE("Use loadBindWidgetURLWithType:bduss:callback: instead");

@end
