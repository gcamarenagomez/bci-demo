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

@class SCSKnowledgeManager;

SC_EXTERN NSString * const SCSArticleDownloadBeganNotification;
SC_EXTERN NSString * const SCSArticleDownloadFinishedNotification;

/**
 A `SCSArticle` object represents a knowledge base article.
 
 This article may or may not already be downloaded locally.
 Use the `-[SCSArticle isArticleContentDownloaded]` property to check whether
 it is downloaded. You can download the article with the
 `-[SCSArticle downloadContentWithOptions:completion:]` method.
 */
@interface SCSArticle : NSObject

/** Unique article ID. */
@property (nonatomic, copy, readonly) NSString *articleId;

/** Article number. */
@property (nonatomic, copy, readonly) NSString *articleNumber;

/** Summary text for the article. */
@property (nonatomic, copy, readonly) NSString *summary;

/** Article title. */
@property (nonatomic, copy, readonly) NSString *title;

/** Last published date for this article. */
@property (nonatomic, strong, readonly) NSDate *lastPublishedDate;

/** Amount of local storage (in bytes) used for this article. */
@property (nonatomic, assign, readonly) NSUInteger storageUsed;

/** Date article was last accessed. */
@property (nonatomic, copy, readonly) NSDate *lastAccessedDate;

/** Knowledge manager instance this article belongs to */
@property (nonatomic, weak, readonly) SCSKnowledgeManager *manager;

/** Returns true if the article details stored in local storage gets stale */
@property (nonatomic, readonly, getter=isStale) BOOL stale;

/**
 Downloads article contents.
 
 @param options Cache options defining exactly what content to download. 
                See `SCSArticleDownloadOption`.
 @param completionBlock The block to execute after download completes. 
                        You may specify `nil` for this parameter.
 @see `SCSArticleDownloadOption`
 */
- (void)downloadContentWithOptions:(SCSArticleDownloadOption)options completion:(nullable void(^)(NSError * __nullable error))completionBlock;

/** Whether article content has been downloaded. */
- (BOOL)isArticleContentDownloaded;

/** Whether associated article content (such as images) have been downloaded */
- (BOOL)isAssociatedContentDownloaded;

/**
 Delete the cache for the article.
 
 Returns YES if the article has been deleted.
 **/
- (BOOL)deleteCache;

@end

NS_ASSUME_NONNULL_END
