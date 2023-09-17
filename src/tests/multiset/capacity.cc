#include <gtest/gtest.h>

#include <set>

#include "../../s21_multiset.h"
#include "../item.h"
#include "../multiset_helpers.h"

// GCOVR_EXCL_START

namespace {

TEST(MultiSet, T0Empty) {
  s21::MultiSet<Item, ComparatorItem> s21_multiset;
  std::multiset<Item, ComparatorItem> multiset;

  EXPECT_EQ(s21_multiset.Empty(), multiset.empty());
}

TEST(MultiSet, T1Empty) {
  s21::MultiSet<Item, ComparatorItem> s21_multiset{
      {Item(1, 'a', 0.1)}, {Item(2, 'b', 0.2)}, {Item(3, 'c', 0.3)},
      {Item(4, 'd', 0.4)}, {Item(5, 'e', 0.5)}, {Item(6, 'f', 0.6)},
  };
  std::multiset<Item, ComparatorItem> multiset{
      {Item(1, 'a', 0.1)}, {Item(2, 'b', 0.2)}, {Item(3, 'c', 0.3)},
      {Item(4, 'd', 0.4)}, {Item(5, 'e', 0.5)}, {Item(6, 'f', 0.6)},
  };

  EXPECT_EQ(s21_multiset.Empty(), multiset.empty());
}

TEST(MultiSet, T0Size) {
  s21::MultiSet<Item, ComparatorItem> s21_multiset{
      {Item(6, 'f', 0.6)}, {Item(1, 'a', 0.1)}, {Item(1, 'a', 0.1)},
      {Item(1, 'a', 0.1)}, {Item(1, 'a', 0.1)}, {Item(4, 'd', 0.4)},
      {Item(3, 'c', 0.3)}, {Item(3, 'c', 0.3)}, {Item(2, 'b', 0.2)},
      {Item(2, 'b', 0.2)}, {Item(2, 'b', 0.2)}, {Item(3, 'c', 0.3)},
      {Item(3, 'c', 0.3)}, {Item(3, 'c', 0.3)}, {Item(4, 'd', 0.4)},
      {Item(4, 'd', 0.4)}, {Item(5, 'e', 0.5)}, {Item(6, 'f', 0.6)},
  };
  std::multiset<Item, ComparatorItem> multiset{
      {Item(6, 'f', 0.6)}, {Item(1, 'a', 0.1)}, {Item(1, 'a', 0.1)},
      {Item(1, 'a', 0.1)}, {Item(1, 'a', 0.1)}, {Item(4, 'd', 0.4)},
      {Item(3, 'c', 0.3)}, {Item(3, 'c', 0.3)}, {Item(2, 'b', 0.2)},
      {Item(2, 'b', 0.2)}, {Item(2, 'b', 0.2)}, {Item(3, 'c', 0.3)},
      {Item(3, 'c', 0.3)}, {Item(3, 'c', 0.3)}, {Item(4, 'd', 0.4)},
      {Item(4, 'd', 0.4)}, {Item(5, 'e', 0.5)}, {Item(6, 'f', 0.6)},
  };

  EXPECT_EQ(s21_multiset.Size(), multiset.size());
}

TEST(MultiSet, T1Size) {
  s21::MultiSet<Item, ComparatorItem> s21_multiset{
      {Item(3, 'c', 0.3)}, {Item(1, 'a', 0.1)}, {Item(2, 'b', 0.2)},
      {Item(2, 'b', 0.2)}, {Item(3, 'c', 0.3)},
  };
  std::multiset<Item, ComparatorItem> multiset{
      {Item(3, 'c', 0.3)}, {Item(1, 'a', 0.1)}, {Item(2, 'b', 0.2)},
      {Item(2, 'b', 0.2)}, {Item(3, 'c', 0.3)},
  };

  EXPECT_EQ(s21_multiset.Size(), multiset.size());
}

}  // namespace

// GCOVR_EXCL_STOP
