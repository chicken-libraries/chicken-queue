//
// file: queue.h
// author: Michael Brockus
// gmail: <michaelbrockus@gmail.com>
//
#ifndef CHICKEN_QUEUE_PACKAGE_H
#define CHICKEN_QUEUE_PACKAGE_H

//
// Macros to control the visibility of functions provided by this package
//
#ifdef BUILDING_CHICKEN_QUEUE_PACKAGE
#define CHICKEN_PUBLIC __attribute__((visibility("default")))
#else
#define CHICKEN_PUBLIC
#endif

//
//   PUBLIC APPLICATION INTERFACE
// --------------------------------
//
// Published package with provided public application interface for
// use in the users application. Please note that we are internationally
// targeting c23 standard.
//

typedef struct QueueOf QueueOf;

//
// Constructor and destructor functions
//

CHICKEN_PUBLIC QueueOf *chickenQueueCreate(void);
CHICKEN_PUBLIC void chickenQueueErase(QueueOf **structureRef);

//
// Operations provided
//

CHICKEN_PUBLIC void chickenQueuePush(QueueOf *structurePtr, char *data);
CHICKEN_PUBLIC char *chickenQueuePop(QueueOf *structurePtr);
CHICKEN_PUBLIC char *chickenQueuePeek(QueueOf *structurePtr);
CHICKEN_PUBLIC unsigned int chickenQueueItsEmpty(QueueOf *structurePtr);
CHICKEN_PUBLIC unsigned int chickenQueueNotEmpty(QueueOf *structurePtr);

#endif // end of CHICKEN_PACKAGE_H
