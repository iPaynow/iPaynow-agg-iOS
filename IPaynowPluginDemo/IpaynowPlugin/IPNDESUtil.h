//
//  IPNDESUtil.h
//  TestPlugin
//
//  Created by 刘宁 on 14/11/26.
//  Copyright (c) 2014年 Ipaynow. All rights reserved.
//

#import <Foundation/Foundation.h>


@interface IPNDESUtil : NSObject

/**
 *  MD5加密
 *
 *  @param inPutText 加密前字符串
 *
 *  @return 加密后字符串
 */
+ (NSString*)md5Encrypt: (NSString *) inPutText;


/**
 *  Base64加密
 *
 *  @param plainText 加密前字符串
 *  @param keyStr    秘钥
 *
 *  @return 加密后字符串
 */
+ (NSString *)tripleDESEncrypt:(NSString *)plainText WithKey:(NSString *)keyStr;


/**
 *  16进制转字符串
 *
 *  @param data 16进制data
 *
 *  @return 字符串
 */
+ (NSString *)hexStringFromString:(NSData *)data;

@end
