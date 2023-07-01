#include <gtest/gtest.h>

#include <list>
#include <vector>

#include "../../s21_list.h"
#include "../item.h"
#include "../list_helpers.h"

// GCOVR_EXCL_START

namespace
{
// PUSH_BACK ============================================================
// PUSH_BACK ============================================================
// PUSH_BACK ============================================================

TEST(Push_back, T0PushBack)
{
    std::list<Item> list;
    list.push_back(Item(4));
    s21::List<Item> s21_list;
    s21_list.Push_back(Item(4));

    EXPECT_TRUE(s21_list == list);
}

TEST(Push_back, T1PushBack)
{
    std::list<Item> list;
    list.push_back(Item(0));
    list.push_back(Item(10));
    list.push_back(Item(20));

    s21::List<Item> s21_list;
    s21_list.Push_back(Item(0));
    s21_list.Push_back(Item(10));
    s21_list.Push_back(Item(20));

    EXPECT_TRUE(s21_list == list);
}

TEST(Push_back, T2PushBack)
{
    std::list<Item> list;
    list.push_back(Item(0));
    list.push_back(Item(10));
    list.push_back(Item(20));
    list.push_back(Item(30));
    list.push_back(Item(40));

    s21::List<Item> s21_list;
    s21_list.Push_back(Item(0));
    s21_list.Push_back(Item(10));
    s21_list.Push_back(Item(20));
    s21_list.Push_back(Item(30));
    s21_list.Push_back(Item(40));

    EXPECT_TRUE(s21_list == list);
}

TEST(Push_back, T3PushBackMove)
{
    std::vector<Item> items1 { Item(11), Item(22, 'b', 0.22), Item(33, 'c', 0.33) };
    std::vector<Item> items2 { Item(55), Item(66, 'f', 0.666), Item(77, 'g', 0.7777) };

    std::vector<Item> items11(items1);
    std::vector<Item> items22(items2);


    s21::List<std::vector<Item>> s21_list;
    s21_list.Push_back(std::move(items1));
    s21_list.Push_back(std::move(items2));

    std::list<std::vector<Item>> list;
    list.push_back(std::move(items11));
    list.push_back(std::move(items22));

    EXPECT_EQ(s21_list, list);
    EXPECT_TRUE(items1.empty());
    EXPECT_TRUE(items2.empty());
}

} //  namespace

// GCOVR_EXCL_STOP