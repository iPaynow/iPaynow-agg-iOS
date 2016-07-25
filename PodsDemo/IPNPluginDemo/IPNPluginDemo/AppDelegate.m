//
//  AppDelegate.m
//  IPNPluginDemo
//
//  Created by 黄睿 on 2016/7/22.
//  Copyright © 2016年 iPayNow. All rights reserved.
//

#import "AppDelegate.h"
#import "IpaynowPluginApi.h"
#include <sys/sysctl.h>

@interface AppDelegate ()

@end

@implementation AppDelegate


- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    return YES;
}

- (void)applicationWillResignActive:(UIApplication *)application {
    
}

- (void)applicationDidEnterBackground:(UIApplication *)application {

}

- (void)applicationWillEnterForeground:(UIApplication *)application {
    [IpaynowPluginApi willEnterForeground];
}

- (void)applicationDidBecomeActive:(UIApplication *)application {
    
}

- (void)applicationWillTerminate:(UIApplication *)application {
    
}

-(BOOL)application:(UIApplication *)application openURL:(NSURL *)url sourceApplication:(NSString *)sourceApplication annotation:(id)annotation{
    return  [IpaynowPluginApi application:application openURL:url sourceApplication:sourceApplication annotation:annotation];
}

// iOS9版本之后推荐回调
-(BOOL)application:(UIApplication *)app openURL:(NSURL *)url options:(NSDictionary<NSString *,id> *)options{
    NSString *sourceApplication = options[@"UIApplicationOpenURLOptionSourceApplicationKey"];
    return [IpaynowPluginApi application:app openURL:url sourceApplication:sourceApplication annotation: [[NSNull alloc]init]];
}


@end
