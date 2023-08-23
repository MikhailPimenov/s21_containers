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

    // EXPECT_EQ(s21_map, map);
}

TEST(Map, T2Destructor)
{
    s21::Map<int, Item> s21_map;
    s21_map.Insert(std::make_pair(4, Item()));

    // EXPECT_EQ(s21_map, map);
}







}  // namespace

// GCOVR_EXCL_STOP
