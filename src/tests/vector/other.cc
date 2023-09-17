#include <gtest/gtest.h>

#include <vector>

#include "../../s21_vector.h"
#include "../item.h"
#include "../vector_helpers.h"

// GCOVR_EXCL_START

namespace {

TEST(Vector, T0OperatorEqual) {
  s21::Vector<Item> s21_source{Item(11), Item(22, 'b'), Item(33, 'c', 0.3333),
                               Item(44, 'd', 0.44444)};
  std::vector<Item> source{Item(11), Item(22, 'b'), Item(33, 'c', 0.3333),
                           Item(44, 'd', 0.44444)};

  s21::Vector<Item> s21_vector(s21_source.begin(), s21_source.end());
  std::vector<Item> vector(source.begin(), source.end());

  EXPECT_TRUE(s21_vector == vector);
}

TEST(Vector, T1OperatorEqual) {
  s21::Vector<Item> s21_source{Item(11), Item(22, 'b'), Item(33, 'c', 0.3333),
                               Item(44, 'd', 0.44444)};
  std::vector<Item> source{Item(11), Item(22, 'b'), Item(33, 'c', 0.3333),
                           Item(44, 'd', 0.44444), Item(55, 'e', 0.55555555)};

  s21::Vector<Item> s21_vector(s21_source.begin(), s21_source.end());
  std::vector<Item> vector(source.begin(), source.end());

  EXPECT_FALSE(s21_vector == vector);
}

TEST(Vector, T2OperatorEqual) {
  s21::Vector<Item> s21_source{Item(11), Item(22, 'b'), Item(33, 'c', 0.3333),
                               Item(44, 'd', 0.44444)};
  std::vector<Item> source{Item(6666), Item(22, 'b'), Item(33, 'c', 0.3333),
                           Item(44, 'd', 0.44444)};

  s21::Vector<Item> s21_vector(s21_source.begin(), s21_source.end());
  std::vector<Item> vector(source.begin(), source.end());

  EXPECT_FALSE(s21_vector == vector);
}

TEST(Vector, T3OperatorEqual) {
  s21::Vector<Item> s21_source{Item(11), Item(22, 'b'), Item(33, 'c', 0.3333),
                               Item(44, 'd', 0.44444)};
  s21::Vector<Item> source{Item(11), Item(22, 'b'), Item(33, 'c', 0.3333),
                           Item(44, 'd', 0.44444)};

  s21::Vector<Item> s21_vector(s21_source.begin(), s21_source.end());
  s21::Vector<Item> vector(source.begin(), source.end());

  EXPECT_TRUE(s21_vector == vector);
}

TEST(Vector, T4OperatorEqual) {
  s21::Vector<Item> s21_source{Item(11), Item(22, 'b'), Item(33, 'c', 0.3333),
                               Item(44, 'd', 0.44444)};
  s21::Vector<Item> source{Item(11), Item(22, 'b'), Item(33, 'c', 0.3333),
                           Item(44, 'd', 0.44444), Item(55, 'e', 0.55555555)};

  s21::Vector<Item> s21_vector(s21_source.begin(), s21_source.end());
  s21::Vector<Item> vector(source.begin(), source.end());

  EXPECT_FALSE(s21_vector == vector);
}

TEST(Vector, T5OperatorEqual) {
  s21::Vector<Item> s21_source{Item(11), Item(22, 'b'), Item(33, 'c', 0.3333),
                               Item(44, 'd', 0.44444)};
  s21::Vector<Item> source{Item(6666), Item(22, 'b'), Item(33, 'c', 0.3333),
                           Item(44, 'd', 0.44444)};

  s21::Vector<Item> s21_vector(s21_source.begin(), s21_source.end());
  s21::Vector<Item> vector(source.begin(), source.end());

  EXPECT_FALSE(s21_vector == vector);
}

TEST(Vector, T6OperatorNotEqual) {
  s21::Vector<Item> s21_source{Item(11), Item(22, 'b'), Item(33, 'c', 0.3333),
                               Item(44, 'd', 0.44444)};
  s21::Vector<Item> source{Item(11), Item(22, 'b'), Item(33, 'c', 0.3333),
                           Item(44, 'd', 0.44444)};

  s21::Vector<Item> s21_vector(s21_source.begin(), s21_source.end());
  s21::Vector<Item> vector(source.begin(), source.end());

  EXPECT_FALSE(s21_vector != vector);
}

TEST(Vector, T7OperatorNotEqual) {
  s21::Vector<Item> s21_source{Item(11), Item(22, 'b'), Item(33, 'c', 0.3333),
                               Item(44, 'd', 0.44444)};
  s21::Vector<Item> source{Item(11), Item(22, 'b'), Item(33, 'c', 0.3333),
                           Item(44, 'd', 0.44444), Item(55, 'e', 0.55555555)};

  s21::Vector<Item> s21_vector(s21_source.begin(), s21_source.end());
  s21::Vector<Item> vector(source.begin(), source.end());

  EXPECT_TRUE(s21_vector != vector);
}

TEST(Vector, T8OperatorNotEqual) {
  s21::Vector<Item> s21_source{Item(11), Item(22, 'b'), Item(33, 'c', 0.3333),
                               Item(44, 'd', 0.44444)};
  s21::Vector<Item> source{Item(6666), Item(22, 'b'), Item(33, 'c', 0.3333),
                           Item(44, 'd', 0.44444)};

  s21::Vector<Item> s21_vector(s21_source.begin(), s21_source.end());
  s21::Vector<Item> vector(source.begin(), source.end());

  EXPECT_TRUE(s21_vector != vector);
}

}  // namespace

// GCOVR_EXCL_STOP