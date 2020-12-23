//
// file: test_cases.c
// author: Michael Brockus
// gmail: <michaelbrockus@gmail.com>
//
// USE CASE:
//
// The use case of this file is to contain the test cases needed by this
// project since its important to test once implementation against a set
// of common test cases
//
#include "chicken/queue.h"
#include <unity.h>

QueueOf *queue;

//
//  project setup teardown functions if needed
//
void setUp(void)
{
    queue = chickenQueueCreate();
} // end of function setUp

void tearDown(void)
{
    chickenQueueErase(&queue);
} // end of function tearDown

//
// list of all the test cases for this project
//
static void test_chickenQueuePush(void)
{
    TEST_ASSERT_NOT_NULL(queue);
    chickenQueuePush(queue, "2021");
    TEST_ASSERT_EQUAL_STRING("2021", chickenQueuePeek(queue));

    chickenQueuePush(queue, "2077");
    chickenQueuePush(queue, "2010");
    TEST_ASSERT_EQUAL_STRING("2021", chickenQueuePeek(queue));
} // end of test case

static void test_chickenQueuePush_withNullptr(void)
{
    chickenQueuePush(NULL, "2021");
    TEST_ASSERT_EQUAL_STRING(NULL, chickenQueuePeek(queue));

    chickenQueuePush(NULL, "2077");
    chickenQueuePush(NULL, "2010");
    TEST_ASSERT_EQUAL_STRING(NULL, chickenQueuePeek(queue));
} // end of test case

static void test_chickenQueuePop(void)
{
    TEST_ASSERT_NOT_NULL(queue);
    chickenQueuePush(queue, "red chicken");
    chickenQueuePush(queue, "blue chicken");
    chickenQueuePush(queue, "black chicken");
    chickenQueuePush(queue, "green chicken");
    chickenQueuePush(queue, "yellow chicken");

    TEST_ASSERT_EQUAL_STRING("red chicken", chickenQueuePeek(queue));
    chickenQueuePop(queue);
    TEST_ASSERT_EQUAL_STRING("blue chicken", chickenQueuePeek(queue));
    chickenQueuePop(queue);
    TEST_ASSERT_EQUAL_STRING("black chicken", chickenQueuePeek(queue));

} // end of test case

static void test_chickenQueuePop_withNullptr(void)
{
    chickenQueuePush(NULL, "red chicken");
    chickenQueuePush(NULL, "blue chicken");
    chickenQueuePush(NULL, "black chicken");

    TEST_ASSERT_EQUAL_STRING(NULL, chickenQueuePeek(queue));
    chickenQueuePop(queue);
    TEST_ASSERT_EQUAL_STRING(NULL, chickenQueuePeek(queue));
} // end of test case

static void test_chickenQueueItsEmpty(void)
{
    TEST_ASSERT_NOT_NULL(queue);
    TEST_ASSERT_TRUE(chickenQueueItsEmpty(queue));
    chickenQueuePush(queue, "red chicken");
    TEST_ASSERT_FALSE(chickenQueueItsEmpty(queue));

    TEST_ASSERT_EQUAL_STRING("red chicken", chickenQueuePeek(queue));
} // end of test case

static void test_chickenQueueItsEmpty_withNullptr(void)
{
    chickenQueuePush(NULL, "red chicken");
    TEST_ASSERT_TRUE(chickenQueueItsEmpty(queue));

    TEST_ASSERT_EQUAL_STRING(NULL, chickenQueuePeek(queue));
} // end of test case

static void test_chickenQueueNotEmpty(void)
{
    TEST_ASSERT_NOT_NULL(queue);
    TEST_ASSERT_FALSE(chickenQueueNotEmpty(queue));
    chickenQueuePush(queue, "red chicken");
    TEST_ASSERT_TRUE(chickenQueueNotEmpty(queue));

    TEST_ASSERT_EQUAL_STRING("red chicken", chickenQueuePeek(queue));
} // end of test case

static void test_chickenQueueNotEmpty_withNullptr(void)
{
    chickenQueuePush(NULL, "red chicken");
    TEST_ASSERT_FALSE(chickenQueueNotEmpty(queue));

    TEST_ASSERT_EQUAL_STRING(NULL, chickenQueuePeek(queue));
} // end of test case

//
//  here main is used as the test runner
//
int main(void)
{
    UNITY_BEGIN();

    RUN_TEST(test_chickenQueuePush);
    RUN_TEST(test_chickenQueuePop);
    RUN_TEST(test_chickenQueueItsEmpty);
    RUN_TEST(test_chickenQueueNotEmpty);
    RUN_TEST(test_chickenQueuePush_withNullptr);
    RUN_TEST(test_chickenQueuePop_withNullptr);
    RUN_TEST(test_chickenQueueItsEmpty_withNullptr);
    RUN_TEST(test_chickenQueueNotEmpty_withNullptr);

    return UNITY_END();
} // end of function main
