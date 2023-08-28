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













}; // namespace

// GCOVR_EXCL_STOP