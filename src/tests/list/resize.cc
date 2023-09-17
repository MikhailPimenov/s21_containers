#include <gtest/gtest.h>

#include <list>

#include "../../s21_list.h"
#include "../item.h"
#include "../list_helpers.h"

//  GCOVR_EXCL_START

namespace {
TEST(List, T0ResizeCountValue) {
  s21::List<Item> s21_list = {
      Item(11), Item(22), Item(33), Item(44), Item(55), Item(66),
  };
  s21_list.Resize(6, Item(666));

  std::list<Item> list = {
      Item(11), Item(22), Item(33), Item(44), Item(55), Item(66),
  };

  list.resize(6, Item(666));

  EXPECT_TRUE(s21_list == list);
}

TEST(List, T1ResizeCountValue) {
  s21::List<Item> s21_list = {
      Item(11), Item(22), Item(33), Item(44), Item(55), Item(66),
  };
  s21_list.Resize(8, Item(666));

  std::list<Item> list = {
      Item(11), Item(22), Item(33), Item(44), Item(55), Item(66),
  };

  list.resize(8, Item(666));

  EXPECT_TRUE(s21_list == list);
}

TEST(List, T2ResizeCountValue) {
  s21::List<Item> s21_list = {
      Item(11), Item(22), Item(33), Item(44), Item(55), Item(66),
  };
  s21_list.Resize(2, Item(666));

  std::list<Item> list = {
      Item(11), Item(22), Item(33), Item(44), Item(55), Item(66),
  };

  list.resize(2, Item(666));

  EXPECT_TRUE(s21_list == list);
}

TEST(List, T0ResizeCount) {
  s21::List<Item> s21_list = {
      Item(11), Item(22), Item(33), Item(44), Item(55), Item(66),
  };
  s21_list.Resize(6);

  std::list<Item> list = {
      Item(11), Item(22), Item(33), Item(44), Item(55), Item(66),
  };

  list.resize(6);

  EXPECT_TRUE(s21_list == list);
}

TEST(List, T1ResizeCount) {
  s21::List<Item> s21_list = {
      Item(11), Item(22), Item(33), Item(44), Item(55), Item(66),
  };
  s21_list.Resize(8);

  std::list<Item> list = {
      Item(11), Item(22), Item(33), Item(44), Item(55), Item(66),
  };

  list.resize(8);

  EXPECT_TRUE(s21_list == list);
}

TEST(List, T2ResizeCount) {
  s21::List<Item> s21_list = {
      Item(11), Item(22), Item(33), Item(44), Item(55), Item(66),
  };
  s21_list.Resize(2);

  std::list<Item> list = {
      Item(11), Item(22), Item(33), Item(44), Item(55), Item(66),
  };

  list.resize(2);

  EXPECT_TRUE(s21_list == list);
}
}  //  namespace

//  GCOVR_EXCL_STOP