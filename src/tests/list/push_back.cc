#include <gtest/gtest.h>

#include <list>

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

} //  namespace

// GCOVR_EXCL_STOP