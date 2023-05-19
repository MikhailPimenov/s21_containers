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
}   //  namespace

// GCOVR_EXCL_STOP