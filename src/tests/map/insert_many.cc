#include <gtest/gtest.h>

#include <map>

#include "../../s21_map.h"
#include "../../s21_vector.h"
#include "../item.h"
#include "../map_helpers.h"
#include "../vector_helpers.h"

//  GCOVR_EXCL_START
// template <typename Key, typename Value>
// bool operator==(const std::pair<const Key, Value>& left, const
// std::pair<const Key, Value>& right) {
//     return (left.first == right.first && right.second == left.second);
// }

// template <typename Key, typename Value>
// bool operator!=(const std::pair<const Key, Value>& left, const
// std::pair<const Key, Value>& right) {
//     return !(left == right);
// }

// template <typename Key, typename Value>
// std::ostream& operator<<(std::ostream& out, const std::pair<const Key,
// Value>& object) {
//     assert(0);
//     out<< "{ " << object.first << ": " << object.second << "}\n";
//     return out;
// }

// template <typename Key, typename Value>
// std::ostream& operator<<(std::ostream& out, typename s21::Map<const Key,
// Value>::iterator it) {
//     assert(0);
//     out<< "{ " << *it << "}\n";
//     return out;
// }

namespace {
TEST(Map, T0InsertManyBack) {
  s21::Map<int, Item> s21_map{
      {11, Item(11)}, {22, Item(22)}, {33, Item(33)},
      {44, Item(44)}, {55, Item(55)}, {66, Item(66)},
  };

  s21::Map<int, Item> s21_map_expected{
      {11, Item(11)}, {22, Item(22)}, {33, Item(33)},   {44, Item(44)},
      {55, Item(55)}, {66, Item(66)}, {666, Item(666)}, {777, Item(777)},
  };

  s21_map.Insert_many(std::make_pair(666, Item(666)),
                      std::make_pair(777, Item(777)));

  EXPECT_EQ(s21_map, s21_map_expected);
}

TEST(Map, T1InsertManyEmptyBack) {
  s21::Map<int, Item> s21_map;

  s21::Map<int, Item> s21_map_expected{
      {11, Item(11)}, {22, Item(22)}, {33, Item(33)},   {44, Item(44)},
      {55, Item(55)}, {66, Item(66)}, {666, Item(666)}, {777, Item(777)},
  };

  s21::Vector<std::pair<s21::Map<int, Item>::iterator, bool>> s21_result =
      s21_map.Insert_many(
          std::make_pair(11, Item(11)), std::make_pair(22, Item(22)),
          std::make_pair(33, Item(33)), std::make_pair(44, Item(44)),
          std::make_pair(55, Item(55)), std::make_pair(66, Item(66)),
          std::make_pair(666, Item(666)), std::make_pair(777, Item(777)));

  EXPECT_EQ(s21_map, s21_map_expected);
}

TEST(Map, T0InsertMany) {
  s21::Map<int, Item> s21_map;
  s21::Map<int, Item> s21_map2 = s21_map;

  s21::Map<int, Item> s21_map_expected{
      {11, Item(11)}, {22, Item(22)}, {33, Item(33)},   {44, Item(44)},
      {55, Item(55)}, {66, Item(66)}, {666, Item(666)}, {777, Item(777)},
  };

  s21::Vector<std::pair<s21::Map<int, Item>::iterator, bool>>
      s21_result_expected;
  s21_result_expected.Push_back(s21_map2.Insert(std::make_pair(11, Item(11))));
  s21_result_expected.Push_back(s21_map2.Insert(std::make_pair(22, Item(22))));
  s21_result_expected.Push_back(s21_map2.Insert(std::make_pair(33, Item(33))));
  s21_result_expected.Push_back(s21_map2.Insert(std::make_pair(44, Item(44))));
  s21_result_expected.Push_back(s21_map2.Insert(std::make_pair(55, Item(55))));
  s21_result_expected.Push_back(s21_map2.Insert(std::make_pair(66, Item(66))));
  s21_result_expected.Push_back(
      s21_map2.Insert(std::make_pair(666, Item(666))));
  s21_result_expected.Push_back(
      s21_map2.Insert(std::make_pair(777, Item(777))));

  s21::Vector<std::pair<s21::Map<int, Item>::iterator, bool>> s21_result =
      s21_map.Insert_many(
          std::make_pair(11, Item(11)), std::make_pair(22, Item(22)),
          std::make_pair(33, Item(33)), std::make_pair(44, Item(44)),
          std::make_pair(55, Item(55)), std::make_pair(66, Item(66)),
          std::make_pair(666, Item(666)), std::make_pair(777, Item(777)));

  EXPECT_EQ(s21_map, s21_map_expected);
  EXPECT_EQ(s21_map2, s21_map_expected);

  EXPECT_EQ(s21_result.Size(), s21_result_expected.Size());
  auto it = s21_result.begin();
  auto it_expected = s21_result_expected.begin();

  while (it != s21_result.end() && it_expected != s21_result_expected.end()) {
    EXPECT_EQ(*(it->first), *(it_expected->first));
    EXPECT_EQ(it->second, it_expected->second);
    ++it;
    ++it_expected;
  }
}

TEST(Map, T1InsertMany) {
  s21::Map<int, Item> s21_map{
      {44, Item(44)},
      {55, Item(55)},
  };
  s21::Map<int, Item> s21_map2 = s21_map;

  s21::Map<int, Item> s21_map_expected{
      {11, Item(11)}, {22, Item(22)}, {33, Item(33)},   {44, Item(44)},
      {55, Item(55)}, {66, Item(66)}, {666, Item(666)}, {777, Item(777)},
  };

  s21::Vector<std::pair<s21::Map<int, Item>::iterator, bool>>
      s21_result_expected;
  s21_result_expected.Push_back(s21_map2.Insert(std::make_pair(11, Item(11))));
  s21_result_expected.Push_back(s21_map2.Insert(std::make_pair(22, Item(22))));
  s21_result_expected.Push_back(s21_map2.Insert(std::make_pair(33, Item(33))));
  s21_result_expected.Push_back(s21_map2.Insert(std::make_pair(44, Item(44))));
  s21_result_expected.Push_back(s21_map2.Insert(std::make_pair(55, Item(55))));
  s21_result_expected.Push_back(s21_map2.Insert(std::make_pair(66, Item(66))));
  s21_result_expected.Push_back(
      s21_map2.Insert(std::make_pair(666, Item(666))));
  s21_result_expected.Push_back(
      s21_map2.Insert(std::make_pair(777, Item(777))));

  s21::Vector<std::pair<s21::Map<int, Item>::iterator, bool>> s21_result =
      s21_map.Insert_many(
          std::make_pair(11, Item(11)), std::make_pair(22, Item(22)),
          std::make_pair(33, Item(33)), std::make_pair(44, Item(44)),
          std::make_pair(55, Item(55)), std::make_pair(66, Item(66)),
          std::make_pair(666, Item(666)), std::make_pair(777, Item(777)));

  EXPECT_EQ(s21_map, s21_map_expected);
  EXPECT_EQ(s21_map2, s21_map_expected);

  EXPECT_EQ(s21_result.Size(), s21_result_expected.Size());
  auto it = s21_result.begin();
  auto it_expected = s21_result_expected.begin();

  while (it != s21_result.end() && it_expected != s21_result_expected.end()) {
    EXPECT_EQ(*(it->first), *(it_expected->first));
    EXPECT_EQ(it->second, it_expected->second);
    ++it;
    ++it_expected;
  }
}

TEST(Map, T2InsertMany) {
  s21::Map<int, Item> s21_map{
      {111, Item(111, 's', 0.111)},
      {44, Item(44)},
      {55, Item(55)},
  };
  s21::Map<int, Item> s21_map2 = s21_map;

  s21::Map<int, Item> s21_map_expected{
      {111, Item(111, 's', 0.111)},
      {11, Item(11)},
      {22, Item(22)},
      {33, Item(33)},
      {44, Item(44)},
      {55, Item(55)},
      {66, Item(66)},
      {666, Item(666)},
      {777, Item(777)},
  };

  s21::Vector<std::pair<s21::Map<int, Item>::iterator, bool>>
      s21_result_expected;
  s21_result_expected.Push_back(s21_map2.Insert(std::make_pair(11, Item(11))));
  s21_result_expected.Push_back(s21_map2.Insert(std::make_pair(22, Item(22))));
  s21_result_expected.Push_back(s21_map2.Insert(std::make_pair(33, Item(33))));
  s21_result_expected.Push_back(s21_map2.Insert(std::make_pair(44, Item(44))));
  s21_result_expected.Push_back(s21_map2.Insert(std::make_pair(55, Item(55))));
  s21_result_expected.Push_back(s21_map2.Insert(std::make_pair(66, Item(66))));
  s21_result_expected.Push_back(
      s21_map2.Insert(std::make_pair(666, Item(666))));
  s21_result_expected.Push_back(
      s21_map2.Insert(std::make_pair(777, Item(777))));

  s21::Vector<std::pair<s21::Map<int, Item>::iterator, bool>> s21_result =
      s21_map.Insert_many(
          std::make_pair(11, Item(11)), std::make_pair(22, Item(22)),
          std::make_pair(33, Item(33)), std::make_pair(44, Item(44)),
          std::make_pair(55, Item(55)), std::make_pair(66, Item(66)),
          std::make_pair(666, Item(666)), std::make_pair(777, Item(777)));

  EXPECT_EQ(s21_map, s21_map_expected);
  EXPECT_EQ(s21_map2, s21_map_expected);

  EXPECT_EQ(s21_result.Size(), s21_result_expected.Size());
  auto it = s21_result.begin();
  auto it_expected = s21_result_expected.begin();

  while (it != s21_result.end() && it_expected != s21_result_expected.end()) {
    EXPECT_EQ(*(it->first), *(it_expected->first));
    EXPECT_EQ(it->second, it_expected->second);
    ++it;
    ++it_expected;
  }
}

}  // namespace

//  GCOVR_EXCL_STOP