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

TEST(Map, T3RandomErase)
{
    // return;
    s21::Map<int, Item> s21_map;

    s21_map.Insert(std::make_pair(3, Item(3)));
    s21_map.Insert(std::make_pair(5, Item(5)));
    s21_map.Insert(std::make_pair(5, Item(5)));
    s21_map.Insert(std::make_pair(4, Item(4)));

    s21_map.Insert(std::make_pair(14, Item(14)));
    s21_map.Insert(std::make_pair(11, Item(11)));
    s21_map.Insert(std::make_pair(7, Item(7)));
    s21_map.Insert(std::make_pair(8, Item(8)));
    s21_map.Insert(std::make_pair(-8, Item(-8)));
    s21_map.Insert(std::make_pair(7, Item(7)));
    s21_map.Insert(std::make_pair(-18, Item(-18)));
    s21_map.Insert(std::make_pair(6, Item(6)));
    s21_map.Insert(std::make_pair(3, Item(3)));
    s21_map.Insert(std::make_pair(29, Item(29)));
    s21_map.Insert(std::make_pair(30, Item(30)));
    s21_map.Insert(std::make_pair(31, Item(31)));
    s21_map.Insert(std::make_pair(34, Item(34)));
    s21_map.Insert(std::make_pair(37, Item(37)));


    std::map<int, Item> map;

    map.insert(std::make_pair(3, Item(3)));
    map.insert(std::make_pair(5, Item(5)));
    map.insert(std::make_pair(5, Item(5)));
    map.insert(std::make_pair(4, Item(4)));

    map.insert(std::make_pair(14, Item(14)));
    map.insert(std::make_pair(11, Item(11)));
    map.insert(std::make_pair(7, Item(7)));
    map.insert(std::make_pair(8, Item(8)));
    map.insert(std::make_pair(-8, Item(-8)));
    map.insert(std::make_pair(7, Item(7)));
    map.insert(std::make_pair(-18, Item(-18)));
    map.insert(std::make_pair(6, Item(6)));
    map.insert(std::make_pair(3, Item(3)));
    map.insert(std::make_pair(29, Item(29)));
    map.insert(std::make_pair(30, Item(30)));
    map.insert(std::make_pair(31, Item(31)));
    map.insert(std::make_pair(34, Item(34)));
    map.insert(std::make_pair(37, Item(37)));



    // std::cout << s21_map << "\n\n";
    s21::Map<int, Item>::const_iterator s21_it = s21_map.cbegin();
    std::map<int, Item>::const_iterator it = map.cbegin();
    for (int i = 0; i < 7; ++i) {
        ++s21_it;
        ++it;
    }

    s21_map.Erase(s21_it);
    map.erase(it);

    EXPECT_EQ(s21_map, map);
    EXPECT_TRUE(minimalHeightAVL(s21_map.Size(), s21_map.Height()));    
}


TEST(Map, T4RandomErase)
{
    // return;
    s21::Map<int, Item> s21_map;

    s21_map.Insert(std::make_pair(3, Item(3)));
    s21_map.Insert(std::make_pair(5, Item(5)));
    s21_map.Insert(std::make_pair(5, Item(5)));
    s21_map.Insert(std::make_pair(4, Item(4)));

    s21_map.Insert(std::make_pair(14, Item(14)));
    s21_map.Insert(std::make_pair(11, Item(11)));
    s21_map.Insert(std::make_pair(7, Item(7)));
    s21_map.Insert(std::make_pair(8, Item(8)));
    s21_map.Insert(std::make_pair(-8, Item(-8)));
    s21_map.Insert(std::make_pair(7, Item(7)));
    s21_map.Insert(std::make_pair(-18, Item(-18)));
    s21_map.Insert(std::make_pair(6, Item(6)));
    s21_map.Insert(std::make_pair(3, Item(3)));
    s21_map.Insert(std::make_pair(29, Item(29)));
    s21_map.Insert(std::make_pair(30, Item(30)));
    s21_map.Insert(std::make_pair(31, Item(31)));
    s21_map.Insert(std::make_pair(34, Item(34)));
    s21_map.Insert(std::make_pair(37, Item(37)));


    std::map<int, Item> map;

    map.insert(std::make_pair(3, Item(3)));
    map.insert(std::make_pair(5, Item(5)));
    map.insert(std::make_pair(5, Item(5)));
    map.insert(std::make_pair(4, Item(4)));

    map.insert(std::make_pair(14, Item(14)));
    map.insert(std::make_pair(11, Item(11)));
    map.insert(std::make_pair(7, Item(7)));
    map.insert(std::make_pair(8, Item(8)));
    map.insert(std::make_pair(-8, Item(-8)));
    map.insert(std::make_pair(7, Item(7)));
    map.insert(std::make_pair(-18, Item(-18)));
    map.insert(std::make_pair(6, Item(6)));
    map.insert(std::make_pair(3, Item(3)));
    map.insert(std::make_pair(29, Item(29)));
    map.insert(std::make_pair(30, Item(30)));
    map.insert(std::make_pair(31, Item(31)));
    map.insert(std::make_pair(34, Item(34)));
    map.insert(std::make_pair(37, Item(37)));



    // std::cout << s21_map << "\n\n";
    s21::Map<int, Item>::const_iterator s21_it = s21_map.cbegin();
    std::map<int, Item>::const_iterator it = map.cbegin();
    for (int i = 0; i < 10; ++i) {
        ++s21_it;
        ++it;
    }

    s21_map.Erase(s21_it);
    map.erase(it);

    EXPECT_EQ(s21_map, map);
    EXPECT_TRUE(minimalHeightAVL(s21_map.Size(), s21_map.Height()));    
}

