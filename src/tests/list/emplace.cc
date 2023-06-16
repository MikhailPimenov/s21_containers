#include <gtest/gtest.h>

#include <list>

#include "../../s21_list.h"
#include "../item.h"
#include "../list_helpers.h"

// GCOVR_EXCL_START

namespace
{
TEST(List, T0Emplace)
{
    s21::List<Item> s21_list;
    s21::List<Item>::const_iterator s21_pos = s21_list.cbegin();

    s21_list.Emplace(s21_pos, 555);
    s21::List<Item>::iterator s21_it = s21_list.Emplace(s21_pos, 666);

    std::list<Item> list;
    std::list<Item>::const_iterator pos = list.cbegin();

    list.emplace(pos, 555);
    std::list<Item>::iterator it = list.emplace(pos, 666);

    EXPECT_TRUE(s21_list == list);
    EXPECT_TRUE(*s21_it == *it);
}

TEST(List, T0EmplaceBack)
{
    std::list<Item> list;
    const Item &item = list.emplace_back(444);
    s21::List<Item> s21_list;

    const Item &s21_item = s21_list.Emplace_back(444);

    EXPECT_TRUE(s21_list == list);
    EXPECT_TRUE(s21_item == item);
}

TEST(List, T1EmplaceBack)
{
    std::list<Item> list;
    list.emplace_back(444);
    list.emplace_back(555);
    const Item &item = list.emplace_back(666);
    list.emplace_back(777);

    s21::List<Item> s21_list;
    s21_list.Emplace_back(444);
    s21_list.Emplace_back(555);
    const Item &s21_item = s21_list.Emplace_back(666);
    s21_list.Emplace_back(777);

    EXPECT_TRUE(s21_list == list);
    EXPECT_TRUE(s21_item == item);
}

TEST(List, T2EmplaceBack)
{
    std::list<Item> list = {
        Item(11),
        Item(22),
        Item(33),
    };
    list.emplace_back(444);
    list.emplace_back(555);
    const Item &item = list.emplace_back(666);
    list.emplace_back(777);

    s21::List<Item> s21_list = {
        Item(11),
        Item(22),
        Item(33),
    };
    s21_list.Emplace_back(444);
    s21_list.Emplace_back(555);
    const Item &s21_item = s21_list.Emplace_back(666);
    s21_list.Emplace_back(777);

    EXPECT_TRUE(s21_list == list);
    EXPECT_TRUE(s21_item == item);
}

TEST(List, T3EmplaceBack)
{
    std::list<Item> list = {
        Item(11),
        Item(22),
        Item(33),
    };
    list.emplace_back(444);
    list.emplace_back(555);
    list.pop_back();
    const Item &item = list.emplace_back(666);
    list.emplace_back(777);

    s21::List<Item> s21_list = {
        Item(11),
        Item(22),
        Item(33),
    };
    s21_list.Emplace_back(444);
    s21_list.Emplace_back(555);
    s21_list.Pop_back();
    const Item &s21_item = s21_list.Emplace_back(666);
    s21_list.Emplace_back(777);

    EXPECT_TRUE(s21_list == list);
    EXPECT_TRUE(s21_item == item);
}

TEST(List, T0EmplaceFront)
{
    std::list<Item> list;
    const Item &item = list.emplace_front(444);
    s21::List<Item> s21_list;

    const Item &s21_item = s21_list.Emplace_front(444);

    EXPECT_TRUE(s21_list == list);
    EXPECT_TRUE(s21_item == item);
}

TEST(List, T1EmplaceFront)
{
    std::list<Item> list;
    list.emplace_front(444);
    list.emplace_front(555);
    const Item &item = list.emplace_front(666);
    list.emplace_front(777);

    s21::List<Item> s21_list;
    s21_list.Emplace_front(444);
    s21_list.Emplace_front(555);
    const Item &s21_item = s21_list.Emplace_front(666);
    s21_list.Emplace_front(777);

    EXPECT_TRUE(s21_list == list);
    EXPECT_TRUE(s21_item == item);
}

TEST(List, T2EmplaceFront)
{
    std::list<Item> list = {
        Item(11),
        Item(22),
        Item(33),
    };
    list.emplace_front(444);
    list.emplace_front(555);
    const Item &item = list.emplace_front(666);
    list.emplace_front(777);

    s21::List<Item> s21_list = {
        Item(11),
        Item(22),
        Item(33),
    };
    s21_list.Emplace_front(444);
    s21_list.Emplace_front(555);
    const Item &s21_item = s21_list.Emplace_front(666);
    s21_list.Emplace_front(777);

    EXPECT_TRUE(s21_list == list);
    EXPECT_TRUE(s21_item == item);
}

TEST(List, T3EmplaceFront)
{
    std::list<Item> list = {
        Item(11),
        Item(22),
        Item(33),
    };
    list.emplace_front(444);
    list.emplace_front(555);
    list.pop_back();
    const Item &item = list.emplace_front(666);
    list.emplace_front(777);

    s21::List<Item> s21_list = {
        Item(11),
        Item(22),
        Item(33),
    };
    s21_list.Emplace_front(444);
    s21_list.Emplace_front(555);
    s21_list.Pop_back();
    const Item &s21_item = s21_list.Emplace_front(666);
    s21_list.Emplace_front(777);

    EXPECT_TRUE(s21_list == list);
    EXPECT_TRUE(s21_item == item);
}

TEST(List, T0EmplaceMixed)
{
    std::list<Item> list = {
        Item(11),
        Item(22),
        Item(33),
    };
    list.emplace_front(444);
    list.emplace_back(888);
    list.emplace_front(555);
    list.emplace_back(999);
    list.pop_back();
    const Item &item = list.emplace_front(666);
    list.emplace_front(777);

    s21::List<Item> s21_list = {
        Item(11),
        Item(22),
        Item(33),
    };
    s21_list.Emplace_front(444);
    s21_list.Emplace_back(888);
    s21_list.Emplace_front(555);
    s21_list.Emplace_back(999);
    s21_list.Pop_back();
    const Item &s21_item = s21_list.Emplace_front(666);
    s21_list.Emplace_front(777);

    EXPECT_TRUE(s21_list == list);
    EXPECT_TRUE(s21_item == item);
}

TEST(List, T0EmplaceMixedVariadic)
{
    std::list<Item> list = {
        Item(11),
        Item(22),
        Item(33),
    };
    list.emplace_front(444, 'c', 0.75);
    list.emplace_back(888, 'd', 0.666);
    list.emplace_front(555, 'e');
    list.emplace_back(999);
    list.pop_back();
    const Item &item = list.emplace_front(666);
    list.emplace_front(777);

    s21::List<Item> s21_list = {
        Item(11),
        Item(22),
        Item(33),
    };
    s21_list.Emplace_front(444, 'c', 0.75);
    s21_list.Emplace_back(888, 'd', 0.666);
    s21_list.Emplace_front(555, 'e');
    s21_list.Emplace_back(999);
    s21_list.Pop_back();
    const Item &s21_item = s21_list.Emplace_front(666);
    s21_list.Emplace_front(777);

    EXPECT_TRUE(s21_list == list);
    EXPECT_TRUE(s21_item == item);
}
} // namespace

// GCOVR_EXCL_STOP