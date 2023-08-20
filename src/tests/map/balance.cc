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
    // return;
    // std::cout << "leftleft case:\n";
    s21::Map<double, Item> s21_map;
    std::cout << "insert 5.0\n";
    s21_map.Insert(std::make_pair(5.0, Item(5)));
    std::cout << s21_map <<'\n';
    std::cout << "insert 3.0\n";
    s21_map.Insert(std::make_pair(3.0, Item(5)));
    std::cout << s21_map <<'\n';
    std::cout << "insert 2.0\n";
    s21_map.Insert(std::make_pair(2.0, Item(5)));
    std::cout << s21_map <<'\n';

    std::cout << "insert 1.0\n";
    s21_map.Insert(std::make_pair(1.0, Item(5, 'D')));
    std::cout << s21_map <<'\n';
    std::cout << "insert 2.5\n";
    s21_map.Insert(std::make_pair(2.5, Item(5, 'C')));
    std::cout << s21_map <<'\n';
    std::cout << "insert 4.0\n";
    s21_map.Insert(std::make_pair(4.0, Item(5, 'B')));
    std::cout << s21_map <<'\n';
    std::cout << "insert 7.0\n";
    s21_map.Insert(std::make_pair(7.0, Item(5, 'A')));
    std::cout << s21_map <<'\n';


    EXPECT_TRUE(minimalHeight(s21_map.Size(), s21_map.Height()));    
}

TEST(Map, T1RightRightCase)
{
    // return;
    s21::Map<double, Item> s21_map;
    // std::cout << "rightright case:\n";
    std::cout << "insert 3.0\n";
    s21_map.Insert(std::make_pair(3.0, Item(5)));
    std::cout << s21_map <<'\n';
    std::cout << "insert 5.0\n";
    s21_map.Insert(std::make_pair(5.0, Item(5)));
    std::cout << s21_map <<'\n';
    std::cout << "insert 7.0\n";
    s21_map.Insert(std::make_pair(7.0, Item(5)));
    std::cout << s21_map <<'\n';

    std::cout << "insert 2.5\n";
    s21_map.Insert(std::make_pair(2.5, Item(5, 'A')));
    std::cout << s21_map <<'\n';
    std::cout << "insert 4.5\n";
    s21_map.Insert(std::make_pair(4.5, Item(5, 'B')));
    std::cout << s21_map <<'\n';
    std::cout << "insert 6.5\n";
    s21_map.Insert(std::make_pair(6.5, Item(5, 'C')));
    std::cout << s21_map <<'\n';
    std::cout << "insert 7.5\n";
    s21_map.Insert(std::make_pair(7.5, Item(5, 'D')));
    std::cout << s21_map <<'\n';

    
    EXPECT_TRUE(minimalHeight(s21_map.Size(), s21_map.Height()));    
}

TEST(Map, T2LeftRightCase)
{
    // return;
    s21::Map<double, Item> s21_map;

    std::cout << "insert 5.0\n";
    s21_map.Insert(std::make_pair(5.0, Item(5)));
    std::cout << s21_map << "\n\n";
    std::cout << "insert 3.0\n";
    s21_map.Insert(std::make_pair(3.0, Item(5)));
    std::cout << s21_map << "\n\n";
    std::cout << "insert 4.0\n";
    s21_map.Insert(std::make_pair(4.0, Item(5)));
    std::cout << s21_map << "\n\n";

    std::cout << "insert 5.5\n";
    s21_map.Insert(std::make_pair(5.5, Item(5, 'A')));
    std::cout << s21_map << "\n\n";
    std::cout << "insert 4.5\n";
    s21_map.Insert(std::make_pair(4.5, Item(5, 'D')));
    std::cout << s21_map << "\n\n";
    std::cout << "insert 3.5\n";
    s21_map.Insert(std::make_pair(3.5, Item(5, 'C')));
    std::cout << s21_map << "\n\n";
    std::cout << "insert 2.5\n";
    s21_map.Insert(std::make_pair(2.5, Item(5, 'B')));
    std::cout << s21_map << "\n\n";

    
    EXPECT_TRUE(minimalHeight(s21_map.Size(), s21_map.Height()));    
}

TEST(Map, T3RightLeftCase)
{
    // return;
    s21::Map<double, Item> s21_map;

    std::cout << "insert 3.0\n";
    s21_map.Insert(std::make_pair(3.0, Item(5)));
    std::cout << s21_map << "\n\n";
    std::cout << "insert 5.0\n";
    s21_map.Insert(std::make_pair(5.0, Item(5)));
    std::cout << s21_map << "\n\n";
    std::cout << "insert 4.0\n";
    s21_map.Insert(std::make_pair(4.0, Item(5)));
    std::cout << s21_map << "\n\n";

    std::cout << "insert 2.5\n";
    s21_map.Insert(std::make_pair(2.5, Item(5, 'A')));
    std::cout << s21_map << "\n\n";
    std::cout << "insert 3.5\n";
    s21_map.Insert(std::make_pair(3.5, Item(5, 'D')));
    std::cout << s21_map << "\n\n";
    std::cout << "insert 4.5\n";
    s21_map.Insert(std::make_pair(4.5, Item(5, 'C')));
    std::cout << s21_map << "\n\n";
    std::cout << "insert 5.5\n";
    s21_map.Insert(std::make_pair(5.5, Item(5, 'B')));
    std::cout << s21_map << "\n\n";


    EXPECT_TRUE(minimalHeight(s21_map.Size(), s21_map.Height()));    
}





}  // namespace

// GCOVR_EXCL_STOP
