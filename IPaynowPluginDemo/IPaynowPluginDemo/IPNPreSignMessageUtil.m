//
//  IPNPreSignMessageUtil.m
//  TestPlugin
//
//  Created by Chuck on 2017/7/26.
//  Copyright © 2017年 iPayNow. All rights reserved.
//

#import "IPNPreSignMessageUtil.h"
#import <objc/runtime.h>

@implementation IPNPreSignMessageUtil

-(NSString *)generatePresignMessage{

    
    Class clazz = [self class];
    u_int count;
    
    objc_property_t* properties = class_copyPropertyList(clazz, &count);
    NSMutableArray* propertyArray = [NSMutableArray arrayWithCapacity:count];
    for (int i = 0; i < count ; i++){
        const char* propertyName = property_getName(properties[i]);
        [propertyArray addObject:[NSString  stringWithCString:propertyName encoding:NSUTF8StringEncoding]];
    }
    free(properties);
    
    NSMutableDictionary *dic=[NSMutableDictionary new];
    for (NSString *name in propertyArray){
        NSString* value = [self valueForKey:name];
        if (value !=nil && ![@"" isEqualToString:value])
             [dic setValue:value forKey:name];
    }
    
    NSArray *keys = [dic allKeys];
    NSSortDescriptor *descriptor = [NSSortDescriptor sortDescriptorWithKey:nil ascending:YES];
    NSArray *descriptors = [NSArray arrayWithObject:descriptor];
    NSArray *sortedArray = [keys sortedArrayUsingDescriptors:descriptors];
    
    NSString *sortedString=@"";
    int time=0;
    for (NSString *key in sortedArray) {
        NSString *value=[dic objectForKey:key];
        if (key==nil)  continue;
        
        if (time>0)
            sortedString=[sortedString stringByAppendingFormat:@"&%@=%@",key,value];
        else
            sortedString=[sortedString stringByAppendingFormat:@"%@=%@",key,value];
        time++;
    }
    
    return sortedString;
}

@end
