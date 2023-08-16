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


TEST(Map, T0Insert)
{
    s21::Map<int, Item> s21_map;
    s21_map.Insert(std::make_pair(4, Item(4)));
    s21_map.Insert(std::make_pair(6, Item(6)));
    s21_map.Insert(std::make_pair(7, Item(7)));
    s21_map.Insert(std::make_pair(1, Item(1)));

    std::cout << s21_map << '\n';

    std::map<int, Item> map;

    // EXPECT_EQ(s21_map, map);
}

TEST(Map, T1Insert)
{
    s21::Map<int, Item> s21_map;
    s21_map.Insert(std::make_pair(1, Item(1)));
    s21_map.Insert(std::make_pair(4, Item(4)));
    s21_map.Insert(std::make_pair(6, Item(6)));
    s21_map.Insert(std::make_pair(7, Item(7)));

    std::cout << s21_map << '\n';

    std::map<int, Item> map;

    // EXPECT_EQ(s21_map, map);
}

TEST(Map, T2Insert)
{
    s21::Map<int, Item> s21_map;
    s21_map.Insert(std::make_pair(1, Item(1)));

    std::cout << s21_map << '\n';

    std::map<int, Item> map;

    // EXPECT_EQ(s21_map, map);
}


TEST(Map, T3Insert)
{
    s21::Map<int, Item> s21_map;
    s21_map.Insert(std::make_pair(-4, Item(4)));
    s21_map.Insert(std::make_pair(6, Item(6)));
    s21_map.Insert(std::make_pair(7, Item(7)));
    s21_map.Insert(std::make_pair(1, Item(1)));

    std::cout << s21_map << '\n';

    // s21::Map<>::const_iterator s21_it = s21_map.cbegin();

    std::map<int, Item> map;

    // EXPECT_EQ(s21_map, map);
}

TEST(Map, T4Insert)
{
    s21::Map<int, Item> s21_map;
    s21_map.Insert(std::make_pair(-4, Item(4)));
    s21_map.Insert(std::make_pair(-6, Item(6)));
    s21_map.Insert(std::make_pair(-7, Item(7)));
    s21_map.Insert(std::make_pair(-1, Item(1)));

    std::cout << s21_map << '\n';

    std::map<int, Item> map;

    // EXPECT_EQ(s21_map, map);
}

TEST(Map, T5Insert)
{
    s21::Map<int, Item> s21_map;
    s21_map.Insert(std::make_pair(-4, Item(4)));
    s21_map.Insert(std::make_pair(6, Item(6)));
    s21_map.Insert(std::make_pair(0, Item(7)));
    s21_map.Insert(std::make_pair(-1, Item(1)));

    std::cout << s21_map << '\n';

    std::map<int, Item> map;

    // EXPECT_EQ(s21_map, map);
}





}  // namespace

// GCOVR_EXCL_STOP
