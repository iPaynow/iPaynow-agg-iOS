//
//  ViewController.h
//  IPNPluginDemo
//
//  Created by 黄睿 on 2016/7/22.
//  Copyright © 2016年 iPayNow. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "IpaynowPluginDelegate.h"

@interface ViewController : UIViewController<IpaynowPluginDelegate,UIAlertViewDelegate>{
    UIAlertView *mAlert;
    NSMutableData *mData;
}


@end

