#include <gtest/gtest.h>

#include <map>

#include "../../s21_multimap.h"
#include "../item.h"
#include "../multimap_helpers.h"

// GCOVR_EXCL_START

namespace {

TEST(Multimap, T0Empty) {
  s21::MultiMap<int, Item> s21_multimap;
  std::multimap<int, Item> multimap;

  EXPECT_EQ(s21_multimap.Empty(), multimap.empty());
}

TEST(Multimap, T1Empty) {
  s21::MultiMap<int, Item> s21_multimap{
      {1, Item(1, 'a', 0.1)}, {2, Item(2, 'b', 0.2)}, {3, Item(3, 'c', 0.3)},
      {4, Item(4, 'd', 0.4)}, {5, Item(5, 'e', 0.5)}, {6, Item(6, 'f', 0.6)},
  };
  std::multimap<int, Item> multimap{
      {1, Item(1, 'a', 0.1)}, {2, Item(2, 'b', 0.2)}, {3, Item(3, 'c', 0.3)},
      {4, Item(4, 'd', 0.4)}, {5, Item(5, 'e', 0.5)}, {6, Item(6, 'f', 0.6)},
  };

  EXPECT_EQ(s21_multimap.Empty(), multimap.empty());
}

TEST(Multimap, T0Size) {
  s21::MultiMap<int, Item> s21_multimap{
      {1, Item(1, 'a', 0.1)}, {2, Item(2, 'b', 0.2)}, {3, Item(3, 'c', 0.3)},
      {4, Item(4, 'd', 0.4)}, {5, Item(5, 'e', 0.5)}, {6, Item(6, 'f', 0.6)},
  };
  std::multimap<int, Item> multimap{
      {1, Item(1, 'a', 0.1)}, {2, Item(2, 'b', 0.2)}, {3, Item(3, 'c', 0.3)},
      {4, Item(4, 'd', 0.4)}, {5, Item(5, 'e', 0.5)}, {6, Item(6, 'f', 0.6)},
  };

  EXPECT_EQ(s21_multimap.Size(), multimap.size());
}

TEST(Multimap, T1Size) {
  s21::MultiMap<int, Item> s21_multimap{
      {2, Item(2, 'b', 0.2)}, {3, Item(3, 'c', 0.3)}, {1, Item(1, 'a', 0.1)},
      {3, Item(3, 'c', 0.3)}, {1, Item(1, 'a', 0.1)}, {1, Item(1, 'a', 0.1)},
      {1, Item(1, 'a', 0.1)}, {1, Item(1, 'a', 0.1)}, {2, Item(2, 'b', 0.2)},
      {2, Item(2, 'b', 0.2)}, {2, Item(2, 'b', 0.2)}, {2, Item(2, 'b', 0.2)},
      {2, Item(2, 'b', 0.2)}, {3, Item(3, 'c', 0.3)}, {3, Item(3, 'c', 0.3)},
  };
  std::multimap<int, Item> multimap{
      {2, Item(2, 'b', 0.2)}, {3, Item(3, 'c', 0.3)}, {1, Item(1, 'a', 0.1)},
      {3, Item(3, 'c', 0.3)}, {1, Item(1, 'a', 0.1)}, {1, Item(1, 'a', 0.1)},
      {1, Item(1, 'a', 0.1)}, {1, Item(1, 'a', 0.1)}, {2, Item(2, 'b', 0.2)},
      {2, Item(2, 'b', 0.2)}, {2, Item(2, 'b', 0.2)}, {2, Item(2, 'b', 0.2)},
      {2, Item(2, 'b', 0.2)}, {3, Item(3, 'c', 0.3)}, {3, Item(3, 'c', 0.3)},
  };

  EXPECT_EQ(s21_multimap.Size(), multimap.size());
}

}  // namespace

// GCOVR_EXCL_STOP
