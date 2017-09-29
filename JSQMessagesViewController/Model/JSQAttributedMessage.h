//
//  Created by Jesse Squires
//  http://www.jessesquires.com
//
//
//  Documentation
//  http://cocoadocs.org/docsets/JSQMessagesViewController
//
//
//  GitHub
//  https://github.com/jessesquires/JSQMessagesViewController
//
//
//  License
//  Copyright (c) 2014 Jesse Squires
//  Released under an MIT license: http://opensource.org/licenses/MIT
//

#import "JSQMessage.h"

#import "JSQMessageAttributedData.h"

@interface JSQAttributedMessage : JSQMessage <JSQMessageAttributedData>


/**
 *  Returns the body text of the message, or `nil` if the message is a media message.
 *  That is, if `isMediaMessage` is equal to `YES` then this value will be `nil`.
 */
@property (copy, nonatomic, readonly) NSAttributedString *attributedText;

/**
 *  If is a button, then we put an invisble overlay over the message text, this is because of weird behaviour
 *  in iOS 11 which seems to stop on tap gesture working, perhaps due to copy and paste conflict with text below
 */
@property (assign, nonatomic, readonly) BOOL isButton;



#pragma mark - Initialization
/**
 *  Initializes and returns a message object having the given senderId, displayName, text,
 *  and current system date.
 *
 *  @param senderId       The unique identifier for the user who sent the message. This value must not be `nil`.
 *  @param displayName    The display name for the user who sent the message. This value must not be `nil`.
 *  @param attributedText The body attributed text of the message. This value must not be `nil`.
 *
 *  @discussion Initializing a `JSQMessage` with this method will set `isMediaMessage` to `NO`.
 *
 *  @return An initialized `JSQMessage` object if successful, `nil` otherwise.
 */
+ (instancetype)messageWithSenderId:(NSString *)senderId
                        displayName:(NSString *)displayName
                     attributedText:(NSAttributedString *) attributedText;


/**
 *  Initializes and returns a message object having the given senderId, senderDisplayName, date, and text.
 *
 *  @param senderId             The unique identifier for the user who sent the message. This value must not be `nil`.
 *  @param senderDisplayName    The display name for the user who sent the message. This value must not be `nil`.
 *  @param date                 The date that the message was sent. This value must not be `nil`.
 *  @param attributedText       The body atributed text of the message. This value must not be `nil`.
 *
 *  @discussion Initializing a `JSQMessage` with this method will set `isMediaMessage` to `NO`.
 *
 *  @return An initialized `JSQMessage` object if successful, `nil` otherwise.
 */
- (instancetype)initWithSenderId:(NSString *)senderId
               senderDisplayName:(NSString *)senderDisplayName
                            date:(NSDate *)date
                  attributedText:(NSAttributedString *) attributeText;

- (instancetype)initWithSenderId:(NSString *)senderId
               senderDisplayName:(NSString *)senderDisplayName
                            date:(NSDate *)date
                  attributedText:(NSAttributedString *)attributedText
                        isButton:(BOOL)isButton;

@end
