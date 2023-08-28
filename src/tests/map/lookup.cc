#include <gtest/gtest.h>

#include <map>

#include "../../s21_map.h"
#include "../item.h"
#include "../map_helpers.h"

// GCOVR_EXCL_START

class Item2 {
private:
    int a_;
public:


    friend std::ostream& operator<<(std::ostream& out, const Item2& object) {
        out << "Item2(" << object.a_ << ')';
        return out;
    }

};

bool operator==(const Item2& left, const Item2& right) {
    return false;
}

bool operator!=(const Item2& left, const Item2& right) {
    return false;
}

namespace
{



TEST(Map, T0Find)
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


    const auto s21_it = s21_map.Find(7);
    const auto it = map.find(7);



    EXPECT_EQ(*s21_it, *it);
    EXPECT_EQ(s21_map, map);
}

TEST(Map, T1Find)
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


    const auto s21_it = s21_map.Find(4);
    const auto it = map.find(4);


    EXPECT_EQ(*s21_it, *it);
    EXPECT_EQ(s21_map, map);
}

TEST(Map, T2Find)
{

    s21::Map<int, Item> s21_map;
    s21_map.Insert(std::make_pair(4, Item(4)));
    s21_map.Insert(std::make_pair(5, Item(5)));
    s21_map.Insert(std::make_pair(6, Item(6)));
    s21_map.Insert(std::make_pair(7, Item(7)));
    s21_map.Insert(std::make_pair(1, Item(1)));

    std::map<int, Item> map;
    map.insert(std::make_pair(4, Item(4)));
    map.insert(std::make_pair(5, Item(5)));
    map.insert(std::make_pair(6, Item(6)));
    map.insert(std::make_pair(7, Item(7)));
    map.insert(std::make_pair(1, Item(1)));


    const auto s21_it = s21_map.Find(1);
    const auto it = map.find(1);


    EXPECT_EQ(*s21_it, *it);
    EXPECT_EQ(s21_map, map);
}

TEST(Map, T3Find)
{

    s21::Map<int, Item> s21_map;
    s21_map.Insert(std::make_pair(4, Item(4)));
    s21_map.Insert(std::make_pair(5, Item(5)));
    s21_map.Insert(std::make_pair(6, Item(6)));
    s21_map.Insert(std::make_pair(7, Item(7)));
    s21_map.Insert(std::make_pair(1, Item(1)));

    std::map<int, Item> map;
    map.insert(std::make_pair(4, Item(4)));
    map.insert(std::make_pair(5, Item(5)));
    map.insert(std::make_pair(6, Item(6)));
    map.insert(std::make_pair(7, Item(7)));
    map.insert(std::make_pair(1, Item(1)));


    const auto s21_it = s21_map.Find(6);
    const auto it = map.find(6);


    EXPECT_EQ(*s21_it, *it);
    EXPECT_EQ(s21_map, map);
}

TEST(Map, T4FindEnd)
{
    s21::Map<int, Item> s21_map;
    s21_map.Insert(std::make_pair(4, Item(4)));
    s21_map.Insert(std::make_pair(5, Item(5)));
    s21_map.Insert(std::make_pair(6, Item(6)));
    s21_map.Insert(std::make_pair(7, Item(7)));
    s21_map.Insert(std::make_pair(1, Item(1)));

    std::map<int, Item> map;
    map.insert(std::make_pair(4, Item(4)));
    map.insert(std::make_pair(5, Item(5)));
    map.insert(std::make_pair(6, Item(6)));
    map.insert(std::make_pair(7, Item(7)));
    map.insert(std::make_pair(1, Item(1)));


    const auto s21_it = s21_map.Find(99);
    const auto it = map.find(99);


    EXPECT_EQ(s21_it, s21_map.end());
    EXPECT_EQ(it, map.end());
    EXPECT_EQ(s21_map, map);
}


TEST(Map, T0Contains)
{
    s21::Map<int, Item> s21_map;
    s21_map.Insert(std::make_pair(4, Item(4)));
    s21_map.Insert(std::make_pair(5, Item(5)));
    s21_map.Insert(std::make_pair(6, Item(6)));
    s21_map.Insert(std::make_pair(7, Item(7)));
    s21_map.Insert(std::make_pair(1, Item(1)));

    EXPECT_EQ(s21_map.Contains(4), true);
}

TEST(Map, T1Contains)
{
    s21::Map<int, Item> s21_map;
    s21_map.Insert(std::make_pair(4, Item(4)));
    s21_map.Insert(std::make_pair(5, Item(5)));
    s21_map.Insert(std::make_pair(6, Item(6)));
    s21_map.Insert(std::make_pair(7, Item(7)));
    s21_map.Insert(std::make_pair(1, Item(1)));

    EXPECT_EQ(s21_map.Contains(5), true);
}

TEST(Map, T2Contains)
{
    s21::Map<int, Item> s21_map;
    s21_map.Insert(std::make_pair(4, Item(4)));
    s21_map.Insert(std::make_pair(5, Item(5)));
    s21_map.Insert(std::make_pair(6, Item(6)));
    s21_map.Insert(std::make_pair(7, Item(7)));
    s21_map.Insert(std::make_pair(1, Item(1)));

    EXPECT_EQ(s21_map.Contains(6), true);
}

TEST(Map, T3Contains)
{
    s21::Map<int, Item> s21_map;
    s21_map.Insert(std::make_pair(4, Item(4)));
    s21_map.Insert(std::make_pair(5, Item(5)));
    s21_map.Insert(std::make_pair(6, Item(6)));
    s21_map.Insert(std::make_pair(7, Item(7)));
    s21_map.Insert(std::make_pair(1, Item(1)));

    EXPECT_EQ(s21_map.Contains(7), true);
}

TEST(Map, T4Contains)
{
    s21::Map<int, Item> s21_map;
    s21_map.Insert(std::make_pair(4, Item(4)));
    s21_map.Insert(std::make_pair(5, Item(5)));
    s21_map.Insert(std::make_pair(6, Item(6)));
    s21_map.Insert(std::make_pair(7, Item(7)));
    s21_map.Insert(std::make_pair(1, Item(1)));

    EXPECT_EQ(s21_map.Contains(1), true);
}


TEST(Map, T5ContainsNo)
{
    s21::Map<int, Item> s21_map;
    s21_map.Insert(std::make_pair(4, Item(4)));
    s21_map.Insert(std::make_pair(5, Item(5)));
    s21_map.Insert(std::make_pair(6, Item(6)));
    s21_map.Insert(std::make_pair(7, Item(7)));
    s21_map.Insert(std::make_pair(1, Item(1)));

    EXPECT_EQ(s21_map.Contains(99), false);
}


TEST(Map, T6ContainsEmpty)
{
    s21::Map<int, Item> s21_map;
    EXPECT_EQ(s21_map.Contains(99), false);
}

}; // namespace

// GCOVR_EXCL_STOP