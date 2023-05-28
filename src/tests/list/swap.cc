#include <gtest/gtest.h>

#include <list>

#include "../../s21_list.h"
#include "../item.h"
#include "../list_helpers.h"

// GCOVR_EXCL_START

namespace
{

TEST(List, T0Swap)
{
    s21::List<Item> s21_list1 = { Item(11), Item(22), Item(33),};
    s21::List<Item> s21_list2 = { Item(111), Item(222), Item(333), Item(444), Item(555), Item(666),};
    
    const s21::List<Item> s21_copy1(s21_list1);
    const s21::List<Item> s21_copy2(s21_list2);

    s21_list1.Swap(s21_list2);

    EXPECT_TRUE(s21_list1 == s21_copy2);
    EXPECT_TRUE(s21_list2 == s21_copy1);


}

TEST(List, T1Swap)
{
    s21::List<Item> s21_list1 = { Item(11), Item(22), Item(33),};
    s21::List<Item> s21_list2 = { Item(111), Item(222), Item(333), Item(444), Item(555), Item(666),};
    
    const s21::List<Item> s21_copy1(s21_list1);
    const s21::List<Item> s21_copy2(s21_list2);

    s21_list2.Swap(s21_list1);

    EXPECT_TRUE(s21_list1 == s21_copy2);
    EXPECT_TRUE(s21_list2 == s21_copy1);


}

TEST(List, T2Swap)
{
    s21::List<Item> s21_list1;
    s21::List<Item> s21_list2 = { Item(111), Item(222), Item(333), Item(444), Item(555), Item(666),};
    
    const s21::List<Item> s21_copy1(s21_list1);
    const s21::List<Item> s21_copy2(s21_list2);

    s21_list1.Swap(s21_list2);

    EXPECT_TRUE(s21_list1 == s21_copy2);
    EXPECT_TRUE(s21_list2 == s21_copy1);


}


TEST(List, T3Swap)
{
    s21::List<Item> s21_list1;
    s21::List<Item> s21_list2;
    
    const s21::List<Item> s21_copy1(s21_list1);
    const s21::List<Item> s21_copy2(s21_list2);

    s21_list2.Swap(s21_list1);

    EXPECT_TRUE(s21_list1 == s21_copy2);
    EXPECT_TRUE(s21_list2 == s21_copy1);


}

TEST(List, T4SwapSelf)
{
    s21::List<Item> s21_list1 = {Item(11), Item(22), Item(33),};
    
    const s21::List<Item> s21_copy1(s21_list1);

    s21_list1.Swap(s21_list1);

    EXPECT_TRUE(s21_list1 == s21_copy1);

}
}
// GCOVR_EXCL_STOP