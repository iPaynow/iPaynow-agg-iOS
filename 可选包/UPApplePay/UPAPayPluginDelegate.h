//
//  Header.h
//  UPAPayPlugin
//
//  Created by zhangyi on 10/27/15.
//  Copyright © 2015 UnionPay. All rights reserved.
//

#import <Foundation/Foundation.h>


typedef NS_ENUM(NSInteger,UPPaymentResultStatus) {
    
    UPPaymentResultStatusSuccess,
    UPPaymentResultStatusFailure,
    UPPaymentResultStatusCancel,
    UPPaymentResultStatusUnknownCancel
};


@interface UPPayResult:NSObject
@property UPPaymentResultStatus paymentResultStatus;
@property (nonatomic,strong) NSString* errorDescription;
@property (nonatomic,strong) NSString* otherInfo;
@end



@protocol UPAPayPluginDelegate <NSObject>
-(void) UPAPayPluginResult:(UPPayResult *) payResult;
@end