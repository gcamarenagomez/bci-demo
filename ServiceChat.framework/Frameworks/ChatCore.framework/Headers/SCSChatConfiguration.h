/*
 * Copyright 2016 salesforce.com, inc.
 * All rights reserved.
 *
 * Use of this software is subject to the salesforce.com Developerforce Terms of
 * Use and other applicable terms that salesforce.com may make available, as may be
 * amended from time to time. You may not decompile, reverse engineer, disassemble,
 * attempt to derive the source code of, decrypt, modify, or create derivative
 * works of this software, updates thereto, or any part thereof. You may not use
 * the software to engage in any development activity that infringes the rights of
 * a third party, including that which interferes with, damages, or accesses in an
 * unauthorized manner the servers, networks, or other properties or services of
 * salesforce.com or any third party.
 *
 * WITHOUT LIMITING THE GENERALITY OF THE FOREGOING, THE SOFTWARE IS PROVIDED
 * "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED. IN NO EVENT SHALL
 * SALESFORCE.COM HAVE ANY LIABILITY FOR ANY DAMAGES, INCLUDING BUT NOT LIMITED TO,
 * DIRECT, INDIRECT, SPECIAL, INCIDENTAL, PUNITIVE, OR CONSEQUENTIAL DAMAGES, OR
 * DAMAGES BASED ON LOST PROFITS, DATA OR USE, IN CONNECTION WITH THE SOFTWARE,
 * HOWEVER CAUSED AND, WHETHER IN CONTRACT, TORT OR UNDER ANY OTHER THEORY OF
 * LIABILITY, WHETHER OR NOT YOU HAVE BEEN ADVISED OF THE POSSIBILITY OF SUCH
 * DAMAGES.
 */

#import <Foundation/Foundation.h>

@class SCSPrechatObject;

/**
 A `SCSChatConfiguration` object contains configuration information for a
 Live Agent Chat session.
 */
@interface SCSChatConfiguration : NSObject <NSCopying>

/**
 Describes how a chat session is presented.
 */
typedef NS_ENUM(NSUInteger, SCSChatPresentationStyle) {
    /**
     Present chat session in full-screen mode.
     */
    SCSChatPresentationStyleFullscreen = 1,

    /**
     Present chat session in non-blocking mode.
     */
    SCSChatPresentationStyleNonBlocking
};

///---------------------------------
/// @name Initialization
///---------------------------------

/**
 Instantiates an `SCSChatConfiguration` object for use with 
 `-[SCSChat startSessionWithConfiguration:]`.

 @param liveAgentPod The hostname for the LiveAgent endpoints that your 
                     organization has been assigned.
 @param orgId        The Salesforce 15 character Organization ID.
 @param deploymentId The unique ID for the deployment that this client will be 
                     configured to use.
 @param buttonId     The unique ID for the chat configuration that this client 
                     will use.
 @return The `SCSChatConfiguration` instance.
 */
- (instancetype)initWithLiveAgentPod:(NSString *)liveAgentPod
                               orgId:(NSString *)orgId
                        deploymentId:(NSString *)deploymentId
                            buttonId:(NSString *)buttonId;

///---------------------------------
/// @name Deployment Configuration
///---------------------------------

/**
 The hostname for the LiveAgent endpoints that your organization has been assigned.
 
 @see `-initWithLiveAgentPod:orgId:deploymentId:buttonId:`
 */
@property (nonatomic, strong, readonly) NSString *liveAgentPod;

/**
 The Salesforce 15 character Organization ID.
 
 @see `-initWithLiveAgentPod:orgId:deploymentId:buttonId:`
 */
@property (nonatomic, strong, readonly) NSString *organizationId;

/**
 The unique ID for the deployment that this client will be configured to use.
 
 @see `-initWithLiveAgentPod:orgId:deploymentId:buttonId:`
 */
@property (nonatomic, strong, readonly) NSString *deploymentId;

/**
 The unique ID for the chat configuration that this client will use.
 
 @see `-initWithLiveAgentPod:orgId:deploymentId:buttonId:`
 */
@property (nonatomic, strong, readonly) NSString *buttonId;

///---------------------------------
/// @name Session Behavior
///---------------------------------

/**
 An array of `SCSPrechatObject` objects defining the custom information
 this session will provide.
 */
@property (nonatomic, readonly, strong) NSMutableArray<SCSPrechatObject*> *prechatFields;

/**
 Defines how the Live Agent Chat session is presented when it starts.

 Defaults to `SCSChatPresentationStyleNonBlocking`.
 */
@property (nonatomic, assign) SCSChatPresentationStyle presentationStyle;


/**
 Determines whether the framework receives and displays updates about the session queue position.
 
 Defaults to `YES`
 */
@property (nonatomic, assign) BOOL queueUpdatesEnabled;

/**
 Determines whether session logs are sent for collection.
 Logs sent remotely do not collect personal information. Unique IDs are
 created for tying logs to sessions, and those IDs cannot be correlated back to
 specific users.
 
 Default to `YES`.
 */
@property (nonatomic) BOOL remoteLoggingEnabled;

@end
