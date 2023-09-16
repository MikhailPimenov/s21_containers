#include <gtest/gtest.h>

#include <map>

#include "../../s21_multimap.h"
#include "../../s21_vector.h"
#include "../item.h"
#include "../multimap_helpers.h"
#include "../vector_helpers.h"


//  GCOVR_EXCL_START

namespace
{
TEST(MultiMap, T0InsertManyBack)
{
    s21::MultiMap<int, Item> s21_multimap {
        {11, Item(11)} , 
        {22, Item(22)} , 
        {33, Item(33)} , 
        {44, Item(44)} , 
        {55, Item(55)} , 
        {66, Item(66)} ,
    };

    s21::MultiMap<int, Item> s21_multimap_expected {
        {11, Item(11)} , 
        {22, Item(22)} , 
        {33, Item(33)} , 
        {44, Item(44)} , 
        {55, Item(55)} , 
        {66, Item(66)} ,
        {666, Item(666)} , 
        {777, Item(777)} ,
    };

    
    s21_multimap.Insert_many(std::make_pair(666, Item(666)), std::make_pair(777, Item(777)) );


    EXPECT_EQ(s21_multimap, s21_multimap_expected);
}

TEST(MultiMap, T1InsertManyEmptyBack)
{
    s21::MultiMap<int, Item> s21_multimap;

    s21::MultiMap<int, Item> s21_multimap_expected {
        {11, Item(11)} , 
        {22, Item(22)} , 
        {33, Item(33)} , 
        {44, Item(44)} , 
        {55, Item(55)} , 
        {66, Item(66)} ,
        {666, Item(666)} , 
        {777, Item(777)} ,
    };

    
    s21::Vector<std::pair<s21::MultiMap<int, Item>::iterator,bool>> s21_result = s21_multimap.Insert_many(std::make_pair(11, Item(11)),
        std::make_pair(22, Item(22)),
        std::make_pair(33, Item(33)),
        std::make_pair(44, Item(44)),
        std::make_pair(55, Item(55)),
        std::make_pair(66, Item(66)),
        std::make_pair(666, Item(666)), 
        std::make_pair(777, Item(777))
    );


    EXPECT_EQ(s21_multimap, s21_multimap_expected);
}



TEST(MultiMap, T0InsertMany)
{
    s21::MultiMap<int, Item> s21_multimap;
    s21::MultiMap<int, Item> s21_multimap2 = s21_multimap;

    s21::MultiMap<int, Item> s21_multimap_expected {
        {11, Item(11)} , 
        {22, Item(22)} , 
        {33, Item(33)} , 
        {44, Item(44)} , 
        {55, Item(55)} , 
        {66, Item(66)} ,
        {666, Item(666)} , 
        {777, Item(777)} ,
    };

    s21::Vector<std::pair<s21::MultiMap<int, Item>::iterator,bool>> s21_result_expected;
    s21_result_expected.Push_back(s21_multimap2.Insert(std::make_pair(11, Item(11))));
    s21_result_expected.Push_back(s21_multimap2.Insert(std::make_pair(22, Item(22))));
    s21_result_expected.Push_back(s21_multimap2.Insert(std::make_pair(33, Item(33))));
    s21_result_expected.Push_back(s21_multimap2.Insert(std::make_pair(44, Item(44))));
    s21_result_expected.Push_back(s21_multimap2.Insert(std::make_pair(55, Item(55))));
    s21_result_expected.Push_back(s21_multimap2.Insert(std::make_pair(66, Item(66))));
    s21_result_expected.Push_back(s21_multimap2.Insert(std::make_pair(666, Item(666))));
    s21_result_expected.Push_back(s21_multimap2.Insert(std::make_pair(777, Item(777))));
  
    s21::Vector<std::pair<s21::MultiMap<int, Item>::iterator,bool>> s21_result = s21_multimap.Insert_many(
        std::make_pair(11, Item(11)) , 
        std::make_pair(22, Item(22)) , 
        std::make_pair(33, Item(33)) , 
        std::make_pair(44, Item(44)) , 
        std::make_pair(55, Item(55)) , 
        std::make_pair(66, Item(66)) ,
        std::make_pair(666, Item(666)) , 
        std::make_pair(777, Item(777))
    );


    EXPECT_EQ(s21_multimap, s21_multimap_expected);
    EXPECT_EQ(s21_multimap2, s21_multimap_expected);

    EXPECT_EQ(s21_result.Size(), s21_result_expected.Size());
    auto it = s21_result.begin();
    auto it_expected = s21_result_expected.begin();

    while (it != s21_result.end() && it_expected != s21_result_expected.end()) {
        EXPECT_EQ(*(it->first), *(it_expected->first));
        EXPECT_EQ(it->second, it_expected->second);
        ++it;
        ++it_expected;
    }
}

TEST(MultiMap, T1InsertMany)
{
    s21::MultiMap<int, Item> s21_multimap { 
        {44, Item(44, 'a')} , 
        {55, Item(55)} , 
    };
    s21::MultiMap<int, Item> s21_multimap2 = s21_multimap;

    s21::MultiMap<int, Item> s21_multimap_expected {
        {11, Item(11)} , 
        {22, Item(22)} , 
        {33, Item(33)} , 
        {44, Item(44, 'a')} , 
        {44, Item(44)} , 
        {55, Item(55)} ,
        {55, Item(55)} , 
        {66, Item(66)} ,
        {666, Item(666)} , 
        {777, Item(777)} ,
    };

    s21::Vector<std::pair<s21::MultiMap<int, Item>::iterator,bool>> s21_result_expected;
    s21_result_expected.Push_back(s21_multimap2.Insert(std::make_pair(11, Item(11))));
    s21_result_expected.Push_back(s21_multimap2.Insert(std::make_pair(22, Item(22))));
    s21_result_expected.Push_back(s21_multimap2.Insert(std::make_pair(33, Item(33))));
    s21_result_expected.Push_back(s21_multimap2.Insert(std::make_pair(44, Item(44))));
    s21_result_expected.Push_back(s21_multimap2.Insert(std::make_pair(55, Item(55))));
    s21_result_expected.Push_back(s21_multimap2.Insert(std::make_pair(66, Item(66))));
    s21_result_expected.Push_back(s21_multimap2.Insert(std::make_pair(666, Item(666))));
    s21_result_expected.Push_back(s21_multimap2.Insert(std::make_pair(777, Item(777))));
  
    s21::Vector<std::pair<s21::MultiMap<int, Item>::iterator,bool>> s21_result = s21_multimap.Insert_many(
        std::make_pair(11, Item(11)) , 
        std::make_pair(22, Item(22)) , 
        std::make_pair(33, Item(33)) , 
        std::make_pair(44, Item(44)) , 
        std::make_pair(55, Item(55)) , 
        std::make_pair(66, Item(66)) ,
        std::make_pair(666, Item(666)) , 
        std::make_pair(777, Item(777))
    );


    EXPECT_EQ(s21_multimap, s21_multimap_expected);
    EXPECT_EQ(s21_multimap2, s21_multimap_expected);

    EXPECT_EQ(s21_result.Size(), s21_result_expected.Size());
    auto it = s21_result.begin();
    auto it_expected = s21_result_expected.begin();

    while (it != s21_result.end() && it_expected != s21_result_expected.end()) {
        EXPECT_EQ(*(it->first), *(it_expected->first));
        EXPECT_EQ(it->second, it_expected->second);
        ++it;
        ++it_expected;
    }
}


TEST(MultiMap, T2InsertMany)
{
    s21::MultiMap<int, Item> s21_multimap { 
        {111, Item(111, 's', 0.111)} , 
        {44, Item(44, 'a')} , 
        {55, Item(55)} , 
    };
    s21::MultiMap<int, Item> s21_multimap2 = s21_multimap;

    s21::MultiMap<int, Item> s21_multimap_expected {
        {111, Item(111, 's', 0.111)} ,
        {11, Item(11)} , 
        {22, Item(22)} , 
        {33, Item(33)} , 
        {44, Item(44, 'a')} ,
        {44, Item(44)} , 
        {55, Item(55)} , 
        {55, Item(55)} ,
        {66, Item(66)} ,
        {666, Item(666)} , 
        {777, Item(777)} ,
    };

    s21::Vector<std::pair<s21::MultiMap<int, Item>::iterator,bool>> s21_result_expected;
    s21_result_expected.Push_back(s21_multimap2.Insert(std::make_pair(11, Item(11))));
    s21_result_expected.Push_back(s21_multimap2.Insert(std::make_pair(22, Item(22))));
    s21_result_expected.Push_back(s21_multimap2.Insert(std::make_pair(33, Item(33))));
    s21_result_expected.Push_back(s21_multimap2.Insert(std::make_pair(44, Item(44))));
    s21_result_expected.Push_back(s21_multimap2.Insert(std::make_pair(55, Item(55))));
    s21_result_expected.Push_back(s21_multimap2.Insert(std::make_pair(66, Item(66))));
    s21_result_expected.Push_back(s21_multimap2.Insert(std::make_pair(666, Item(666))));
    s21_result_expected.Push_back(s21_multimap2.Insert(std::make_pair(777, Item(777))));
  
    s21::Vector<std::pair<s21::MultiMap<int, Item>::iterator,bool>> s21_result = s21_multimap.Insert_many(
        std::make_pair(11, Item(11)) , 
        std::make_pair(22, Item(22)) , 
        std::make_pair(33, Item(33)) , 
        std::make_pair(44, Item(44)) , 
        std::make_pair(55, Item(55)) , 
        std::make_pair(66, Item(66)) ,
        std::make_pair(666, Item(666)) , 
        std::make_pair(777, Item(777))
    );


    EXPECT_EQ(s21_multimap, s21_multimap_expected);
    EXPECT_EQ(s21_multimap2, s21_multimap_expected);

    EXPECT_EQ(s21_result.Size(), s21_result_expected.Size());
    auto it = s21_result.begin();
    auto it_expected = s21_result_expected.begin();

    while (it != s21_result.end() && it_expected != s21_result_expected.end()) {
        EXPECT_EQ(*(it->first), *(it_expected->first));
        EXPECT_EQ(it->second, it_expected->second);
        ++it;
        ++it_expected;
    }
}




} // namespace

//  GCOVR_EXCL_STOP