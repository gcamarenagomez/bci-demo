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

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@class SCSArticleViewController, SCSArticle, SCSCategory;

/**
 Delegate protocol used to interact with article view controllers.
 */
@protocol SCSArticleViewControllerDelegate <NSObject>

@optional

/**
 Message sent to the delegate when the selected category is changed.

 @param controller  The article view controller.
 @param newCategory The new category.
 */
- (void)articleController:(SCSArticleViewController*)controller categoryDidChange:(SCSCategory*)newCategory;

/**
 Informs the delegate when an article will be shown.
 
 This message is sent immediately upon setting a new article.

 @param controller The article view controller.
 @param article    The article to be displayed, or `nil` if no article is selected.
 */
- (void)articleController:(SCSArticleViewController*)controller willShowArticle:(nullable SCSArticle*)article;

/**
 Informs the delegate when an article has finished being shown.
 
 This is sent when the article has finished loading and is displayed on the screen.  If the view controller isn't initially presented in the view hierarchy when the article is initially set, this message may be delayed until the controller is eventually presented and the article is loaded.

 @param controller The article view controller.
 @param article    The article being shown, or `nil` if no article is selected.
 */
- (void)articleController:(SCSArticleViewController*)controller didShowArticle:(nullable SCSArticle*)article;

/**
 The target height for the given header view.

 If this method isn't implemented, the height for the article header will be determined automatically.  If a header view isn't to be used for this article, this method is never called.

 @param controller The article view controller.
 @param headerView The header view to be displayed.

 @return Positive float value for the desired target header view height.
 */
- (CGFloat)articleController:(SCSArticleViewController*)controller heightForHeaderView:(UIView*)headerView;

/**
 Header view to display above the article.
 
 If this method isn't implemented, a default header view will be used if an image is available for this article.  If you do not wish for a header to be displayed, you can return `nil` from this method to opt out of displaying a header.
 
 Auto Layout rules will be applied when adding this view to the hierarchy.

 @param controller The article view controller.
 @param article    The article being displayed.

 @return UIView instance to be used within the header, or `nil`.
 */
- (nullable __kindof UIView *)articleController:(SCSArticleViewController*)controller headerViewForArticle:(SCSArticle*)article;

@end

NS_ASSUME_NONNULL_END
