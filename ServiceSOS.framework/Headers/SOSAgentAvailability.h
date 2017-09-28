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

/**
 *  Enum for the Availability Status updates generated by the 
 * `-[SOSAgentAvailabilityDelegate agentAvailability:didChange:]` event.
 *
 * @see `SOSAgentAvailabilityDelegate`
 */
typedef NS_ENUM(NSInteger, SOSAgentAvailabilityStatusType) {
    /**
     *  The base status of the agentAvailability. This is the first response you will
     *  see after you begin polling. This state is reset whenever polling is stopped.
     */
    SOSAgentAvailabilityStatusUnknown = 0,
    /**
     *  An agent may be currently available to receive incoming SOS sessions.
     *  It is possible that an agent may become unavailable between polling, so this
     *  is only an indicator that it is possible that an agent can answer a call.
     */
    SOSAgentAvailabilityStatusAvailable = 1,
    /**
     *  No agents are currently available to receive SOS calls.
     */
    SOSAgentAvailabilityStatusUnavailable = 2
};

/**
 *  Delegate protocol for `SOSAgentAvailability`.
 *
 *  Implement this protocol in your classes to listen for availability change events from the `SOSAgentAvailability` class.
 */
@protocol SOSAgentAvailabilityDelegate <NSObject>
@optional
/**
 *  Delegate method invoked when the `SOSAgentAvailability` status has changed.
 *
 *  @param agentAvailability  The `SOSAgentAvailability` instance which fired the event.
 *  @param availabilityStatus The current `SOSAgentAvailabilityStatusType`.
 *  @see `SOSAgentAvailabilityStatusType`
 */
- (void)agentAvailability:(__weak id)agentAvailability didChange:(SOSAgentAvailabilityStatusType)availabilityStatus;

/**
 *  Delegate method invoked when the `SOSAgentAvailability` polling has returned an error.
 *
 *  @param agentAvailability `SOSAgentAvailability` instance which invoked the delegate method.
 *  @param error             `NSError` instance describing the error.
 */
- (void)agentAvailability:(__weak id)agentAvailability didError:(NSError*)error;

@end

/**
 *  The `SOSAgentAvailability` class allows you to configure periodic polling against a single SOS deployment for your organization.
 *
 *  When the availability changes, an `-[SOSAgentAvailabilityDelegate agentAvailability:didChange:]` event is fired.
 *
 *  @see `SOSAgentAvailabilityDelegate`
 */
@interface SOSAgentAvailability : NSObject

/**
 *  Initializes the agent polling. With the given credentials this will begin polling to determine agent availability.
 *  This can be leveraged to provide context to modify application UI depending on agent availability.
 *
 *  @note Currently we can only support polling a single deployment at a time.
 *
 *  @param organizationId The Salesforce organization id.
 *  @param deploymentID   The unique id of the deployment for this session.
 *  @param liveAgentPod   The hostname for the LiveAgent pod that your organization has been assigned.
 */
- (void)startPollingWithOrganizationId:(NSString *)organizationId deploymentId:(NSString *)deploymentID liveAgentPod:(NSString *)liveAgentPod;

/**
 *  Discontinues polling operations. It is recommended that you stop polling in situations or views where no SOS functionality
 *  is appropriate/implemented.
 */
- (void)stopPolling;

/**
 *  The current availability status.
 */
@property (nonatomic) SOSAgentAvailabilityStatusType availabilityStatus;

///---------------------------------
/// @name Delegate Management
///---------------------------------

/**
 *  Adds an instance of an NSObject implementing the `SOSAgentAvailabilityDelegate` protocol to the list of delegates to notify.
 *
 *  @param delegate `NSObject` instance to add.
 *  @see `SOSAgentAvailabilityDelegate`
 */
- (void)addDelegate:(id<SOSAgentAvailabilityDelegate>)delegate;

/**
 *  Removes an instance of an NSObject implementing the `SOSAgentAvailabilityDelegate` protocol to the list of delegates to notify.
 *
 *  @param delegate NSObject instance to remove.
 *  @see `SOSAgentAvailabilityDelegate`
 */
- (void)removeDelegate:(id<SOSAgentAvailabilityDelegate>)delegate;

@end
