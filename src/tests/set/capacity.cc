#include <gtest/gtest.h>

#include <deque>
#include <list>
#include <set>
#include <stack>
#include <vector>

#include "../../s21_set.h"
#include "../item.h"
#include "../set_helpers.h"

// GCOVR_EXCL_START

namespace {

TEST(Set, T0Empty) {
  s21::Set<Item, ComparatorItem> s21_set;
  std::set<Item, ComparatorItem> set;

  EXPECT_EQ(s21_set.Empty(), set.empty());
}

TEST(Set, T1Empty) {
  s21::Set<Item, ComparatorItem> s21_set{
      {Item(1, 'a', 0.1)}, {Item(2, 'b', 0.2)}, {Item(3, 'c', 0.3)},
      {Item(4, 'd', 0.4)}, {Item(5, 'e', 0.5)}, {Item(6, 'f', 0.6)},
  };
  std::set<Item, ComparatorItem> set{
      {Item(1, 'a', 0.1)}, {Item(2, 'b', 0.2)}, {Item(3, 'c', 0.3)},
      {Item(4, 'd', 0.4)}, {Item(5, 'e', 0.5)}, {Item(6, 'f', 0.6)},
  };

  EXPECT_EQ(s21_set.Empty(), set.empty());
}

TEST(Set, T0Size) {
  s21::Set<Item, ComparatorItem> s21_set{
      {Item(1, 'a', 0.1)}, {Item(2, 'b', 0.2)}, {Item(3, 'c', 0.3)},
      {Item(4, 'd', 0.4)}, {Item(5, 'e', 0.5)}, {Item(6, 'f', 0.6)},
  };
  std::set<Item, ComparatorItem> set{
      {Item(1, 'a', 0.1)}, {Item(2, 'b', 0.2)}, {Item(3, 'c', 0.3)},
      {Item(4, 'd', 0.4)}, {Item(5, 'e', 0.5)}, {Item(6, 'f', 0.6)},
  };

  EXPECT_EQ(s21_set.Size(), set.size());
}

TEST(Set, T1Size) {
  s21::Set<Item, ComparatorItem> s21_set{
      {Item(1, 'a', 0.1)},
      {Item(2, 'b', 0.2)},
      {Item(3, 'c', 0.3)},
  };
  std::set<Item, ComparatorItem> set{
      {Item(1, 'a', 0.1)},
      {Item(2, 'b', 0.2)},
      {Item(3, 'c', 0.3)},
  };
  EXPECT_EQ(s21_set.Size(), set.size());
}

}  // namespace

// GCOVR_EXCL_STOP
