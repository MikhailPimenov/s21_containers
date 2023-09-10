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

    std::map<int, Item> map;
    map.insert(std::make_pair(4, Item(4)));
    map.insert(std::make_pair(6, Item(6)));
    map.insert(std::make_pair(7, Item(7)));
    map.insert(std::make_pair(1, Item(1)));

    EXPECT_EQ(s21_map, map);
}

TEST(Map, T1Insert)
{
    s21::Map<int, Item> s21_map;
    s21_map.Insert(std::make_pair(1, Item(1)));
    s21_map.Insert(std::make_pair(4, Item(4)));
    s21_map.Insert(std::make_pair(6, Item(6)));
    s21_map.Insert(std::make_pair(7, Item(7)));

    std::map<int, Item> map;
    map.insert(std::make_pair(1, Item(1)));
    map.insert(std::make_pair(4, Item(4)));
    map.insert(std::make_pair(6, Item(6)));
    map.insert(std::make_pair(7, Item(7)));

    EXPECT_EQ(s21_map, map);
}

TEST(Map, T2Insert)
{
    s21::Map<int, Item> s21_map;
    s21_map.Insert(std::make_pair(1, Item(1)));


    std::map<int, Item> map;
    map.insert(std::make_pair(1, Item(1)));

    EXPECT_EQ(s21_map, map);
}


TEST(Map, T3Insert)
{
    s21::Map<int, Item> s21_map;
    s21_map.Insert(std::make_pair(-4, Item(4)));
    s21_map.Insert(std::make_pair(6, Item(6)));
    s21_map.Insert(std::make_pair(7, Item(7)));
    s21_map.Insert(std::make_pair(1, Item(1)));

    std::map<int, Item> map;
    map.insert(std::make_pair(-4, Item(4)));
    map.insert(std::make_pair(6, Item(6)));
    map.insert(std::make_pair(7, Item(7)));
    map.insert(std::make_pair(1, Item(1)));

    EXPECT_EQ(s21_map, map);
}

TEST(Map, T4Insert)
{
    s21::Map<int, Item> s21_map;
    s21_map.Insert(std::make_pair(-4, Item(4)));
    s21_map.Insert(std::make_pair(-6, Item(6)));
    s21_map.Insert(std::make_pair(-7, Item(7)));
    s21_map.Insert(std::make_pair(-1, Item(1)));

    std::map<int, Item> map;
    map.insert(std::make_pair(-4, Item(4)));
    map.insert(std::make_pair(-6, Item(6)));
    map.insert(std::make_pair(-7, Item(7)));
    map.insert(std::make_pair(-1, Item(1)));

    EXPECT_EQ(s21_map, map);
}

TEST(Map, T5Insert)
{
    s21::Map<int, Item> s21_map;
    s21_map.Insert(std::make_pair(-4, Item(4)));
    s21_map.Insert(std::make_pair(6, Item(6)));
    s21_map.Insert(std::make_pair(0, Item(7)));
    s21_map.Insert(std::make_pair(-1, Item(1)));

    std::map<int, Item> map;
    map.insert(std::make_pair(-4, Item(4)));
    map.insert(std::make_pair(6, Item(6)));
    map.insert(std::make_pair(0, Item(7)));
    map.insert(std::make_pair(-1, Item(1)));

    EXPECT_EQ(s21_map, map);
}












TEST(Map, T0Clear)
{
    s21::Map<int, Item> s21_map {
        {10, Item(10, 'a', 0.1)},
        {20, Item(20, 'b', 0.2)},
        {30, Item(30, 'c', 0.3)},
        {40, Item(40, 'd', 0.4)},
        {50, Item(50, 'e', 0.5)},
        {60, Item(60, 'f', 0.6)},
        {70, Item(70, 'g', 0.7)},
        {80, Item(80, 'h', 0.8)},
        {90, Item(90, 'i', 0.9)},
    };

    std::map<int, Item> map {
        {10, Item(10, 'a', 0.1)},
        {20, Item(20, 'b', 0.2)},
        {30, Item(30, 'c', 0.3)},
        {40, Item(40, 'd', 0.4)},
        {50, Item(50, 'e', 0.5)},
        {60, Item(60, 'f', 0.6)},
        {70, Item(70, 'g', 0.7)},
        {80, Item(80, 'h', 0.8)},
        {90, Item(90, 'i', 0.9)},
    };

    s21_map.Clear();
    map.clear();

    EXPECT_EQ(s21_map, map);
}

TEST(Map, T1ClearEmpty)
{
    s21::Map<int, Item> s21_map;
    std::map<int, Item> map;

    s21_map.Clear();
    map.clear();

    EXPECT_EQ(s21_map, map);
}










}  // namespace

// GCOVR_EXCL_STOP
