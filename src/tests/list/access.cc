#include <gtest/gtest.h>

#include <list>

#include "../../s21_list.h"
#include "../item.h"
#include "../list_helpers.h"

// GCOVR_EXCL_START

namespace
{
TEST(Access, T0Front)
{
    s21::List<Item> s21_list{Item(111), Item(222), Item(333)};
    std::list<Item> list{Item(111), Item(222), Item(333)};

    s21_list.Front() = Item(666);
    list.front() = Item(666);

    EXPECT_TRUE(s21_list == list);
}

TEST(Access, T1FrontConst)
{
    const s21::List<Item> s21_list{Item(111), Item(222), Item(333)};
    const std::list<Item> list{Item(111), Item(222), Item(333)};

    const Item s21_first = s21_list.Front();
    const Item first = list.front();

    EXPECT_TRUE(s21_first == first);
}

TEST(Access, T2Back)
{
    s21::List<Item> s21_list{Item(111), Item(222), Item(333)};
    std::list<Item> list{Item(111), Item(222), Item(333)};

    s21_list.Back() = Item(666);
    list.back() = Item(666);

    EXPECT_TRUE(s21_list == list);
}

TEST(Access, T3BackConst)
{
    const s21::List<Item> s21_list{Item(111), Item(222), Item(333)};
    const std::list<Item> list{Item(111), Item(222), Item(333)};

    const Item s21_last = s21_list.Back();
    const Item last = list.back();

    EXPECT_TRUE(s21_last == last);
}

TEST(Access, T4Back)
{
    s21::List<Item> s21_list{Item(111), Item(222), Item(333)};
    std::list<Item> list{Item(111), Item(222), Item(333)};

    s21_list.Back() = Item(666);
    list.back() = Item(666);

    EXPECT_TRUE(s21_list == list);

    s21_list.Push_back(Item(777));
    list.push_back(Item(777));
    s21_list.Push_back(Item(888));
    list.push_back(Item(888));

    s21_list.Back() = Item(666);
    list.back() = Item(666);

    EXPECT_TRUE(s21_list == list);
}

TEST(Access, T5BackConst)
{
    const s21::List<Item> s21_list{Item(111), Item(222), Item(333), Item(777), Item(888)};
    const std::list<Item> list{Item(111), Item(222), Item(333), Item(777), Item(888)};

    const Item s21_last = s21_list.Back();
    const Item last = list.back();

    EXPECT_TRUE(s21_last == last);
}
} // namespace

// GCOVR_EXCL_STOP