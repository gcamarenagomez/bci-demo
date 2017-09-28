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

@class SCSCategory, SCSKnowledgeManager;

/**
 A `SCSCategoryGroup` represents a data category group. A category group 
 contains a hierarchical tree of data categories.
 
 Refer to `SCSCategory` for a representation of data categories.
 */
@interface SCSCategoryGroup : NSObject

/**
 Unique category group name.
 */
@property (nonatomic, copy, readonly) NSString *name;

/**
 Label, or display name, for this category group.
 */
@property (nonatomic, copy, readonly) NSString *label;

/**
 String describing which types of objects this category group can be used for.
 */
@property (nonatomic, copy, readonly) NSString *objectUsage;

/**
 Array of root-level child categories within this category group.
 
 @see `SCSCategory`
 */
@property (nonatomic, strong, readonly) NSArray<SCSCategory*> *childCategories;

/**
 The knowledge manager this category group belongs to.
 */
@property (nonatomic, weak, readonly) SCSKnowledgeManager *manager;

/**
 Returns a category within this category group that matches the specified name.

 @param name Category name.

 @return SCSCategory instance matching the specified category name, 
         or `nil` if no child category is found.
 
 @see `-[SCSCategory categoryWithName:]`
 */
- (nullable SCSCategory*)categoryWithName:(NSString*)name;

/**
 Returns a string suitable for debugging that displays the contents of the 
 category group tree.
 */
@property (readonly, copy) NSString *debugDescription;

@end

NS_ASSUME_NONNULL_END
