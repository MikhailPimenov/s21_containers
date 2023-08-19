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


TEST(Map, T0IteratorOperatorPlus)
{
    s21::Map<int, Item> s21_map;
    s21_map.Insert(std::make_pair(4, Item(4)));
    s21_map.Insert(std::make_pair(6, Item(6)));
    s21_map.Insert(std::make_pair(7, Item(7)));
    s21_map.Insert(std::make_pair(7, Item(7)));
    s21_map.Insert(std::make_pair(8, Item(8)));
    s21_map.Insert(std::make_pair(-1, Item(-1)));
    s21_map.Insert(std::make_pair(-10, Item(-10)));
    s21_map.Insert(std::make_pair(1, Item(1)));
    s21_map.Insert(std::make_pair(5, Item(5)));

    // std::cout << s21_map << '\n';

    std::map<int, Item> map;
    map.insert(std::make_pair(4, Item(4)));
    map.insert(std::make_pair(6, Item(6)));
    map.insert(std::make_pair(7, Item(7)));
    map.insert(std::make_pair(7, Item(7)));
    map.insert(std::make_pair(8, Item(8)));
    map.insert(std::make_pair(-1, Item(-1)));
    map.insert(std::make_pair(-10, Item(-10)));
    map.insert(std::make_pair(1, Item(1)));
    map.insert(std::make_pair(5, Item(5)));
    
    s21::Map<int, Item>::iterator s21_it = s21_map.begin();
    std::map<int, Item>::iterator it = map.begin();

    while (s21_it != s21_map.end() || it != map.end()) {
        EXPECT_EQ(*s21_it, *it);
        ++s21_it;
        ++it;
    }
}

// class Azaza {
//     int _a;
// public:
//     Azaza(int a = 0) : _a{a} {}

// public:
//     // bool operator<(const Azaza& other) const {
//     //     return _a < other._a;
//     // }
// };

TEST(Map, T1IteratorOperatorMinus)
{
    s21::Map<int, Item> s21_map;
    s21_map.Insert(std::make_pair(4, Item(4)));
    s21_map.Insert(std::make_pair(6, Item(6)));
    s21_map.Insert(std::make_pair(7, Item(7)));
    s21_map.Insert(std::make_pair(7, Item(7)));
    s21_map.Insert(std::make_pair(8, Item(8)));
    s21_map.Insert(std::make_pair(-1, Item(-1)));
    s21_map.Insert(std::make_pair(-10, Item(-10)));
    s21_map.Insert(std::make_pair(1, Item(1)));
    s21_map.Insert(std::make_pair(5, Item(5)));

    // std::cout << s21_map << '\n';

    std::map<int, Item> map;
    map.insert(std::make_pair(4, Item(4)));
    map.insert(std::make_pair(6, Item(6)));
    map.insert(std::make_pair(7, Item(7)));
    map.insert(std::make_pair(7, Item(7)));
    map.insert(std::make_pair(8, Item(8)));
    map.insert(std::make_pair(-1, Item(-1)));
    map.insert(std::make_pair(-10, Item(-10)));
    map.insert(std::make_pair(1, Item(1)));
    map.insert(std::make_pair(5, Item(5)));
    
    s21::Map<int, Item>::iterator s21_it = s21_map.end();
    std::map<int, Item>::iterator it = map.end();

    // for (auto s21_it = --s21_map.end(); s21_it != s21_map.begin(); --s21_it)
        // std::cout << (*s21_it).first << " : " << (*s21_it).second << "\n";

    --s21_it;
    --it;

    while (s21_it != s21_map.begin() || it != map.begin()) {
        EXPECT_EQ(*s21_it, *it);
        --s21_it;
        --it;
    }

    // std::map<Azaza, Item> m;
    // m.insert(std::make_pair(Azaza(), Item(44)));
    // m.inserT(Azaza(), Item(44));
}










TEST(Map, T2ReverseIteratorOperatorPlus)
{
    s21::Map<int, Item> s21_map;
    s21_map.Insert(std::make_pair(4, Item(4)));
    s21_map.Insert(std::make_pair(6, Item(6)));
    s21_map.Insert(std::make_pair(7, Item(7)));
    s21_map.Insert(std::make_pair(7, Item(7)));
    s21_map.Insert(std::make_pair(8, Item(8)));
    s21_map.Insert(std::make_pair(-1, Item(-1)));
    s21_map.Insert(std::make_pair(-10, Item(-10)));
    s21_map.Insert(std::make_pair(1, Item(1)));
    s21_map.Insert(std::make_pair(5, Item(5)));

    // std::cout << s21_map << '\n';

    std::map<int, Item> map;
    map.insert(std::make_pair(4, Item(4)));
    map.insert(std::make_pair(6, Item(6)));
    map.insert(std::make_pair(7, Item(7)));
    map.insert(std::make_pair(7, Item(7)));
    map.insert(std::make_pair(8, Item(8)));
    map.insert(std::make_pair(-1, Item(-1)));
    map.insert(std::make_pair(-10, Item(-10)));
    map.insert(std::make_pair(1, Item(1)));
    map.insert(std::make_pair(5, Item(5)));
    
    s21::Map<int, Item>::reverse_iterator s21_it = s21_map.rbegin();
    std::map<int, Item>::reverse_iterator it = map.rbegin();

    while (s21_it != s21_map.rend() || it != map.rend()) {
        EXPECT_EQ(*s21_it, *it);
        ++s21_it;
        ++it;
    }
}

TEST(Map, T3ReverseIteratorOperatorMinus)
{
    s21::Map<int, Item> s21_map;
    s21_map.Insert(std::make_pair(4, Item(4)));
    s21_map.Insert(std::make_pair(6, Item(6)));
    s21_map.Insert(std::make_pair(7, Item(7)));
    s21_map.Insert(std::make_pair(7, Item(7)));
    s21_map.Insert(std::make_pair(8, Item(8)));
    s21_map.Insert(std::make_pair(-1, Item(-1)));
    s21_map.Insert(std::make_pair(-10, Item(-10)));
    s21_map.Insert(std::make_pair(1, Item(1)));
    s21_map.Insert(std::make_pair(5, Item(5)));

    // std::cout << s21_map << '\n';

    std::map<int, Item> map;
    map.insert(std::make_pair(4, Item(4)));
    map.insert(std::make_pair(6, Item(6)));
    map.insert(std::make_pair(7, Item(7)));
    map.insert(std::make_pair(7, Item(7)));
    map.insert(std::make_pair(8, Item(8)));
    map.insert(std::make_pair(-1, Item(-1)));
    map.insert(std::make_pair(-10, Item(-10)));
    map.insert(std::make_pair(1, Item(1)));
    map.insert(std::make_pair(5, Item(5)));
    
    s21::Map<int, Item>::reverse_iterator s21_it = s21_map.rend();
    std::map<int, Item>::reverse_iterator it = map.rend();

    for (auto s21_it = s21_map.rbegin(); s21_it != s21_map.rend(); ++s21_it)
        std::cout << (*s21_it).first << " : " << (*s21_it).second << "\n";

    --s21_it;
    --it;

    while (s21_it != s21_map.rbegin() || it != map.rbegin()) {
        EXPECT_EQ(*s21_it, *it);
        --s21_it;
        --it;
    }
}



}  // namespace

// GCOVR_EXCL_STOP
