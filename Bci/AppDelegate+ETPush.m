//
//  AppDelegate+ETPush.m
//  Bci
//
//  Created by Gabriel Camarena Gomez on 9/27/17.
//  Copyright © 2017 Salesforce. All rights reserved.
//

#import "AppDelegate+ETPush.h"
#import "ETPush.h"
#import "AppDelegate+ETPushConstants.h"
#import "ETAnalytics.h"
#import "ETRegion.h"
#import "ETWKLandingPagePresenter.h"
@import ServiceCore;
@import ServiceKnowledge;

#import <UserNotifications/UserNotifications.h>
#import <SalesforceSDKCore/SFPushNotificationManager.h>

@implementation AppDelegate (ETPush)
#pragma mark - SDK Setup
- (BOOL)application:(UIApplication *)application shouldInitETSDKWithOptions:(NSDictionary *)launchOptions {
    
    
    /**MC for push notifications*/
    /*BOOL successful = NO;
    NSError *error = nil;
    
    [[ETPush pushManager] setCloudPageWithAlertDelegate:self];

    SCSServiceConfiguration *config = [[SCSServiceConfiguration alloc]
                                       initWithCommunity:[NSURL URLWithString:@"https://sdodemo-main-15bf2838a3d-15e5d09798a.force.com/cumuluscommunity"]
                                       dataCategoryGroup:@"Retail_Banking"
                                       rootDataCategory:@"All"];
    

    [SCServiceCloud sharedInstance].serviceConfiguration = config;
    
#ifdef DEBUG

    [ETPush setETLoggerToRequiredState:YES];
    
    successful = [[ETPush pushManager] configureSDKWithAppID:kETAppID_Debug                // Configure the SDK with the Debug App ID
                                              andAccessToken:kETAccessToken_Debug        // Configure the SDK with the Debug Access Token
                                               withAnalytics:YES                        // Enable Analytics
                                         andLocationServices:YES                        // Enable Location Services (Geofence Messaging)
                                        andProximityServices:YES                        // Enable Proximity services (Beacon Messaging)
                                               andCloudPages:YES                        // Enable Cloud Pages
                                             withPIAnalytics:YES                        // Enable WAMA / PI Analytics
                                                       error:&error];
    
#else

    successful = [[ETPush pushManager] configureSDKWithAppID:kETAppID_Prod                // Configure the SDK with the Debug App ID
                                              andAccessToken:kETAccessToken_Prod        // Configure the SDK with the Debug Access Token
                                               withAnalytics:YES                        // Enable Analytics
                                         andLocationServices:YES                        // Enable Location Services (Geofence Messaging)
                                        andProximityServices:YES                        // Enable Proximity services (Beacon Messaging)
                                               andCloudPages:YES                        // Enable Cloud Pages
                                             withPIAnalytics:YES                        // Enable WAMA / PI Analytics
                                                       error:&error];
#endif

    if (!successful) {
        dispatch_async(dispatch_get_main_queue(), ^{

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdeprecated-declarations"
            [[[UIAlertView alloc] initWithTitle:NSLocalizedString(@"Failed configureSDKWithAppID!", @"Failed configureSDKWithAppID!")
                                        message:[error localizedDescription]
                                       delegate:nil
                              cancelButtonTitle:NSLocalizedString(@"OK", @"OK")
                              otherButtonTitles:nil] show];
#pragma clang diagnostic pop
            
        });
        
        [ETAnalytics trackPageView:@"data://SDKInitializationFailed" andTitle:[error localizedDescription] andItem:nil andSearch:nil];
        
    } else {

        if (floor(NSFoundationVersionNumber) > NSFoundationVersionNumber_iOS_9_x_Max) {
            [[ETPush pushManager] registerForRemoteNotificationsWithDelegate:self options:(UNAuthorizationOptionAlert + UNAuthorizationOptionBadge + UNAuthorizationOptionSound) categories:nil completionHandler:^(BOOL granted, NSError * _Nullable error) {
                
                NSLog(@"Registered for remote notifications: %d", granted);
                
            }];
        }
        else {
            UIUserNotificationSettings *settings = [UIUserNotificationSettings settingsForTypes:
                                                    UIUserNotificationTypeBadge |
                                                    UIUserNotificationTypeSound |
                                                    UIUserNotificationTypeAlert
                                                                                     categories:nil];
 
            [[ETPush pushManager] registerUserNotificationSettings:settings];
            [[ETPush pushManager] registerForRemoteNotifications];
        }

        [[ETLocationManager sharedInstance] startWatchingLocation];
        

        [ETRegion retrieveGeofencesFromET];
        

        [ETRegion retrieveProximityFromET];

        [[ETPush pushManager] applicationLaunchedWithOptions:launchOptions];
        
        [ETAnalytics trackPageView:@"data://SDKInitializationCompletedSuccessfully" andTitle:@"SDK Initialization Completed" andItem:nil andSearch:nil];

        [[ETPush pushManager] addAttributeNamed:@"MyBooleanAttribute" value:@"0"];

        [ETPush getSDKState];
        
    }*/
    
    return YES;
}

