#include <gtest/gtest.h>

#include <set>

#include "../../s21_multiset.h"
#include "../item.h"
#include "../multiset_helpers.h"

// GCOVR_EXCL_START

namespace
{


TEST(MultiSet, T0Insert)
{
    s21::MultiSet<Item, ComparatorItem> s21_multiset;
    s21_multiset.Insert(Item(4));
    s21_multiset.Insert(Item(6));
    s21_multiset.Insert(Item(7));
    s21_multiset.Insert(Item(1));

    std::multiset<Item, ComparatorItem> multiset;
    multiset.insert(Item(4));
    multiset.insert(Item(6));
    multiset.insert(Item(7));
    multiset.insert(Item(1));

    EXPECT_EQ(s21_multiset, multiset);
}

TEST(MultiSet, T1Insert)
{
    s21::MultiSet<Item, ComparatorItem> s21_multiset;
    s21_multiset.Insert(Item(1));
    s21_multiset.Insert(Item(4));
    s21_multiset.Insert(Item(6));
    s21_multiset.Insert(Item(7));

    std::multiset<Item, ComparatorItem> multiset;
    multiset.insert(Item(1));
    multiset.insert(Item(4));
    multiset.insert(Item(6));
    multiset.insert(Item(7));

    EXPECT_EQ(s21_multiset, multiset);
}

TEST(MultiSet, T2Insert)
{
    s21::MultiSet<Item, ComparatorItem> s21_multiset;
    s21_multiset.Insert(Item(1));


    std::multiset<Item, ComparatorItem> multiset;
    multiset.insert(Item(1));

    EXPECT_EQ(s21_multiset, multiset);
}


TEST(MultiSet, T3Insert)
{
    s21::MultiSet<Item, ComparatorItem> s21_multiset;
    s21_multiset.Insert(Item(-4));
    s21_multiset.Insert(Item(6));
    s21_multiset.Insert(Item(7));
    s21_multiset.Insert(Item(1));

    std::multiset<Item, ComparatorItem> multiset;
    multiset.insert(Item(-4));
    multiset.insert(Item(6));
    multiset.insert(Item(7));
    multiset.insert(Item(1));

    EXPECT_EQ(s21_multiset, multiset);
}

TEST(MultiSet, T4Insert)
{
    s21::MultiSet<Item, ComparatorItem> s21_multiset;
    s21_multiset.Insert(Item(-4));
    s21_multiset.Insert(Item(-6));
    s21_multiset.Insert(Item(-7));
    s21_multiset.Insert(Item(-1));

    std::multiset<Item, ComparatorItem> multiset;
    multiset.insert(Item(-4));
    multiset.insert(Item(-6));
    multiset.insert(Item(-7));
    multiset.insert(Item(-1));

    EXPECT_EQ(s21_multiset, multiset);
}

TEST(MultiSet, T5Insert)
{
    s21::MultiSet<Item, ComparatorItem> s21_multiset;
    s21_multiset.Insert(Item(4));
    s21_multiset.Insert(Item(6));
    s21_multiset.Insert(Item(7));
    s21_multiset.Insert(Item(1));

    std::multiset<Item, ComparatorItem> multiset;
    multiset.insert(Item(4));
    multiset.insert(Item(6));
    multiset.insert(Item(7));
    multiset.insert(Item(1));

    EXPECT_EQ(s21_multiset, multiset);
}












TEST(MultiSet, T0Clear)
{
    s21::MultiSet<Item, ComparatorItem> s21_multiset {
        {Item(10, 'a', 0.1)},
        {Item(20, 'b', 0.2)},
        {Item(30, 'c', 0.3)},
        {Item(40, 'd', 0.4)},
        {Item(50, 'e', 0.5)},
        {Item(60, 'f', 0.6)},
        {Item(70, 'g', 0.7)},
        {Item(80, 'h', 0.8)},
        {Item(90, 'i', 0.9)},
    };

    std::multiset<Item, ComparatorItem> multiset {
        {Item(10, 'a', 0.1)},
        {Item(20, 'b', 0.2)},
        {Item(30, 'c', 0.3)},
        {Item(40, 'd', 0.4)},
        {Item(50, 'e', 0.5)},
        {Item(60, 'f', 0.6)},
        {Item(70, 'g', 0.7)},
        {Item(80, 'h', 0.8)},
        {Item(90, 'i', 0.9)},
    };

    s21_multiset.Clear();
    multiset.clear();

    EXPECT_EQ(s21_multiset, multiset);
}

TEST(MultiSet, T1ClearEmpty)
{
    s21::MultiSet<Item, ComparatorItem> s21_multiset;
    std::multiset<Item, ComparatorItem> multiset;

    s21_multiset.Clear();
    multiset.clear();

    EXPECT_EQ(s21_multiset, multiset);
}










}  // namespace

// GCOVR_EXCL_STOP
