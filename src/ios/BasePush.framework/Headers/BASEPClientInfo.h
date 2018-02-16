//
//  BASEPushClientiOS.h
//  BASEPushClientiOS
//
//  Created by Schmunk, Sergej (415) on 22.07.14.
//  Copyright (c) 2014 Daimler TSS GmbH. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "BASEPCredentials.h"
#import <UIKit/UIKit.h>

/**
 * The BASEClienInfo object is used as the transfer object to the backend. All Information within this object a required to communicate with the backend.
 
    Default values for operatingSystem, osVersion, deviceType are already set. 
 */
@interface BASEPClientInfo : NSObject


/**
 * Holds credentials for authenticating the client
 */
@property  BASEPCredentials* credentials;

/**
 * This property can be used to customize the push behaviour of a user. Please insert only BASECategory objects into this array.
 */
@property NSMutableSet* categories;

/**
 * In order to receive messages for a specific language this property can be used.
 */
@property  NSString* language;

/**
 * Holds the operating system of the current device.
 */
@property  NSString* operatingSystem;

/**
 * Holds the operating system version of the current device.
 */
@property  NSString* osVersion;

/**
 * Holds the device type of the current device.
 */
@property  NSString* deviceType;

/**
 * Creates new instance of client info with provided credentials. From UIDevice fills in operatingSystem, osVersion and deviceType.
 */
+ (instancetype)clientInfoWithCredentials:(BASEPCredentials*)credentials;

@end
