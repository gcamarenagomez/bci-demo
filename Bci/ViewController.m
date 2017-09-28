//
//  ViewController.m
//  Bci
//
//  Created by Gabriel Camarena Gomez on 9/27/17.
//  Copyright © 2017 Salesforce. All rights reserved.
//

#import "ViewController.h"
@import ServiceCore;
@import ServiceKnowledge;
#import <SalesforceSDKCore/SFRestAPI.h>
#import <SalesforceSDKCore/SFRestRequest.h>


@implementation ViewController

@synthesize dataRows;



- (void)viewDidLoad {
    [super viewDidLoad];
    self.title = @"BCI App";
    
    //Here we use a query that should work on either Force.com or Database.com
    /*SFRestRequest *request = [[SFRestAPI sharedInstance] requestForQuery:@"SELECT Name FROM User LIMIT 10"];
    [[SFRestAPI sharedInstance] send:request delegate:self];*/
}


- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (void)dealloc
{
    self.dataRows = nil;
}


- (IBAction)showHelp:(id)sender {
    // Show the Knowledge interface
    [[SCServiceCloud sharedInstance].knowledge setInterfaceVisible:YES                                                          animated:YES                                                        completion:nil];
}

#pragma mark - SFRestDelegate

- (void)request:(SFRestRequest *)request didLoadResponse:(id)jsonResponse {
    /*NSArray *records = jsonResponse[@"records"];
    NSLog(@"request:didLoadResponse: #records: %lu", (unsigned long)records.count);
    self.dataRows = records;
    dispatch_async(dispatch_get_main_queue(), ^{
        [self.tableView reloadData];
    });*/
}


- (void)request:(SFRestRequest*)request didFailLoadWithError:(NSError*)error {
    NSLog(@"request:didFailLoadWithError: %@", error);
    // Add your failed error handling here
}

- (void)requestDidCancelLoad:(SFRestRequest *)request {
    NSLog(@"requestDidCancelLoad: %@", request);
    // Add your failed error handling here
}

- (void)requestDidTimeout:(SFRestRequest *)request {
    NSLog(@"requestDidTimeout: %@", request);
    // Add your failed error handling here
}

@end
