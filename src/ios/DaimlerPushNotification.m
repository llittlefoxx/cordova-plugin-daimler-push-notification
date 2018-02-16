/********* daimlerpushnotification.m Cordova Plugin Implementation *******/

/*
Daimler Push notification plugin created by :

    Mohamed ali Tlili & Joachim Schuster
mohamedali.tlili@esprit.tn

    */

#import <Cordova/CDV.h>
    #import <BasePush/BasePush.h>

    #define kTokenIndex 0
#define kApiIndex 1
#define kUrlIndex 2
#define kCategoryStringIndex 3
#define kUserLanguageIndex 4
#define REGISTERED_TOPICS_DICT @"REGISTERED_TOPICS_DICT"
    @interface daimlerpushnotification : CDVPlugin {
// Member variables go here.

}

@property BASEPClientInfo *clientInfo;

- (void)daimlerPushSubscribe:(CDVInvokedUrlCommand*)command;


    @end


    @implementation daimlerpushnotification


    - (NSMutableSet *)createInitialCategories:(NSArray*)categories {
  NSMutableSet* baseCategories = [NSMutableSet new];
for (NSDictionary* category in categories) {
  NSString* categoryName = category[@"category"];
NSArray* topics = category[@"topics"];
BASEPCategory* brandCategory = [BASEPCategory categoryWithName:categoryName andTagsSet:[topics mutableCopy]];
[baseCategories addObject:brandCategory];
}
return baseCategories;
}


- (void) setDeviceToken:(NSData *) deviceToken api: (NSString *) apiKey categoryData:(NSArray *)categories {

// Setup Push settings -
    BASEPCredentials *credentials = [[BASEPCredentials alloc] init];

[credentials setApiKey:apiKey];
[credentials setDeviceToken:deviceToken];

// Default Device Information like operation system, os version, device type  are set by default.
    BASEPClientInfo *clientInfo = [BASEPClientInfo clientInfoWithCredentials:credentials];

// Setup User Specific Settings --- THIS IS OPTIONAL, DEPENDS ON YOUR USE CASE
clientInfo.categories = [self createInitialCategories:categories];

self.clientInfo = clientInfo;

}

- (void)daimlerPushSubscribe:(CDVInvokedUrlCommand*)command {
  NSString* token = [command.arguments objectAtIndex:kTokenIndex];
NSString* apiKey = [command.arguments objectAtIndex:kApiIndex];
NSString *baseUrl = [command.arguments objectAtIndex:kUrlIndex];
NSString* categoriesString = [command.arguments objectAtIndex:kCategoryStringIndex];
NSString *userLanguage = [command.arguments objectAtIndex:kUserLanguageIndex];

NSData* categoriesData = [categoriesString dataUsingEncoding:NSUTF8StringEncoding];
NSError* error;
NSArray* categories = [NSJSONSerialization JSONObjectWithData:categoriesData options:0 error:&error];

//1. we get the wohle dictionary (aka object) of categories and parese it

    //converting the device token from string to NSdata
NSString * tokenParameter = token;
NSMutableData *dataToken= [[NSMutableData alloc] init];
unsigned char whole_byte;
char byte_chars[3] = {'\0','\0','\0'};
int i;
for (i=0; i < [tokenParameter length]/2; i++) {
  byte_chars[0] = [tokenParameter characterAtIndex:i*2];
byte_chars[1] = [tokenParameter characterAtIndex:i*2+1];
whole_byte = strtol(byte_chars, NULL, 16);
[dataToken appendBytes:&whole_byte length:1];
}

NSLog(@"my token %@", dataToken);

[self setDeviceToken:dataToken api:apiKey categoryData:categories ];


BASEPPushManager *pushManager = [BASEPPushManager pushManagerWithURL:[NSURL URLWithString:baseUrl]];

self.clientInfo.language = userLanguage;

    // can be used for initial and update requests
    // 304 for nothing happend client is same // 204 update successfull on server
[pushManager didRegisterForRemoteNotificationsWithClientInfo:self.clientInfo success: ^(int responseCode){
  NSLog(@"Successfully registered device.");
} failure: ^(NSError *error, int responseCode) {
  NSLog(@"Registering device failed.");
}];

}


@end


