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
#import "SCDefines.h"

NS_ASSUME_NONNULL_BEGIN

SC_EXTERN NSString * const SCSKnowledgeManagerCategoryAddedNotification;
SC_EXTERN NSString * const SCSKnowledgeManagerCategoryUpdatedNotification;
SC_EXTERN NSString * const SCSKnowledgeManagerCategoryDeletedNotification;
SC_EXTERN NSString * const SCSKnowledgeManagerCategoryKey;
SC_EXTERN NSString * const SCSKnowledgeManagerIndexKey;

@class SCSCategoryGroup, SCSCategory, SCSArticle, SCSArticleQuery, SFUserAccount;

/**
 A `SCSKnowledgeManager` object is used to interact with knowledge data such as
 category groups, categories, and articles.
 
 The knowledge manager abstracts the storage, network retrieval, and queries 
 for interacting with data in an efficient fashion. You can use this
 object to fetch categories and articles from your org. Once fetched, you 
 can use this object to get cached content. See the `SCSArticleQuery`
 class for an explanation on how to query for content.
 
 The knowledge manager caches data for offline use, allowing categories and 
 articles to be used even when no network is available.  To stay informed 
 about important changes in the underlying data model, any changes to the 
 underlying categories will be advertised through the use of the 
 following notifications:

 * `SCSKnowledgeManagerCategoryAddedNotification` -- A new category is added.
 * `SCSKnowledgeManagerCategoryUpdatedNotification` -- A category has been 
   modified (e.g. title, child categories, etc)
 * `SCSKnowledgeManagerCategoryDeletedNotification` -- A category has been deleted.

 The object of the notification will be the `SCSKnowledgeManager` instance 
 itself, while the category in question is stored in the notification's 
 `userInfo` dictionary under the `SCSKnowledgeManagerCategoryKey` key.
 */
@interface SCSKnowledgeManager : NSObject

/**
 User account used for network interactions and offline caching.
 
 This value will change if the `+defaultManager` instance is used.
 
 @see `+defaultManager`
 */
@property (nonatomic, strong, readonly) SFUserAccount *userAccount;

/**
 Singleton instance of the knowledge manager.
 
 This singleton instance automatically uses the user account currently
 selected within `SCServiceCloud.account`.

 @return Shared knowledge manager instance.
 */
+ (instancetype)defaultManager;

/**
 Returns a knowledge manager instance with the given user account.

 @param account User account to use.

 @return Initialized knowledge manager.
 */
+ (SCSKnowledgeManager *)knowledgeManagerWithUserAccount:(SFUserAccount *)account;

/**
 Triggers a fetch to load the categories for the user's organization.
 
 The data returned will automatically be cached, and any changes that have 
 occurred since the previous fetch will be updated.

 @param completionHandler Optional completion block to be called when the 
                          operation completes.
 */
- (void)fetchAllCategoriesWithCompletionHandler:(nullable void (^)(NSArray <SCSCategoryGroup *> * __nullable categoryGroups, NSError * __nullable error))completionHandler;

/**
 Indicates whether this knowledge manager has fetched new category
 information since it was created.
 
 @note It is not always necessary to fetch new categories, especially since 
 that may be a costly operation to perform if your organization has a 
 large number of categories.

 @return `YES` if this instance has successfully completed 
               `-fetchAllCategoriesWithCompletionHandler:`, otherwise `NO`.
 */
- (BOOL)hasFetchedCategories;

/**
 Indicates whether this knowledge manager has determined the supported
 languages since it was created.
 
 @note It is not always necessary to fetch the list, it may be a costly operation
 it does not need to be done more than once.
 
 @return `YES` if this instance has successfully completed
                `-fetchKnowledgeSupportedLanguagesWithCompletionHandler:`, otherwise `NO`
 */
- (BOOL)hasFetchedSupportedLanguages;

/**
 Returns all the public category groups for the current organization.
 
 @warning This array may be empty if no data has been previously cached.

 @return Array of `SCSCategoryGroup` instances
 @see `SCSCategoryGroup`
 */
- (NSArray<SCSCategoryGroup*>*)allCategoryGroups;

/**
 Returns the category group matching the given name.

 @warning This may return `nil` if no data has been previously cached.

 @param name Name of the category group to return.

 @return `SCSCategoryGroup` instance, or `nil` if none is found with that name.
 @see `SCSCategoryGroup`
 */
- (nullable SCSCategoryGroup*)categoryGroupWithName:(NSString*)name;

/**
 Returns a cached article object with the given article ID.

 @param articleId Article ID to search for.

 @return `SCSArticle` matching the given ID, or `nil` if no article is
         found in the cache with that name.
 @see `SCSArticle`
 */
- (nullable SCSArticle*)articleWithId:(NSString*)articleId;

/**
 Returns cached article objects matching the given query.
 
 This method searches through the database of existing article information 
 stored locally to identify articles.  No network operations are invoked 
 through this method, and this can safely be used even when offline.  
 For performing requests against the network, please see the 
 `-fetchArticlesWithQuery:completion:` method

 @param query      Query to use for identifying articles.
 @param completion Completion block to invoke when the articles are found.
 @see `-fetchArticlesWithQuery:completion:`
 @see `SCSArticleQuery`
 @see `SCSArticle`
 */
- (void)articlesMatchingQuery:(SCSArticleQuery*)query completion:(void(^)(NSArray<SCSArticle*> * _Nullable articles, NSError * _Nullable error))completion;

/**
 Fetches articles from the server that match the given query.

 @param query      Query to use for identifying articles.
 @param completion Completion block to invoke when articles are found.
 @see `SCSArticleQuery`
 @see `SCSArticle`
 */
- (void)fetchArticlesWithQuery:(SCSArticleQuery*)query completion:(nullable void(^)(NSArray<SCSArticle*> *articles, NSError * __nullable error))completion;

/**
 Clear the cache data from the disk if the cache exists on the disk.
 
 @param completion Completion block to invoke when deletion of the cache is completed or if an error occurs.
 */
- (void)deleteCacheIfExists:(void(^)(NSError * _Nullable error))completion;

/**
 Fetches the supported languages for knowledge.
 
 @param completion Completion block to invoke when the supported languages have been recieved from the org or an error occurs.
 */
- (void)fetchSupportedLanguagesWithCompletion:(nullable void (^)(NSArray <NSString *>* __nullable languages, NSError * __nullable error))completion;

@end

NS_ASSUME_NONNULL_END
