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
    }

    TEST(List, T0ConstructorInitializerList) {
        s21::List<Item> s21_list = {Item(11), Item(22), Item(33), Item(44), Item(55)};
        std::list<Item> list = {Item(11), Item(22), Item(33), Item(44), Item(55)};

        EXPECT_TRUE(s21_list == list);
    }

    TEST(List, T0Modify) {
        s21::List<Item> s21_list = {Item(11), Item(22), Item(33), Item(44), Item(55)};
        std::list<Item> list = {Item(11), Item(22), Item(33), Item(44), Item(55)};

        auto it = list.begin();
        ++it;
        ++it;
        *it = Item(666);

        auto s21_it = s21_list.begin();
        ++s21_it;
        ++s21_it;
        *s21_it = Item(666);

        EXPECT_TRUE(s21_list == list);
    }
}   //  namespace

// GCOVR_EXCL_STOP