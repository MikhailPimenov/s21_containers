#include <gtest/gtest.h>

// #include <stack>
// #include <list>
// #include <vector>
// #include <deque>
#include <set>

#include "../../s21_set.h"
#include "../item.h"
#include "../set_helpers.h"

// GCOVR_EXCL_START

namespace
{


TEST(Map, T0IteratorOperatorPlus)
{
    s21::Set<Item, ComparatorItem> s21_set;
    s21_set.Insert(Item(4));
    s21_set.Insert(Item(6));
    s21_set.Insert(Item(7));
    s21_set.Insert(Item(7));
    s21_set.Insert(Item(8));
    s21_set.Insert(Item(-1));
    s21_set.Insert(Item(-10));
    s21_set.Insert(Item(1));
    s21_set.Insert(Item(5));

    // std::cout << s21_set << '\n';

    std::set<Item, ComparatorItem> set;
    set.insert(Item(4));
    set.insert(Item(6));
    set.insert(Item(7));
    set.insert(Item(7));
    set.insert(Item(8));
    set.insert(Item(-1));
    set.insert(Item(-10));
    set.insert(Item(1));
    set.insert(Item(5));
    
    s21::Set<Item, ComparatorItem>::iterator s21_it = s21_set.begin();
    std::set<Item, ComparatorItem>::iterator it = set.begin();

    while (s21_it != s21_set.end() || it != set.end()) {
        EXPECT_EQ(*s21_it, *it);
        ++s21_it;
        ++it;
    }
}

TEST(Map, T1IteratorOperatorMinus)
{
    s21::Set<Item, ComparatorItem> s21_set;
    s21_set.Insert(Item(4));
    s21_set.Insert(Item(6));
    s21_set.Insert(Item(7));
    s21_set.Insert(Item(7));
    s21_set.Insert(Item(8));
    s21_set.Insert(Item(-1));
    s21_set.Insert(Item(-10));
    s21_set.Insert(Item(1));
    s21_set.Insert(Item(5));

    // std::cout << s21_set << '\n';

    std::set<Item, ComparatorItem> set;
    set.insert(Item(4));
    set.insert(Item(6));
    set.insert(Item(7));
    set.insert(Item(7));
    set.insert(Item(8));
    set.insert(Item(-1));
    set.insert(Item(-10));
    set.insert(Item(1));
    set.insert(Item(5));
    
    s21::Set<Item, ComparatorItem>::iterator s21_it = s21_set.end();
    std::set<Item, ComparatorItem>::iterator it = set.end();

    // for (auto s21_it = --s21_set.end(); s21_it != s21_set.begin(); --s21_it)
        // std::cout << (*s21_it).first << " : " << (*s21_it).second << "\n";

    --s21_it;
    --it;

    while (s21_it != s21_set.begin() || it != set.begin()) {
        EXPECT_EQ(*s21_it, *it);
        --s21_it;
        --it;
    }

    // std::set<Azaza, Item> m;
    // m.insert(std::make_pair(Azaza(), Item(44)));
    // m.inserT(Azaza(), Item(44));
}










TEST(Map, T2ReverseIteratorOperatorPlus)
{
    s21::Set<Item, ComparatorItem> s21_set;
    s21_set.Insert(Item(4));
    s21_set.Insert(Item(6));
    s21_set.Insert(Item(7));
    s21_set.Insert(Item(7));
    s21_set.Insert(Item(8));
    s21_set.Insert(Item(-1));
    s21_set.Insert(Item(-10));
    s21_set.Insert(Item(1));
    s21_set.Insert(Item(5));

    // std::cout << s21_set << '\n';

    std::set<Item, ComparatorItem> set;
    set.insert(Item(4));
    set.insert(Item(6));
    set.insert(Item(7));
    set.insert(Item(7));
    set.insert(Item(8));
    set.insert(Item(-1));
    set.insert(Item(-10));
    set.insert(Item(1));
    set.insert(Item(5));
    
    s21::Set<Item, ComparatorItem>::reverse_iterator s21_it = s21_set.rbegin();
    std::set<Item, ComparatorItem>::reverse_iterator it = set.rbegin();

    while (s21_it != s21_set.rend() || it != set.rend()) {
        EXPECT_EQ(*s21_it, *it);
        ++s21_it;
        ++it;
    }
}

TEST(Map, T3ReverseIteratorOperatorMinus)
{
    s21::Set<Item, ComparatorItem> s21_set;
    s21_set.Insert(Item(4));
    s21_set.Insert(Item(6));
    s21_set.Insert(Item(7));
    s21_set.Insert(Item(7));
    s21_set.Insert(Item(8));
    s21_set.Insert(Item(-1));
    s21_set.Insert(Item(-10));
    s21_set.Insert(Item(1));
    s21_set.Insert(Item(5));

    // std::cout << s21_set << '\n';

    std::set<Item, ComparatorItem> set;
    set.insert(Item(4));
    set.insert(Item(6));
    set.insert(Item(7));
    set.insert(Item(7));
    set.insert(Item(8));
    set.insert(Item(-1));
    set.insert(Item(-10));
    set.insert(Item(1));
    set.insert(Item(5));
    
    s21::Set<Item, ComparatorItem>::reverse_iterator s21_it = s21_set.rend();
    std::set<Item, ComparatorItem>::reverse_iterator it = set.rend();

    // for (auto s21_it = s21_set.rbegin(); s21_it != s21_set.rend(); ++s21_it)
    //     std::cout << (*s21_it).first << " : " << (*s21_it).second << "\n";

    --s21_it;
    --it;

    while (s21_it != s21_set.rbegin() || it != set.rbegin()) {
        EXPECT_EQ(*s21_it, *it);
        --s21_it;
        --it;
    }
}

TEST(Map, T0IteratorOperatorMinusPost)
{
    s21::Set<Item, ComparatorItem> s21_set;
    s21_set.Insert(Item(4));
    s21_set.Insert(Item(6));
    s21_set.Insert(Item(7));
    s21_set.Insert(Item(7));
    s21_set.Insert(Item(8));
    s21_set.Insert(Item(-1));
    s21_set.Insert(Item(-10));
    s21_set.Insert(Item(1));
    s21_set.Insert(Item(5));

    // std::cout << s21_set << '\n';

    std::set<Item, ComparatorItem> set;
    set.insert(Item(4));
    set.insert(Item(6));
    set.insert(Item(7));
    set.insert(Item(7));
    set.insert(Item(8));
    set.insert(Item(-1));
    set.insert(Item(-10));
    set.insert(Item(1));
    set.insert(Item(5));
    
    s21::Set<Item, ComparatorItem>::iterator s21_it = s21_set.end();
    std::set<Item, ComparatorItem>::iterator it = set.end();

    // for (auto s21_it = s21_set.rbegin(); s21_it != s21_set.rend(); ++s21_it)
    //     std::cout << (*s21_it).first << " : " << (*s21_it).second << "\n";

    s21_it--;
    it--;

    while (s21_it != s21_set.begin() || it != set.begin()) 
        EXPECT_EQ(*(s21_it--), *(it--));

}

TEST(Map, T0IteratorOperatorPlusPost)
{
    s21::Set<Item, ComparatorItem> s21_set;
    s21_set.Insert(Item(4));
    s21_set.Insert(Item(6));
    s21_set.Insert(Item(7));
    s21_set.Insert(Item(7));
    s21_set.Insert(Item(8));
    s21_set.Insert(Item(-1));
    s21_set.Insert(Item(-10));
    s21_set.Insert(Item(1));
    s21_set.Insert(Item(5));

    // std::cout << s21_set << '\n';

    std::set<Item, ComparatorItem> set;
    set.insert(Item(4));
    set.insert(Item(6));
    set.insert(Item(7));
    set.insert(Item(7));
    set.insert(Item(8));
    set.insert(Item(-1));
    set.insert(Item(-10));
    set.insert(Item(1));
    set.insert(Item(5));
    
    s21::Set<Item, ComparatorItem>::iterator s21_it = s21_set.begin();
    std::set<Item, ComparatorItem>::iterator it = set.begin();

    // for (auto s21_it = s21_set.rbegin(); s21_it != s21_set.rend(); ++s21_it)
    //     std::cout << (*s21_it).first << " : " << (*s21_it).second << "\n";

    s21_it++;
    it++;

    while (s21_it != s21_set.end() || it != set.end()) 
        EXPECT_EQ(*(s21_it++), *(it++));

}

// TEST(Map, T0ReverseIteratorOperatorMinusPost)
// {
//     s21::Set<Item, ComparatorItem> s21_set;
//     s21_set.Insert(Item(4));
//     s21_set.Insert(Item(6));
//     s21_set.Insert(Item(7));
//     s21_set.Insert(Item(7));
//     s21_set.Insert(Item(8));
//     s21_set.Insert(Item(-1));
//     s21_set.Insert(Item(-10));
//     s21_set.Insert(Item(1));
//     s21_set.Insert(Item(5));

//     // std::cout << s21_set << '\n';

//     std::set<Item, ComparatorItem> set;
//     set.insert(Item(4));
//     set.insert(Item(6));
//     set.insert(Item(7));
//     set.insert(Item(7));
//     set.insert(Item(8));
//     set.insert(Item(-1));
//     set.insert(Item(-10));
//     set.insert(Item(1));
//     set.insert(Item(5));
    
//     s21::Set<Item, ComparatorItem>::reverse_iterator s21_it = s21_set.rend();
//     std::set<Item, ComparatorItem>::reverse_iterator it = set.rend();

//     // for (auto s21_it = s21_set.rbegin(); s21_it != s21_set.rend(); ++s21_it)
//     //     std::cout << (*s21_it).first << " : " << (*s21_it).second << "\n";

//     s21_it--;
//     it--;

//     while (s21_it != s21_set.rbegin() || it != set.rbegin()) 
//         EXPECT_EQ(*(s21_it--), *(it--));

// }

TEST(Map, T0ReverseIteratorOperatorPlusPost)
{
    s21::Set<Item, ComparatorItem> s21_set;
    s21_set.Insert(Item(4));
    s21_set.Insert(Item(6));
    s21_set.Insert(Item(7));
    s21_set.Insert(Item(7));
    s21_set.Insert(Item(8));
    s21_set.Insert(Item(-1));
    s21_set.Insert(Item(-10));
    s21_set.Insert(Item(1));
    s21_set.Insert(Item(5));

    // std::cout << s21_set << '\n';

    std::set<Item, ComparatorItem> set;
    set.insert(Item(4));
    set.insert(Item(6));
    set.insert(Item(7));
    set.insert(Item(7));
    set.insert(Item(8));
    set.insert(Item(-1));
    set.insert(Item(-10));
    set.insert(Item(1));
    set.insert(Item(5));
    
    s21::Set<Item, ComparatorItem>::reverse_iterator s21_it = s21_set.rbegin();
    std::set<Item, ComparatorItem>::reverse_iterator it = set.rbegin();

    s21_it++;
    it++;

    while (s21_it != s21_set.rend() || it != set.rend()) 
        EXPECT_EQ(*(s21_it++), *(it++));

}


}  // namespace

// GCOVR_EXCL_STOP
