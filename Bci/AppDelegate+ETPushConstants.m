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
NSString *const kETAppID_Debug                       = @"063c6e5e-18b4-44ca-9b68-370b8ea0b301";
NSString *const kETAccessToken_Debug                 = @"rap5cwdqx8cwcnz3r56mzsvv";
NSString *const kETAppID_Prod                        = @"063c6e5e-18b4-44ca-9b68-370b8ea0b301";
NSString *const kETAccessToken_Prod                  = @"rap5cwdqx8cwcnz3r56mzsvv";

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
