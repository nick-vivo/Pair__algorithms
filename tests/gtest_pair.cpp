#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <pair.h>

TEST(CONSTRUCTORS, DEFAULT)
{
    pair<int, int> a;

    ASSERT_EQ(a.key(), 0);
    ASSERT_EQ(a.value(), 0);
}

TEST(CONSTRUCTORS_METHODS, Get_and_Conctructor_value_key)
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

    c.key() = false;
    c.value() = true;
    ASSERT_EQ(c.key(), false);
    ASSERT_EQ(c.value(), true);
}

TEST(OPERATORS, EQUALITY)
{
    pair a(1, 2);
    pair b(2, 3);

    b = a;

    ASSERT_EQ(b.key(), 1);
    ASSERT_EQ(b.value(), 2 );
}

TEST(OPERATORS, SUM)
{
    pair a(1, 2);
    pair b(2, 3);

    pair<int, int> c;

    c = a + b;

    ASSERT_EQ(c.key(), 3);
    ASSERT_EQ(c.value(), 5);
}

TEST(OPERATORS, SUM_EQ)
{
    pair a(1, 2);
    pair b(2, 3);
    a += b;

    ASSERT_EQ(a.key(), 3);
    ASSERT_EQ(a.value(), 5);
}