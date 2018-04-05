//
//  AppDelegate+ETPush.h
//  Bci
//
//  Created by Gabriel Camarena Gomez on 9/27/17.
//  Copyright © 2017 Salesforce. All rights reserved.
//

#import "AppDelegate.h"
#import <UserNotifications/UserNotifications.h>

@interface AppDelegate (ETPush) <UNUserNotificationCenterDelegate, ExactTargetCloudPageWithAlertDelegate>

- (BOOL)application : (UIApplication *)application shouldInitETSDKWithOptions : (NSDictionary *)launchOptions;

@end
