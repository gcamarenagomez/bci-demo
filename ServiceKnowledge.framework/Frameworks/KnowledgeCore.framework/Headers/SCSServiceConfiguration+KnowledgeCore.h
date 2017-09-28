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
@import ServiceCore.ServiceCommon;
#import "SCDefines.h"

NS_ASSUME_NONNULL_BEGIN

@interface SCSServiceConfiguration (KnowledgeCore)

/**
 The unique name of the data category group to use when communicating with Service Cloud.
 
 @see `rootDataCategory`
 @see `-initWithCommunity:dataCategoryGroup:rootDataCategory:`
 */
@property (nullable, nonatomic, copy, readonly) NSString *dataCategoryGroup;

/**
 The data category to use as the root when displaying knowledge articles.
 
 @see `dataCategoryGroup`
 @see `-initWithCommunity:dataCategoryGroup:rootDataCategory:`
 */
@property (nullable, nonatomic, copy, readonly) NSString *rootDataCategory;

/**
 Set the override language to be used when loading articles. For unauthenticated users this value is used to override the
 language value on the deivce. For unauthenticated users this value is used to override the device language if the deivce
 language is not one of the supported language on the server.
 */
@property (nullable, nonatomic, copy) NSString *language;

/**
 The path pointing to the folder where the images in Data Category Header View, Article Header View, and Article Cell are rendered from.
 This can be an absolute path or relative path to the application bundle.
 */
@property (nullable, nonatomic, copy) NSString *imageFolderPath;

/**
 Specifies the sort by field to be used to sort while displaying articles in 
 Support home and Data Category Detail and article list screen.
 */
@property (nonatomic) SCArticleSortByField articleSortByField;

/**
 Specifies the sort order (ascending or descending) to be used to sort while 
 displaying articles in Support home and Data Category Detail and article list 
 screen.
 */
@property (nonatomic) SCArticleSortOrder articleSortOrder;

/**
 Creates a service configuration with the given communityURL, data category group, and root data category.
 
 @param communityURL URL of the community which hosts the public knowledge base.
 @param dataCategoryGroup Data category group name.
 @param rootDataCategory  Root data category name.
 */
- (instancetype)initWithCommunity:(NSURL*)communityURL dataCategoryGroup:(NSString*)dataCategoryGroup rootDataCategory:(NSString*)rootDataCategory;

@end

NS_ASSUME_NONNULL_END
