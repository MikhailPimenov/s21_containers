#include <gtest/gtest.h>

#include <stack>
#include <list>
#include <vector>
#include <deque>
#include <map>

#include "../../s21_multimap.h"
#include "../item.h"
#include "../multimap_helpers.h"

// GCOVR_EXCL_START

namespace
{


TEST(Map, T0IteratorOperatorPlus)
{
    s21::MultiMap<int, Item> s21_multimap;
    s21_multimap.Insert(std::make_pair(4, Item(4)));
    s21_multimap.Insert(std::make_pair(6, Item(6)));
    s21_multimap.Insert(std::make_pair(7, Item(7)));
    s21_multimap.Insert(std::make_pair(7, Item(7)));
    s21_multimap.Insert(std::make_pair(8, Item(8)));
    s21_multimap.Insert(std::make_pair(-1, Item(-1)));
    s21_multimap.Insert(std::make_pair(-10, Item(-10)));
    s21_multimap.Insert(std::make_pair(1, Item(1)));
    s21_multimap.Insert(std::make_pair(5, Item(5)));

    // std::cout << s21_multimap << '\n';

    std::multimap<int, Item> multimap;
    multimap.insert(std::make_pair(4, Item(4)));
    multimap.insert(std::make_pair(6, Item(6)));
    multimap.insert(std::make_pair(7, Item(7)));
    multimap.insert(std::make_pair(7, Item(7)));
    multimap.insert(std::make_pair(8, Item(8)));
    multimap.insert(std::make_pair(-1, Item(-1)));
    multimap.insert(std::make_pair(-10, Item(-10)));
    multimap.insert(std::make_pair(1, Item(1)));
    multimap.insert(std::make_pair(5, Item(5)));
    
    s21::MultiMap<int, Item>::iterator s21_it = s21_multimap.begin();
    std::multimap<int, Item>::iterator it = multimap.begin();

    while (s21_it != s21_multimap.end() || it != multimap.end()) {
        EXPECT_EQ(*s21_it, *it);
        ++s21_it;
        ++it;
    }
}

TEST(Map, T1IteratorOperatorMinus)
{
    s21::MultiMap<int, Item> s21_multimap;
    s21_multimap.Insert(std::make_pair(4, Item(4)));
    s21_multimap.Insert(std::make_pair(6, Item(6)));
    s21_multimap.Insert(std::make_pair(7, Item(7)));
    s21_multimap.Insert(std::make_pair(7, Item(7)));
    s21_multimap.Insert(std::make_pair(8, Item(8)));
    s21_multimap.Insert(std::make_pair(-1, Item(-1)));
    s21_multimap.Insert(std::make_pair(-10, Item(-10)));
    s21_multimap.Insert(std::make_pair(1, Item(1)));
    s21_multimap.Insert(std::make_pair(5, Item(5)));

    // std::cout << s21_multimap << '\n';

    std::multimap<int, Item> multimap;
    multimap.insert(std::make_pair(4, Item(4)));
    multimap.insert(std::make_pair(6, Item(6)));
    multimap.insert(std::make_pair(7, Item(7)));
    multimap.insert(std::make_pair(7, Item(7)));
    multimap.insert(std::make_pair(8, Item(8)));
    multimap.insert(std::make_pair(-1, Item(-1)));
    multimap.insert(std::make_pair(-10, Item(-10)));
    multimap.insert(std::make_pair(1, Item(1)));
    multimap.insert(std::make_pair(5, Item(5)));
    
    s21::MultiMap<int, Item>::iterator s21_it = s21_multimap.end();
    std::multimap<int, Item>::iterator it = multimap.end();

    // for (auto s21_it = --multimap.end(); s21_it != multimap.begin(); --s21_it)
        // std::cout << (*s21_it).first << " : " << (*s21_it).second << "\n";

    --s21_it;
    --it;

    while (s21_it != s21_multimap.begin() || it != multimap.begin()) {
        EXPECT_EQ(*s21_it, *it);
        --s21_it;
        --it;
    }

    // std::multimap<Azaza, Item> m;
    // m.insert(std::make_pair(Azaza(), Item(44)));
    // m.inserT(Azaza(), Item(44));
}










TEST(Map, T2ReverseIteratorOperatorPlus)
{
    s21::MultiMap<int, Item> s21_multimap;
    s21_multimap.Insert(std::make_pair(4, Item(4)));
    s21_multimap.Insert(std::make_pair(6, Item(6)));
    s21_multimap.Insert(std::make_pair(7, Item(7)));
    s21_multimap.Insert(std::make_pair(7, Item(7)));
    s21_multimap.Insert(std::make_pair(8, Item(8)));
    s21_multimap.Insert(std::make_pair(-1, Item(-1)));
    s21_multimap.Insert(std::make_pair(-10, Item(-10)));
    s21_multimap.Insert(std::make_pair(1, Item(1)));
    s21_multimap.Insert(std::make_pair(5, Item(5)));

    // std::cout << s21_multimap << '\n';

    std::multimap<int, Item> multimap;
    multimap.insert(std::make_pair(4, Item(4)));
    multimap.insert(std::make_pair(6, Item(6)));
    multimap.insert(std::make_pair(7, Item(7)));
    multimap.insert(std::make_pair(7, Item(7)));
    multimap.insert(std::make_pair(8, Item(8)));
    multimap.insert(std::make_pair(-1, Item(-1)));
    multimap.insert(std::make_pair(-10, Item(-10)));
    multimap.insert(std::make_pair(1, Item(1)));
    multimap.insert(std::make_pair(5, Item(5)));
    
    s21::MultiMap<int, Item>::reverse_iterator s21_it = s21_multimap.rbegin();
    std::multimap<int, Item>::reverse_iterator it = multimap.rbegin();

    while (s21_it != s21_multimap.rend() || it != multimap.rend()) {
        EXPECT_EQ(*s21_it, *it);
        ++s21_it;
        ++it;
    }
}

TEST(Map, T3ReverseIteratorOperatorMinus)
{
    s21::MultiMap<int, Item> s21_multimap;
    s21_multimap.Insert(std::make_pair(4, Item(4)));
    s21_multimap.Insert(std::make_pair(6, Item(6)));
    s21_multimap.Insert(std::make_pair(7, Item(7)));
    s21_multimap.Insert(std::make_pair(7, Item(7)));
    s21_multimap.Insert(std::make_pair(8, Item(8)));
    s21_multimap.Insert(std::make_pair(-1, Item(-1)));
    s21_multimap.Insert(std::make_pair(-10, Item(-10)));
    s21_multimap.Insert(std::make_pair(1, Item(1)));
    s21_multimap.Insert(std::make_pair(5, Item(5)));

    // std::cout << s21_multimap << '\n';

    std::multimap<int, Item> multimap;
    multimap.insert(std::make_pair(4, Item(4)));
    multimap.insert(std::make_pair(6, Item(6)));
    multimap.insert(std::make_pair(7, Item(7)));
    multimap.insert(std::make_pair(7, Item(7)));
    multimap.insert(std::make_pair(8, Item(8)));
    multimap.insert(std::make_pair(-1, Item(-1)));
    multimap.insert(std::make_pair(-10, Item(-10)));
    multimap.insert(std::make_pair(1, Item(1)));
    multimap.insert(std::make_pair(5, Item(5)));
    
    s21::MultiMap<int, Item>::reverse_iterator s21_it = s21_multimap.rend();
    std::multimap<int, Item>::reverse_iterator it = multimap.rend();

    // for (auto s21_it = s21_multimap.rbegin(); s21_it != s21_multimap.rend(); ++s21_it)
    //     std::cout << (*s21_it).first << " : " << (*s21_it).second << "\n";

    --s21_it;
    --it;

    while (s21_it != s21_multimap.rbegin() || it != multimap.rbegin()) {
        EXPECT_EQ(*s21_it, *it);
        --s21_it;
        --it;
    }
}

TEST(Map, T0IteratorOperatorMinusPost)
{
    s21::MultiMap<int, Item> s21_multimap;
    s21_multimap.Insert(std::make_pair(4, Item(4)));
    s21_multimap.Insert(std::make_pair(6, Item(6)));
    s21_multimap.Insert(std::make_pair(7, Item(7)));
    s21_multimap.Insert(std::make_pair(7, Item(7)));
    s21_multimap.Insert(std::make_pair(8, Item(8)));
    s21_multimap.Insert(std::make_pair(-1, Item(-1)));
    s21_multimap.Insert(std::make_pair(-10, Item(-10)));
    s21_multimap.Insert(std::make_pair(1, Item(1)));
    s21_multimap.Insert(std::make_pair(5, Item(5)));

    // std::cout << s21_multimap << '\n';

    std::multimap<int, Item> multimap;
    multimap.insert(std::make_pair(4, Item(4)));
    multimap.insert(std::make_pair(6, Item(6)));
    multimap.insert(std::make_pair(7, Item(7)));
    multimap.insert(std::make_pair(7, Item(7)));
    multimap.insert(std::make_pair(8, Item(8)));
    multimap.insert(std::make_pair(-1, Item(-1)));
    multimap.insert(std::make_pair(-10, Item(-10)));
    multimap.insert(std::make_pair(1, Item(1)));
    multimap.insert(std::make_pair(5, Item(5)));
    
    s21::MultiMap<int, Item>::iterator s21_it = s21_multimap.end();
    std::multimap<int, Item>::iterator it = multimap.end();

    // for (auto s21_it = s21_multimap.rbegin(); s21_it != s21_multimap.rend(); ++s21_it)
    //     std::cout << (*s21_it).first << " : " << (*s21_it).second << "\n";

    s21_it--;
    it--;

    while (s21_it != s21_multimap.begin() || it != multimap.begin()) 
        EXPECT_EQ(*(s21_it--), *(it--));

}

TEST(Map, T0IteratorOperatorPlusPost)
{
    s21::MultiMap<int, Item> s21_multimap;
    s21_multimap.Insert(std::make_pair(4, Item(4)));
    s21_multimap.Insert(std::make_pair(6, Item(6)));
    s21_multimap.Insert(std::make_pair(7, Item(7)));
    s21_multimap.Insert(std::make_pair(7, Item(7)));
    s21_multimap.Insert(std::make_pair(8, Item(8)));
    s21_multimap.Insert(std::make_pair(-1, Item(-1)));
    s21_multimap.Insert(std::make_pair(-10, Item(-10)));
    s21_multimap.Insert(std::make_pair(1, Item(1)));
    s21_multimap.Insert(std::make_pair(5, Item(5)));

    // std::cout << s21_multimap << '\n';

    std::multimap<int, Item> multimap;
    multimap.insert(std::make_pair(4, Item(4)));
    multimap.insert(std::make_pair(6, Item(6)));
    multimap.insert(std::make_pair(7, Item(7)));
    multimap.insert(std::make_pair(7, Item(7)));
    multimap.insert(std::make_pair(8, Item(8)));
    multimap.insert(std::make_pair(-1, Item(-1)));
    multimap.insert(std::make_pair(-10, Item(-10)));
    multimap.insert(std::make_pair(1, Item(1)));
    multimap.insert(std::make_pair(5, Item(5)));
    
    s21::MultiMap<int, Item>::iterator s21_it = s21_multimap.begin();
    std::multimap<int, Item>::iterator it = multimap.begin();

    // for (auto s21_it = s21_multimap.rbegin(); s21_it != s21_multimap.rend(); ++s21_it)
    //     std::cout << (*s21_it).first << " : " << (*s21_it).second << "\n";

    s21_it++;
    it++;

    while (s21_it != s21_multimap.end() || it != multimap.end()) 
        EXPECT_EQ(*(s21_it++), *(it++));

}

// TEST(Map, T0ReverseIteratorOperatorMinusPost)
// {
//     s21::MultiMap<int, Item> s21_multimap;
//     s21_multimap.Insert(std::make_pair(4, Item(4)));
//     s21_multimap.Insert(std::make_pair(6, Item(6)));
//     s21_multimap.Insert(std::make_pair(7, Item(7)));
//     s21_multimap.Insert(std::make_pair(7, Item(7)));
//     s21_multimap.Insert(std::make_pair(8, Item(8)));
//     s21_multimap.Insert(std::make_pair(-1, Item(-1)));
//     s21_multimap.Insert(std::make_pair(-10, Item(-10)));
//     s21_multimap.Insert(std::make_pair(1, Item(1)));
//     s21_multimap.Insert(std::make_pair(5, Item(5)));

//     // std::cout << s21_multimap << '\n';

//     std::multimap<int, Item> multimap;
//     multimap.insert(std::make_pair(4, Item(4)));
//     multimap.insert(std::make_pair(6, Item(6)));
//     multimap.insert(std::make_pair(7, Item(7)));
//     multimap.insert(std::make_pair(7, Item(7)));
//     multimap.insert(std::make_pair(8, Item(8)));
//     multimap.insert(std::make_pair(-1, Item(-1)));
//     multimap.insert(std::make_pair(-10, Item(-10)));
//     multimap.insert(std::make_pair(1, Item(1)));
//     multimap.insert(std::make_pair(5, Item(5)));
    
//     s21::MultiMap<int, Item>::reverse_iterator s21_it = multimap.rend();
//     std::multimap<int, Item>::reverse_iterator it = multimap.rend();

//     // for (auto s21_it = s21_multimap.rbegin(); s21_it != s21_multimap.rend(); ++s21_it)
//     //     std::cout << (*s21_it).first << " : " << (*s21_it).second << "\n";

//     s21_it--;
//     it--;

//     while (s21_it != s21_multimap.rbegin() || it != multimap.rbegin()) 
//         EXPECT_EQ(*(s21_it--), *(it--));

// }

TEST(Map, T0ReverseIteratorOperatorPlusPost)
{
    s21::MultiMap<int, Item> s21_multimap;
    s21_multimap.Insert(std::make_pair(4, Item(4)));
    s21_multimap.Insert(std::make_pair(6, Item(6)));
    s21_multimap.Insert(std::make_pair(7, Item(7)));
    s21_multimap.Insert(std::make_pair(7, Item(7)));
    s21_multimap.Insert(std::make_pair(8, Item(8)));
    s21_multimap.Insert(std::make_pair(-1, Item(-1)));
    s21_multimap.Insert(std::make_pair(-10, Item(-10)));
    s21_multimap.Insert(std::make_pair(1, Item(1)));
    s21_multimap.Insert(std::make_pair(5, Item(5)));

    // std::cout << s21_multimap << '\n';

    std::multimap<int, Item> multimap;
    multimap.insert(std::make_pair(4, Item(4)));
    multimap.insert(std::make_pair(6, Item(6)));
    multimap.insert(std::make_pair(7, Item(7)));
    multimap.insert(std::make_pair(7, Item(7)));
    multimap.insert(std::make_pair(8, Item(8)));
    multimap.insert(std::make_pair(-1, Item(-1)));
    multimap.insert(std::make_pair(-10, Item(-10)));
    multimap.insert(std::make_pair(1, Item(1)));
    multimap.insert(std::make_pair(5, Item(5)));
    
    s21::MultiMap<int, Item>::reverse_iterator s21_it = s21_multimap.rbegin();
    std::multimap<int, Item>::reverse_iterator it = multimap.rbegin();

    for (auto s21_it = s21_multimap.rbegin(); s21_it != s21_multimap.rend(); s21_it++)
        std::cout << (*s21_it).first << " : " << (*s21_it).second << "\n";

    s21_it++;
    it++;

    while (s21_it != s21_multimap.rend() || it != multimap.rend()) 
        EXPECT_EQ(*(s21_it++), *(it++));

}


}  // namespace

// GCOVR_EXCL_STOP