TEST(Map, T5RandomErase)
{
    // return;
    s21::Map<int, Item> s21_map;

    s21_map.Insert(std::make_pair(3, Item(3)));
    s21_map.Insert(std::make_pair(5, Item(5)));
    s21_map.Insert(std::make_pair(5, Item(5)));
    s21_map.Insert(std::make_pair(4, Item(4)));

    s21_map.Insert(std::make_pair(14, Item(14)));
    s21_map.Insert(std::make_pair(11, Item(11)));
    s21_map.Insert(std::make_pair(7, Item(7)));
    s21_map.Insert(std::make_pair(8, Item(8)));
    s21_map.Insert(std::make_pair(-8, Item(-8)));
    s21_map.Insert(std::make_pair(7, Item(7)));
    s21_map.Insert(std::make_pair(-18, Item(-18)));
    s21_map.Insert(std::make_pair(6, Item(6)));
    s21_map.Insert(std::make_pair(3, Item(3)));
    s21_map.Insert(std::make_pair(29, Item(29)));
    s21_map.Insert(std::make_pair(30, Item(30)));
    s21_map.Insert(std::make_pair(31, Item(31)));
    s21_map.Insert(std::make_pair(34, Item(34)));
    s21_map.Insert(std::make_pair(37, Item(37)));


    std::map<int, Item> map;

    map.insert(std::make_pair(3, Item(3)));
    map.insert(std::make_pair(5, Item(5)));
    map.insert(std::make_pair(5, Item(5)));
    map.insert(std::make_pair(4, Item(4)));

    map.insert(std::make_pair(14, Item(14)));
    map.insert(std::make_pair(11, Item(11)));
    map.insert(std::make_pair(7, Item(7)));
    map.insert(std::make_pair(8, Item(8)));
    map.insert(std::make_pair(-8, Item(-8)));
    map.insert(std::make_pair(7, Item(7)));
    map.insert(std::make_pair(-18, Item(-18)));
    map.insert(std::make_pair(6, Item(6)));
    map.insert(std::make_pair(3, Item(3)));
    map.insert(std::make_pair(29, Item(29)));
    map.insert(std::make_pair(30, Item(30)));
    map.insert(std::make_pair(31, Item(31)));
    map.insert(std::make_pair(34, Item(34)));
    map.insert(std::make_pair(37, Item(37)));



    // std::cout << s21_map << "\n\n";
    s21::Map<int, Item>::const_iterator s21_it = s21_map.cbegin();
    std::map<int, Item>::const_iterator it = map.cbegin();
    for (int i = 0; i < 3; ++i) {
        ++s21_it;
        ++it;
    }

    s21_map.Erase(s21_it);
    map.erase(it);

    EXPECT_EQ(s21_map, map);
    EXPECT_TRUE(minimalHeightAVL(s21_map.Size(), s21_map.Height()));    
}

