#include <gtest/gtest.h>

#include <stack>
#include <list>
#include <vector>
#include <deque>
#include <set>

#include "../../s21_set.h"
#include "../item.h"
#include "../set_helpers.h"

// GCOVR_EXCL_START

namespace
{


TEST(Set, T0DefaultConstructor)
{
    s21::Set<Item, ComparatorItem> s21_set;
    std::set<Item, ComparatorItem> set;

    // std::cout << s21_map << '\n';

    // for (auto it = map.cbegin(); it != map.cend(); ++it)
    //     std::cout << "{" << it->first << " : " << it->second << "}\n";

    EXPECT_EQ(s21_set, set);
}

TEST(Set, T1Destructor)
{
    s21::Set<Item, ComparatorItem> s21_set;
    std::set<Item, ComparatorItem> set;

    // s21_map.Insert(std::make_pair(4, Item()));
    // s21_map.Insert(std::make_pair(3, Item()));
    // s21_map.Insert(std::make_pair(5, Item()));

    EXPECT_EQ(s21_set, set);
}

TEST(Set, T2Destructor)
{
    s21::Set<Item, ComparatorItem> s21_set;
    s21_set.Insert(Item());

    std::set<Item, ComparatorItem> set;
    set.insert(Item());


    EXPECT_EQ(s21_set, set);
}





TEST(Set, T0ConstructorInitializer)
{
    s21::Set<Item, ComparatorItem> s21_set {
        {Item(1, 'a', 0.1)},
        {Item(2, 'b', 0.2)},
        {Item(3, 'c', 0.3)},
        {Item(4, 'd', 0.4)},
        {Item(5, 'e', 0.5)},
        {Item(6, 'f', 0.6)},
    };
    std::set<Item, ComparatorItem> set {
        {Item(1, 'a', 0.1)},
        {Item(2, 'b', 0.2)},
        {Item(3, 'c', 0.3)},
        {Item(4, 'd', 0.4)},
        {Item(5, 'e', 0.5)},
        {Item(6, 'f', 0.6)},
    };

    EXPECT_EQ(s21_set, set);
}





TEST(Set, T0CopyConstructor)
{
    const s21::Set<Item, ComparatorItem> s21_source {
        {Item(1, 'a', 0.1)},
        {Item(2, 'b', 0.2)},
        {Item(3, 'c', 0.3)},
        {Item(4, 'd', 0.4)},
        {Item(5, 'e', 0.5)},
        {Item(6, 'f', 0.6)},
    };
    const std::set<Item, ComparatorItem> source {
        {Item(1, 'a', 0.1)},
        {Item(2, 'b', 0.2)},
        {Item(3, 'c', 0.3)},
        {Item(4, 'd', 0.4)},
        {Item(5, 'e', 0.5)},
        {Item(6, 'f', 0.6)},
    };

    s21::Set<Item, ComparatorItem> s21_copy = s21_source;  // copy constructor, not operator=
    std::set<Item, ComparatorItem> copy = source;



    EXPECT_EQ(s21_copy, copy);
}

TEST(Set, T1CopyConstructorEmpty)
{
    const s21::Set<Item, ComparatorItem> s21_source;
    const std::set<Item, ComparatorItem> source;

    s21::Set<Item, ComparatorItem> s21_copy = s21_source;  // copy constructor, not operator=
    std::set<Item, ComparatorItem> copy = source;

    EXPECT_EQ(s21_copy, copy);
}





TEST(Set, T0CopyAssignmentOperator)
{
    const s21::Set<Item, ComparatorItem> s21_source {
        {Item(1, 'a', 0.1)},
        {Item(2, 'b', 0.2)},
        {Item(3, 'c', 0.3)},
        {Item(4, 'd', 0.4)},
        {Item(5, 'e', 0.5)},
        {Item(6, 'f', 0.6)},
    };
    const std::set<Item, ComparatorItem> source {
        {Item(1, 'a', 0.1)},
        {Item(2, 'b', 0.2)},
        {Item(3, 'c', 0.3)},
        {Item(4, 'd', 0.4)},
        {Item(5, 'e', 0.5)},
        {Item(6, 'f', 0.6)},
    };

    s21::Set<Item, ComparatorItem> s21_copy;
    s21_copy = s21_source;  
    std::set<Item, ComparatorItem> copy;
    copy = source;

    EXPECT_EQ(s21_copy, copy);
}

TEST(Set, T1CopyAssignmentOperator)
{
    const s21::Set<Item, ComparatorItem> s21_source;
    const std::set<Item, ComparatorItem> source;

    s21::Set<Item, ComparatorItem> s21_copy;
    s21_copy = s21_source;
    std::set<Item, ComparatorItem> copy;
    copy = source;

    EXPECT_EQ(s21_copy, copy);
}



TEST(Set, T0MoveAssignmentOperator)
{
    s21::Set<Item, ComparatorItem> s21_source {
        {Item(1, 'a', 0.1)},
        {Item(2, 'b', 0.2)},
        {Item(3, 'c', 0.3)},
        {Item(4, 'd', 0.4)},
        {Item(5, 'e', 0.5)},
        {Item(6, 'f', 0.6)},
    };
    std::set<Item, ComparatorItem> source {
        {Item(1, 'a', 0.1)},
        {Item(2, 'b', 0.2)},
        {Item(3, 'c', 0.3)},
        {Item(4, 'd', 0.4)},
        {Item(5, 'e', 0.5)},
        {Item(6, 'f', 0.6)},
    };



    s21::Set<Item, ComparatorItem> s21_copy {
        {Item(3, 'c', 0.3)},
        {Item(4, 'd', 0.4)},
    };
    s21_copy = std::move(s21_source);  

    std::set<Item, ComparatorItem> copy {
        {Item(3, 'c', 0.3)},
        {Item(4, 'd', 0.4)},
    };
    copy = std::move(source);


    EXPECT_EQ(s21_copy, copy);

    const s21::Set<Item, ComparatorItem> s21_empty;
    EXPECT_EQ(s21_source, s21_empty);
    
    const std::set<Item, ComparatorItem> empty;
    EXPECT_EQ(source, empty);
}

TEST(Set, T1MoveAssignmentOperator)
{
    s21::Set<Item, ComparatorItem> s21_source;
    std::set<Item, ComparatorItem> source;



    s21::Set<Item, ComparatorItem> s21_copy {
        {Item(3, 'c', 0.3)},
        {Item(4, 'd', 0.4)},
    };
    s21_copy = std::move(s21_source);  

    std::set<Item, ComparatorItem> copy {
        {Item(3, 'c', 0.3)},
        {Item(4, 'd', 0.4)},
    };
    copy = std::move(source);


    EXPECT_EQ(s21_copy, copy);

    const s21::Set<Item, ComparatorItem> s21_empty;
    EXPECT_EQ(s21_source, s21_empty);
    
    const std::set<Item, ComparatorItem> empty;
    EXPECT_EQ(source, empty);
}







TEST(Set, T0MoveConstructor)
{
    s21::Set<Item, ComparatorItem> s21_source {
        {Item(1, 'a', 0.1)},
        {Item(2, 'b', 0.2)},
        {Item(3, 'c', 0.3)},
        {Item(4, 'd', 0.4)},
        {Item(5, 'e', 0.5)},
        {Item(6, 'f', 0.6)},
    };
    std::set<Item, ComparatorItem> source {
        {Item(1, 'a', 0.1)},
        {Item(2, 'b', 0.2)},
        {Item(3, 'c', 0.3)},
        {Item(4, 'd', 0.4)},
        {Item(5, 'e', 0.5)},
        {Item(6, 'f', 0.6)},
    };



    s21::Set<Item, ComparatorItem> s21_copy = std::move(s21_source);  
    std::set<Item, ComparatorItem> copy = std::move(source);


    EXPECT_EQ(s21_copy, copy);

    const s21::Set<Item, ComparatorItem> s21_empty;
    EXPECT_EQ(s21_source, s21_empty);
    
    const std::set<Item, ComparatorItem> empty;
    EXPECT_EQ(source, empty);
}

TEST(Map, T1MoveConstructor)
{
    s21::Set<Item, ComparatorItem> s21_source;
    std::set<Item, ComparatorItem> source;



    s21::Set<Item, ComparatorItem> s21_copy = std::move(s21_source);  
    std::set<Item, ComparatorItem> copy = std::move(source);


    EXPECT_EQ(s21_copy, copy);

    const s21::Set<Item, ComparatorItem> s21_empty;
    EXPECT_EQ(s21_source, s21_empty);
    
    const std::set<Item, ComparatorItem> empty;
    EXPECT_EQ(source, empty);
}



}  // namespace

// GCOVR_EXCL_STOP
