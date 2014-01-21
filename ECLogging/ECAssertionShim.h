//
//  Created by Sam Deane on 30/08/2012.
//  Copyright (c) 2014 Sam Deane, Elegant Chaos. All rights reserved.
//

// Fake version of ECLogging - potentially allows us to drop the real thing in at some point in the future

#define ECAssertShouldntBeHereBase(imp)							imp(FALSE)
#define ECAssertNonNilBase(expression, imp)						imp((expression) != nil)
#define ECAssertNilBase(expression, imp)						imp((expression) == nil)
#define ECAssertCountAtLeastBase(container, countMinimum, imp)	imp([container count] >= countMinimum)
#define ECAssertEmptyBase(object, imp)
#define ECCastTo(_class_,_expression_)                          ((_class_*) (_expression_))

#if EC_DEBUG

#define ECAssert(expression) NSAssert(expression, @"Expression %s was false", #expression)
#define ECAssertC(expression) assert(expression)

#else // NON-DEBUG

#define ECAssert(expression)
#define ECAssertC(expression)

#endif

#define ECAssertShouldntBeHere() ECAssertShouldntBeHereBase(ECAssert)
#define ECAssertShouldntBeHereC() ECAssertShouldntBeHereBase(ECAssertC)

#define ECAssertNonNil(expression) ECAssertNonNilBase(expression, ECAssert)
#define ECAssertNonNilC(expression) ECAssertNonNilBase(expression, ECAssertC)

#define ECAssertNil(expression) ECAssertNilBase(expression, ECAssert)
#define ECAssertNilC(expression) ECAssertNilBase(expression, ECAssertC)

#define ECAssertCountAtLeast(container, countMinimum) ECAssertCountAtLeastBase(container, countMinimum, ECAssert)
#define ECAssertCountAtLeastC(container, countMinimum) ECAssertCountAtLeastBase(container, countMinimum, ECAssertC)

#define ECAssertEmpty(item) do { if ([item respondsToSelector:@selector(length)]) { ECAssert([(NSString*) item length] == 0); } else { ECAssert([item count] == 0); } } while (0)

#define ECAssertIsKindOfClass(o, c) ECAssert(((o) == nil) || [o isKindOfClass:[c class]])
#define ECAssertIsMemberOfClass(o, c) ECAssert(((o) == nil) || [o isMemberOfClass:[c class]])
