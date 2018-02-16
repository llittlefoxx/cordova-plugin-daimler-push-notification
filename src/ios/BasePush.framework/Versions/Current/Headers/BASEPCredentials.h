//
//  BASEAuthInfos.h
//  BasePush
//
//  Created by Schmunk, Sergej (415) on 30.09.14.
//  Copyright (c) 2014 Daimler TSS GmbH. All rights reserved.
//

#import <Foundation/Foundation.h>


/*
 
    This object holds all properties that are required to identify the device and to authenticate with the backend.
 
 */

@interface BASEPCredentials : NSObject

/*
 A device token you received from Apple
 */
@property NSData* deviceToken;


/*
 *
 * an property that is recevied from Base; Required to use the base api
 *
 */
@property NSString* apiKey;


/*
 An application key you received from BASE
 */
@property NSString* applicationKey;

/*
 A secret you received from BASE
 */
@property NSString* secret;

/**
 * Createns new credentials with given applicaiton key and secret for the provided device token.
 *
 * @Deprecated : Method deprecated, instead use 
 *
 * "[credentialsWithAPIKey:(NSString*)apiKey forDeviceToken:(NSData*)deviceToken]"
 *
 */
+credentialsWithApplicationKey:(NSString*)applicationKey andSecret:(NSString*)secret forDeviceToken:(NSData*)deviceToken __deprecated;

/**
 * Createns new credentials with given api key for the provided device token.
 */
+credentialsWithAPIKey:(NSString*)apiKey forDeviceToken:(NSData*)deviceToken;


@end
