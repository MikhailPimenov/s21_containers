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


TEST(Map, T0Erase)
{
    s21::Map<int, Item> s21_map;
    std::map<int, Item> map;

    s21_map.Insert(std::make_pair(4, Item()));
    s21_map.Insert(std::make_pair(3, Item()));
    s21_map.Insert(std::make_pair(7, Item()));

    std::cout << s21_map << '\n';

    map.insert(std::make_pair(4, Item()));
    map.insert(std::make_pair(3, Item()));
    map.insert(std::make_pair(7, Item()));
    std::cout << "Before erase: \n";
    for (auto it = map.cbegin(); it != map.cend(); ++it)
        std::cout << "{" << it->first << " : " << it->second << "}\n";


    s21_map.Erase(s21_map.cbegin());
    map.erase(map.begin());
    std::cout << "After erase: \n\n";

    // for (auto it = map.cbegin(); it != map.cend(); ++it)
    //     std::cout << "{" << it->first << " : " << it->second << "}\n";

    EXPECT_EQ(s21_map, map);
    EXPECT_TRUE(minimalHeightAVL(s21_map.Size(), s21_map.Height()));
}

TEST(Map, T1Erase)
{
    s21::Map<int, Item> s21_map;
    s21_map.Insert(std::make_pair(4, Item()));
    s21_map.Insert(std::make_pair(3, Item()));
    s21_map.Insert(std::make_pair(5, Item()));

    // EXPECT_EQ(s21_map, map);
}

TEST(Map, T2Erase)
{
    s21::Map<int, Item> s21_map;
    s21_map.Insert(std::make_pair(4, Item()));

    
}







}  // namespace

// GCOVR_EXCL_STOP
