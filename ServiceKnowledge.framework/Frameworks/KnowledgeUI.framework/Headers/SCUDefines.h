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

#ifndef SCU_EXTERN
#ifdef __cplusplus
#define SCU_EXTERN   extern "C" __attribute__((visibility ("default")))
#else
#define SCU_EXTERN   extern __attribute__((visibility ("default")))
#endif
#endif

#if DEBUG
    #define SCU_UNIT_TESTS_AVAILABLE NS_CLASS_AVAILABLE(10_10, 8_0)
    #define SCU_UNIT_TESTS_EXTERN SCU_EXTERN
#else
    #define SCU_UNIT_TESTS_AVAILABLE NS_CLASS_AVAILABLE(10_10, 8_0)
    #define SCU_UNIT_TESTS_EXTERN SCU_EXTERN
#endif

/* Default appearance styling will be applied */
SCU_EXTERN NSString * const SCUAppearanceStyleDefault;

SCU_EXTERN NSString * const kSCAppearanceCategoryHeaderArrow;
SCU_EXTERN NSString * const kSCAppearanceEmptyArticle;
SCU_EXTERN NSString * const kSCAppearanceEmptySection;
SCU_EXTERN NSString * const kSCAppearanceSubCategoryIcon;
SCU_EXTERN NSString * const kSCAppearanceActionSearch;
SCU_EXTERN NSString * const kSCAppearanceNoSearchResult;
SCU_EXTERN NSString * const kSCAppearanceSearchPlaceholder;
