//
//  AppDelegate+ETPushConstants.h
//  Bci
//
//  Created by Gabriel Camarena Gomez on 9/27/17.
//  Copyright © 2017 Salesforce. All rights reserved.
//

#import "AppDelegate.h"

@interface AppDelegate (ETPushConstants)


// Debug Application ID
FOUNDATION_EXPORT NSString *const kETAppID_Debug;
// Debug Access Token
FOUNDATION_EXPORT NSString *const kETAccessToken_Debug;
// Production Application ID
FOUNDATION_EXPORT NSString *const kETAppID_Prod;
// Production Access Token
FOUNDATION_EXPORT NSString *const kETAccessToken_Prod;

FOUNDATION_EXPORT NSString *const kMessageTypeLocation;
FOUNDATION_EXPORT NSString *const kUserDefaultsLastPushReceivedDate;
FOUNDATION_EXPORT NSString *const kUserDefaultsPushUserInfo;
FOUNDATION_EXPORT NSString *const kUserDefaultsMessageType;
FOUNDATION_EXPORT NSString *const kUserDefaultsAlertText;
FOUNDATION_EXPORT NSString *const kMessageDetailCustomKeyDiscountCode;
FOUNDATION_EXPORT NSString *const kPushDefineOpenDirectPayloadKey;
FOUNDATION_EXPORT NSString *const kPushDefineCloudPagePayloadKey;
FOUNDATION_EXPORT NSString *const kPushDefinePersistentNotificationKey;

#pragma mark - Attributes
extern NSString *const kPUDAttributeFirstName;
extern NSString *const kPUDAttributeLastName;

@end
