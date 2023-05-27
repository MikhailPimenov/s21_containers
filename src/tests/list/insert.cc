#include <gtest/gtest.h>
#include <list>
#include "../../s21_list.h"
#include "../item.h"
#include "../list_helpers.h"

// GCOVR_EXCL_START

namespace {
    TEST(List, T0InsertPosValue) {
        s21::List<Item> s21_list = {Item(11), Item(22), Item(33), Item(44), Item(55), Item(66),};
        std::list<Item> list = {Item(11), Item(22), Item(33), Item(44), Item(55), Item(66),};

        s21::List<Item>::const_iterator s21_pos = s21_list.cbegin();
        ++s21_pos;
        ++s21_pos;
        const auto s21_it = s21_list.Insert(s21_pos, Item(666));

        std::list<Item>::const_iterator pos = list.cbegin();
        ++pos;
        ++pos;
        const auto it = list.insert(pos, Item(666));
       

        EXPECT_TRUE(s21_list == list);
        EXPECT_TRUE(*s21_it == *it); 
    }

    TEST(List, T1InsertPosValue) {
        s21::List<Item> s21_list = {Item(11), Item(22), Item(33), Item(44), Item(55), Item(66),};
        std::list<Item> list = {Item(11), Item(22), Item(33), Item(44), Item(55), Item(66),};

        s21::List<Item>::const_iterator s21_pos = s21_list.cend();
        --s21_pos;
        --s21_pos;
        const auto s21_it = s21_list.Insert(s21_pos, Item(666));

        std::list<Item>::const_iterator pos = list.cend();
        --pos;
        --pos;
        const auto it = list.insert(pos, Item(666));
       

        EXPECT_TRUE(s21_list == list);    
        EXPECT_TRUE(*s21_it == *it); 
    }

    TEST(List, T2InsertPosValueBegin) {
        s21::List<Item> s21_list = {Item(11), Item(22), Item(33), Item(44), Item(55), Item(66),};
        std::list<Item> list = {Item(11), Item(22), Item(33), Item(44), Item(55), Item(66),};

        s21::List<Item>::const_iterator s21_pos = s21_list.cbegin();
        const auto s21_it = s21_list.Insert(s21_pos, Item(666));

        std::list<Item>::const_iterator pos = list.cbegin();
        const auto it = list.insert(pos, Item(666));
       

        EXPECT_TRUE(s21_list == list);  
        print(s21_list);  
        EXPECT_TRUE(*s21_it == *it); 
    }

    TEST(List, T3InsertPosValueEnd) {
        s21::List<Item> s21_list = {Item(11), Item(22), Item(33), Item(44), Item(55), Item(66),};
        std::list<Item> list = {Item(11), Item(22), Item(33), Item(44), Item(55), Item(66),};

        s21::List<Item>::const_iterator s21_pos = s21_list.cend();
        const auto s21_it = s21_list.Insert(s21_pos, Item(666));

        std::list<Item>::const_iterator pos = list.cend();
        const auto it = list.insert(pos, Item(666));
       

        EXPECT_TRUE(s21_list == list);    
        EXPECT_TRUE(*s21_it == *it); 
    }
}  //  namespace