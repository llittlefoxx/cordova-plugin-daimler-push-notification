//
//  BASECategory.h
//  BASEPushClientiOS
//
//  Created by Schmunk, Sergej (415) on 28.08.14.
//  Copyright (c) 2014 Daimler TSS GmbH. All rights reserved.
//

#import <Foundation/Foundation.h>

/*
 
 This object should be used to customize the push behaviour of the current user. You can use this object for a category. 
 
 Example: category name: "cars" and the tags would be "c-class, b-class, e-class"
 
 */

@interface BASEPCategory : NSObject

/*
 category name
 */
@property NSString *name;

/*
 this object hold diffrent features for the given category
 */
@property NSMutableSet *tags;

+(instancetype)categoryWithName:(NSString*)name andTagsSet:(NSMutableSet*)tags;

@end
