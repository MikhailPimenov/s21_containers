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


    auto s21_it = s21_map.Find(7);
    auto it = map.find(7);



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

TEST(Map, T5FindConst)
{
    const s21::Map<int, Item> s21_map {
        {1, Item(1, 'a', 0.1)},
        {2, Item(2, 'b', 0.2)},
        {3, Item(3, 'c', 0.3)},
        {4, Item(4, 'd', 0.4)},
        {5, Item(5, 'e', 0.5)},
        {6, Item(6, 'f', 0.6)},
    };
    const std::map<int, Item> map {
        {1, Item(1, 'a', 0.1)},
        {2, Item(2, 'b', 0.2)},
        {3, Item(3, 'c', 0.3)},
        {4, Item(4, 'd', 0.4)},
        {5, Item(5, 'e', 0.5)},
        {6, Item(6, 'f', 0.6)},
    };

    EXPECT_EQ(*s21_map.Find(3), *map.find(3));
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

TEST(Map, T7ContainsNo)
{
    const s21::Map<int, Item> s21_map {
        {1, Item(1, 'a', 0.1)},
        {2, Item(2, 'b', 0.2)},
        {3, Item(3, 'c', 0.3)},
        {4, Item(4, 'd', 0.4)},
        {5, Item(5, 'e', 0.5)},
        {6, Item(6, 'f', 0.6)},
    };

    
    EXPECT_EQ(s21_map.Contains(99), false);
}

TEST(Map, T8Contains)
{
    const s21::Map<int, Item> s21_map {
        {1, Item(1, 'a', 0.1)},
        {2, Item(2, 'b', 0.2)},
        {3, Item(3, 'c', 0.3)},
        {4, Item(4, 'd', 0.4)},
        {5, Item(5, 'e', 0.5)},
        {6, Item(6, 'f', 0.6)},
    };

    EXPECT_EQ(s21_map.Contains(3), true);
}

TEST(Map, T0LowerBound)
{
    const s21::Map<int, Item> s21_map {
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

    const std::map<int, Item> map {
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



    EXPECT_EQ(*s21_map.Lower_bound(5), *map.lower_bound(5));
}

TEST(Map, T1LowerBound)
{
    const s21::Map<int, Item> s21_map {
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

    const std::map<int, Item> map {
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



    EXPECT_EQ(*s21_map.Lower_bound(15), *map.lower_bound(15));
}

TEST(Map, T2LowerBound)
{
    const s21::Map<int, Item> s21_map {
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

    const std::map<int, Item> map {
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

    EXPECT_EQ(*s21_map.Lower_bound(25), *map.lower_bound(25));
}

TEST(Map, T3LowerBound)
{
    const s21::Map<int, Item> s21_map {
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

    const std::map<int, Item> map {
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

    EXPECT_EQ(*s21_map.Lower_bound(35), *map.lower_bound(35));
}

TEST(Map, T4LowerBound)
{
    const s21::Map<int, Item> s21_map {
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

    const std::map<int, Item> map {
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

    EXPECT_EQ(*s21_map.Lower_bound(45), *map.lower_bound(45));
}

TEST(Map, T5LowerBound)
{
    const s21::Map<int, Item> s21_map {
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

    const std::map<int, Item> map {
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

    EXPECT_EQ(*s21_map.Lower_bound(55), *map.lower_bound(55));
}

TEST(Map, T6LowerBound)
{
    const s21::Map<int, Item> s21_map {
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

    const std::map<int, Item> map {
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

    EXPECT_EQ(*s21_map.Lower_bound(65), *map.lower_bound(65));
}

TEST(Map, T7LowerBound)
{
    const s21::Map<int, Item> s21_map {
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

    const std::map<int, Item> map {
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

    EXPECT_EQ(*s21_map.Lower_bound(75), *map.lower_bound(75));
}

TEST(Map, T8LowerBound)
{
    const s21::Map<int, Item> s21_map {
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

    const std::map<int, Item> map {
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

    EXPECT_EQ(*s21_map.Lower_bound(85), *map.lower_bound(85));
}

TEST(Map, T9LowerBound)
{
    const s21::Map<int, Item> s21_map {
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

    const std::map<int, Item> map {
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

    EXPECT_EQ(s21_map.Lower_bound(95), s21_map.end()); 
    EXPECT_EQ(map.lower_bound(95), map.end());
}

TEST(Map, T10LowerBound)
{
    const s21::Map<int, Item> s21_map {
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

    const std::map<int, Item> map {
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

    EXPECT_EQ(s21_map.Lower_bound(105), s21_map.end()); 
    EXPECT_EQ(map.lower_bound(105), map.end());
}

TEST(Map, T11LowerBound)
{
    const s21::Map<int, Item> s21_map {
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

    const std::map<int, Item> map {
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

    EXPECT_EQ(*s21_map.Lower_bound(10), *map.lower_bound(10));
}

TEST(Map, T12LowerBound)
{
    const s21::Map<int, Item> s21_map {
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

    const std::map<int, Item> map {
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

    EXPECT_EQ(*s21_map.Lower_bound(20), *map.lower_bound(20));
}

TEST(Map, T13LowerBound)
{
    const s21::Map<int, Item> s21_map {
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

    const std::map<int, Item> map {
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

    EXPECT_EQ(*s21_map.Lower_bound(30), *map.lower_bound(30));
}

TEST(Map, T0UpperBound)
{
    const s21::Map<int, Item> s21_map {
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

    const std::map<int, Item> map {
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

    // std::cout << s21_map.Upper_bound(30) << '\n';

    EXPECT_EQ(*s21_map.Upper_bound(30), *map.upper_bound(30));
}

TEST(Map, T1UpperBound)
{
    const s21::Map<int, Item> s21_map {
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

    const std::map<int, Item> map {
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

    // std::cout << s21_map.Upper_bound(30) << '\n';

    EXPECT_EQ(*s21_map.Upper_bound(25), *map.upper_bound(25));
}

TEST(Map, T2UpperBound)
{
    const s21::Map<int, Item> s21_map {
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

    const std::map<int, Item> map {
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

    EXPECT_EQ(*s21_map.Upper_bound(25), *map.upper_bound(25));
}

TEST(Map, T3UpperBound)
{
    const s21::Map<int, Item> s21_map {
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

    const std::map<int, Item> map {
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

    EXPECT_EQ(*s21_map.Upper_bound(35), *map.upper_bound(35));
}

TEST(Map, T4UpperBound)
{
    const s21::Map<int, Item> s21_map {
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

    const std::map<int, Item> map {
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

    EXPECT_EQ(*s21_map.Upper_bound(45), *map.upper_bound(45));
}

TEST(Map, T5UpperBound)
{
    const s21::Map<int, Item> s21_map {
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

    const std::map<int, Item> map {
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

    EXPECT_EQ(*s21_map.Upper_bound(55), *map.upper_bound(55));
}

TEST(Map, T6UpperBound)
{
    const s21::Map<int, Item> s21_map {
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

    const std::map<int, Item> map {
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

    EXPECT_EQ(*s21_map.Upper_bound(65), *map.upper_bound(65));
}

TEST(Map, T7UpperBound)
{
    const s21::Map<int, Item> s21_map {
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

    const std::map<int, Item> map {
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

    EXPECT_EQ(*s21_map.Upper_bound(75), *map.upper_bound(75));
}

TEST(Map, T8UpperBound)
{
    const s21::Map<int, Item> s21_map {
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

    const std::map<int, Item> map {
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

    EXPECT_EQ(*s21_map.Upper_bound(85), *map.upper_bound(85));
}

TEST(Map, T9UpperBound)
{
    const s21::Map<int, Item> s21_map {
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

    const std::map<int, Item> map {
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

    EXPECT_EQ(s21_map.Upper_bound(95), s21_map.end()); 
    EXPECT_EQ(map.upper_bound(95), map.end());
}

TEST(Map, T10UpperBound)
{
    const s21::Map<int, Item> s21_map {
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

    const std::map<int, Item> map {
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

    EXPECT_EQ(s21_map.Upper_bound(105), s21_map.end()); 
    EXPECT_EQ(map.upper_bound(105), map.end());
}

TEST(Map, T11UpperBound)
{
    const s21::Map<int, Item> s21_map {
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

    const std::map<int, Item> map {
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

    EXPECT_EQ(*s21_map.Upper_bound(10), *map.upper_bound(10));
}

TEST(Map, T12UpperBound)
{
    const s21::Map<int, Item> s21_map {
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

    const std::map<int, Item> map {
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

    EXPECT_EQ(*s21_map.Upper_bound(20), *map.upper_bound(20));
}

TEST(Map, T13UpperBound)
{
    const s21::Map<int, Item> s21_map {
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

    const std::map<int, Item> map {
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

    EXPECT_EQ(*s21_map.Upper_bound(30), *map.upper_bound(30));
}








TEST(Map, T0EqualRangeEnd)
{
    const s21::Map<int, Item> s21_map {
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

    const std::map<int, Item> map {
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

    const auto s21_pair = s21_map.Equal_range(105);
    const auto pair = map.equal_range(105);

    EXPECT_EQ(s21_pair.first, s21_map.end()); 
    EXPECT_EQ(s21_pair.second, s21_map.end()); 
    EXPECT_EQ(pair.first, map.end()); 
    EXPECT_EQ(pair.second, map.end()); 
}

TEST(Map, T1EqualRangeEnd)
{
    const s21::Map<int, Item> s21_map {
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

    const std::map<int, Item> map {
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

    const auto s21_pair = s21_map.Equal_range(500);
    const auto pair = map.equal_range(500);

    EXPECT_EQ(s21_pair.first, s21_map.end()); 
    EXPECT_EQ(s21_pair.second, s21_map.end()); 
    EXPECT_EQ(pair.first, map.end()); 
    EXPECT_EQ(pair.second, map.end()); 
}

TEST(Map, T2EqualRange)
{
    const s21::Map<int, Item> s21_map {
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

    const std::map<int, Item> map {
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

    const auto s21_pair = s21_map.Equal_range(10);
    const auto pair = map.equal_range(10);

    EXPECT_EQ(*(s21_pair.first), *(pair.first)); 
    EXPECT_EQ(*(s21_pair.second), *(pair.second)); 
}

TEST(Map, T3EqualRange)
{
    const s21::Map<int, Item> s21_map {
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

    const std::map<int, Item> map {
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

    const auto s21_pair = s21_map.Equal_range(20);
    const auto pair = map.equal_range(20);

    EXPECT_EQ(*(s21_pair.first), *(pair.first)); 
    EXPECT_EQ(*(s21_pair.second), *(pair.second)); 
}

TEST(Map, T4EqualRange)
{
    const s21::Map<int, Item> s21_map {
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

    const std::map<int, Item> map {
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

    const auto s21_pair = s21_map.Equal_range(30);
    const auto pair = map.equal_range(30);

    EXPECT_EQ(*(s21_pair.first), *(pair.first)); 
    EXPECT_EQ(*(s21_pair.second), *(pair.second)); 
}

TEST(Map, T5EqualRange)
{
    const s21::Map<int, Item> s21_map {
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

    const std::map<int, Item> map {
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

    const auto s21_pair = s21_map.Equal_range(35);
    const auto pair = map.equal_range(35);

    EXPECT_EQ(*(s21_pair.first), *(pair.first)); 
    EXPECT_EQ(*(s21_pair.second), *(pair.second)); 
}

TEST(Map, T6EqualRange)
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

    const auto s21_pair = s21_map.Equal_range(40);
    const auto pair = map.equal_range(40);

    EXPECT_EQ(*(s21_pair.first), *(pair.first)); 
    EXPECT_EQ(*(s21_pair.second), *(pair.second)); 
}

TEST(Map, T7EqualRange)
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

    const auto s21_pair = s21_map.Equal_range(45);
    const auto pair = map.equal_range(45);

    EXPECT_EQ(*(s21_pair.first), *(pair.first)); 
    EXPECT_EQ(*(s21_pair.second), *(pair.second)); 
}

TEST(Map, T8EqualRange)
{
    const s21::Map<int, Item> s21_map {
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

    const std::map<int, Item> map {
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

    const auto s21_pair = s21_map.Equal_range(50);
    const auto pair = map.equal_range(50);

    EXPECT_EQ(*(s21_pair.first), *(pair.first)); 
    EXPECT_EQ(*(s21_pair.second), *(pair.second)); 

    // s21::BaseNode b;
    // s21::SingleNode s;
    // s21::MultiNode m;
}







}; // namespace

// GCOVR_EXCL_STOP