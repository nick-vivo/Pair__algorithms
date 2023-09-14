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

Array<int> function()
{
    Array<int> a(3);

    a[0] = 0;
    a[1] = 1;
    a[2] = 2;

    return a;
}

TEST(CONSCTRUCTOR_COPY, CPY)
{
    Array<int> b(function());

    ASSERT_EQ(b[0], 0);
    ASSERT_EQ(b[1], 1);
    ASSERT_EQ(b[2], 2);
    ASSERT_EQ(b.size(), 3);
}