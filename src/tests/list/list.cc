#include <gtest/gtest.h>
#include <list>
#include "../../s21_list.h"

// GCOVR_EXCL_START

template <typename Type>
bool operator==(const s21::List<Type>& s21_list, const std::list<Type>& list) {
    if (s21_list.Size() != list.size())
        return false;

    // const auto iterator = list.cbegin();
    // const auto s21_iterator = s21_list.cbegin();

    // while (iterator != list.cend()) {
    //     if (*iterator != *s21_iterator)
    //         return false;
    //     ++iterator;
    //     ++s21_iterator;
    // }    
    
    return true;
}

class Item {

};

namespace {
    TEST(ListTests, Test0DefaultConstructor) {
        s21::List<Item> s21_list;
        std::list<Item> list;


        EXPECT_TRUE(s21_list == list);
    }
}   //  namespace

// GCOVR_EXCL_STOP