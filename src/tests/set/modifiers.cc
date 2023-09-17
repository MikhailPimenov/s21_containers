#include <gtest/gtest.h>

#include <set>

#include "../../s21_set.h"
#include "../item.h"
#include "../set_helpers.h"

// GCOVR_EXCL_START

namespace {

TEST(Set, T0Insert) {
  s21::Set<Item, ComparatorItem> s21_set;
  s21_set.Insert(Item(4));
  s21_set.Insert(Item(6));
  s21_set.Insert(Item(7));
  s21_set.Insert(Item(1));

  std::set<Item, ComparatorItem> set;
  set.insert(Item(4));
  set.insert(Item(6));
  set.insert(Item(7));
  set.insert(Item(1));

  EXPECT_EQ(s21_set, set);
}

TEST(Set, T1Insert) {
  s21::Set<Item, ComparatorItem> s21_set;
  s21_set.Insert(Item(1));
  s21_set.Insert(Item(4));
  s21_set.Insert(Item(6));
  s21_set.Insert(Item(7));

  std::set<Item, ComparatorItem> set;
  set.insert(Item(1));
  set.insert(Item(4));
  set.insert(Item(6));
  set.insert(Item(7));

  EXPECT_EQ(s21_set, set);
}

TEST(Set, T2Insert) {
  s21::Set<Item, ComparatorItem> s21_set;
  s21_set.Insert(Item(1));

  std::set<Item, ComparatorItem> set;
  set.insert(Item(1));

  EXPECT_EQ(s21_set, set);
}

TEST(Set, T3Insert) {
  s21::Set<Item, ComparatorItem> s21_set;
  s21_set.Insert(Item(-4));
  s21_set.Insert(Item(6));
  s21_set.Insert(Item(7));
  s21_set.Insert(Item(1));

  std::set<Item, ComparatorItem> set;
  set.insert(Item(-4));
  set.insert(Item(6));
  set.insert(Item(7));
  set.insert(Item(1));

  EXPECT_EQ(s21_set, set);
}

TEST(Set, T4Insert) {
  s21::Set<Item, ComparatorItem> s21_set;
  s21_set.Insert(Item(-4));
  s21_set.Insert(Item(-6));
  s21_set.Insert(Item(-7));
  s21_set.Insert(Item(-1));

  std::set<Item, ComparatorItem> set;
  set.insert(Item(-4));
  set.insert(Item(-6));
  set.insert(Item(-7));
  set.insert(Item(-1));

  EXPECT_EQ(s21_set, set);
}

TEST(Set, T5Insert) {
  s21::Set<Item, ComparatorItem> s21_set;
  s21_set.Insert(Item(4));
  s21_set.Insert(Item(6));
  s21_set.Insert(Item(7));
  s21_set.Insert(Item(1));

  std::set<Item, ComparatorItem> set;
  set.insert(Item(4));
  set.insert(Item(6));
  set.insert(Item(7));
  set.insert(Item(1));

  EXPECT_EQ(s21_set, set);
}

TEST(Set, T0Clear) {
  s21::Set<Item, ComparatorItem> s21_set{
      {Item(10, 'a', 0.1)}, {Item(20, 'b', 0.2)}, {Item(30, 'c', 0.3)},
      {Item(40, 'd', 0.4)}, {Item(50, 'e', 0.5)}, {Item(60, 'f', 0.6)},
      {Item(70, 'g', 0.7)}, {Item(80, 'h', 0.8)}, {Item(90, 'i', 0.9)},
  };

  std::set<Item, ComparatorItem> set{
      {Item(10, 'a', 0.1)}, {Item(20, 'b', 0.2)}, {Item(30, 'c', 0.3)},
      {Item(40, 'd', 0.4)}, {Item(50, 'e', 0.5)}, {Item(60, 'f', 0.6)},
      {Item(70, 'g', 0.7)}, {Item(80, 'h', 0.8)}, {Item(90, 'i', 0.9)},
  };

  s21_set.Clear();
  set.clear();

  EXPECT_EQ(s21_set, set);
}

TEST(Set, T1ClearEmpty) {
  s21::Set<Item, ComparatorItem> s21_set;
  std::set<Item, ComparatorItem> set;

  s21_set.Clear();
  set.clear();

  EXPECT_EQ(s21_set, set);
}

}  // namespace

// GCOVR_EXCL_STOP
