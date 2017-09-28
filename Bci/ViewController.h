//
//  ViewController.h
//  Bci
//
//  Created by Gabriel Camarena Gomez on 9/27/17.
//  Copyright © 2017 Salesforce. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <SalesforceSDKCore/SFRestAPI.h>

@interface ViewController : UIViewController <SFRestDelegate> {
    
    NSMutableArray *dataRows;
    
}

@property (nonatomic, strong) NSArray *dataRows;

@end
