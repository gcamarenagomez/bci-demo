//
//  AppDelegate+ETPushConstants.m
//  Bci
//
//  Created by Gabriel Camarena Gomez on 9/27/17.
//  Copyright © 2017 Salesforce. All rights reserved.
//

#import "AppDelegate+ETPushConstants.h"

@implementation AppDelegate (ETPushConstants)

// Code@ AppIDs and Access Tokens for the debug and production versions of your app
// These values should be stored securely by your application or retrieved from a remote server
NSString *const kETAppID_Debug                       = @"fb24ddd7-1833-425e-a52a-906d92d9c362";
NSString *const kETAccessToken_Debug                 = @"hdsmqfntpmjhzjfqvc4c243m";
NSString *const kETAppID_Prod                        = @"fb24ddd7-1833-425e-a52a-906d92d9c362";
NSString *const kETAccessToken_Prod                  = @"hdsmqfntpmjhzjfqvc4c243m";

// Constants used for Strings
NSString *const kMessageTypeLocation                 = @"Location";
NSString *const kUserDefaultsLastPushReceivedDate    = @"ud_lastPushReceivedDate";
NSString *const kUserDefaultsPushUserInfo            = @"ud_pushUserInfo";
NSString *const kUserDefaultsMessageType             = @"ud_messageType";
NSString *const kUserDefaultsAlertText               = @"ud_alertText";
NSString *const kMessageDetailCustomKeyDiscountCode  = @"discount_code";
NSString *const kPushDefineOpenDirectPayloadKey      = @"_od";
NSString *const kPushDefineCloudPagePayloadKey       = @"_x";
NSString *const kPushDefinePersistentNotificationKey = @"_p";

NSString *const kPUDAttributeFirstName = @"FirstName";
NSString *const kPUDAttributeLastName = @"LastName";

@end
