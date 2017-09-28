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

#ifndef __SCCDefines_h__
#define __SCCDefines_h__

#import <Foundation/Foundation.h>

#ifndef SC_EXTERN
#ifdef __cplusplus
#define SC_EXTERN   extern "C" __attribute__((visibility ("default")))
#else
#define SC_EXTERN   extern __attribute__((visibility ("default")))
#endif
#endif

SC_EXTERN NSString * const SCInterfaceStyleDefault;

// Authentication
SC_EXTERN NSString * const SCServiceTypeCases;
SC_EXTERN NSString * const SCServiceTypeKnowledge;
SC_EXTERN NSString * const SCServiceCloudErrorDomain;
SC_EXTERN NSString * const SCSOAuthInvalidSessionId;

// Error Domain
SC_EXTERN NSString * const SCServiceErrorDomain;

/**
 * Possible error response codes when authenticating a user with your Salesforce org.
 */
typedef NS_ENUM(NSInteger, SCServiceErrorCode) {
    /**
     * Error condition when the session has expired or is invalid.
     */
    SCServiceUserSessionExpiredOrInvalidError = 401,
    /**
     * Error condition when the request to authenticate a user is refused by the server.
     */
    SCServiceUserRequestRefusedError = 403,
    /**
     * Error condition when the requested resource is not found on the server.
     */
    SCServiceUserResourceNotFoundError = 404,
};

SC_EXTERN NSString * const kSCAppearanceImageClose;
SC_EXTERN NSString * const kSCAppearanceNoConnection;
SC_EXTERN NSString * const kSCAppearanceDone;
SC_EXTERN NSString * const kSCAppearanceBack;
SC_EXTERN NSString * const kSCAppearanceGenericError;
SC_EXTERN NSString * const kSCAppearanceWhiteBubble;
SC_EXTERN NSString * const kSCAppearanceSubmitButtonPreviousArrow;
SC_EXTERN NSString * const kSCAppearanceSubmitButtonNextArrow;
SC_EXTERN NSString * const kSCAppearanceMinimizeButtonImage;
SC_EXTERN NSString * const kSCAppearanceError;
SC_EXTERN NSString * const kSCAppearanceNoAccess;
SC_EXTERN NSString * const kSCAppearanceCountBadgeBackground;

/// Branding text label constant names
SC_EXTERN NSString * const SCAppearanceLabelArticleListTitleName;
SC_EXTERN NSString * const SCAppearanceLabelArticleListSummaryName;
SC_EXTERN NSString * const SCAppearanceLabelCategoryListTitleName;
SC_EXTERN NSString * const SCAppearanceLabelCaseFeedItemBodyName;

// Case branding tokens
SC_EXTERN NSString * const SCAppearanceLabelCaseListTitle;
SC_EXTERN NSString * const SCAppearanceLabelCaseListDate;
SC_EXTERN NSString * const SCAppearanceLabelCaseListSubTitle;
SC_EXTERN NSString * const SCAppearanceLabelCaseDetailTitle;
SC_EXTERN NSString * const SCAppearanceLabelCaseDetailSubtitle;
SC_EXTERN NSString * const SCAppearanceLabelCaseFeedTitle;

// Actions
SC_EXTERN NSString * const SCSActionCaseInterface;
SC_EXTERN NSString * const SCSActionCasePublisher;
SC_EXTERN NSString * const SCSActionCaseList;
SC_EXTERN NSString * const SCSActionArticleSearch;
SC_EXTERN NSString * const SCSActionChatInterface;

// Default sort indexes for the built-in action items.
typedef enum : NSUInteger {
    SCSActionItemDefaultSortArticleSearch = 10,
    SCSActionItemDefaultSortCaseInterface = 20,
    SCSActionItemDefaultSortChatInterface = 30,
    SCSActionItemDefaultSortSOSInterface  = 40,
} SCSActionItemDefaultSort;

// Notifications
SC_EXTERN NSString * const SCUServiceUserAccountChangedNotification;

//Remote notification payload
SC_EXTERN NSString * const SCSNotificationPayloadKeyCaseId;

// Live agent Logging
SC_EXTERN NSString * const SCServiceCloudLoggingErrorDomain;

#endif