TEST(Map, T6RandomErase)
{
    // return;
    s21::Map<int, Item> s21_map;

    s21_map.Insert(std::make_pair(3, Item(3)));
    s21_map.Insert(std::make_pair(5, Item(5)));
    s21_map.Insert(std::make_pair(5, Item(5)));
    s21_map.Insert(std::make_pair(4, Item(4)));

    s21_map.Insert(std::make_pair(14, Item(14)));
    s21_map.Insert(std::make_pair(11, Item(11)));
    s21_map.Insert(std::make_pair(7, Item(7)));
    s21_map.Insert(std::make_pair(8, Item(8)));
    s21_map.Insert(std::make_pair(-8, Item(-8)));
    s21_map.Insert(std::make_pair(7, Item(7)));
    s21_map.Insert(std::make_pair(-18, Item(-18)));
    s21_map.Insert(std::make_pair(6, Item(6)));
    s21_map.Insert(std::make_pair(3, Item(3)));
    s21_map.Insert(std::make_pair(29, Item(29)));
    s21_map.Insert(std::make_pair(30, Item(30)));
    s21_map.Insert(std::make_pair(31, Item(31)));
    s21_map.Insert(std::make_pair(34, Item(34)));
    s21_map.Insert(std::make_pair(37, Item(37)));


    std::map<int, Item> map;

    map.insert(std::make_pair(3, Item(3)));
    map.insert(std::make_pair(5, Item(5)));
    map.insert(std::make_pair(5, Item(5)));
    map.insert(std::make_pair(4, Item(4)));

    map.insert(std::make_pair(14, Item(14)));
    map.insert(std::make_pair(11, Item(11)));
    map.insert(std::make_pair(7, Item(7)));
    map.insert(std::make_pair(8, Item(8)));
    map.insert(std::make_pair(-8, Item(-8)));
    map.insert(std::make_pair(7, Item(7)));
    map.insert(std::make_pair(-18, Item(-18)));
    map.insert(std::make_pair(6, Item(6)));
    map.insert(std::make_pair(3, Item(3)));
    map.insert(std::make_pair(29, Item(29)));
    map.insert(std::make_pair(30, Item(30)));
    map.insert(std::make_pair(31, Item(31)));
    map.insert(std::make_pair(34, Item(34)));
    map.insert(std::make_pair(37, Item(37)));



    // std::cout << s21_map << "\n\n";
    s21::Map<int, Item>::const_iterator s21_it = s21_map.cbegin();
    std::map<int, Item>::const_iterator it = map.cbegin();
    for (int i = 0; i < 5; ++i) {
        ++s21_it;
        ++it;
    }

    s21_map.Erase(s21_it);
    map.erase(it);

    EXPECT_EQ(s21_map, map);
    EXPECT_TRUE(minimalHeightAVL(s21_map.Size(), s21_map.Height()));    
}

TEST(Map, T7RandomErase)
{
    // return;
    s21::Map<int, Item> s21_map;

    s21_map.Insert(std::make_pair(3, Item(3)));
    s21_map.Insert(std::make_pair(5, Item(5)));
    s21_map.Insert(std::make_pair(5, Item(5)));
    s21_map.Insert(std::make_pair(4, Item(4)));

    s21_map.Insert(std::make_pair(14, Item(14)));
    s21_map.Insert(std::make_pair(11, Item(11)));
    s21_map.Insert(std::make_pair(7, Item(7)));
    s21_map.Insert(std::make_pair(8, Item(8)));
    s21_map.Insert(std::make_pair(-8, Item(-8)));
    s21_map.Insert(std::make_pair(7, Item(7)));
    s21_map.Insert(std::make_pair(-18, Item(-18)));
    s21_map.Insert(std::make_pair(6, Item(6)));
    s21_map.Insert(std::make_pair(3, Item(3)));
    s21_map.Insert(std::make_pair(29, Item(29)));
    s21_map.Insert(std::make_pair(30, Item(30)));
    s21_map.Insert(std::make_pair(31, Item(31)));
    s21_map.Insert(std::make_pair(34, Item(34)));
    s21_map.Insert(std::make_pair(37, Item(37)));


    std::map<int, Item> map;

    map.insert(std::make_pair(3, Item(3)));
    map.insert(std::make_pair(5, Item(5)));
    map.insert(std::make_pair(5, Item(5)));
    map.insert(std::make_pair(4, Item(4)));

    map.insert(std::make_pair(14, Item(14)));
    map.insert(std::make_pair(11, Item(11)));
    map.insert(std::make_pair(7, Item(7)));
    map.insert(std::make_pair(8, Item(8)));
    map.insert(std::make_pair(-8, Item(-8)));
    map.insert(std::make_pair(7, Item(7)));
    map.insert(std::make_pair(-18, Item(-18)));
    map.insert(std::make_pair(6, Item(6)));
    map.insert(std::make_pair(3, Item(3)));
    map.insert(std::make_pair(29, Item(29)));
    map.insert(std::make_pair(30, Item(30)));
    map.insert(std::make_pair(31, Item(31)));
    map.insert(std::make_pair(34, Item(34)));
    map.insert(std::make_pair(37, Item(37)));



    // std::cout << s21_map << "\n\n";
    s21::Map<int, Item>::const_iterator s21_it = s21_map.cbegin();
    std::map<int, Item>::const_iterator it = map.cbegin();
    for (int i = 0; i < 8; ++i) {
        ++s21_it;
        ++it;
    }

    s21_map.Erase(s21_it);
    map.erase(it);

    EXPECT_EQ(s21_map, map);
    EXPECT_TRUE(minimalHeightAVL(s21_map.Size(), s21_map.Height()));    
}




}  // namespace

// GCOVR_EXCL_STOP
