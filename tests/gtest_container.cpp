#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <container_pair.h>
#include <string>

using string = std::string;
TEST(ALL, ALL_IN_ALL)
{
    Container_Pair<string, int> cont(5);

    ASSERT_EQ(cont.max_size(), 5);
    ASSERT_EQ(cont.count_size(), 0);

    cont.add( pair<string, int>("First", 1) );
    ASSERT_EQ(cont["First"], 1);
    ASSERT_EQ(cont.max_size(), 5);
    ASSERT_EQ(cont.count_size(), 1);
    ASSERT_ANY_THROW(cont["FirstT"]);
    
    cont.add( pair<string, int>("Second", 2) );
    ASSERT_EQ(cont["First"], 1);
    ASSERT_EQ(cont["Second"], 2);
    ASSERT_EQ(cont.max_size(), 5);
    ASSERT_EQ(cont.count_size(), 2);
    ASSERT_ANY_THROW(cont["Third"]);
    
    cont.add( pair<string, int>("Third", 3) );
    ASSERT_EQ(cont["First"], 1);
    ASSERT_EQ(cont["Second"], 2);
    ASSERT_EQ(cont["Third"], 3);
    ASSERT_EQ(cont.max_size(), 5);
    ASSERT_EQ(cont.count_size(), 3);
    ASSERT_ANY_THROW(cont["Four"]);

    cont.add( pair<string, int>("Four", 4) );
    ASSERT_EQ(cont["First"], 1);
    ASSERT_EQ(cont["Second"], 2);
    ASSERT_EQ(cont["Third"], 3);
    ASSERT_EQ(cont["Four"], 4);
    ASSERT_EQ(cont.max_size(), 5);
    ASSERT_EQ(cont.count_size(), 4);
    ASSERT_ANY_THROW(cont["Five"]);
    
    cont.add( pair<string, int>("Five", 5) );
    ASSERT_EQ(cont["First"], 1);
    ASSERT_EQ(cont["Second"], 2);
    ASSERT_EQ(cont["Third"], 3);
    ASSERT_EQ(cont["Four"], 4);
    ASSERT_EQ(cont["Five"], 5);
    ASSERT_EQ(cont.max_size(), 5);
    ASSERT_EQ(cont.count_size(), 5);
    ASSERT_ANY_THROW(cont["Six"]);
    
    ASSERT_ANY_THROW(cont.add( pair<string, int>("SEVEN", 5) ));
}

TEST(VERIFICATION, FIRST)
{
    Container_Pair<string, int> cont(3);
    
    cont.add( pair<string, int>("First", 1) );
    ASSERT_ANY_THROW( cont.add( pair<string, int>("First", 2) ) );
    cont.add( pair<string, int>("Second", 1) );
    ASSERT_EQ(cont["First"], 1);
    ASSERT_EQ(cont["Second"], 1);
}