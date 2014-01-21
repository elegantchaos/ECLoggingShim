//
//  SVGImporter.h
//  SVGImportTest
//
//  Created by Sam Deane on 30/08/2012.
//  Copyright (c) 2014 Sam Deane, Elegant Chaos. All rights reserved.
//

// Fake version of ECLogging - potentially allows us to drop the real thing in at some point in the future

#define ECDebug(chan, ...) if (*(ECGetChannel(chan))) do { \
    NSString* msg = [NSString stringWithFormat:__VA_ARGS__]; \
    NSString* ch = [[NSString stringWithFormat:@"«%s»", #chan] stringByPaddingToLength:30 withString:@" " startingAtIndex:0]; \
    NSLog(@"%@%@", ch, msg); } while (false)

#define ECChannelEnable(chan) *(ECGetChannel(chan)) = YES
#define ECChannelDisable(chan) *(ECGetChannel(chan)) = NO
#define ECGetChannel(chan) getChannel##chan(#chan)
#define ECDeclareDebugChannel(chan) extern BOOL getChannel##chan(const char* name)
#define ECDefineDebugChannel(chan) BOOL* getChannel##chan(const char* name) { static BOOL enabled = YES; return &enabled; }