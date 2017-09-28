//
//  AppDelegate.m
//  Bci
//
//  Created by Gabriel Camarena Gomez on 9/27/17.
//  Copyright © 2017 Salesforce. All rights reserved.
//

#import "AppDelegate.h"
//#import "AppDelegate+ETPush.h"
#import "InitialViewController.h"
#import "ViewController.h"
@import ServiceCore;
@import ServiceKnowledge;

//#import <UserNotifications/UserNotifications.h>
#import <SalesforceSDKCore/SFPushNotificationManager.h>
#import <SalesforceSDKCore/SFDefaultUserManagementViewController.h>
#import <SalesforceSDKCore/SalesforceSDKManager.h>
#import <SalesforceSDKCore/SFUserAccountManager.h>
#import <SmartStore/SalesforceSDKManagerWithSmartStore.h>
#import <SalesforceSDKCore/SFLoginViewController.h>

static NSString * const RemoteAccessConsumerKey = @"3MVG9g9rbsTkKnAXrtKvJJXtmvsgz83EFrR0GVw7eunHqJldAydGcQYyBzTxPWNeRUcGkaTIeYhfjuLa5FrO.";
static NSString * const OAuthRedirectURI        = @"mysampleapp://auth/success";

@interface AppDelegate ()

/**
 * Convenience method for setting up the main UIViewController and setting self.window's rootViewController
 * property accordingly.
 */
- (void)setupRootViewController;

/**
 * (Re-)sets the view state when the app first loads (or post-logout).
 */
- (void)initializeAppViewState;

@end

@implementation AppDelegate

@synthesize window = _window;

- (id)init{
    self = [super init];
    if(self){
        //[SFAuthenticationManager sharedManager].advancedAuthConfiguration = SFOAuthAdvancedAuthConfigurationRequire;
        [SalesforceSDKManager setInstanceClass:[SalesforceSDKManagerWithSmartStore class]];
        [SalesforceSDKManager sharedManager].connectedAppId = RemoteAccessConsumerKey;
        [SalesforceSDKManager sharedManager].connectedAppCallbackUri = OAuthRedirectURI;
        [SalesforceSDKManager sharedManager].authScopes = @[ @"web", @"api" ];
        
        __weak AppDelegate *weakSelf = self;
        [SalesforceSDKManager sharedManager].postLaunchAction = ^(SFSDKLaunchAction launchActionList){
            
            [[SFPushNotificationManager sharedInstance] registerForRemoteNotifications];
            [weakSelf setupRootViewController];
        };
        [SalesforceSDKManager sharedManager].launchErrorAction = ^(NSError *error, SFSDKLaunchAction launchActionList){
            [weakSelf initializeAppViewState];
            [[SalesforceSDKManager sharedManager] launch];
        };
        [SalesforceSDKManager sharedManager].postLogoutAction = ^{
            [weakSelf handleSdkManagerLogout];
        };
        [SalesforceSDKManager sharedManager].switchUserAction = ^(SFUserAccount *fromUser, SFUserAccount *toUser){
            [weakSelf handleUserSwitch:fromUser toUser:toUser];
        };
    }
    return self;
}

// DO NOT COPY AND PASTE THIS DIRECTLY INTO YOUR APP DELEGATE.M FILE.
// YOUR APPDELEGATE.M FILE ALREADY CONTAINS THIS METHOD, YOU
// ONLY NEED TO ADD THE CALL to the shouldInitETSDKWithOptions method below
- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    self.window = [[UIWindow alloc] initWithFrame:[UIScreen mainScreen].bounds];
    [self initializeAppViewState];
    // This line is a required addition to your AppDelegate.m's method of the same name.
    // it is responsible for the initialization of the SDK from our category.
    //[self application:application shouldInitETSDKWithOptions:launchOptions];
    
    SCSServiceConfiguration *config = [[SCSServiceConfiguration alloc]
                                       initWithCommunity:[NSURL URLWithString:@"https://sdodemo-main-15bf2838a3d-15e5d09798a.force.com/cumuluscommunity"]
                                       dataCategoryGroup:@"Retail_Banking"
                                       rootDataCategory:@"All"];
    
    
    [SCServiceCloud sharedInstance].serviceConfiguration = config;
    [[SalesforceSDKManager sharedManager] launch];
    
    
    return YES;
}

