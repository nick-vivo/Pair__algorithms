#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <pair.h>

TEST(CONSTRUCTORS, DEFAULT)
{
    pair<int, int> a;

    ASSERT_EQ(a.key(), 0);
    ASSERT_EQ(a.value(), 0);
}

TEST(CONSTRUCTORS, NOT_DEFAULT)
{
    pair a(1, 2);
    pair b(2.3, 3.3);
    pair c(true, false);

    ASSERT_EQ(a.key(), 1);
    ASSERT_EQ(a.value(), 2);

    ASSERT_EQ(b.key(), 2.3);
    ASSERT_EQ(b.value(), 3.3);

    ASSERT_EQ(c.key(), true);
    ASSERT_EQ(c.value(), false);
}