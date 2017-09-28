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

NS_ASSUME_NONNULL_BEGIN

@class SCSCategoryGroup, SCSKnowledgeManager;

/**
 A `SCSCategory` represents an individual data category within a data category group.
 Categories form a tree hierarchy, where an individual category has one parent category
 (with the exception of a root-level category, which does not have a parent),
 and it may have multiple child categories.
 
 Refer to `SCSCategoryGroup` for a representation of a data category group.
 */
@interface SCSCategory : NSObject

/**
 Unique name for this category.
 */
@property (nonatomic, copy, readonly) NSString * name;

/**
 Label, or display name, for this category.
 */
@property (nonatomic, copy, readonly) NSString * label;

/**
 API URL for this category.
 */
@property (nonatomic, copy, readonly) NSString * url;

/**
 Array of immediate child categories below this one.
 If this category is a leaf category, this array will be empty.
 */
@property (nonatomic, strong, readonly) NSArray<SCSCategory*> *childCategories;

/**
 Reference to this category's immediate parent.
 For root-level categories, this value is `nil`.
 */
@property (nonatomic, weak, readonly, nullable) SCSCategory *parentCategory;

/**
 The category group that this category resides within.
 
 @see `SCSCategoryGroup`
 */
@property (nonatomic, weak, readonly, nullable) SCSCategoryGroup *categoryGroup;

/**
 The knowledge manager this category belongs to.
 */
@property (nonatomic, weak, readonly) SCSKnowledgeManager *manager;

/**
 Returns a category at or below this category that matches the specified name.

 @param name Category name.

 @return `SCSCategory` instance matching the specified category name, or `nil` if no child category is found.
 
 @see `-[SCSCategoryGroup categoryWithName:]`
 */
- (nullable SCSCategory*)categoryWithName:(NSString*)name;

@end

NS_ASSUME_NONNULL_END
