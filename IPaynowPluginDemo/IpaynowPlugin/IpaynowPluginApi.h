//
//  IpaynowPluginApi.h
//  TestPlugin
//
//  Created by dby on 14-8-19.
//  Copyright (c) 2014年 Ipaynow. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "IpaynowPluginDelegate.h"

@interface IpaynowPluginApi : NSObject

/**
 *  设置导航栏颜色
 *
 *  @param color 颜色
 */
+ (void)setStemeColor:(UIColor *)color;

/**
 *  用户Apple Pay支付 （如不使用Apple Pay支付，可不写）
 *
 *  @param merchantID merchatID
 */
+ (void)setMerchantID:(NSString *)merchantID;


/**
 *  用户苹果应用内支付（如不使用应用内支付，可不写）
 *
 *  @param productID 产品ID
 *  @param quantity  数量
 *  @param orderNo   订单
 */
+ (void)setProductIdentifier:(NSString *)productID andQuantity:(NSInteger)quantity orderNo:(NSString *)orderNo;


/**
 是否隐藏loading页面

 @param isHidden 隐藏
 */
+ (void)setLoadingViewHidden:(BOOL)isHidden;



/**
 *  是否在支付状态返回之前隐藏loading页面 （为防止用户重复支付不建议使用）
 *
 *  @param isHidden 隐藏
 */
+ (void)setBeforeReturnLoadingHidden:(BOOL)isHidden;



/**
 *  支付接口
 *
 *  @param data           参数组成的字符串
 *  @param scheme         scheme description
 *  @param viewController 所在的viewController
 *  @param delegate       接口返回代理
 *
 *  @return 是否成功
 */
+ (BOOL)pay:(NSString*)data AndScheme:(NSString*)scheme viewController:(UIViewController*)viewController delegate:(id<IpaynowPluginDelegate>)delegate;


/**
 *  从第三方返回时调用，写于AppDelegate中openUrl方法中
 *
 *  @param application       application description
 *  @param url               url description
 *  @param sourceApplication sourceApplication description
 *  @param annotation        annotation description
 *
 *  @return return value description
 */
+ (BOOL)application:(UIApplication *)application openURL:(NSURL *)url sourceApplication:(NSString *)sourceApplication annotation:(id)annotation;


/**
 *  启动app时候调用，用户微信支付
 */
+ (void)willEnterForeground;
@end
