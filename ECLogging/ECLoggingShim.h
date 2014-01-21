//
//  Created by Sam Deane on 30/08/2012.
//  Copyright (c) 2014 Sam Deane, Elegant Chaos. All rights reserved.
//

// Fake version of ECLogging - potentially allows us to drop the real thing in at some point in the future

#define ECLOGGING 0

#if EC_RELEASE

#define ECDebug(chan, ...)
#define ECDebugOnly(x)
#define ECReleaseOnly(x) x

#define ECChannelEnable(chan)
#define ECChannelDisable(chan)
#define ECGetChannel(chan)
#define ECDeclareDebugChannel(chan)
#define ECDefineDebugChannel(chan)
#define ECOptionEnabled(key) ([[NSUserDefaults standardUserDefaults] boolForKey:key])
#define ECDebugOptionEnabled(key) (NO)

#else

#define ECDebug(chan, ...) if (*(ECGetChannel(chan))) do { \
    NSString* msg = [NSString stringWithFormat:__VA_ARGS__]; \
    NSString* ch = [[NSString stringWithFormat:@"«%s»", #chan] stringByPaddingToLength:30 withString:@" " startingAtIndex:0]; \
    NSLog(@"%@%@", ch, msg); } while (false)

#define ECDebugOnly(x) x
#define ECReleaseOnly(x)

#define ECChannelEnable(chan) *(ECGetChannel(chan)) = YES
#define ECChannelDisable(chan) *(ECGetChannel(chan)) = NO
#define ECGetChannel(chan) getChannel##chan(#chan)
#define ECDeclareDebugChannel(chan) extern BOOL* getChannel##chan(const char* name)
#define ECDefineDebugChannel(chan) BOOL* getChannel##chan(const char* name) { static BOOL enabled = NO; return &enabled; }
#define ECOptionEnabled(key) ([[NSUserDefaults standardUserDefaults] boolForKey:key])
#define ECDebugOptionEnabled(key) ECOptionEnabled(key)

#endif