#pragma mark - Lifecycle Callbacks

// The method will be called on the delegate only if the application is in the foreground. If the method is not implemented or the handler is not called in a timely manner then the notification will not be presented. The application can choose to have the notification presented as a sound, badge, alert and/or in the notification list. This decision should be based on whether the information in the notification is otherwise visible to the user.
- (void)userNotificationCenter:(UNUserNotificationCenter *)center willPresentNotification:(UNNotification *)notification withCompletionHandler:(void (^)(UNNotificationPresentationOptions options))completionHandler {
    
    if (completionHandler != nil) {
        if ([[ETPush pushManager] shouldShowLocalAlert] == YES) {
            completionHandler(UNNotificationPresentationOptionAlert);
        }
        else {
            [[ETPush pushManager] handleNotification:notification.request.content.userInfo forApplicationState:[UIApplication sharedApplication].applicationState];
            completionHandler(UNNotificationPresentationOptionNone);
        }
    }
    else {
        [[ETPush pushManager] handleNotification:notification.request.content.userInfo forApplicationState:[UIApplication sharedApplication].applicationState];
    }
}

// The method will be called on the delegate when the user responded to the notification by opening the application, dismissing the notification or choosing a UNNotificationAction. The delegate must be set before the application returns from applicationDidFinishLaunching:.
- (void)userNotificationCenter:(UNUserNotificationCenter *)center didReceiveNotificationResponse:(UNNotificationResponse *)response withCompletionHandler:(void(^)(void))completionHandler {
    
    /**
     Inform the JB4ASDK that the device received a remote notification
     */
    [[ETPush pushManager] handleUserNotificationResponse:response];
    
    if (completionHandler != nil) {
        completionHandler();
    }
}

- (void)application:(UIApplication *)application didRegisterUserNotificationSettings:(UIUserNotificationSettings *)notificationSettings {
    /**
     Inform the JB4ASDK of the requested notification settings
     */
    [[ETPush pushManager] didRegisterUserNotificationSettings:notificationSettings];
}

- (void)application:(UIApplication *)application didRegisterForRemoteNotificationsWithDeviceToken:(NSData *)deviceToken {
    /**
     Inform the JB4ASDK of the device token
     */
    [[ETPush pushManager] registerDeviceToken:deviceToken];
}

-(void)application:(UIApplication *)application didFailToRegisterForRemoteNotificationsWithError:(NSError *)error {
    /**
     Inform the JB4ASDK that the device failed to register and did not receive a device token
     */
    [[ETPush pushManager] applicationDidFailToRegisterForRemoteNotificationsWithError:error];
    [ETAnalytics trackPageView:@"data://applicationDidFailToRegisterForRemoteNotificationsWithError" andTitle:[error localizedDescription] andItem:nil andSearch:nil];
    
}

- (void)applicationDidEnterBackground:(UIApplication *)application {
    /**
     Use this method to disable Location Services through the MobilePush SDK.
     */
    [[ETLocationManager sharedInstance]startWatchingLocation];
}

- (void)applicationDidBecomeActive:(UIApplication *)application {
    /**
     Use this method to initiate Location Services through the MobilePush SDK.
     */
    [[ETLocationManager sharedInstance]stopWatchingLocation];
}

#pragma mark - Message Received Callbacks
-(void)application:(UIApplication *)application didReceiveLocalNotification:(UILocalNotification *)notification {
    /**
     Inform the JB4ASDK that the device received a local notification
     */
    NSLog(@"Local Notification Receieved");
    [[ETPush pushManager] handleLocalNotification:notification];
}

- (void)application:(UIApplication *)application didReceiveRemoteNotification:(NSDictionary *)userInfo fetchCompletionHandler:(void (^)(UIBackgroundFetchResult result))handler {
    /**
     Inform the JB4ASDK that the device received a remote notification
     */
    [[ETPush pushManager] handleNotification:userInfo forApplicationState:application.applicationState];
    
    handler(UIBackgroundFetchResultNoData);
}

#pragma mark Cloud Page delegates
- (void)didReceiveCloudPageWithAlertMessageWithContents:(NSString *)payload {
    [[UIApplication sharedApplication].keyWindow.rootViewController presentViewController:[[ETWKLandingPagePresenter alloc] initForLandingPageAt:payload]
                                                                                 animated:YES
                                                                               completion:nil];
}

-(BOOL)shouldDeliverCloudPageWithAlertMessageIfAppIsRunning {
    return YES;
}


@end
