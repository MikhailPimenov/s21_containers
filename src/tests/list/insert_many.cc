#include <gtest/gtest.h>

#include <list>

#include "../../s21_list.h"
#include "../item.h"
#include "../list_helpers.h"

//  GCOVR_EXCL_START

namespace
{
TEST(List, T0InsertMany)
{
    s21::List<Item> s21_list = {
        Item(11), Item(22), Item(33), Item(44), Item(55), Item(66),
    };

    s21::List<Item> s21_list_expected= {
        Item(11), Item(22), Item(33), Item(44), Item(55), Item(66), Item(666), Item(777),
    };

    
    s21_list.Insert_many_back(Item(666), Item(777));


    EXPECT_EQ(s21_list, s21_list_expected);
}

TEST(List, T1InsertManyEmpty)
{
    s21::List<Item> s21_list;

    s21::List<Item> s21_list_expected= {
        Item(11), Item(22), Item(33), Item(44), Item(55), Item(66), Item(666), Item(777),
    };

    
    s21_list.Insert_many_back(Item(11), Item(22), Item(33), Item(44), Item(55), Item(66), Item(666), Item(777));


    EXPECT_EQ(s21_list, s21_list_expected);
}

} // namespace

//  GCOVR_EXCL_STOP