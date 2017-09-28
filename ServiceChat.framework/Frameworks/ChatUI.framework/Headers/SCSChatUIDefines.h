//
//  SCSChatDefines.h
//  ChatUI
//
//  Created by Michael Nachbaur on 2/24/16.
//  Copyright © 2016 Salesforce.com. All rights reserved.
//

#import <Foundation/Foundation.h>

#ifndef SC_EXTERN
#ifdef __cplusplus
#define SC_EXTERN   extern "C" __attribute__((visibility ("default")))
#else
#define SC_EXTERN   extern __attribute__((visibility ("default")))
#endif
#endif

SC_EXTERN NSString * const kSCAppearanceChatIcon;
SC_EXTERN NSString * const kSCAppearanceChatAgentAvatar;
SC_EXTERN NSString * const SCSChatUILogIdentifier;
SC_EXTERN NSString * const kSCAppearanceAttachmentClipIcon;
SC_EXTERN NSString * const kSCAppearancePreChatIcon;
SC_EXTERN NSString * const kSCAppearanceDropdown;
SC_EXTERN NSString * const kSCAppearanceChatConnectingIcon;
SC_EXTERN NSString * const kSCAppearanceChatConnectingIconLarge;

