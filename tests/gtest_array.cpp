#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <array.h>

TEST(ARRAY, ALL)
{
    Array<int> arr(4);
    arr[0] = 0;
    arr[1] = 1;
    arr[2] = 2;
    arr[3] = 3;

    ASSERT_ANY_THROW( arr[4] );
    ASSERT_ANY_THROW( arr[-1] );
    ASSERT_EQ(arr[0], 0);
    ASSERT_EQ(arr[1], 1);
    ASSERT_EQ(arr[2], 2);
    ASSERT_EQ(arr[3], 3);
    ASSERT_EQ(arr.size(), 4);
}