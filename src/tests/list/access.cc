#include <gtest/gtest.h>
#include <list>
#include "../../s21_list.h"
#include "../item.h"
#include "../list_helpers.h"

// GCOVR_EXCL_START

namespace {
    TEST(Access, T0Front) {
        s21::List<Item> s21_list {Item(111), Item(222), Item(333)};
        std::list<Item> list {Item(111), Item(222), Item(333)};

        const Item s21_first = s21_list.Front();
        const Item first = list.front();

        EXPECT_TRUE(s21_first == first);
    }
}

// GCOVR_EXCL_STOP