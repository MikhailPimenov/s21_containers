#include <gtest/gtest.h>

#include <map>

#include "../../s21_multimap.h"
#include "../item.h"
#include "../multimap_helpers.h"

// GCOVR_EXCL_START

namespace {

TEST(MultiMap, T0Insert) {
  s21::MultiMap<int, Item> s21_multimap;
  s21_multimap.Insert(std::make_pair(4, Item(4)));
  s21_multimap.Insert(std::make_pair(6, Item(6)));
  s21_multimap.Insert(std::make_pair(7, Item(7)));
  s21_multimap.Insert(std::make_pair(1, Item(1)));

  std::multimap<int, Item> multimap;
  multimap.insert(std::make_pair(4, Item(4)));
  multimap.insert(std::make_pair(6, Item(6)));
  multimap.insert(std::make_pair(7, Item(7)));
  multimap.insert(std::make_pair(1, Item(1)));

  EXPECT_EQ(s21_multimap, multimap);
}

TEST(MultiMap, T1Insert) {
  s21::MultiMap<int, Item> s21_multimap;
  s21_multimap.Insert(std::make_pair(1, Item(1)));
  s21_multimap.Insert(std::make_pair(4, Item(4)));
  s21_multimap.Insert(std::make_pair(6, Item(6)));
  s21_multimap.Insert(std::make_pair(7, Item(7)));

  std::multimap<int, Item> multimap;
  multimap.insert(std::make_pair(1, Item(1)));
  multimap.insert(std::make_pair(4, Item(4)));
  multimap.insert(std::make_pair(6, Item(6)));
  multimap.insert(std::make_pair(7, Item(7)));

  EXPECT_EQ(s21_multimap, multimap);
}

TEST(MultiMap, T2Insert) {
  s21::MultiMap<int, Item> s21_multimap;
  s21_multimap.Insert(std::make_pair(1, Item(1)));

  std::multimap<int, Item> multimap;
  multimap.insert(std::make_pair(1, Item(1)));

  EXPECT_EQ(s21_multimap, multimap);
}

TEST(MultiMap, T3Insert) {
  s21::MultiMap<int, Item> s21_multimap;
  s21_multimap.Insert(std::make_pair(-4, Item(4)));
  s21_multimap.Insert(std::make_pair(6, Item(6)));
  s21_multimap.Insert(std::make_pair(7, Item(7)));
  s21_multimap.Insert(std::make_pair(1, Item(1)));

  std::multimap<int, Item> multimap;
  multimap.insert(std::make_pair(-4, Item(4)));
  multimap.insert(std::make_pair(6, Item(6)));
  multimap.insert(std::make_pair(7, Item(7)));
  multimap.insert(std::make_pair(1, Item(1)));

  EXPECT_EQ(s21_multimap, multimap);
}

TEST(MultiMap, T4Insert) {
  s21::MultiMap<int, Item> s21_multimap;
  s21_multimap.Insert(std::make_pair(-4, Item(4)));
  s21_multimap.Insert(std::make_pair(-6, Item(6)));
  s21_multimap.Insert(std::make_pair(-7, Item(7)));
  s21_multimap.Insert(std::make_pair(-1, Item(1)));

  std::multimap<int, Item> multimap;
  multimap.insert(std::make_pair(-4, Item(4)));
  multimap.insert(std::make_pair(-6, Item(6)));
  multimap.insert(std::make_pair(-7, Item(7)));
  multimap.insert(std::make_pair(-1, Item(1)));

  EXPECT_EQ(s21_multimap, multimap);
}

TEST(MultiMap, T5Insert) {
  s21::MultiMap<int, Item> s21_multimap;
  s21_multimap.Insert(std::make_pair(-4, Item(4)));
  s21_multimap.Insert(std::make_pair(6, Item(6)));
  s21_multimap.Insert(std::make_pair(0, Item(7)));
  s21_multimap.Insert(std::make_pair(-1, Item(1)));

  std::multimap<int, Item> multimap;
  multimap.insert(std::make_pair(-4, Item(4)));
  multimap.insert(std::make_pair(6, Item(6)));
  multimap.insert(std::make_pair(0, Item(7)));
  multimap.insert(std::make_pair(-1, Item(1)));

  EXPECT_EQ(s21_multimap, multimap);
}

TEST(MultiMap, T0Clear) {
  s21::MultiMap<int, Item> s21_multimap{
      {10, Item(10, 'a', 0.1)}, {20, Item(20, 'b', 0.2)},
      {30, Item(30, 'c', 0.3)}, {40, Item(40, 'd', 0.4)},
      {50, Item(50, 'e', 0.5)}, {60, Item(60, 'f', 0.6)},
      {70, Item(70, 'g', 0.7)}, {80, Item(80, 'h', 0.8)},
      {90, Item(90, 'i', 0.9)},
  };

  std::multimap<int, Item> multimap{
      {10, Item(10, 'a', 0.1)}, {20, Item(20, 'b', 0.2)},
      {30, Item(30, 'c', 0.3)}, {40, Item(40, 'd', 0.4)},
      {50, Item(50, 'e', 0.5)}, {60, Item(60, 'f', 0.6)},
      {70, Item(70, 'g', 0.7)}, {80, Item(80, 'h', 0.8)},
      {90, Item(90, 'i', 0.9)},
  };

  s21_multimap.Clear();
  multimap.clear();

  EXPECT_EQ(s21_multimap, multimap);
}

TEST(MultiMap, T1ClearEmpty) {
  s21::MultiMap<int, Item> s21_multimap;
  std::multimap<int, Item> multimap;

  s21_multimap.Clear();
  multimap.clear();

  EXPECT_EQ(s21_multimap, multimap);
}

}  // namespace

// GCOVR_EXCL_STOP
