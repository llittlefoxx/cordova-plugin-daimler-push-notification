//
//  BASEPushManager.h
//  BASEPushClientiOS
//
//  Created by Schmunk, Sergej (415) on 22.07.14.
//  Copyright (c) 2014 Daimler TSS GmbH. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "BASEPClientInfo.h"


#define BASE_URL_PRODUCTION @"https://base.daimler-tss.com/base.push.server/"
#define BASE_URL_DEVELOPMENT @"https://base-int.daimler-tss.com/base.push.server/"
/*
 This class helps communicate with the BASE backend. Some operations requried are the following:
 
 * register the client to receive push messages
 * update the client information to change the push behaviour
 * unregister the client from receiving push (House of Apps requirement)
 
 */

@interface BASEPPushManager : NSObject 


/*
 
 Use this method for the first time to create an BASE Push manager. The manager handels all operations that can be excueted from the client. Register, Unregister and Update Push information for the client.
 
 @param URL: URL to the base system
 
 Returns the singleton instance of the push manager. 
 
 */
+ (BASEPPushManager *)pushManagerWithURL: (NSURL*) baseURL ;



/*
 
 Use this method for the first time to create an BASE Push manager. The manager handels all operations that can be excueted from the client. Register, Unregister and Update Push information for the client.
 
 @param URL: URL to the base system
 @wether you want to enable caching. Prevents the api to make networkcalls if the nohting has changed. 
 
 Returns the singleton instance of the push manager.
 
 */
+ (BASEPPushManager *)pushManagerWithURL: (NSURL*) baseURL enableCaching:(BOOL)enabled;


/*
  This method registers a device with all properties (categories, device metadata ..) to the BASE backend in order to receive push messages (the operation is asynchronous)
 
 @param BASEClientInfo includes all properties that are needed for the reqistration
 @param success this block is called after a successful registration; returns the http status code as int
 @param failure this block is called when the reqistration fails. The NSError object and the status code are passed to this block. 
 
 */
-(void)didRegisterForRemoteNotificationsWithClientInfo:(BASEPClientInfo*) clientInfo
                      success:(void (^)(int responseCode))success
                      failure:(void (^)(NSError *, int responseCode))failure;


/*
 This method updates the device information on the BASE backend. This is method should be used if some parameters. For example, new categories were changed by the user. (the operation is asynchronous)
 
 @param BASEClientInfo includes all information to receive push messages.
 @param success this block is called after a successful update; returns the http status code as int
 @param failure this block is called when the update fails. The NSError object and the status code are passed to this block.
 
 */
- (void) updateRegistrationWithClientInfo: (BASEPClientInfo*) clientInfo
                  success:(void (^)(int responseCode))success
                  failure:(void (^)(NSError *, int responseCode))failure;



/*
 This method unregisters a device from receiving push notfications. This is also a House of Apps requirement. (the operation is asynchronous)
 
 @param BASEPCredentials to unregister the client from receiving push messages.
 @param success this block is called after a successful sign off; returns the http status code as int
 @param failure this block is called when the sign off fails. The NSError object and the status code are passed to this block.
 
 */
- (void) removeRegistrationWithCredentials: (BASEPCredentials*) credentials
                  success:(void (^)(int responseCode))success
                  failure:(void (^)(NSError *, int responseCode))failure;


/*
 
 This method enables caching. If caching is enabled requests to register the client with the base backend are only made once a week if the client information stays unchanged. If the client information changes a request to the backend will be made. 
 
 The cache is stored within the user defaults. However, it is encoded.
 
 This behaviour helps to save the battery of the phone. Further the network trafic will be reduced.
 
 Default Value is: TRUE

*/

- (void) enableCaching:(BOOL) enabled;
    

@end
