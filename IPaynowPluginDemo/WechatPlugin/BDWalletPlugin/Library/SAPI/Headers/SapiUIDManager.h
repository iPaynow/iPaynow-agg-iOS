//
//  SapiUIDManager.h
//  VSapiComAdapter_Standard_Archs
//
//  Created by xia leon on 13-2-27.
//
//

#import <Foundation/Foundation.h>

@interface SapiUIDManager : NSObject

+ (SapiUIDManager *)sharedInstance;
- (NSString *)getMACAddress;
- (NSString *)getUIDFilePath;
- (NSString *)createSourceUID;
- (NSString *)md5:(NSString *)aInput;
- (NSString *)readUIDValue;

@end