- (void)application:(UIApplication *)application didRegisterForRemoteNotificationsWithDeviceToken:(NSData *)deviceToken
{
    [[SFPushNotificationManager sharedInstance] didRegisterForRemoteNotificationsWithDeviceToken:deviceToken];
    if ([SFUserAccountManager sharedInstance].currentUser.credentials.accessToken != nil) {
        [[SFPushNotificationManager sharedInstance] registerForSalesforceNotifications];
    }
}

- (void)application:(UIApplication *)application didFailToRegisterForRemoteNotificationsWithError:(NSError *)error
{
    // Respond to any push notification registration errors here.
}

- (void)applicationWillResignActive:(UIApplication *)application {
    // Sent when the application is about to move from active to inactive state. This can occur for certain types of temporary interruptions (such as an incoming phone call or SMS message) or when the user quits the application and it begins the transition to the background state.
    // Use this method to pause ongoing tasks, disable timers, and invalidate graphics rendering callbacks. Games should use this method to pause the game.
}


- (void)applicationDidEnterBackground:(UIApplication *)application {
    // Use this method to release shared resources, save user data, invalidate timers, and store enough application state information to restore your application to its current state in case it is terminated later.
    // If your application supports background execution, this method is called instead of applicationWillTerminate: when the user quits.
}


- (void)applicationWillEnterForeground:(UIApplication *)application {
    // Called as part of the transition from the background to the active state; here you can undo many of the changes made on entering the background.
}


- (void)applicationDidBecomeActive:(UIApplication *)application {
    // Restart any tasks that were paused (or not yet started) while the application was inactive. If the application was previously in the background, optionally refresh the user interface.
}


- (void)applicationWillTerminate:(UIApplication *)application {
    // Called when the application is about to terminate. Save data if appropriate. See also applicationDidEnterBackground:.
}

#pragma mark - Private methods
- (void)initializeAppViewState
{
    if (![NSThread isMainThread]) {
        dispatch_async(dispatch_get_main_queue(), ^{
            [self initializeAppViewState];
        });
        return;
    }
    
    self.window.rootViewController = [[InitialViewController alloc] initWithNibName:nil bundle:nil];
    [self.window makeKeyAndVisible];
}

- (void)setupRootViewController{
    NSBundle *bundle = [NSBundle mainBundle];
    UIStoryboard *sb = [UIStoryboard storyboardWithName:@"Main" bundle:bundle];
    ViewController *rootVC = [sb instantiateInitialViewController];
    //ViewController *rootVC = [[ViewController alloc] initWithNibName:nil bundle:nil];
    UINavigationController *navVC = [[UINavigationController alloc] initWithRootViewController:rootVC];
    self.window.rootViewController = rootVC;
}

- (void)resetViewState:(void (^)(void))postResetBlock
{
    if ((self.window.rootViewController).presentedViewController) {
        [self.window.rootViewController dismissViewControllerAnimated:NO completion:^{
            postResetBlock();
        }];
    } else {
        postResetBlock();
    }
}

- (void)handleSdkManagerLogout
{
    [self resetViewState:^{
        [self initializeAppViewState];
        
        // Multi-user pattern:
        // - If there are two or more existing accounts after logout, let the user choose the account
        //   to switch to.
        // - If there is one existing account, automatically switch to that account.
        // - If there are no further authenticated accounts, present the login screen.
        //
        // Alternatively, you could just go straight to re-initializing your app state, if you know
        // your app does not support multiple accounts.  The logic below will work either way.
        NSArray *allAccounts = [SFUserAccountManager sharedInstance].allUserAccounts;
        if (allAccounts.count > 1) {
            SFDefaultUserManagementViewController *userSwitchVc = [[SFDefaultUserManagementViewController alloc] initWithCompletionBlock:^(SFUserManagementAction action) {
                [self.window.rootViewController dismissViewControllerAnimated:YES completion:NULL];
            }];
            [self.window.rootViewController presentViewController:userSwitchVc animated:YES completion:NULL];
        } else {
            if (allAccounts.count == 1) {
                [SFUserAccountManager sharedInstance].currentUser = ([SFUserAccountManager sharedInstance].allUserAccounts)[0];
            }
            
            [[SalesforceSDKManager sharedManager] launch];
        }
    }];
}

- (void)handleUserSwitch:(SFUserAccount *)fromUser
                  toUser:(SFUserAccount *)toUser
{
    [self resetViewState:^{
        [self initializeAppViewState];
        [[SalesforceSDKManager sharedManager] launch];
    }];
}



@end
