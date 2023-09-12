#include <gtest/gtest.h>

#include <stack>
#include <list>
#include <vector>
#include <deque>
#include <map>

#include "../../s21_map.h"
#include "../item.h"
#include "../map_helpers.h"

// GCOVR_EXCL_START

namespace
{


TEST(Map, T0DefaultConstructor)
{
    s21::Map<int, Item> s21_map;
    std::map<int, Item> map;

    EXPECT_EQ(s21_map, map);
}

TEST(Map, T1Destructor)
{
    s21::Map<int, Item> s21_map;
    s21_map.Insert(std::make_pair(4, Item()));
    s21_map.Insert(std::make_pair(3, Item()));
    s21_map.Insert(std::make_pair(5, Item()));
}

TEST(Map, T2Destructor)
{
    s21::Map<int, Item> s21_map;
    s21_map.Insert(std::make_pair(4, Item()));

    std::map<int, Item> map;
    map.insert(std::make_pair(4, Item()));


    EXPECT_EQ(s21_map, map);
}





TEST(Map, T0ConstructorInitializer)
{
    s21::Map<int, Item> s21_map {
        {1, Item(1, 'a', 0.1)},
        {2, Item(2, 'b', 0.2)},
        {3, Item(3, 'c', 0.3)},
        {4, Item(4, 'd', 0.4)},
        {5, Item(5, 'e', 0.5)},
        {6, Item(6, 'f', 0.6)},
    };
    std::map<int, Item> map {
        {1, Item(1, 'a', 0.1)},
        {2, Item(2, 'b', 0.2)},
        {3, Item(3, 'c', 0.3)},
        {4, Item(4, 'd', 0.4)},
        {5, Item(5, 'e', 0.5)},
        {6, Item(6, 'f', 0.6)},
    };

    EXPECT_EQ(s21_map, map);
}





TEST(Map, T0CopyConstructor)
{
    const s21::Map<int, Item> s21_source {
        {1, Item(1, 'a', 0.1)},
        {2, Item(2, 'b', 0.2)},
        {3, Item(3, 'c', 0.3)},
        {4, Item(4, 'd', 0.4)},
        {5, Item(5, 'e', 0.5)},
        {6, Item(6, 'f', 0.6)},
    };
    const std::map<int, Item> source {
        {1, Item(1, 'a', 0.1)},
        {2, Item(2, 'b', 0.2)},
        {3, Item(3, 'c', 0.3)},
        {4, Item(4, 'd', 0.4)},
        {5, Item(5, 'e', 0.5)},
        {6, Item(6, 'f', 0.6)},
    };

    s21::Map<int, Item> s21_copy = s21_source;  // copy constructor, not operator=
    std::map<int, Item> copy = source;



    EXPECT_EQ(s21_copy, copy);
}

TEST(Map, T1CopyConstructorEmpty)
{
    const s21::Map<int, Item> s21_source;
    const std::map<int, Item> source;

    s21::Map<int, Item> s21_copy = s21_source;  // copy constructor, not operator=
    std::map<int, Item> copy = source;

    EXPECT_EQ(s21_copy, copy);
}





TEST(Map, T0CopyAssignmentOperator)
{
    const s21::Map<int, Item> s21_source {
        {1, Item(1, 'a', 0.1)},
        {2, Item(2, 'b', 0.2)},
        {3, Item(3, 'c', 0.3)},
        {4, Item(4, 'd', 0.4)},
        {5, Item(5, 'e', 0.5)},
        {6, Item(6, 'f', 0.6)},
    };
    const std::map<int, Item> source {
        {1, Item(1, 'a', 0.1)},
        {2, Item(2, 'b', 0.2)},
        {3, Item(3, 'c', 0.3)},
        {4, Item(4, 'd', 0.4)},
        {5, Item(5, 'e', 0.5)},
        {6, Item(6, 'f', 0.6)},
    };

    s21::Map<int, Item> s21_copy;
    s21_copy = s21_source;  
    std::map<int, Item> copy;
    copy = source;

    EXPECT_EQ(s21_copy, copy);
}

TEST(Map, T1CopyAssignmentOperator)
{
    const s21::Map<int, Item> s21_source;
    const std::map<int, Item> source;

    s21::Map<int, Item> s21_copy;
    s21_copy = s21_source;
    std::map<int, Item> copy;
    copy = source;

    EXPECT_EQ(s21_copy, copy);
}



TEST(Map, T0MoveAssignmentOperator)
{
    s21::Map<int, Item> s21_source {
        {1, Item(1, 'a', 0.1)},
        {2, Item(2, 'b', 0.2)},
        {3, Item(3, 'c', 0.3)},
        {4, Item(4, 'd', 0.4)},
        {5, Item(5, 'e', 0.5)},
        {6, Item(6, 'f', 0.6)},
    };
    std::map<int, Item> source {
        {1, Item(1, 'a', 0.1)},
        {2, Item(2, 'b', 0.2)},
        {3, Item(3, 'c', 0.3)},
        {4, Item(4, 'd', 0.4)},
        {5, Item(5, 'e', 0.5)},
        {6, Item(6, 'f', 0.6)},
    };



    s21::Map<int, Item> s21_copy {
        {3, Item(3, 'c', 0.3)},
        {4, Item(4, 'd', 0.4)},
    };
    s21_copy = std::move(s21_source);  

    std::map<int, Item> copy {
        {3, Item(3, 'c', 0.3)},
        {4, Item(4, 'd', 0.4)},
    };
    copy = std::move(source);


    EXPECT_EQ(s21_copy, copy);

    const s21::Map<int, Item> s21_empty;
    EXPECT_EQ(s21_source, s21_empty);
    
    const std::map<int, Item> empty;
    EXPECT_EQ(source, empty);
}

TEST(Map, T1MoveAssignmentOperator)
{
    s21::Map<int, Item> s21_source;
    std::map<int, Item> source;



    s21::Map<int, Item> s21_copy {
        {3, Item(3, 'c', 0.3)},
        {4, Item(4, 'd', 0.4)},
    };
    s21_copy = std::move(s21_source);  

    std::map<int, Item> copy {
        {3, Item(3, 'c', 0.3)},
        {4, Item(4, 'd', 0.4)},
    };
    copy = std::move(source);


    EXPECT_EQ(s21_copy, copy);

    const s21::Map<int, Item> s21_empty;
    EXPECT_EQ(s21_source, s21_empty);
    
    const std::map<int, Item> empty;
    EXPECT_EQ(source, empty);
}







TEST(Map, T0MoveConstructor)
{
    s21::Map<int, Item> s21_source {
        {1, Item(1, 'a', 0.1)},
        {2, Item(2, 'b', 0.2)},
        {3, Item(3, 'c', 0.3)},
        {4, Item(4, 'd', 0.4)},
        {5, Item(5, 'e', 0.5)},
        {6, Item(6, 'f', 0.6)},
    };
    std::map<int, Item> source {
        {1, Item(1, 'a', 0.1)},
        {2, Item(2, 'b', 0.2)},
        {3, Item(3, 'c', 0.3)},
        {4, Item(4, 'd', 0.4)},
        {5, Item(5, 'e', 0.5)},
        {6, Item(6, 'f', 0.6)},
    };



    s21::Map<int, Item> s21_copy = std::move(s21_source);  
    std::map<int, Item> copy = std::move(source);


    EXPECT_EQ(s21_copy, copy);

    const s21::Map<int, Item> s21_empty;
    EXPECT_EQ(s21_source, s21_empty);
    
    const std::map<int, Item> empty;
    EXPECT_EQ(source, empty);
}

TEST(Map, T1MoveConstructor)
{
    s21::Map<int, Item> s21_source;
    std::map<int, Item> source;



    s21::Map<int, Item> s21_copy = std::move(s21_source);  
    std::map<int, Item> copy = std::move(source);


    EXPECT_EQ(s21_copy, copy);

    const s21::Map<int, Item> s21_empty;
    EXPECT_EQ(s21_source, s21_empty);
    
    const std::map<int, Item> empty;
    EXPECT_EQ(source, empty);
}



}  // namespace

// GCOVR_EXCL_STOP
