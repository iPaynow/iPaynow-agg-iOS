//
//  SAPIJSONUtility.h
//  SAPIBridge
//
//  Created by Vinson.D.Warm on 9/3/13.
//  Copyright (c) 2013 SAPI. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface SAPIJSONUtility : NSObject

+ (id)objectFromJSONString:(NSString *)jsonStr;

+ (NSString *)stringFromJSONObject:(id)object;

+ (id)objectFromJSONData:(NSData *)jsonData;

+ (NSData *)dataFromJSONObject:(id)object;

+ (NSData *)dataFromJSONString:(NSString *)jsonStr;

+ (NSString *)stringFromJSONData:(NSData *)jsonData;

@end
