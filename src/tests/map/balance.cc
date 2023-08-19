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


TEST(Map, T0LeftLeftCase)
{
    s21::Map<double, Item> s21_map;
    std::cout << "insert 5.0\n";
    s21_map.Insert(std::make_pair(5.0, Item(5)));
    std::cout << "insert 3.0\n";
    s21_map.Insert(std::make_pair(3.0, Item(5)));
    std::cout << "insert 2.0\n";
    s21_map.Insert(std::make_pair(2.0, Item(5)));

    std::cout << "insert 1.0\n";
    s21_map.Insert(std::make_pair(1.0, Item(5, 'D')));
    std::cout << "insert 2.5\n";
    s21_map.Insert(std::make_pair(2.5, Item(5, 'C')));
    std::cout << "insert 4.0\n";
    s21_map.Insert(std::make_pair(4.0, Item(5, 'B')));
    std::cout << "insert 7.0\n";
    s21_map.Insert(std::make_pair(7.0, Item(5, 'A')));

    std::cout << "leftleft case:\n";
    std::cout << s21_map <<'\n';

    // s21_map.Balance_left_left();

    std::cout << s21_map <<'\n';
}

TEST(Map, T1RightRightCase)
{
    s21::Map<double, Item> s21_map;
    s21_map.Insert(std::make_pair(3.0, Item(5)));
    s21_map.Insert(std::make_pair(5.0, Item(5)));
    s21_map.Insert(std::make_pair(7.0, Item(5)));

    s21_map.Insert(std::make_pair(2.0, Item(5, 'A')));
    s21_map.Insert(std::make_pair(4.0, Item(5, 'B')));
    s21_map.Insert(std::make_pair(6.0, Item(5, 'C')));
    s21_map.Insert(std::make_pair(8.0, Item(5, 'D')));

    
}

TEST(Map, T2LeftRightCase)
{
    s21::Map<double, Item> s21_map;

    s21_map.Insert(std::make_pair(5.0, Item(5)));
    s21_map.Insert(std::make_pair(3.0, Item(5)));
    s21_map.Insert(std::make_pair(4.0, Item(5)));

    s21_map.Insert(std::make_pair(6.0, Item(5, 'A')));
    s21_map.Insert(std::make_pair(4.5, Item(5, 'D')));
    s21_map.Insert(std::make_pair(3.5, Item(5, 'C')));
    s21_map.Insert(std::make_pair(2.5, Item(5, 'B')));



    
}

TEST(Map, T3RightLeftCase)
{
    s21::Map<double, Item> s21_map;

    s21_map.Insert(std::make_pair(3.0, Item(5)));
    s21_map.Insert(std::make_pair(5.0, Item(5)));
    s21_map.Insert(std::make_pair(4.0, Item(5)));

    s21_map.Insert(std::make_pair(2.5, Item(5, 'A')));
    s21_map.Insert(std::make_pair(3.5, Item(5, 'D')));
    s21_map.Insert(std::make_pair(4.5, Item(5, 'C')));
    s21_map.Insert(std::make_pair(5.5, Item(5, 'B')));



    
}





}  // namespace

// GCOVR_EXCL_STOP
