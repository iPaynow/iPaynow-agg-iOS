//
//  MainViewController.h
//  TestIpaynow
//
//  Created by dby on 14-8-16.
//  Copyright (c) 2014年 Ipaynow. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "IpaynowPluginDelegate.h"

@interface MainViewController : UIViewController<IpaynowPluginDelegate, UIAlertViewDelegate> {
    UIAlertView* mAlert;
    NSMutableData* mData;
}

@end





