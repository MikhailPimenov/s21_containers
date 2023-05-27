#include <gtest/gtest.h>
#include <list>
#include "../../s21_list.h"
#include "../item.h"
#include "../list_helpers.h"

// GCOVR_EXCL_START

namespace {
    TEST(List, T0AssignCountType) {
        s21::List<Item> s21_list = {Item(11), Item(22),};
        std::list<Item> list = {Item(11), Item(22),};

        s21_list.Assign(6, Item(666));
        list.assign(6, Item(666));

        EXPECT_TRUE(s21_list == list);    
    }

    TEST(List, T1AssignIterator) {
        const s21::List<Item> s21_source = {Item(11), Item(22), Item(33), Item(44), Item(55), Item(66),};
        const std::list<Item> source = {Item(11), Item(22), Item(33), Item(44), Item(55), Item(66),};

        s21::List<Item> s21_list(s21_source);
        std::list<Item> list(source);

        s21_list.Assign(s21_source.cbegin(), --(s21_source.cend()));
        list.assign(source.cbegin(), --(source.cend()));

        EXPECT_TRUE(s21_list == list);    
    }

    TEST(List, T2AssignIterator) {
        const s21::List<Item> s21_source = {Item(11), Item(22), Item(33), Item(44), Item(55), Item(66),};
        const std::list<Item> source = {Item(11), Item(22), Item(33), Item(44), Item(55), Item(66),};

        s21::List<Item> s21_list(s21_source);
        std::list<Item> list(source);

        s21_list.Assign(s21_source.crbegin(), --(s21_source.crend()));
        list.assign(source.crbegin(), --(source.crend()));

        EXPECT_TRUE(s21_list == list);    
    }

    TEST(List, T3AssignIterator) {
        const s21::List<Item> s21_source = {Item(11), Item(22), Item(33), Item(44), Item(55), Item(66),};
        const std::list<Item> source = {Item(11), Item(22), Item(33), Item(44), Item(55), Item(66),};

        s21::List<Item> s21_list(s21_source);
        std::list<Item> list(source);

        s21_list.Assign(++(s21_source.cbegin()), --(s21_source.cend()));
        list.assign(++(source.cbegin()), --(source.cend()));

        EXPECT_TRUE(s21_list == list);    
    }

    TEST(List, T4AssignIterator) {
        const s21::List<Item> s21_source = {Item(11), Item(22), Item(33), Item(44), Item(55), Item(66),};
        const std::list<Item> source = {Item(11), Item(22), Item(33), Item(44), Item(55), Item(66),};

        s21::List<Item> s21_list(s21_source);
        std::list<Item> list(source);

        s21_list.Assign(++(s21_source.crbegin()), --(s21_source.crend()));
        list.assign(++(source.crbegin()), --(source.crend()));

        EXPECT_TRUE(s21_list == list);    
    }

    TEST(List, T5AssignInitializer) {
        s21::List<Item> s21_list = {Item(11), Item(22), Item(33), Item(44), Item(55), Item(66),};
        std::list<Item> list = {Item(11), Item(22), Item(33), Item(44), Item(55), Item(66),};

        s21_list.Assign({Item(666), Item(777)});
        list.assign({Item(666), Item(777)});

        EXPECT_TRUE(s21_list == list);    
    }

    TEST(List, T6AssignInitializer) {
        s21::List<Item> s21_list = {Item(11), Item(22), Item(33), Item(44), Item(55), Item(66),};
        std::list<Item> list = {Item(11), Item(22), Item(33), Item(44), Item(55), Item(66),};

        s21_list.Assign({});
        list.assign({});

        // EXPECT_TRUE(s21_list == list);    
    }
}  //  namespace

// GCOVR_EXCL_STOP