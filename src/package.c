//
// file: package.c
// author: Michael Brockus
// gmail: <michaelbrockus@gmail.com>
//
#include "chicken/queue.h"

#include <stdlib.h>
#include <string.h>

enum
{
    failed,
    success
}; // end of local enums

//
// This is the official definition for the Chicken Libraries
// 'QueueNode' type.
//
// Members:
// > [_data] is the private data member that represents the
//           data in the structure
// > [_nextPtr] is the pointer to the next node in the stack
//
struct QueueNode
{
    char *_data;
    struct QueueNode *_nextPtr;
}; // end of struct

//
// This is the official definition for the Chicken Libraries
// 'QueueOf' type.
//
// Members:
// > _beginPtr is the pointer to queue begin
// > _endPtr is the pointer to queue end
//
struct QueueOf
{
    size_t _size;
    struct QueueNode *_endPtr;
    struct QueueNode *_beginPtr;
}; // end of struct

//
// Should return a newly hatched data structure object if
// it pass the not nullptr test. But if it was a bad egg
// we just return nullptr.
//
// Param list:
// -> There is none to speak of at this time.
//
QueueOf *chickenQueueCreate(void)
{
    QueueOf *newStructure = malloc(sizeof(*newStructure));
    if (!newStructure)
    {
        return NULL;
    } // end if
    newStructure->_beginPtr = NULL;
    newStructure->_endPtr = NULL;
    newStructure->_size = 0;
    return newStructure;
} // end of function chickenQueueCreate

//
// Should erase the queue structure if it’s not nullptr else
// do nothing.
//
// Param list:
// -> [structureRef]: Reference pointer to your structure
//
void chickenQueueErase(QueueOf **structureRef)
{
    if (!structureRef || !*structureRef)
    {
        return;
    } // end if

    while (chickenQueueNotEmpty(*structureRef))
    {
        chickenQueuePop(*structureRef);
    } // end while

    free(*structureRef);
    *structureRef = NULL;
} // end of function chickenQueueErase

//
// Should push a new recored into the queue if the
// structure is not nullptr. Else nothing.
//
// Param list:
// -> [structurePtr]: Pointer to your structure
// -> [data]: Your data being passed in
//
void chickenQueuePush(QueueOf *structurePtr, char *data)
{
    if (!structurePtr)
    {
        return;
    } // end if

    QueueNode *temp = malloc(sizeof(*temp));
    if (!temp)
    {
        return;
    } // end if
    temp->_data = data;
    temp->_nextPtr = NULL;

    //
    // If queue is empty, then set the new node to both begin and end
    if (!structurePtr->_endPtr)
    {
        structurePtr->_beginPtr = structurePtr->_endPtr = temp;
    } // end if
    else
    {
        structurePtr->_endPtr->_nextPtr = temp;
        structurePtr->_endPtr = temp;
    } // end else

    ++structurePtr->_size;
} // end of function chickenQueuePush

//
// Should return the value stored in the removed node from
// structure if the structure is both not nullptr and or
// empty. If so where gonna return nullptr.
//
// Param list:
// -> [structurePtr]: Pointer to your structure
//
QueueNode *chickenQueuePop(QueueOf *structurePtr)
{
    if (!structurePtr || !structurePtr->_beginPtr)
    {
        return NULL;
    } // end if

    //
    // Here we store previous node to begin and move it close to end
    QueueNode *temp = structurePtr->_beginPtr;
    structurePtr->_beginPtr = structurePtr->_beginPtr->_nextPtr;

    if (!structurePtr->_beginPtr)
    {
        return structurePtr->_endPtr = NULL;
    } // end if
    else
    {
        return temp;
    } // end else
} // end of function chickenQueuePop

//
// Should return the value stored in begin pointer from
// structure if the structure is both not nullptr and or
// empty. If so where gonna return nullptr.
//
// Param list:
// -> [structurePtr]: Pointer to your structure
//
char *chickenQueuePeek(QueueOf *structurePtr)
{
    if (!structurePtr || !structurePtr->_beginPtr)
    {
        return NULL;
    } // end if
    return structurePtr->_beginPtr->_data;
} // end of function chickenQueuePeek

//
// Should return a success value if the structure is an
// empty structure.
//
// Param list:
// -> [structurePtr]: Pointer to your structure
//
unsigned int chickenQueueItsEmpty(QueueOf *structurePtr)
{
    return (!structurePtr->_beginPtr) ? success : failed;
} // end of functions chickenQueueItsEmpty

//
// Should return a success value if the structure is not
// empty in anyway.
//
// Param list:
// -> [structurePtr]: Pointer to your structure
//
unsigned int chickenQueueNotEmpty(QueueOf *structurePtr)
{
    return (structurePtr->_beginPtr) ? success : failed;
} // end of functions chickenQueueNotEmpty
