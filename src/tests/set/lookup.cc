#include <gtest/gtest.h>

#include <set>

#include "../../s21_set.h"
#include "../item.h"
#include "../set_helpers.h"

// GCOVR_EXCL_START

namespace {

TEST(Set, T0Find) {
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

  auto s21_it = s21_set.Find(Item(7));
  auto it = set.find(Item(7));

  EXPECT_EQ(*s21_it, *it);
  EXPECT_EQ(s21_set, set);
}

TEST(Set, T1Find) {
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

  const auto s21_it = s21_set.Find(Item(4));
  const auto it = set.find(Item(4));

  EXPECT_EQ(*s21_it, *it);
  EXPECT_EQ(s21_set, set);
}

TEST(Set, T2Find) {
  s21::Set<Item, ComparatorItem> s21_set;
  s21_set.Insert(Item(4));
  s21_set.Insert(Item(5));
  s21_set.Insert(Item(6));
  s21_set.Insert(Item(7));
  s21_set.Insert(Item(1));

  std::set<Item, ComparatorItem> set;
  set.insert(Item(4));
  set.insert(Item(5));
  set.insert(Item(6));
  set.insert(Item(7));
  set.insert(Item(1));

  const auto s21_it = s21_set.Find(Item(1));
  const auto it = set.find(Item(1));

  EXPECT_EQ(*s21_it, *it);
  EXPECT_EQ(s21_set, set);
}

TEST(Set, T3Find) {
  s21::Set<Item, ComparatorItem> s21_set;
  s21_set.Insert(Item(4));
  s21_set.Insert(Item(5));
  s21_set.Insert(Item(6));
  s21_set.Insert(Item(7));
  s21_set.Insert(Item(1));

  std::set<Item, ComparatorItem> set;
  set.insert(Item(4));
  set.insert(Item(5));
  set.insert(Item(6));
  set.insert(Item(7));
  set.insert(Item(1));

  const auto s21_it = s21_set.Find(Item(6));
  const auto it = set.find(Item(6));

  EXPECT_EQ(*s21_it, *it);
  EXPECT_EQ(s21_set, set);
}

TEST(Set, T4FindEnd) {
  s21::Set<Item, ComparatorItem> s21_set;
  s21_set.Insert(Item(4));
  s21_set.Insert(Item(5));
  s21_set.Insert(Item(6));
  s21_set.Insert(Item(7));
  s21_set.Insert(Item(1));

  std::set<Item, ComparatorItem> set;
  set.insert(Item(4));
  set.insert(Item(5));
  set.insert(Item(6));
  set.insert(Item(7));
  set.insert(Item(1));

  const auto s21_it = s21_set.Find(Item(99));
  const auto it = set.find(Item(99));

  EXPECT_EQ(s21_it, s21_set.end());
  EXPECT_EQ(it, set.end());
  EXPECT_EQ(s21_set, set);
}

TEST(Set, T5FindConst) {
  const s21::Set<Item, ComparatorItem> s21_set{
      {Item(1, 'a', 0.1)}, {Item(2, 'b', 0.2)}, {Item(3, 'c', 0.3)},
      {Item(4, 'd', 0.4)}, {Item(5, 'e', 0.5)}, {Item(6, 'f', 0.6)},
  };
  const std::set<Item, ComparatorItem> set{
      {Item(1, 'a', 0.1)}, {Item(2, 'b', 0.2)}, {Item(3, 'c', 0.3)},
      {Item(4, 'd', 0.4)}, {Item(5, 'e', 0.5)}, {Item(6, 'f', 0.6)},
  };

  EXPECT_EQ(*s21_set.Find(Item(3)), *set.find(Item(3)));
}

TEST(Set, T0Contains) {
  s21::Set<Item, ComparatorItem> s21_set;
  s21_set.Insert(Item(4));
  s21_set.Insert(Item(5));
  s21_set.Insert(Item(6));
  s21_set.Insert(Item(7));
  s21_set.Insert(Item(1));

  EXPECT_EQ(s21_set.Contains(Item(4)), true);
}

TEST(Set, T1Contains) {
  s21::Set<Item, ComparatorItem> s21_set;
  s21_set.Insert(Item(4));
  s21_set.Insert(Item(5));
  s21_set.Insert(Item(6));
  s21_set.Insert(Item(7));
  s21_set.Insert(Item(1));

  EXPECT_EQ(s21_set.Contains(Item(5)), true);
}

TEST(Set, T2Contains) {
  s21::Set<Item, ComparatorItem> s21_set;
  s21_set.Insert(Item(4));
  s21_set.Insert(Item(5));
  s21_set.Insert(Item(6));
  s21_set.Insert(Item(7));
  s21_set.Insert(Item(1));

  EXPECT_EQ(s21_set.Contains(Item(6)), true);
}

TEST(Set, T3Contains) {
  s21::Set<Item, ComparatorItem> s21_set;
  s21_set.Insert(Item(4));
  s21_set.Insert(Item(5));
  s21_set.Insert(Item(6));
  s21_set.Insert(Item(7));
  s21_set.Insert(Item(1));

  EXPECT_EQ(s21_set.Contains(Item(7)), true);
}

TEST(Set, T4Contains) {
  s21::Set<Item, ComparatorItem> s21_set;
  s21_set.Insert(Item(4));
  s21_set.Insert(Item(5));
  s21_set.Insert(Item(6));
  s21_set.Insert(Item(7));
  s21_set.Insert(Item(1));

  EXPECT_EQ(s21_set.Contains(Item(1)), true);
}

TEST(Set, T5ContainsNo) {
  s21::Set<Item, ComparatorItem> s21_set;
  s21_set.Insert(Item(4));
  s21_set.Insert(Item(5));
  s21_set.Insert(Item(6));
  s21_set.Insert(Item(7));
  s21_set.Insert(Item(1));

  EXPECT_EQ(s21_set.Contains(Item(99)), false);
}

TEST(Set, T6ContainsEmpty) {
  s21::Set<Item, ComparatorItem> s21_set;
  EXPECT_EQ(s21_set.Contains(Item(99)), false);
}

TEST(Set, T7ContainsNo) {
  const s21::Set<Item, ComparatorItem> s21_set{
      {Item(1, 'a', 0.1)}, {Item(2, 'b', 0.2)}, {Item(3, 'c', 0.3)},
      {Item(4, 'd', 0.4)}, {Item(5, 'e', 0.5)}, {Item(6, 'f', 0.6)},
  };

  EXPECT_EQ(s21_set.Contains(Item(99)), false);
}

TEST(Set, T8Contains) {
  const s21::Set<Item, ComparatorItem> s21_set{
      {Item(1, 'a', 0.1)}, {Item(2, 'b', 0.2)}, {Item(3, 'c', 0.3)},
      {Item(4, 'd', 0.4)}, {Item(5, 'e', 0.5)}, {Item(6, 'f', 0.6)},
  };

  EXPECT_EQ(s21_set.Contains(Item(3)), true);
}

TEST(Set, T0LowerBound) {
  const s21::Set<Item, ComparatorItem> s21_set{
      {Item(10, 'a', 0.1)}, {Item(20, 'b', 0.2)}, {Item(30, 'c', 0.3)},
      {Item(40, 'd', 0.4)}, {Item(50, 'e', 0.5)}, {Item(60, 'f', 0.6)},
      {Item(70, 'g', 0.7)}, {Item(80, 'h', 0.8)}, {Item(90, 'i', 0.9)},
  };

  const std::set<Item, ComparatorItem> set{
      {Item(10, 'a', 0.1)}, {Item(20, 'b', 0.2)}, {Item(30, 'c', 0.3)},
      {Item(40, 'd', 0.4)}, {Item(50, 'e', 0.5)}, {Item(60, 'f', 0.6)},
      {Item(70, 'g', 0.7)}, {Item(80, 'h', 0.8)}, {Item(90, 'i', 0.9)},
  };

  EXPECT_EQ(*s21_set.Lower_bound(Item(5)), *set.lower_bound(Item(5)));
}

TEST(Set, T1LowerBound) {
  const s21::Set<Item, ComparatorItem> s21_set{
      {Item(10, 'a', 0.1)}, {Item(20, 'b', 0.2)}, {Item(30, 'c', 0.3)},
      {Item(40, 'd', 0.4)}, {Item(50, 'e', 0.5)}, {Item(60, 'f', 0.6)},
      {Item(70, 'g', 0.7)}, {Item(80, 'h', 0.8)}, {Item(90, 'i', 0.9)},
  };

  const std::set<Item, ComparatorItem> set{
      {Item(10, 'a', 0.1)}, {Item(20, 'b', 0.2)}, {Item(30, 'c', 0.3)},
      {Item(40, 'd', 0.4)}, {Item(50, 'e', 0.5)}, {Item(60, 'f', 0.6)},
      {Item(70, 'g', 0.7)}, {Item(80, 'h', 0.8)}, {Item(90, 'i', 0.9)},
  };

  EXPECT_EQ(*s21_set.Lower_bound(Item(15)), *set.lower_bound(Item(15)));
}

TEST(Set, T2LowerBound) {
  const s21::Set<Item, ComparatorItem> s21_set{
      {Item(10, 'a', 0.1)}, {Item(20, 'b', 0.2)}, {Item(30, 'c', 0.3)},
      {Item(40, 'd', 0.4)}, {Item(50, 'e', 0.5)}, {Item(60, 'f', 0.6)},
      {Item(70, 'g', 0.7)}, {Item(80, 'h', 0.8)}, {Item(90, 'i', 0.9)},
  };

  const std::set<Item, ComparatorItem> set{
      {Item(10, 'a', 0.1)}, {Item(20, 'b', 0.2)}, {Item(30, 'c', 0.3)},
      {Item(40, 'd', 0.4)}, {Item(50, 'e', 0.5)}, {Item(60, 'f', 0.6)},
      {Item(70, 'g', 0.7)}, {Item(80, 'h', 0.8)}, {Item(90, 'i', 0.9)},
  };

  EXPECT_EQ(*s21_set.Lower_bound(Item(25)), *set.lower_bound(Item(25)));
}

TEST(Set, T3LowerBound) {
  const s21::Set<Item, ComparatorItem> s21_set{
      {Item(10, 'a', 0.1)}, {Item(20, 'b', 0.2)}, {Item(30, 'c', 0.3)},
      {Item(40, 'd', 0.4)}, {Item(50, 'e', 0.5)}, {Item(60, 'f', 0.6)},
      {Item(70, 'g', 0.7)}, {Item(80, 'h', 0.8)}, {Item(90, 'i', 0.9)},
  };

  const std::set<Item, ComparatorItem> set{
      {Item(10, 'a', 0.1)}, {Item(20, 'b', 0.2)}, {Item(30, 'c', 0.3)},
      {Item(40, 'd', 0.4)}, {Item(50, 'e', 0.5)}, {Item(60, 'f', 0.6)},
      {Item(70, 'g', 0.7)}, {Item(80, 'h', 0.8)}, {Item(90, 'i', 0.9)},
  };

  EXPECT_EQ(*s21_set.Lower_bound(Item(35)), *set.lower_bound(Item(35)));
}

TEST(Set, T4LowerBound) {
  const s21::Set<Item, ComparatorItem> s21_set{
      {Item(10, 'a', 0.1)}, {Item(20, 'b', 0.2)}, {Item(30, 'c', 0.3)},
      {Item(40, 'd', 0.4)}, {Item(50, 'e', 0.5)}, {Item(60, 'f', 0.6)},
      {Item(70, 'g', 0.7)}, {Item(80, 'h', 0.8)}, {Item(90, 'i', 0.9)},
  };

  const std::set<Item, ComparatorItem> set{
      {Item(10, 'a', 0.1)}, {Item(20, 'b', 0.2)}, {Item(30, 'c', 0.3)},
      {Item(40, 'd', 0.4)}, {Item(50, 'e', 0.5)}, {Item(60, 'f', 0.6)},
      {Item(70, 'g', 0.7)}, {Item(80, 'h', 0.8)}, {Item(90, 'i', 0.9)},
  };

  EXPECT_EQ(*s21_set.Lower_bound(Item(45)), *set.lower_bound(Item(45)));
}

TEST(Set, T5LowerBound) {
  const s21::Set<Item, ComparatorItem> s21_set{
      {Item(10, 'a', 0.1)}, {Item(20, 'b', 0.2)}, {Item(30, 'c', 0.3)},
      {Item(40, 'd', 0.4)}, {Item(50, 'e', 0.5)}, {Item(60, 'f', 0.6)},
      {Item(70, 'g', 0.7)}, {Item(80, 'h', 0.8)}, {Item(90, 'i', 0.9)},
  };

  const std::set<Item, ComparatorItem> set{
      {Item(10, 'a', 0.1)}, {Item(20, 'b', 0.2)}, {Item(30, 'c', 0.3)},
      {Item(40, 'd', 0.4)}, {Item(50, 'e', 0.5)}, {Item(60, 'f', 0.6)},
      {Item(70, 'g', 0.7)}, {Item(80, 'h', 0.8)}, {Item(90, 'i', 0.9)},
  };

  EXPECT_EQ(*s21_set.Lower_bound(Item(55)), *set.lower_bound(Item(55)));
}

TEST(Set, T6LowerBound) {
  const s21::Set<Item, ComparatorItem> s21_set{
      {Item(10, 'a', 0.1)}, {Item(20, 'b', 0.2)}, {Item(30, 'c', 0.3)},
      {Item(40, 'd', 0.4)}, {Item(50, 'e', 0.5)}, {Item(60, 'f', 0.6)},
      {Item(70, 'g', 0.7)}, {Item(80, 'h', 0.8)}, {Item(90, 'i', 0.9)},
  };

  const std::set<Item, ComparatorItem> set{
      {Item(10, 'a', 0.1)}, {Item(20, 'b', 0.2)}, {Item(30, 'c', 0.3)},
      {Item(40, 'd', 0.4)}, {Item(50, 'e', 0.5)}, {Item(60, 'f', 0.6)},
      {Item(70, 'g', 0.7)}, {Item(80, 'h', 0.8)}, {Item(90, 'i', 0.9)},
  };

  EXPECT_EQ(*s21_set.Lower_bound(Item(65)), *set.lower_bound(Item(65)));
}

TEST(Set, T7LowerBound) {
  const s21::Set<Item, ComparatorItem> s21_set{
      {Item(10, 'a', 0.1)}, {Item(20, 'b', 0.2)}, {Item(30, 'c', 0.3)},
      {Item(40, 'd', 0.4)}, {Item(50, 'e', 0.5)}, {Item(60, 'f', 0.6)},
      {Item(70, 'g', 0.7)}, {Item(80, 'h', 0.8)}, {Item(90, 'i', 0.9)},
  };

  const std::set<Item, ComparatorItem> set{
      {Item(10, 'a', 0.1)}, {Item(20, 'b', 0.2)}, {Item(30, 'c', 0.3)},
      {Item(40, 'd', 0.4)}, {Item(50, 'e', 0.5)}, {Item(60, 'f', 0.6)},
      {Item(70, 'g', 0.7)}, {Item(80, 'h', 0.8)}, {Item(90, 'i', 0.9)},
  };

  EXPECT_EQ(*s21_set.Lower_bound(Item(75)), *set.lower_bound(Item(75)));
}

TEST(Set, T8LowerBound) {
  const s21::Set<Item, ComparatorItem> s21_set{
      {Item(10, 'a', 0.1)}, {Item(20, 'b', 0.2)}, {Item(30, 'c', 0.3)},
      {Item(40, 'd', 0.4)}, {Item(50, 'e', 0.5)}, {Item(60, 'f', 0.6)},
      {Item(70, 'g', 0.7)}, {Item(80, 'h', 0.8)}, {Item(90, 'i', 0.9)},
  };

  const std::set<Item, ComparatorItem> set{
      {Item(10, 'a', 0.1)}, {Item(20, 'b', 0.2)}, {Item(30, 'c', 0.3)},
      {Item(40, 'd', 0.4)}, {Item(50, 'e', 0.5)}, {Item(60, 'f', 0.6)},
      {Item(70, 'g', 0.7)}, {Item(80, 'h', 0.8)}, {Item(90, 'i', 0.9)},
  };

  EXPECT_EQ(*s21_set.Lower_bound(Item(85)), *set.lower_bound(Item(85)));
}

TEST(Set, T9LowerBound) {
  const s21::Set<Item, ComparatorItem> s21_set{
      {Item(10, 'a', 0.1)}, {Item(20, 'b', 0.2)}, {Item(30, 'c', 0.3)},
      {Item(40, 'd', 0.4)}, {Item(50, 'e', 0.5)}, {Item(60, 'f', 0.6)},
      {Item(70, 'g', 0.7)}, {Item(80, 'h', 0.8)}, {Item(90, 'i', 0.9)},
  };

  const std::set<Item, ComparatorItem> set{
      {Item(10, 'a', 0.1)}, {Item(20, 'b', 0.2)}, {Item(30, 'c', 0.3)},
      {Item(40, 'd', 0.4)}, {Item(50, 'e', 0.5)}, {Item(60, 'f', 0.6)},
      {Item(70, 'g', 0.7)}, {Item(80, 'h', 0.8)}, {Item(90, 'i', 0.9)},
  };

  EXPECT_EQ(s21_set.Lower_bound(Item(95)), s21_set.end());
  EXPECT_EQ(set.lower_bound(Item(95)), set.end());
}

TEST(Set, T10LowerBound) {
  const s21::Set<Item, ComparatorItem> s21_set{
      {Item(10, 'a', 0.1)}, {Item(20, 'b', 0.2)}, {Item(30, 'c', 0.3)},
      {Item(40, 'd', 0.4)}, {Item(50, 'e', 0.5)}, {Item(60, 'f', 0.6)},
      {Item(70, 'g', 0.7)}, {Item(80, 'h', 0.8)}, {Item(90, 'i', 0.9)},
  };

  const std::set<Item, ComparatorItem> set{
      {Item(10, 'a', 0.1)}, {Item(20, 'b', 0.2)}, {Item(30, 'c', 0.3)},
      {Item(40, 'd', 0.4)}, {Item(50, 'e', 0.5)}, {Item(60, 'f', 0.6)},
      {Item(70, 'g', 0.7)}, {Item(80, 'h', 0.8)}, {Item(90, 'i', 0.9)},
  };

  EXPECT_EQ(s21_set.Lower_bound(Item(105)), s21_set.end());
  EXPECT_EQ(set.lower_bound(Item(105)), set.end());
}

TEST(Set, T11LowerBound) {
  const s21::Set<Item, ComparatorItem> s21_set{
      {Item(10, 'a', 0.1)}, {Item(20, 'b', 0.2)}, {Item(30, 'c', 0.3)},
      {Item(40, 'd', 0.4)}, {Item(50, 'e', 0.5)}, {Item(60, 'f', 0.6)},
      {Item(70, 'g', 0.7)}, {Item(80, 'h', 0.8)}, {Item(90, 'i', 0.9)},
  };

  const std::set<Item, ComparatorItem> set{
      {Item(10, 'a', 0.1)}, {Item(20, 'b', 0.2)}, {Item(30, 'c', 0.3)},
      {Item(40, 'd', 0.4)}, {Item(50, 'e', 0.5)}, {Item(60, 'f', 0.6)},
      {Item(70, 'g', 0.7)}, {Item(80, 'h', 0.8)}, {Item(90, 'i', 0.9)},
  };

  EXPECT_EQ(*s21_set.Lower_bound(Item(10)), *set.lower_bound(Item(10)));
}

TEST(Set, T12LowerBound) {
  const s21::Set<Item, ComparatorItem> s21_set{
      {Item(10, 'a', 0.1)}, {Item(20, 'b', 0.2)}, {Item(30, 'c', 0.3)},
      {Item(40, 'd', 0.4)}, {Item(50, 'e', 0.5)}, {Item(60, 'f', 0.6)},
      {Item(70, 'g', 0.7)}, {Item(80, 'h', 0.8)}, {Item(90, 'i', 0.9)},
  };

  const std::set<Item, ComparatorItem> set{
      {Item(10, 'a', 0.1)}, {Item(20, 'b', 0.2)}, {Item(30, 'c', 0.3)},
      {Item(40, 'd', 0.4)}, {Item(50, 'e', 0.5)}, {Item(60, 'f', 0.6)},
      {Item(70, 'g', 0.7)}, {Item(80, 'h', 0.8)}, {Item(90, 'i', 0.9)},
  };

  EXPECT_EQ(*s21_set.Lower_bound(Item(20)), *set.lower_bound(Item(20)));
}

TEST(Set, T13LowerBound) {
  const s21::Set<Item, ComparatorItem> s21_set{
      {Item(10, 'a', 0.1)}, {Item(20, 'b', 0.2)}, {Item(30, 'c', 0.3)},
      {Item(40, 'd', 0.4)}, {Item(50, 'e', 0.5)}, {Item(60, 'f', 0.6)},
      {Item(70, 'g', 0.7)}, {Item(80, 'h', 0.8)}, {Item(90, 'i', 0.9)},
  };

  const std::set<Item, ComparatorItem> set{
      {Item(10, 'a', 0.1)}, {Item(20, 'b', 0.2)}, {Item(30, 'c', 0.3)},
      {Item(40, 'd', 0.4)}, {Item(50, 'e', 0.5)}, {Item(60, 'f', 0.6)},
      {Item(70, 'g', 0.7)}, {Item(80, 'h', 0.8)}, {Item(90, 'i', 0.9)},
  };

  EXPECT_EQ(*s21_set.Lower_bound(Item(30)), *set.lower_bound(Item(30)));
}

TEST(Set, T0UpperBound) {
  const s21::Set<Item, ComparatorItem> s21_set{
      {Item(10, 'a', 0.1)}, {Item(20, 'b', 0.2)}, {Item(30, 'c', 0.3)},
      {Item(40, 'd', 0.4)}, {Item(50, 'e', 0.5)}, {Item(60, 'f', 0.6)},
      {Item(70, 'g', 0.7)}, {Item(80, 'h', 0.8)}, {Item(90, 'i', 0.9)},
  };

  const std::set<Item, ComparatorItem> set{
      {Item(10, 'a', 0.1)}, {Item(20, 'b', 0.2)}, {Item(30, 'c', 0.3)},
      {Item(40, 'd', 0.4)}, {Item(50, 'e', 0.5)}, {Item(60, 'f', 0.6)},
      {Item(70, 'g', 0.7)}, {Item(80, 'h', 0.8)}, {Item(90, 'i', 0.9)},
  };

  // std::cout << s21_set.Upper_bound(30) << '\n';

  EXPECT_EQ(*s21_set.Upper_bound(Item(30)), *set.upper_bound(Item(30)));
}

TEST(Set, T1UpperBound) {
  const s21::Set<Item, ComparatorItem> s21_set{
      {Item(10, 'a', 0.1)}, {Item(20, 'b', 0.2)}, {Item(30, 'c', 0.3)},
      {Item(40, 'd', 0.4)}, {Item(50, 'e', 0.5)}, {Item(60, 'f', 0.6)},
      {Item(70, 'g', 0.7)}, {Item(80, 'h', 0.8)}, {Item(90, 'i', 0.9)},
  };

  const std::set<Item, ComparatorItem> set{
      {Item(10, 'a', 0.1)}, {Item(20, 'b', 0.2)}, {Item(30, 'c', 0.3)},
      {Item(40, 'd', 0.4)}, {Item(50, 'e', 0.5)}, {Item(60, 'f', 0.6)},
      {Item(70, 'g', 0.7)}, {Item(80, 'h', 0.8)}, {Item(90, 'i', 0.9)},
  };

  // std::cout << s21_set.Upper_bound(30) << '\n';

  EXPECT_EQ(*s21_set.Upper_bound(Item(25)), *set.upper_bound(Item(25)));
}

TEST(Set, T2UpperBound) {
  const s21::Set<Item, ComparatorItem> s21_set{
      {Item(10, 'a', 0.1)}, {Item(20, 'b', 0.2)}, {Item(30, 'c', 0.3)},
      {Item(40, 'd', 0.4)}, {Item(50, 'e', 0.5)}, {Item(60, 'f', 0.6)},
      {Item(70, 'g', 0.7)}, {Item(80, 'h', 0.8)}, {Item(90, 'i', 0.9)},
  };

  const std::set<Item, ComparatorItem> set{
      {Item(10, 'a', 0.1)}, {Item(20, 'b', 0.2)}, {Item(30, 'c', 0.3)},
      {Item(40, 'd', 0.4)}, {Item(50, 'e', 0.5)}, {Item(60, 'f', 0.6)},
      {Item(70, 'g', 0.7)}, {Item(80, 'h', 0.8)}, {Item(90, 'i', 0.9)},
  };

  EXPECT_EQ(*s21_set.Upper_bound(Item(25)), *set.upper_bound(Item(25)));
}

TEST(Set, T3UpperBound) {
  const s21::Set<Item, ComparatorItem> s21_set{
      {Item(10, 'a', 0.1)}, {Item(20, 'b', 0.2)}, {Item(30, 'c', 0.3)},
      {Item(40, 'd', 0.4)}, {Item(50, 'e', 0.5)}, {Item(60, 'f', 0.6)},
      {Item(70, 'g', 0.7)}, {Item(80, 'h', 0.8)}, {Item(90, 'i', 0.9)},
  };

  const std::set<Item, ComparatorItem> set{
      {Item(10, 'a', 0.1)}, {Item(20, 'b', 0.2)}, {Item(30, 'c', 0.3)},
      {Item(40, 'd', 0.4)}, {Item(50, 'e', 0.5)}, {Item(60, 'f', 0.6)},
      {Item(70, 'g', 0.7)}, {Item(80, 'h', 0.8)}, {Item(90, 'i', 0.9)},
  };

  EXPECT_EQ(*s21_set.Upper_bound(Item(35)), *set.upper_bound(Item(35)));
}

TEST(Set, T4UpperBound) {
  const s21::Set<Item, ComparatorItem> s21_set{
      {Item(10, 'a', 0.1)}, {Item(20, 'b', 0.2)}, {Item(30, 'c', 0.3)},
      {Item(40, 'd', 0.4)}, {Item(50, 'e', 0.5)}, {Item(60, 'f', 0.6)},
      {Item(70, 'g', 0.7)}, {Item(80, 'h', 0.8)}, {Item(90, 'i', 0.9)},
  };

  const std::set<Item, ComparatorItem> set{
      {Item(10, 'a', 0.1)}, {Item(20, 'b', 0.2)}, {Item(30, 'c', 0.3)},
      {Item(40, 'd', 0.4)}, {Item(50, 'e', 0.5)}, {Item(60, 'f', 0.6)},
      {Item(70, 'g', 0.7)}, {Item(80, 'h', 0.8)}, {Item(90, 'i', 0.9)},
  };

  EXPECT_EQ(*s21_set.Upper_bound(Item(45)), *set.upper_bound(Item(45)));
}

TEST(Set, T5UpperBound) {
  const s21::Set<Item, ComparatorItem> s21_set{
      {Item(10, 'a', 0.1)}, {Item(20, 'b', 0.2)}, {Item(30, 'c', 0.3)},
      {Item(40, 'd', 0.4)}, {Item(50, 'e', 0.5)}, {Item(60, 'f', 0.6)},
      {Item(70, 'g', 0.7)}, {Item(80, 'h', 0.8)}, {Item(90, 'i', 0.9)},
  };

  const std::set<Item, ComparatorItem> set{
      {Item(10, 'a', 0.1)}, {Item(20, 'b', 0.2)}, {Item(30, 'c', 0.3)},
      {Item(40, 'd', 0.4)}, {Item(50, 'e', 0.5)}, {Item(60, 'f', 0.6)},
      {Item(70, 'g', 0.7)}, {Item(80, 'h', 0.8)}, {Item(90, 'i', 0.9)},
  };

  EXPECT_EQ(*s21_set.Upper_bound(Item(55)), *set.upper_bound(Item(55)));
}

TEST(Set, T6UpperBound) {
  const s21::Set<Item, ComparatorItem> s21_set{
      {Item(10, 'a', 0.1)}, {Item(20, 'b', 0.2)}, {Item(30, 'c', 0.3)},
      {Item(40, 'd', 0.4)}, {Item(50, 'e', 0.5)}, {Item(60, 'f', 0.6)},
      {Item(70, 'g', 0.7)}, {Item(80, 'h', 0.8)}, {Item(90, 'i', 0.9)},
  };

  const std::set<Item, ComparatorItem> set{
      {Item(10, 'a', 0.1)}, {Item(20, 'b', 0.2)}, {Item(30, 'c', 0.3)},
      {Item(40, 'd', 0.4)}, {Item(50, 'e', 0.5)}, {Item(60, 'f', 0.6)},
      {Item(70, 'g', 0.7)}, {Item(80, 'h', 0.8)}, {Item(90, 'i', 0.9)},
  };

  EXPECT_EQ(*s21_set.Upper_bound(Item(65)), *set.upper_bound(Item(65)));
}

TEST(Set, T7UpperBound) {
  const s21::Set<Item, ComparatorItem> s21_set{
      {Item(10, 'a', 0.1)}, {Item(20, 'b', 0.2)}, {Item(30, 'c', 0.3)},
      {Item(40, 'd', 0.4)}, {Item(50, 'e', 0.5)}, {Item(60, 'f', 0.6)},
      {Item(70, 'g', 0.7)}, {Item(80, 'h', 0.8)}, {Item(90, 'i', 0.9)},
  };

  const std::set<Item, ComparatorItem> set{
      {Item(10, 'a', 0.1)}, {Item(20, 'b', 0.2)}, {Item(30, 'c', 0.3)},
      {Item(40, 'd', 0.4)}, {Item(50, 'e', 0.5)}, {Item(60, 'f', 0.6)},
      {Item(70, 'g', 0.7)}, {Item(80, 'h', 0.8)}, {Item(90, 'i', 0.9)},
  };

  EXPECT_EQ(*s21_set.Upper_bound(Item(75)), *set.upper_bound(Item(75)));
}

TEST(Set, T8UpperBound) {
  const s21::Set<Item, ComparatorItem> s21_set{
      {Item(10, 'a', 0.1)}, {Item(20, 'b', 0.2)}, {Item(30, 'c', 0.3)},
      {Item(40, 'd', 0.4)}, {Item(50, 'e', 0.5)}, {Item(60, 'f', 0.6)},
      {Item(70, 'g', 0.7)}, {Item(80, 'h', 0.8)}, {Item(90, 'i', 0.9)},
  };

  const std::set<Item, ComparatorItem> set{
      {Item(10, 'a', 0.1)}, {Item(20, 'b', 0.2)}, {Item(30, 'c', 0.3)},
      {Item(40, 'd', 0.4)}, {Item(50, 'e', 0.5)}, {Item(60, 'f', 0.6)},
      {Item(70, 'g', 0.7)}, {Item(80, 'h', 0.8)}, {Item(90, 'i', 0.9)},
  };

  EXPECT_EQ(*s21_set.Upper_bound(Item(85)), *set.upper_bound(Item(85)));
}

TEST(Set, T9UpperBound) {
  const s21::Set<Item, ComparatorItem> s21_set{
      {Item(10, 'a', 0.1)}, {Item(20, 'b', 0.2)}, {Item(30, 'c', 0.3)},
      {Item(40, 'd', 0.4)}, {Item(50, 'e', 0.5)}, {Item(60, 'f', 0.6)},
      {Item(70, 'g', 0.7)}, {Item(80, 'h', 0.8)}, {Item(90, 'i', 0.9)},
  };

  const std::set<Item, ComparatorItem> set{
      {Item(10, 'a', 0.1)}, {Item(20, 'b', 0.2)}, {Item(30, 'c', 0.3)},
      {Item(40, 'd', 0.4)}, {Item(50, 'e', 0.5)}, {Item(60, 'f', 0.6)},
      {Item(70, 'g', 0.7)}, {Item(80, 'h', 0.8)}, {Item(90, 'i', 0.9)},
  };

  EXPECT_EQ(s21_set.Upper_bound(Item(95)), s21_set.end());
  EXPECT_EQ(set.upper_bound(Item(95)), set.end());
}

TEST(Set, T10UpperBound) {
  const s21::Set<Item, ComparatorItem> s21_set{
      {Item(10, 'a', 0.1)}, {Item(20, 'b', 0.2)}, {Item(30, 'c', 0.3)},
      {Item(40, 'd', 0.4)}, {Item(50, 'e', 0.5)}, {Item(60, 'f', 0.6)},
      {Item(70, 'g', 0.7)}, {Item(80, 'h', 0.8)}, {Item(90, 'i', 0.9)},
  };

  const std::set<Item, ComparatorItem> set{
      {Item(10, 'a', 0.1)}, {Item(20, 'b', 0.2)}, {Item(30, 'c', 0.3)},
      {Item(40, 'd', 0.4)}, {Item(50, 'e', 0.5)}, {Item(60, 'f', 0.6)},
      {Item(70, 'g', 0.7)}, {Item(80, 'h', 0.8)}, {Item(90, 'i', 0.9)},
  };

  EXPECT_EQ(s21_set.Upper_bound(Item(105)), s21_set.end());
  EXPECT_EQ(set.upper_bound(Item(105)), set.end());
}

TEST(Set, T11UpperBound) {
  const s21::Set<Item, ComparatorItem> s21_set{
      {Item(10, 'a', 0.1)}, {Item(20, 'b', 0.2)}, {Item(30, 'c', 0.3)},
      {Item(40, 'd', 0.4)}, {Item(50, 'e', 0.5)}, {Item(60, 'f', 0.6)},
      {Item(70, 'g', 0.7)}, {Item(80, 'h', 0.8)}, {Item(90, 'i', 0.9)},
  };

  const std::set<Item, ComparatorItem> set{
      {Item(10, 'a', 0.1)}, {Item(20, 'b', 0.2)}, {Item(30, 'c', 0.3)},
      {Item(40, 'd', 0.4)}, {Item(50, 'e', 0.5)}, {Item(60, 'f', 0.6)},
      {Item(70, 'g', 0.7)}, {Item(80, 'h', 0.8)}, {Item(90, 'i', 0.9)},
  };

  EXPECT_EQ(*s21_set.Upper_bound(Item(10)), *set.upper_bound(Item(10)));
}

TEST(Set, T12UpperBound) {
  const s21::Set<Item, ComparatorItem> s21_set{
      {Item(10, 'a', 0.1)}, {Item(20, 'b', 0.2)}, {Item(30, 'c', 0.3)},
      {Item(40, 'd', 0.4)}, {Item(50, 'e', 0.5)}, {Item(60, 'f', 0.6)},
      {Item(70, 'g', 0.7)}, {Item(80, 'h', 0.8)}, {Item(90, 'i', 0.9)},
  };

  const std::set<Item, ComparatorItem> set{
      {Item(10, 'a', 0.1)}, {Item(20, 'b', 0.2)}, {Item(30, 'c', 0.3)},
      {Item(40, 'd', 0.4)}, {Item(50, 'e', 0.5)}, {Item(60, 'f', 0.6)},
      {Item(70, 'g', 0.7)}, {Item(80, 'h', 0.8)}, {Item(90, 'i', 0.9)},
  };

  EXPECT_EQ(*s21_set.Upper_bound(Item(20)), *set.upper_bound(Item(20)));
}

TEST(Set, T13UpperBound) {
  const s21::Set<Item, ComparatorItem> s21_set{
      {Item(10, 'a', 0.1)}, {Item(20, 'b', 0.2)}, {Item(30, 'c', 0.3)},
      {Item(40, 'd', 0.4)}, {Item(50, 'e', 0.5)}, {Item(60, 'f', 0.6)},
      {Item(70, 'g', 0.7)}, {Item(80, 'h', 0.8)}, {Item(90, 'i', 0.9)},
  };

  const std::set<Item, ComparatorItem> set{
      {Item(10, 'a', 0.1)}, {Item(20, 'b', 0.2)}, {Item(30, 'c', 0.3)},
      {Item(40, 'd', 0.4)}, {Item(50, 'e', 0.5)}, {Item(60, 'f', 0.6)},
      {Item(70, 'g', 0.7)}, {Item(80, 'h', 0.8)}, {Item(90, 'i', 0.9)},
  };

  EXPECT_EQ(*s21_set.Upper_bound(Item(30)), *set.upper_bound(Item(30)));
}

TEST(Set, T0EqualRangeEnd) {
  const s21::Set<Item, ComparatorItem> s21_set{
      {Item(10, 'a', 0.1)}, {Item(20, 'b', 0.2)}, {Item(30, 'c', 0.3)},
      {Item(40, 'd', 0.4)}, {Item(50, 'e', 0.5)}, {Item(60, 'f', 0.6)},
      {Item(70, 'g', 0.7)}, {Item(80, 'h', 0.8)}, {Item(90, 'i', 0.9)},
  };

  const std::set<Item, ComparatorItem> set{
      {Item(10, 'a', 0.1)}, {Item(20, 'b', 0.2)}, {Item(30, 'c', 0.3)},
      {Item(40, 'd', 0.4)}, {Item(50, 'e', 0.5)}, {Item(60, 'f', 0.6)},
      {Item(70, 'g', 0.7)}, {Item(80, 'h', 0.8)}, {Item(90, 'i', 0.9)},
  };

  const auto s21_pair = s21_set.Equal_range(Item(105));
  const auto pair = set.equal_range(Item(105));

  EXPECT_EQ(s21_pair.first, s21_set.end());
  EXPECT_EQ(s21_pair.second, s21_set.end());
  EXPECT_EQ(pair.first, set.end());
  EXPECT_EQ(pair.second, set.end());
}

TEST(Set, T1EqualRangeEnd) {
  const s21::Set<Item, ComparatorItem> s21_set{
      {Item(10, 'a', 0.1)}, {Item(20, 'b', 0.2)}, {Item(30, 'c', 0.3)},
      {Item(40, 'd', 0.4)}, {Item(50, 'e', 0.5)}, {Item(60, 'f', 0.6)},
      {Item(70, 'g', 0.7)}, {Item(80, 'h', 0.8)}, {Item(90, 'i', 0.9)},
  };

  const std::set<Item, ComparatorItem> set{
      {Item(10, 'a', 0.1)}, {Item(20, 'b', 0.2)}, {Item(30, 'c', 0.3)},
      {Item(40, 'd', 0.4)}, {Item(50, 'e', 0.5)}, {Item(60, 'f', 0.6)},
      {Item(70, 'g', 0.7)}, {Item(80, 'h', 0.8)}, {Item(90, 'i', 0.9)},
  };

  const auto s21_pair = s21_set.Equal_range(Item(500));
  const auto pair = set.equal_range(Item(500));

  EXPECT_EQ(s21_pair.first, s21_set.end());
  EXPECT_EQ(s21_pair.second, s21_set.end());
  EXPECT_EQ(pair.first, set.end());
  EXPECT_EQ(pair.second, set.end());
}

TEST(Set, T2EqualRange) {
  const s21::Set<Item, ComparatorItem> s21_set{
      {Item(10, 'a', 0.1)}, {Item(20, 'b', 0.2)}, {Item(30, 'c', 0.3)},
      {Item(40, 'd', 0.4)}, {Item(50, 'e', 0.5)}, {Item(60, 'f', 0.6)},
      {Item(70, 'g', 0.7)}, {Item(80, 'h', 0.8)}, {Item(90, 'i', 0.9)},
  };

  const std::set<Item, ComparatorItem> set{
      {Item(10, 'a', 0.1)}, {Item(20, 'b', 0.2)}, {Item(30, 'c', 0.3)},
      {Item(40, 'd', 0.4)}, {Item(50, 'e', 0.5)}, {Item(60, 'f', 0.6)},
      {Item(70, 'g', 0.7)}, {Item(80, 'h', 0.8)}, {Item(90, 'i', 0.9)},
  };

  const auto s21_pair = s21_set.Equal_range(Item(10));
  const auto pair = set.equal_range(Item(10));

  EXPECT_EQ(*(s21_pair.first), *(pair.first));
  EXPECT_EQ(*(s21_pair.second), *(pair.second));
}

TEST(Set, T3EqualRange) {
  const s21::Set<Item, ComparatorItem> s21_set{
      {Item(10, 'a', 0.1)}, {Item(20, 'b', 0.2)}, {Item(30, 'c', 0.3)},
      {Item(40, 'd', 0.4)}, {Item(50, 'e', 0.5)}, {Item(60, 'f', 0.6)},
      {Item(70, 'g', 0.7)}, {Item(80, 'h', 0.8)}, {Item(90, 'i', 0.9)},
  };

  const std::set<Item, ComparatorItem> set{
      {Item(10, 'a', 0.1)}, {Item(20, 'b', 0.2)}, {Item(30, 'c', 0.3)},
      {Item(40, 'd', 0.4)}, {Item(50, 'e', 0.5)}, {Item(60, 'f', 0.6)},
      {Item(70, 'g', 0.7)}, {Item(80, 'h', 0.8)}, {Item(90, 'i', 0.9)},
  };

  const auto s21_pair = s21_set.Equal_range(Item(20));
  const auto pair = set.equal_range(Item(20));

  EXPECT_EQ(*(s21_pair.first), *(pair.first));
  EXPECT_EQ(*(s21_pair.second), *(pair.second));
}

TEST(Set, T4EqualRange) {
  const s21::Set<Item, ComparatorItem> s21_set{
      {Item(10, 'a', 0.1)}, {Item(20, 'b', 0.2)}, {Item(30, 'c', 0.3)},
      {Item(40, 'd', 0.4)}, {Item(50, 'e', 0.5)}, {Item(60, 'f', 0.6)},
      {Item(70, 'g', 0.7)}, {Item(80, 'h', 0.8)}, {Item(90, 'i', 0.9)},
  };

  const std::set<Item, ComparatorItem> set{
      {Item(10, 'a', 0.1)}, {Item(20, 'b', 0.2)}, {Item(30, 'c', 0.3)},
      {Item(40, 'd', 0.4)}, {Item(50, 'e', 0.5)}, {Item(60, 'f', 0.6)},
      {Item(70, 'g', 0.7)}, {Item(80, 'h', 0.8)}, {Item(90, 'i', 0.9)},
  };

  const auto s21_pair = s21_set.Equal_range(Item(30));
  const auto pair = set.equal_range(Item(30));

  EXPECT_EQ(*(s21_pair.first), *(pair.first));
  EXPECT_EQ(*(s21_pair.second), *(pair.second));
}

TEST(Set, T5EqualRange) {
  const s21::Set<Item, ComparatorItem> s21_set{
      {Item(10, 'a', 0.1)}, {Item(20, 'b', 0.2)}, {Item(30, 'c', 0.3)},
      {Item(40, 'd', 0.4)}, {Item(50, 'e', 0.5)}, {Item(60, 'f', 0.6)},
      {Item(70, 'g', 0.7)}, {Item(80, 'h', 0.8)}, {Item(90, 'i', 0.9)},
  };

  const std::set<Item, ComparatorItem> set{
      {Item(10, 'a', 0.1)}, {Item(20, 'b', 0.2)}, {Item(30, 'c', 0.3)},
      {Item(40, 'd', 0.4)}, {Item(50, 'e', 0.5)}, {Item(60, 'f', 0.6)},
      {Item(70, 'g', 0.7)}, {Item(80, 'h', 0.8)}, {Item(90, 'i', 0.9)},
  };

  const auto s21_pair = s21_set.Equal_range(Item(35));
  const auto pair = set.equal_range(Item(35));

  EXPECT_EQ(*(s21_pair.first), *(pair.first));
  EXPECT_EQ(*(s21_pair.second), *(pair.second));
}

TEST(Set, T6EqualRange) {
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

  const auto s21_pair = s21_set.Equal_range(Item(40));
  const auto pair = set.equal_range(Item(40));

  EXPECT_EQ(*(s21_pair.first), *(pair.first));
  EXPECT_EQ(*(s21_pair.second), *(pair.second));
}

TEST(Set, T7EqualRange) {
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

  const auto s21_pair = s21_set.Equal_range(Item(45));
  const auto pair = set.equal_range(Item(45));

  EXPECT_EQ(*(s21_pair.first), *(pair.first));
  EXPECT_EQ(*(s21_pair.second), *(pair.second));
}

TEST(Set, T8EqualRange) {
  const s21::Set<Item, ComparatorItem> s21_set{
      {Item(10, 'a', 0.1)}, {Item(20, 'b', 0.2)}, {Item(30, 'c', 0.3)},
      {Item(40, 'd', 0.4)}, {Item(50, 'e', 0.5)}, {Item(60, 'f', 0.6)},
      {Item(70, 'g', 0.7)}, {Item(80, 'h', 0.8)}, {Item(90, 'i', 0.9)},
  };

  const std::set<Item, ComparatorItem> set{
      {Item(10, 'a', 0.1)}, {Item(20, 'b', 0.2)}, {Item(30, 'c', 0.3)},
      {Item(40, 'd', 0.4)}, {Item(50, 'e', 0.5)}, {Item(60, 'f', 0.6)},
      {Item(70, 'g', 0.7)}, {Item(80, 'h', 0.8)}, {Item(90, 'i', 0.9)},
  };

  const auto s21_pair = s21_set.Equal_range(Item(50, 'e', 0.5));
  const auto pair = set.equal_range(Item(50, 'e', 0.5));

  EXPECT_EQ(*(s21_pair.first), *(pair.first));
  EXPECT_EQ(*(s21_pair.second), *(pair.second));

  // s21::BaseNode b;
  // s21::SingleNode s;
  // s21::MultiNode m;
  // static_assert(0 && "??");
}

}  // namespace

// GCOVR_EXCL_STOP