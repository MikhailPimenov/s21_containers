#include <gtest/gtest.h>
#include <list>
#include "../../s21_list.h"
#include "../item.h"
#include "../list_helpers.h"

// GCOVR_EXCL_START

namespace {
    TEST(List, T0DefaultConstructor) {
        s21::List<Item> s21_list;
        std::list<Item> list;

        EXPECT_TRUE(s21_list == list);

        s21_list.Push_back(Item(0));
        s21_list.Push_back(Item(10));
        s21_list.Push_back(Item(20));
        print(s21_list);
    }
}   //  namespace

// GCOVR_EXCL_STOP