#include <gtest/gtest.h>
#include <list>
#include "../../s21_list.h"
#include "../item.h"
#include "../list_helpers.h"

// GCOVR_EXCL_START

namespace {
    // PUSH_BACK ============================================================
    // PUSH_BACK ============================================================
    // PUSH_BACK ============================================================

    TEST(Push_front, T0PushFront) {
        std::list<Item> list;
        list.push_front(Item(4));
        s21::List<Item> s21_list;
        s21_list.Push_front(Item(4));

        EXPECT_TRUE(s21_list == list);
    }

    TEST(Push_front, T1PushFront) {
        std::list<Item> list;
        list.push_front(Item(11));
        list.push_front(Item(22));
        list.push_front(Item(33));
        list.push_front(Item(44));
        s21::List<Item> s21_list;
        s21_list.Push_front(Item(11));
        s21_list.Push_front(Item(22));
        s21_list.Push_front(Item(33));
        s21_list.Push_front(Item(44));

        EXPECT_TRUE(s21_list == list);
    }

    TEST(Push_front, T2PushFront) {
        std::list<Item> list;
        list.push_front(Item(11));
        list.push_front(Item(22));
        list.push_front(Item(33));
        list.push_front(Item(44));
        list.push_front(Item(55));
        list.push_front(Item(66));
        list.push_back(Item(111));
        list.push_back(Item(222));
        list.push_back(Item(333));
        list.push_front(Item(77));
        list.push_back(Item(444));
        list.push_front(Item(88));
        s21::List<Item> s21_list;
        s21_list.Push_front(Item(11));
        s21_list.Push_front(Item(22));
        s21_list.Push_front(Item(33));
        s21_list.Push_front(Item(44));
        s21_list.Push_front(Item(55));
        s21_list.Push_front(Item(66));
        s21_list.Push_back(Item(111));
        s21_list.Push_back(Item(222));
        s21_list.Push_back(Item(333));
        s21_list.Push_front(Item(77));
        s21_list.Push_back(Item(444));
        s21_list.Push_front(Item(88));

        EXPECT_TRUE(s21_list == list);
    }


    TEST(Pop_front, T0PopFront) {
        std::list<Item> list = {Item(11), Item(22), Item(33), Item(44),};
        s21::List<Item> s21_list = {Item(11), Item(22), Item(33), Item(44),};

        list.pop_front();
        s21_list.Pop_front();

        EXPECT_TRUE(s21_list == list);
    }

    TEST(Pop_front, T1PopFront) {
        std::list<Item> list = {Item(11), Item(22), Item(33), Item(44),};
        s21::List<Item> s21_list = {Item(11), Item(22), Item(33), Item(44),};

        list.pop_front();
        list.pop_front();
        s21_list.Pop_front();
        s21_list.Pop_front();

        EXPECT_TRUE(s21_list == list);
    }

    TEST(Pop_front, T2PopFront) {
        std::list<Item> list = {Item(11), Item(22), Item(33), Item(44),};
        s21::List<Item> s21_list = {Item(11), Item(22), Item(33), Item(44),};

        list.pop_front();
        list.pop_front();
        list.pop_front();
        s21_list.Pop_front();
        s21_list.Pop_front();
        s21_list.Pop_front();

        EXPECT_TRUE(s21_list == list);
    }

    TEST(Pop_front, T3PopFront) {
        std::list<Item> list = {Item(11), Item(22), Item(33), Item(44),};
        s21::List<Item> s21_list = {Item(11), Item(22), Item(33), Item(44),};

        list.pop_front();
        list.pop_front();
        list.pop_front();
        list.pop_front();
        s21_list.Pop_front();
        s21_list.Pop_front();
        s21_list.Pop_front();
        s21_list.Pop_front();

        EXPECT_TRUE(s21_list == list);
    }

}

// GCOVR_EXCL_STOP