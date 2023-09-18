#include <gtest/gtest.h>

#include <map>

#include "../../s21_map.h"
#include "../item.h"
#include "../map_helpers.h"

// GCOVR_EXCL_START

namespace {

TEST(Map, T0OperatorSubscript) {
  s21::Map<int, Item> s21_map;
  std::map<int, Item> map;

  const Item s21_result = s21_map[666];
  const Item result = map[666];

  EXPECT_EQ(s21_map, map);
  EXPECT_EQ(s21_result, result);
}

TEST(Map, T1OperatorSubscript) {
  s21::Map<int, Item> s21_map{
      {1, Item(1, 'a', 0.1)}, {2, Item(2, 'b', 0.2)}, {3, Item(3, 'c', 0.3)},
      {4, Item(4, 'd', 0.4)}, {5, Item(5, 'e', 0.5)}, {6, Item(6, 'f', 0.6)},
  };
  std::map<int, Item> map{
      {1, Item(1, 'a', 0.1)}, {2, Item(2, 'b', 0.2)}, {3, Item(3, 'c', 0.3)},
      {4, Item(4, 'd', 0.4)}, {5, Item(5, 'e', 0.5)}, {6, Item(6, 'f', 0.6)},
  };

  const Item s21_result = s21_map[666];
  const Item result = map[666];

  EXPECT_EQ(s21_map, map);
  EXPECT_EQ(s21_result, result);

  EXPECT_EQ(s21_map.Empty(), map.empty());
  EXPECT_EQ(s21_map, map);
  EXPECT_EQ(s21_result, result);
}

TEST(Map, T0AtNotFound) {
  s21::Map<int, Item> s21_map{
      {1, Item(1, 'a', 0.1)}, {2, Item(2, 'b', 0.2)}, {3, Item(3, 'c', 0.3)},
      {4, Item(4, 'd', 0.4)}, {5, Item(5, 'e', 0.5)}, {6, Item(6, 'f', 0.6)},
  };

  EXPECT_THROW(s21_map.At(666), std::out_of_range);
}

TEST(Map, T1AtConstNotFound) {
  const s21::Map<int, Item> s21_map{
      {1, Item(1, 'a', 0.1)}, {2, Item(2, 'b', 0.2)}, {3, Item(3, 'c', 0.3)},
      {4, Item(4, 'd', 0.4)}, {5, Item(5, 'e', 0.5)}, {6, Item(6, 'f', 0.6)},
  };

  EXPECT_THROW(s21_map.At(666), std::out_of_range);
}

TEST(Map, T2At) {
  s21::Map<int, Item> s21_map{
      {1, Item(1, 'a', 0.1)}, {2, Item(2, 'b', 0.2)}, {3, Item(3, 'c', 0.3)},
      {4, Item(4, 'd', 0.4)}, {5, Item(5, 'e', 0.5)}, {6, Item(6, 'f', 0.6)},
  };

  EXPECT_EQ(s21_map.At(5), Item(5, 'e', 0.5));
}

TEST(Map, T3AtConst) {
  const s21::Map<int, Item> s21_map{
      {1, Item(1, 'a', 0.1)}, {2, Item(2, 'b', 0.2)}, {3, Item(3, 'c', 0.3)},
      {4, Item(4, 'd', 0.4)}, {5, Item(5, 'e', 0.5)}, {6, Item(6, 'f', 0.6)},
  };

  EXPECT_EQ(s21_map.At(5), Item(5, 'e', 0.5));
}

TEST(Map, T4At) {
  s21::Map<int, Item> s21_map{
      {1, Item(1, 'a', 0.1)}, {2, Item(2, 'b', 0.2)}, {3, Item(3, 'c', 0.3)},
      {4, Item(4, 'd', 0.4)}, {5, Item(5, 'e', 0.5)}, {6, Item(6, 'f', 0.6)},
  };
  std::map<int, Item> map{
      {1, Item(1, 'a', 0.1)}, {2, Item(2, 'b', 0.2)}, {3, Item(3, 'c', 0.3)},
      {4, Item(4, 'd', 0.4)}, {5, Item(5, 'e', 0.5)}, {6, Item(6, 'f', 0.6)},
  };

  s21_map.At(5) = Item(555);
  map.at(5) = Item(555);

  EXPECT_EQ(s21_map, map);
}

TEST(Map, T5At) {
  s21::Map<int, Item> s21_map{
      {1, Item(1, 'a', 0.1)}, {2, Item(2, 'b', 0.2)}, {3, Item(3, 'c', 0.3)},
      {4, Item(4, 'd', 0.4)}, {5, Item(5, 'e', 0.5)}, {6, Item(6, 'f', 0.6)},
  };
  std::map<int, Item> map{
      {1, Item(1, 'a', 0.1)}, {2, Item(2, 'b', 0.2)}, {3, Item(3, 'c', 0.3)},
      {4, Item(4, 'd', 0.4)}, {5, Item(5, 'e', 0.5)}, {6, Item(6, 'f', 0.6)},
  };

  s21_map.At(5) = Item(555);
  map.at(5) = Item(555);

  EXPECT_EQ(s21_map, map);
}

}  // namespace

// GCOVR_EXCL_STOP
