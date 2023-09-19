#include <gtest/gtest.h>

#include <deque>
#include <list>
#include <stack>
#include <vector>

#include "../../s21_vector.h"
#include "../item.h"
#include "../vector_helpers.h"

// GCOVR_EXCL_START

namespace {

TEST(Vector, T0DefaultConstructor) {
  s21::Vector<Item> s21_vector;
  std::vector<Item> vector;

  EXPECT_EQ(s21_vector, vector);
}

TEST(Vector, T1ConstructorInitializer) {
  s21::Vector<Item> s21_vector{Item(11), Item(22, 'b'), Item(33, 'c', 0.3333)};
  std::vector<Item> vector{Item(11), Item(22, 'b'), Item(33, 'c', 0.3333)};

  EXPECT_EQ(s21_vector, vector);
}

TEST(Vector, T2ConstructorInitializerEmpty) {
  s21::Vector<Item> s21_vector{};
  std::vector<Item> vector{};

  EXPECT_EQ(s21_vector, vector);
}

TEST(Vector, T3ConstructorCountValue) {
  s21::Vector<Item> s21_vector(10, Item(11, 'x', 0.55));
  std::vector<Item> vector(10, Item(11, 'x', 0.55));

  EXPECT_EQ(s21_vector, vector);
}

TEST(Vector, T4ConstructorCountValue) {
  s21::Vector<Item> s21_vector(10000, Item(11, 'x', 0.55));
  std::vector<Item> vector(10000, Item(11, 'x', 0.55));

  EXPECT_EQ(s21_vector, vector);
}

TEST(Vector, T5ConstructorCountValueZero) {
  s21::Vector<Item> s21_vector(0, Item(11, 'x', 0.55));
  std::vector<Item> vector(0, Item(11, 'x', 0.55));

  EXPECT_EQ(s21_vector, vector);
}

TEST(Vector, T6ConstructorCopy) {
  const s21::Vector<Item> s21_source{Item(11), Item(22, 'b'),
                                     Item(33, 'c', 0.3333)};
  const std::vector<Item> source{Item(11), Item(22, 'b'),
                                 Item(33, 'c', 0.3333)};

  s21::Vector<Item> s21_vector(s21_source);
  std::vector<Item> vector(source);

  EXPECT_EQ(s21_vector, vector);
}

TEST(Vector, T7ConstructorCopyEmpty) {
  const s21::Vector<Item> s21_source;
  const std::vector<Item> source;

  s21::Vector<Item> s21_vector(s21_source);
  std::vector<Item> vector(source);

  EXPECT_EQ(s21_vector, vector);
}

TEST(Vector, T8ConstructorCopy) {
  const s21::Vector<Item> s21_source(10000, Item(33, 'c', 0.3333));
  const std::vector<Item> source(10000, Item(33, 'c', 0.3333));

  s21::Vector<Item> s21_vector(s21_source);
  std::vector<Item> vector(source);

  EXPECT_EQ(s21_vector, vector);
}

TEST(Vector, T9ConstructorMove) {
  s21::Vector<Item> s21_source{Item(11), Item(22, 'b'), Item(33, 'c', 0.3333)};
  std::vector<Item> source{Item(11), Item(22, 'b'), Item(33, 'c', 0.3333)};

  s21::Vector<Item> s21_vector(std::move(s21_source));
  std::vector<Item> vector(std::move(source));

  EXPECT_EQ(s21_vector, vector);
  EXPECT_EQ(s21_source, source);
}

TEST(Vector, T10ConstructorMoveEmpty) {
  s21::Vector<Item> s21_source;
  std::vector<Item> source;

  s21::Vector<Item> s21_vector(std::move(s21_source));
  std::vector<Item> vector(std::move(source));

  EXPECT_EQ(s21_vector, vector);
  EXPECT_EQ(s21_source, source);
}

TEST(Vector, T11OperatorCopy) {
  const s21::Vector<Item> s21_source{Item(11), Item(22, 'b'),
                                     Item(33, 'c', 0.3333)};
  const std::vector<Item> source{Item(11), Item(22, 'b'),
                                 Item(33, 'c', 0.3333)};

  s21::Vector<Item> s21_vector;
  s21_vector = s21_source;
  std::vector<Item> vector;
  vector = source;

  EXPECT_EQ(s21_vector, vector);
}

TEST(Vector, T12ConstructorCopyEmpty) {
  const s21::Vector<Item> s21_source;
  const std::vector<Item> source;

  s21::Vector<Item> s21_vector;
  s21_vector = s21_source;
  std::vector<Item> vector;
  vector = source;

  EXPECT_EQ(s21_vector, vector);
}

TEST(Vector, T13OperatorCopy) {
  const s21::Vector<Item> s21_source{Item(11), Item(22, 'b'),
                                     Item(33, 'c', 0.3333)};
  const std::vector<Item> source{Item(11), Item(22, 'b'),
                                 Item(33, 'c', 0.3333)};

  s21::Vector<Item> s21_vector(10000, Item(33, 'c', 0.3333));
  s21_vector = s21_source;
  std::vector<Item> vector(10000, Item(33, 'c', 0.3333));
  vector = source;

  EXPECT_EQ(s21_vector, vector);
}

TEST(Vector, T14ConstructorCopyEmpty) {
  const s21::Vector<Item> s21_source;
  const std::vector<Item> source;

  s21::Vector<Item> s21_vector(10000, Item(33, 'c', 0.3333));
  s21_vector = s21_source;
  std::vector<Item> vector(10000, Item(33, 'c', 0.3333));
  vector = source;

  EXPECT_EQ(s21_vector, vector);
}

TEST(Vector, T15ConstructorCopySelf) {
  s21::Vector<Item> s21_vector{Item(11), Item(22, 'b'), Item(33, 'c', 0.3333)};
  auto &a = s21_vector;
  s21_vector = a;
  std::vector<Item> vector{Item(11), Item(22, 'b'), Item(33, 'c', 0.3333)};
  auto &b = vector;
  vector = b;
  // vector = vector;

  EXPECT_EQ(s21_vector, vector);
}

TEST(Vector, T16ConstructorMove) {
  s21::Vector<Item> s21_source{Item(11), Item(22, 'b'), Item(33, 'c', 0.3333)};
  std::vector<Item> source{Item(11), Item(22, 'b'), Item(33, 'c', 0.3333)};

  s21::Vector<Item> s21_vector;
  s21_vector = std::move(s21_source);
  std::vector<Item> vector;
  vector = std::move(source);

  EXPECT_EQ(s21_vector, vector);
  EXPECT_EQ(s21_source, source);
}

TEST(Vector, T17ConstructorMoveEmpty) {
  s21::Vector<Item> s21_source;
  std::vector<Item> source;

  s21::Vector<Item> s21_vector;
  s21_vector = std::move(s21_source);
  std::vector<Item> vector;
  vector = std::move(source);

  EXPECT_EQ(s21_vector, vector);
  EXPECT_EQ(s21_source, source);
}

TEST(Vector, T18ConstructorMove) {
  s21::Vector<Item> s21_source{Item(11), Item(22, 'b'), Item(33, 'c', 0.3333)};
  std::vector<Item> source{Item(11), Item(22, 'b'), Item(33, 'c', 0.3333)};

  s21::Vector<Item> s21_vector(10000, Item(33, 'c', 0.3333));
  s21_vector = std::move(s21_source);
  std::vector<Item> vector(10000, Item(33, 'c', 0.3333));
  vector = std::move(source);

  EXPECT_EQ(s21_vector, vector);
  EXPECT_EQ(s21_source, source);
}

TEST(Vector, T19ConstructorMoveEmpty) {
  s21::Vector<Item> s21_source;
  std::vector<Item> source;

  s21::Vector<Item> s21_vector(10000, Item(33, 'c', 0.3333));
  s21_vector = std::move(s21_source);
  std::vector<Item> vector(10000, Item(33, 'c', 0.3333));
  vector = std::move(source);

  EXPECT_EQ(s21_vector, vector);
  EXPECT_EQ(s21_source, source);
}

// TEST(Vector, T20ConstructorMoveSelf)
// {
//     s21::Vector<Item> s21_vector{ Item(11), Item(22, 'b'), Item(33, 'c',
//     0.3333) }; const s21::Vector<Item> s21_vector_copy(s21_vector);
//     s21_vector = std::move(s21_vector);
//     // std::vector<Item> vector{ Item(11), Item(22, 'b'), Item(33, 'c',
//     0.3333) };
//     // vector = std::move(vector);         // std::vector loses its values,
//     lol

//     // EXPECT_EQ(s21_vector, vector);      // 100% fail
//     EXPECT_EQ(s21_vector, s21_vector_copy);
// }

TEST(Vector, T21ConstructorIterator) {
  s21::Vector<Item> s21_source{Item(11), Item(22, 'b'), Item(33, 'c', 0.3333),
                               Item(44, 'd', 0.44444)};
  s21::Vector<Item> s21_vector(s21_source.begin(), s21_source.end());
  std::vector<Item> source{Item(11), Item(22, 'b'), Item(33, 'c', 0.3333),
                           Item(44, 'd', 0.44444)};
  std::vector<Item> vector(source.begin(), source.end());

  EXPECT_EQ(s21_vector, vector);
}

TEST(Vector, T22AssignIterator) {
  const s21::Vector<Item> s21_source{
      Item(11), Item(22, 'b'), Item(33, 'c', 0.3333), Item(44, 'd', 0.44444)};
  s21::Vector<Item> s21_vector;
  s21_vector.Assign(s21_source.begin(), s21_source.end());

  const std::vector<Item> source{Item(11), Item(22, 'b'), Item(33, 'c', 0.3333),
                                 Item(44, 'd', 0.44444)};
  std::vector<Item> vector;
  vector.assign(source.begin(), source.end());

  EXPECT_EQ(s21_vector, vector);
}

TEST(Vector, T23AssignIterator) {
  const s21::Vector<Item> s21_source{
      Item(11), Item(22, 'b'), Item(33, 'c', 0.3333), Item(44, 'd', 0.44444)};
  s21::Vector<Item> s21_vector{
      Item(11),
      Item(22, 'b'),
  };
  s21_vector.Assign(s21_source.begin(), s21_source.end());

  const std::vector<Item> source{Item(11), Item(22, 'b'), Item(33, 'c', 0.3333),
                                 Item(44, 'd', 0.44444)};
  std::vector<Item> vector{
      Item(11),
      Item(22, 'b'),
  };
  vector.assign(source.begin(), source.end());

  EXPECT_EQ(s21_vector, vector);
}

TEST(Vector, T24AssignIterator) {
  const s21::Vector<Item> s21_source;
  s21::Vector<Item> s21_vector{
      Item(11),
      Item(22, 'b'),
  };
  s21_vector.Assign(s21_source.begin(), s21_source.end());

  const std::vector<Item> source;
  std::vector<Item> vector{
      Item(11),
      Item(22, 'b'),
  };
  vector.assign(source.begin(), source.end());

  EXPECT_EQ(s21_vector, vector);
}

TEST(Vector, T25AssignInitializer) {
  s21::Vector<Item> s21_vector{
      Item(11),
      Item(22, 'b'),
  };
  s21_vector.Assign({Item(11), Item(22, 'b'), Item(33, 'c', 0.3333)});
  std::vector<Item> vector{
      Item(11),
      Item(22, 'b'),
  };
  vector.assign({Item(11), Item(22, 'b'), Item(33, 'c', 0.3333)});

  EXPECT_EQ(s21_vector, vector);
}

TEST(Vector, T26AssignInitializer) {
  s21::Vector<Item> s21_vector;
  s21_vector.Assign({Item(11), Item(22, 'b'), Item(33, 'c', 0.3333)});
  std::vector<Item> vector;
  vector.assign({Item(11), Item(22, 'b'), Item(33, 'c', 0.3333)});

  EXPECT_EQ(s21_vector, vector);
}

TEST(Vector, T27AssignCountValue) {
  s21::Vector<Item> s21_vector(15, Item(11, 'x', 0.55));
  s21_vector.Assign(100, Item(11, 'x', 0.55));
  std::vector<Item> vector(10, Item(11, 'x', 0.55));
  vector.assign(100, Item(11, 'x', 0.55));

  EXPECT_EQ(s21_vector, vector);
}

TEST(Vector, T28AssignCountValue) {
  s21::Vector<Item> s21_vector(10000, Item(11, 'x', 0.55));
  s21_vector.Assign(100000, Item(11, 'x', 0.55));
  std::vector<Item> vector(10000, Item(11, 'x', 0.55));
  vector.assign(100000, Item(11, 'x', 0.55));

  EXPECT_EQ(s21_vector, vector);
}

TEST(Vector, T29AssignCountValueZero) {
  s21::Vector<Item> s21_vector(0, Item(11, 'x', 0.55));
  s21_vector.Assign(0, Item(11, 'x', 0.55));
  std::vector<Item> vector(0, Item(11, 'x', 0.55));
  vector.assign(0, Item(11, 'x', 0.55));

  EXPECT_EQ(s21_vector, vector);
}

TEST(Vector, T30AssignCountValueZero) {
  s21::Vector<Item> s21_vector(0, Item(11, 'x', 0.55));
  s21_vector.Assign(10, Item(11, 'x', 0.55));
  std::vector<Item> vector(0, Item(11, 'x', 0.55));
  vector.assign(10, Item(11, 'x', 0.55));

  EXPECT_EQ(s21_vector, vector);
}

TEST(Vector, T31AssignCountValueZero) {
  s21::Vector<Item> s21_vector(100, Item(111, 'x', 0.555));
  s21_vector.Assign(0, Item(11, 'x', 0.55));
  std::vector<Item> vector(100, Item(111, 'x', 0.555));
  vector.assign(0, Item(11, 'x', 0.55));

  EXPECT_EQ(s21_vector, vector);
}

}  // namespace

// GCOVR_EXCL_STOP
