#include <gtest/gtest.h>

#include <vector>

#include "../../s21_vector.h"
#include "../item.h"
#include "../vector_helpers.h"

// GCOVR_EXCL_START

namespace {

TEST(Vector, T0Iterator) {
  s21::Vector<Item> s21_source{Item(11), Item(22, 'b'), Item(33, 'c', 0.3333),
                               Item(44, 'd', 0.44444)};
  std::vector<Item> source{Item(11), Item(22, 'b'), Item(33, 'c', 0.3333),
                           Item(44, 'd', 0.44444)};

  s21::Vector<Item> s21_vector(s21_source.begin(), s21_source.end());
  std::vector<Item> vector(source.begin(), source.end());

  EXPECT_EQ(s21_vector, vector);
}

TEST(Vector, T1ConstIterator) {
  const s21::Vector<Item> s21_source{
      Item(11), Item(22, 'b'), Item(33, 'c', 0.3333), Item(44, 'd', 0.44444)};
  const std::vector<Item> source{Item(11), Item(22, 'b'), Item(33, 'c', 0.3333),
                                 Item(44, 'd', 0.44444)};

  s21::Vector<Item> s21_vector(s21_source.begin(), s21_source.end());
  std::vector<Item> vector(source.begin(), source.end());

  EXPECT_EQ(s21_vector, vector);
}

TEST(Vector, T2ConstCIterator) {
  const s21::Vector<Item> s21_source{
      Item(11), Item(22, 'b'), Item(33, 'c', 0.3333), Item(44, 'd', 0.44444)};
  const std::vector<Item> source{Item(11), Item(22, 'b'), Item(33, 'c', 0.3333),
                                 Item(44, 'd', 0.44444)};

  s21::Vector<Item> s21_vector(s21_source.cbegin(), s21_source.cend());
  std::vector<Item> vector(source.cbegin(), source.cend());

  EXPECT_EQ(s21_vector, vector);
}

TEST(Vector, T3ReverseIterator) {
  s21::Vector<Item> s21_source{Item(11), Item(22, 'b'), Item(33, 'c', 0.3333),
                               Item(44, 'd', 0.44444)};
  std::vector<Item> source{Item(11), Item(22, 'b'), Item(33, 'c', 0.3333),
                           Item(44, 'd', 0.44444)};

  s21::Vector<Item> s21_vector(s21_source.rbegin(), s21_source.rend());
  std::vector<Item> vector(source.rbegin(), source.rend());

  EXPECT_EQ(s21_vector, vector);
}

TEST(Vector, T4ReverseConstIterator) {
  const s21::Vector<Item> s21_source{
      Item(11), Item(22, 'b'), Item(33, 'c', 0.3333), Item(44, 'd', 0.44444)};
  const std::vector<Item> source{Item(11), Item(22, 'b'), Item(33, 'c', 0.3333),
                                 Item(44, 'd', 0.44444)};

  s21::Vector<Item> s21_vector(s21_source.rbegin(), s21_source.rend());
  std::vector<Item> vector(source.rbegin(), source.rend());

  EXPECT_EQ(s21_vector, vector);
}

TEST(Vector, T5ReverseConstCIterator) {
  const s21::Vector<Item> s21_source{
      Item(11), Item(22, 'b'), Item(33, 'c', 0.3333), Item(44, 'd', 0.44444)};
  const std::vector<Item> source{Item(11), Item(22, 'b'), Item(33, 'c', 0.3333),
                                 Item(44, 'd', 0.44444)};

  s21::Vector<Item> s21_vector(s21_source.crbegin(), s21_source.crend());
  std::vector<Item> vector(source.crbegin(), source.crend());

  EXPECT_EQ(s21_vector, vector);
}

TEST(Vector, T6IteratorOperatorPlus) {
  s21::Vector<Item> s21_source{Item(11), Item(22, 'b'), Item(33, 'c', 0.3333),
                               Item(44, 'd', 0.44444)};
  std::vector<Item> source{Item(11), Item(22, 'b'), Item(33, 'c', 0.3333),
                           Item(44, 'd', 0.44444)};

  s21::Vector<Item> s21_vector(++s21_source.begin(), s21_source.end());
  std::vector<Item> vector(++source.begin(), source.end());

  EXPECT_EQ(s21_vector, vector);
}
TEST(Vector, T7IteratorOperatorPlusPostfix) {
  s21::Vector<Item> s21_source{Item(11), Item(22, 'b'), Item(33, 'c', 0.3333),
                               Item(44, 'd', 0.44444)};
  std::vector<Item> source{Item(11), Item(22, 'b'), Item(33, 'c', 0.3333),
                           Item(44, 'd', 0.44444)};

  s21::Vector<Item> s21_vector(s21_source.begin()++, s21_source.end());
  std::vector<Item> vector(source.begin()++, source.end());

  EXPECT_EQ(s21_vector, vector);
}
TEST(Vector, T8IteratorOperatorMinus) {
  s21::Vector<Item> s21_source{Item(11), Item(22, 'b'), Item(33, 'c', 0.3333),
                               Item(44, 'd', 0.44444)};
  std::vector<Item> source{Item(11), Item(22, 'b'), Item(33, 'c', 0.3333),
                           Item(44, 'd', 0.44444)};

  s21::Vector<Item> s21_vector(s21_source.begin(), --s21_source.end());
  std::vector<Item> vector(source.begin(), --source.end());

  EXPECT_EQ(s21_vector, vector);
}
TEST(Vector, T9IteratorOperatorMinusPostfix) {
  s21::Vector<Item> s21_source{Item(11), Item(22, 'b'), Item(33, 'c', 0.3333),
                               Item(44, 'd', 0.44444)};
  std::vector<Item> source{Item(11), Item(22, 'b'), Item(33, 'c', 0.3333),
                           Item(44, 'd', 0.44444)};

  s21::Vector<Item> s21_vector(s21_source.begin(), s21_source.end()--);
  std::vector<Item> vector(source.begin(), source.end()--);

  EXPECT_EQ(s21_vector, vector);
}
TEST(Vector, T10IteratorOperatorPlus) {
  s21::Vector<Item> s21_source{Item(11), Item(22, 'b'), Item(33, 'c', 0.3333),
                               Item(44, 'd', 0.44444)};
  std::vector<Item> source{Item(11), Item(22, 'b'), Item(33, 'c', 0.3333),
                           Item(44, 'd', 0.44444)};

  s21::Vector<Item>::iterator s21_it = s21_source.begin();
  std::vector<Item>::iterator it = source.begin();

  EXPECT_EQ(*s21_it, *it);
  EXPECT_EQ(*(++s21_it), *(++it));
  EXPECT_EQ(*s21_it, *it);
}
TEST(Vector, T11IteratorOperatorPlusPostfix) {
  s21::Vector<Item> s21_source{Item(11), Item(22, 'b'), Item(33, 'c', 0.3333),
                               Item(44, 'd', 0.44444)};
  std::vector<Item> source{Item(11), Item(22, 'b'), Item(33, 'c', 0.3333),
                           Item(44, 'd', 0.44444)};

  s21::Vector<Item>::iterator s21_it = s21_source.begin();
  std::vector<Item>::iterator it = source.begin();

  EXPECT_EQ(*s21_it, *it);
  EXPECT_EQ(*(s21_it++), *(it++));
  EXPECT_EQ(*s21_it, *it);
}
TEST(Vector, T12IteratorOperatorMinus) {
  s21::Vector<Item> s21_source{Item(11), Item(22, 'b'), Item(33, 'c', 0.3333),
                               Item(44, 'd', 0.44444)};
  std::vector<Item> source{Item(11), Item(22, 'b'), Item(33, 'c', 0.3333),
                           Item(44, 'd', 0.44444)};

  s21::Vector<Item>::iterator s21_it = s21_source.end() - 1;
  std::vector<Item>::iterator it = source.end() - 1;

  EXPECT_EQ(*s21_it, *it);
  EXPECT_EQ(*(--s21_it), *(--it));
  EXPECT_EQ(*s21_it, *it);
}
TEST(Vector, T13IteratorOperatorMinusPostfix) {
  s21::Vector<Item> s21_source{Item(11), Item(22, 'b'), Item(33, 'c', 0.3333),
                               Item(44, 'd', 0.44444)};
  std::vector<Item> source{Item(11), Item(22, 'b'), Item(33, 'c', 0.3333),
                           Item(44, 'd', 0.44444)};

  s21::Vector<Item>::iterator s21_it = s21_source.end() - 1;
  std::vector<Item>::iterator it = source.end() - 1;

  EXPECT_EQ(*s21_it, *it);
  EXPECT_EQ(*(s21_it--), *(it--));
  EXPECT_EQ(*s21_it, *it);
}
TEST(Vector, T14IteratorOperatorMinusIterator) {
  s21::Vector<Item> s21_source{Item(11), Item(22, 'b'), Item(33, 'c', 0.3333),
                               Item(44, 'd', 0.44444)};
  std::vector<Item> source{Item(11), Item(22, 'b'), Item(33, 'c', 0.3333),
                           Item(44, 'd', 0.44444)};

  s21::Vector<Item>::size_type s21_size =
      s21_source.end() - ++s21_source.begin();
  std::vector<Item>::size_type size = source.end() - ++source.begin();

  EXPECT_EQ(s21_size, size);
}
TEST(Vector, T15IteratorOperatorSubscript) {
  s21::Vector<Item> s21_source{Item(11), Item(22, 'b'), Item(33, 'c', 0.3333),
                               Item(44, 'd', 0.44444)};
  std::vector<Item> source{Item(11), Item(22, 'b'), Item(33, 'c', 0.3333),
                           Item(44, 'd', 0.44444)};

  Item s21_item = s21_source.begin()[2];
  Item item = source.begin()[2];

  EXPECT_EQ(s21_item, item);
}
TEST(Vector, T16IteratorOperatorSubscript) {
  s21::Vector<Item> s21_source{Item(11), Item(22, 'b'), Item(33, 'c', 0.3333),
                               Item(44, 'd', 0.44444)};
  std::vector<Item> source{Item(11), Item(22, 'b'), Item(33, 'c', 0.3333),
                           Item(44, 'd', 0.44444)};

  Item s21_item = s21_source.end()[-2];
  Item item = source.end()[-2];

  EXPECT_EQ(s21_item, item);
}
TEST(Vector, T17IteratorOperatorLessEqual) {
  s21::Vector<Item> s21_source{Item(11), Item(22, 'b'), Item(33, 'c', 0.3333),
                               Item(44, 'd', 0.44444)};
  std::vector<Item> source{Item(11), Item(22, 'b'), Item(33, 'c', 0.3333),
                           Item(44, 'd', 0.44444)};

  s21::Vector<Item> s21_vector;
  s21::Vector<Item>::iterator s21_start = s21_source.begin();
  s21::Vector<Item>::iterator s21_stop = s21_source.end() - 2;
  while (s21_start <= s21_stop) {
    s21_vector.Push_back(*s21_start);
    ++s21_start;
  }

  std::vector<Item> vector;
  std::vector<Item>::iterator start = source.begin();
  std::vector<Item>::iterator stop = source.end() - 2;
  while (start <= stop) {
    vector.push_back(*start);
    ++start;
  }

  EXPECT_EQ(s21_vector, vector);
}
TEST(Vector, T18IteratorOperatorGreaterEqual) {
  s21::Vector<Item> s21_source{Item(11), Item(22, 'b'), Item(33, 'c', 0.3333),
                               Item(44, 'd', 0.44444)};
  std::vector<Item> source{Item(11), Item(22, 'b'), Item(33, 'c', 0.3333),
                           Item(44, 'd', 0.44444)};

  s21::Vector<Item> s21_vector;
  s21::Vector<Item>::iterator s21_start = s21_source.end() - 2;
  s21::Vector<Item>::iterator s21_stop = s21_source.begin();
  while (s21_start >= s21_stop) {
    s21_vector.Push_back(*s21_start);
    --s21_start;
  }

  std::vector<Item> vector;
  std::vector<Item>::iterator start = source.end() - 2;
  std::vector<Item>::iterator stop = source.begin();
  while (start >= stop) {
    vector.push_back(*start);
    --start;
  }

  EXPECT_EQ(s21_vector, vector);
}
TEST(Vector, T19IteratorOperatorPlusEqual) {
  s21::Vector<Item> s21_source{Item(11), Item(22, 'b'), Item(33, 'c', 0.3333),
                               Item(44, 'd', 0.44444)};
  std::vector<Item> source{Item(11), Item(22, 'b'), Item(33, 'c', 0.3333),
                           Item(44, 'd', 0.44444)};

  s21::Vector<Item> s21_vector;
  s21::Vector<Item>::iterator s21_start = s21_source.begin();
  s21::Vector<Item>::iterator s21_stop = s21_source.end() - 2;
  while (s21_start <= s21_stop) {
    s21_vector.Push_back(*s21_start);
    s21_start += 2;
  }

  std::vector<Item> vector;
  std::vector<Item>::iterator start = source.begin();
  std::vector<Item>::iterator stop = source.end() - 2;
  while (start <= stop) {
    vector.push_back(*start);
    start += 2;
  }

  EXPECT_EQ(s21_vector, vector);
}
TEST(Vector, T20IteratorOperatorGreaterEqual) {
  s21::Vector<Item> s21_source{Item(11), Item(22, 'b'), Item(33, 'c', 0.3333),
                               Item(44, 'd', 0.44444)};
  std::vector<Item> source{Item(11), Item(22, 'b'), Item(33, 'c', 0.3333),
                           Item(44, 'd', 0.44444)};

  s21::Vector<Item> s21_vector;
  s21::Vector<Item>::iterator s21_start = s21_source.end() - 2;
  s21::Vector<Item>::iterator s21_stop = s21_source.begin();
  while (s21_start >= s21_stop) {
    s21_vector.Push_back(*s21_start);
    s21_start -= 2;
  }

  std::vector<Item> vector;
  std::vector<Item>::iterator start = source.end() - 2;
  std::vector<Item>::iterator stop = source.begin();
  while (start >= stop) {
    vector.push_back(*start);
    start -= 2;
  }

  EXPECT_EQ(s21_vector, vector);
}

TEST(Vector, T21ConstIteratorOperatorPlus) {
  const s21::Vector<Item> s21_source{
      Item(11), Item(22, 'b'), Item(33, 'c', 0.3333), Item(44, 'd', 0.44444)};
  const std::vector<Item> source{Item(11), Item(22, 'b'), Item(33, 'c', 0.3333),
                                 Item(44, 'd', 0.44444)};

  s21::Vector<Item> s21_vector(++s21_source.begin(), s21_source.end());
  std::vector<Item> vector(++source.begin(), source.end());

  EXPECT_EQ(s21_vector, vector);
}
TEST(Vector, T22ConstIteratorOperatorPlusPostfix) {
  const s21::Vector<Item> s21_source{
      Item(11), Item(22, 'b'), Item(33, 'c', 0.3333), Item(44, 'd', 0.44444)};
  const std::vector<Item> source{Item(11), Item(22, 'b'), Item(33, 'c', 0.3333),
                                 Item(44, 'd', 0.44444)};

  s21::Vector<Item> s21_vector(s21_source.begin()++, s21_source.end());
  std::vector<Item> vector(source.begin()++, source.end());

  EXPECT_EQ(s21_vector, vector);
}
TEST(Vector, T23ConstIteratorOperatorMinus) {
  const s21::Vector<Item> s21_source{
      Item(11), Item(22, 'b'), Item(33, 'c', 0.3333), Item(44, 'd', 0.44444)};
  const std::vector<Item> source{Item(11), Item(22, 'b'), Item(33, 'c', 0.3333),
                                 Item(44, 'd', 0.44444)};

  s21::Vector<Item> s21_vector(s21_source.begin(), --s21_source.end());
  std::vector<Item> vector(source.begin(), --source.end());

  EXPECT_EQ(s21_vector, vector);
}
TEST(Vector, T24ConstIteratorOperatorMinusPostfix) {
  s21::Vector<Item> s21_source{Item(11), Item(22, 'b'), Item(33, 'c', 0.3333),
                               Item(44, 'd', 0.44444)};
  std::vector<Item> source{Item(11), Item(22, 'b'), Item(33, 'c', 0.3333),
                           Item(44, 'd', 0.44444)};

  s21::Vector<Item> s21_vector(s21_source.begin(), s21_source.end()--);
  std::vector<Item> vector(source.begin(), source.end()--);

  EXPECT_EQ(s21_vector, vector);
}
TEST(Vector, T25ConstIteratorOperatorPlus) {
  const s21::Vector<Item> s21_source{
      Item(11), Item(22, 'b'), Item(33, 'c', 0.3333), Item(44, 'd', 0.44444)};
  const std::vector<Item> source{Item(11), Item(22, 'b'), Item(33, 'c', 0.3333),
                                 Item(44, 'd', 0.44444)};

  s21::Vector<Item>::const_iterator s21_it = s21_source.begin();
  std::vector<Item>::const_iterator it = source.begin();

  EXPECT_EQ(*s21_it, *it);
  EXPECT_EQ(*(++s21_it), *(++it));
  EXPECT_EQ(*s21_it, *it);
}
TEST(Vector, T26ConstIteratorOperatorPlusPostfix) {
  const s21::Vector<Item> s21_source{
      Item(11), Item(22, 'b'), Item(33, 'c', 0.3333), Item(44, 'd', 0.44444)};
  const std::vector<Item> source{Item(11), Item(22, 'b'), Item(33, 'c', 0.3333),
                                 Item(44, 'd', 0.44444)};

  s21::Vector<Item>::const_iterator s21_it = s21_source.begin();
  std::vector<Item>::const_iterator it = source.begin();

  EXPECT_EQ(*s21_it, *it);
  EXPECT_EQ(*(s21_it++), *(it++));
  EXPECT_EQ(*s21_it, *it);
}
TEST(Vector, T27ConstIteratorOperatorMinus) {
  const s21::Vector<Item> s21_source{
      Item(11), Item(22, 'b'), Item(33, 'c', 0.3333), Item(44, 'd', 0.44444)};
  const std::vector<Item> source{Item(11), Item(22, 'b'), Item(33, 'c', 0.3333),
                                 Item(44, 'd', 0.44444)};

  s21::Vector<Item>::const_iterator s21_it = s21_source.end() - 1;
  std::vector<Item>::const_iterator it = source.end() - 1;

  EXPECT_EQ(*s21_it, *it);
  EXPECT_EQ(*(--s21_it), *(--it));
  EXPECT_EQ(*s21_it, *it);
}
TEST(Vector, T28ConstIteratorOperatorMinusPostfix) {
  const s21::Vector<Item> s21_source{
      Item(11), Item(22, 'b'), Item(33, 'c', 0.3333), Item(44, 'd', 0.44444)};
  const std::vector<Item> source{Item(11), Item(22, 'b'), Item(33, 'c', 0.3333),
                                 Item(44, 'd', 0.44444)};

  s21::Vector<Item>::const_iterator s21_it = s21_source.end() - 1;
  std::vector<Item>::const_iterator it = source.end() - 1;

  EXPECT_EQ(*s21_it, *it);
  EXPECT_EQ(*(s21_it--), *(it--));
  EXPECT_EQ(*s21_it, *it);
}
TEST(Vector, T29ConstIteratorOperatorMinusIterator) {
  const s21::Vector<Item> s21_source{
      Item(11), Item(22, 'b'), Item(33, 'c', 0.3333), Item(44, 'd', 0.44444)};
  const std::vector<Item> source{Item(11), Item(22, 'b'), Item(33, 'c', 0.3333),
                                 Item(44, 'd', 0.44444)};

  s21::Vector<Item>::size_type s21_size =
      s21_source.end() - ++s21_source.begin();
  std::vector<Item>::size_type size = source.end() - ++source.begin();

  EXPECT_EQ(s21_size, size);
}
TEST(Vector, T30ConstIteratorOperatorSubscript) {
  const s21::Vector<Item> s21_source{
      Item(11), Item(22, 'b'), Item(33, 'c', 0.3333), Item(44, 'd', 0.44444)};
  const std::vector<Item> source{Item(11), Item(22, 'b'), Item(33, 'c', 0.3333),
                                 Item(44, 'd', 0.44444)};

  Item s21_item = s21_source.begin()[2];
  Item item = source.begin()[2];

  EXPECT_EQ(s21_item, item);
}
TEST(Vector, T31IteratorOperatorSubscript) {
  const s21::Vector<Item> s21_source{
      Item(11), Item(22, 'b'), Item(33, 'c', 0.3333), Item(44, 'd', 0.44444)};
  const std::vector<Item> source{Item(11), Item(22, 'b'), Item(33, 'c', 0.3333),
                                 Item(44, 'd', 0.44444)};

  Item s21_item = s21_source.end()[-2];
  Item item = source.end()[-2];

  EXPECT_EQ(s21_item, item);
}
TEST(Vector, T32ConstIteratorOperatorLessEqual) {
  const s21::Vector<Item> s21_source{
      Item(11), Item(22, 'b'), Item(33, 'c', 0.3333), Item(44, 'd', 0.44444)};
  const std::vector<Item> source{Item(11), Item(22, 'b'), Item(33, 'c', 0.3333),
                                 Item(44, 'd', 0.44444)};

  s21::Vector<Item> s21_vector;
  s21::Vector<Item>::const_iterator s21_start = s21_source.begin();
  s21::Vector<Item>::const_iterator s21_stop = s21_source.end() - 2;
  while (s21_start <= s21_stop) {
    s21_vector.Push_back(*s21_start);
    ++s21_start;
  }

  std::vector<Item> vector;
  std::vector<Item>::const_iterator start = source.begin();
  std::vector<Item>::const_iterator stop = source.end() - 2;
  while (start <= stop) {
    vector.push_back(*start);
    ++start;
  }

  EXPECT_EQ(s21_vector, vector);
}
TEST(Vector, T33ConstIteratorOperatorGreaterEqual) {
  const s21::Vector<Item> s21_source{
      Item(11), Item(22, 'b'), Item(33, 'c', 0.3333), Item(44, 'd', 0.44444)};
  const std::vector<Item> source{Item(11), Item(22, 'b'), Item(33, 'c', 0.3333),
                                 Item(44, 'd', 0.44444)};

  s21::Vector<Item> s21_vector;
  s21::Vector<Item>::const_iterator s21_start = s21_source.end() - 2;
  s21::Vector<Item>::const_iterator s21_stop = s21_source.begin();
  while (s21_start >= s21_stop) {
    s21_vector.Push_back(*s21_start);
    --s21_start;
  }

  std::vector<Item> vector;
  std::vector<Item>::const_iterator start = source.end() - 2;
  std::vector<Item>::const_iterator stop = source.begin();
  while (start >= stop) {
    vector.push_back(*start);
    --start;
  }

  EXPECT_EQ(s21_vector, vector);
}
TEST(Vector, T34ConstIteratorOperatorPlusEqual) {
  const s21::Vector<Item> s21_source{
      Item(11), Item(22, 'b'), Item(33, 'c', 0.3333), Item(44, 'd', 0.44444)};
  const std::vector<Item> source{Item(11), Item(22, 'b'), Item(33, 'c', 0.3333),
                                 Item(44, 'd', 0.44444)};

  s21::Vector<Item> s21_vector;
  s21::Vector<Item>::const_iterator s21_start = s21_source.begin();
  s21::Vector<Item>::const_iterator s21_stop = s21_source.end() - 2;
  while (s21_start <= s21_stop) {
    s21_vector.Push_back(*s21_start);
    s21_start += 2;
  }

  std::vector<Item> vector;
  std::vector<Item>::const_iterator start = source.begin();
  std::vector<Item>::const_iterator stop = source.end() - 2;
  while (start <= stop) {
    vector.push_back(*start);
    start += 2;
  }

  EXPECT_EQ(s21_vector, vector);
}
TEST(Vector, T35ConstIteratorOperatorGreaterEqual) {
  const s21::Vector<Item> s21_source{
      Item(11), Item(22, 'b'), Item(33, 'c', 0.3333), Item(44, 'd', 0.44444)};
  const std::vector<Item> source{Item(11), Item(22, 'b'), Item(33, 'c', 0.3333),
                                 Item(44, 'd', 0.44444)};

  s21::Vector<Item> s21_vector;
  s21::Vector<Item>::const_iterator s21_start = s21_source.end() - 2;
  s21::Vector<Item>::const_iterator s21_stop = s21_source.begin();
  while (s21_start >= s21_stop) {
    s21_vector.Push_back(*s21_start);
    s21_start -= 2;
  }

  std::vector<Item> vector;
  std::vector<Item>::const_iterator start = source.end() - 2;
  std::vector<Item>::const_iterator stop = source.begin();
  while (start >= stop) {
    vector.push_back(*start);
    start -= 2;
  }

  EXPECT_EQ(s21_vector, vector);
}

TEST(Vector, T36ReverseIteratorOperatorPlus) {
  s21::Vector<Item> s21_source{Item(11), Item(22, 'b'), Item(33, 'c', 0.3333),
                               Item(44, 'd', 0.44444)};
  std::vector<Item> source{Item(11), Item(22, 'b'), Item(33, 'c', 0.3333),
                           Item(44, 'd', 0.44444)};

  s21::Vector<Item> s21_vector(++s21_source.rbegin(), s21_source.rend());
  std::vector<Item> vector(++source.rbegin(), source.rend());

  EXPECT_EQ(s21_vector, vector);
}
TEST(Vector, T37ReverseIteratorOperatorPlusPostfix) {
  s21::Vector<Item> s21_source{Item(11), Item(22, 'b'), Item(33, 'c', 0.3333),
                               Item(44, 'd', 0.44444)};
  std::vector<Item> source{Item(11), Item(22, 'b'), Item(33, 'c', 0.3333),
                           Item(44, 'd', 0.44444)};

  s21::Vector<Item> s21_vector(s21_source.rbegin()++, s21_source.rend());
  std::vector<Item> vector(source.rbegin()++, source.rend());

  EXPECT_EQ(s21_vector, vector);
}
TEST(Vector, T38ReverseIteratorOperatorMinus) {
  s21::Vector<Item> s21_source{Item(11), Item(22, 'b'), Item(33, 'c', 0.3333),
                               Item(44, 'd', 0.44444)};
  std::vector<Item> source{Item(11), Item(22, 'b'), Item(33, 'c', 0.3333),
                           Item(44, 'd', 0.44444)};

  s21::Vector<Item> s21_vector(s21_source.rbegin(), --s21_source.rend());
  std::vector<Item> vector(source.rbegin(), --source.rend());

  EXPECT_EQ(s21_vector, vector);
}
TEST(Vector, T39ReverseIteratorOperatorMinusPostfix) {
  s21::Vector<Item> s21_source{Item(11), Item(22, 'b'), Item(33, 'c', 0.3333),
                               Item(44, 'd', 0.44444)};
  std::vector<Item> source{Item(11), Item(22, 'b'), Item(33, 'c', 0.3333),
                           Item(44, 'd', 0.44444)};

  s21::Vector<Item> s21_vector(s21_source.rbegin(), s21_source.rend()--);
  std::vector<Item> vector(source.rbegin(), source.rend()--);

  EXPECT_EQ(s21_vector, vector);
}
TEST(Vector, T40ReverseIteratorOperatorPlus) {
  s21::Vector<Item> s21_source{Item(11), Item(22, 'b'), Item(33, 'c', 0.3333),
                               Item(44, 'd', 0.44444)};
  std::vector<Item> source{Item(11), Item(22, 'b'), Item(33, 'c', 0.3333),
                           Item(44, 'd', 0.44444)};

  s21::Vector<Item>::reverse_iterator s21_it = s21_source.rbegin();
  std::vector<Item>::reverse_iterator it = source.rbegin();

  EXPECT_EQ(*s21_it, *it);
  EXPECT_EQ(*(++s21_it), *(++it));
  EXPECT_EQ(*s21_it, *it);
}
TEST(Vector, T41ReverseIteratorOperatorPlusPostfix) {
  s21::Vector<Item> s21_source{Item(11), Item(22, 'b'), Item(33, 'c', 0.3333),
                               Item(44, 'd', 0.44444)};
  std::vector<Item> source{Item(11), Item(22, 'b'), Item(33, 'c', 0.3333),
                           Item(44, 'd', 0.44444)};

  s21::Vector<Item>::reverse_iterator s21_it = s21_source.rbegin();
  std::vector<Item>::reverse_iterator it = source.rbegin();

  EXPECT_EQ(*s21_it, *it);
  EXPECT_EQ(*(s21_it++), *(it++));
  EXPECT_EQ(*s21_it, *it);
}
TEST(Vector, T42ReverseIteratorOperatorMinus) {
  s21::Vector<Item> s21_source{Item(11), Item(22, 'b'), Item(33, 'c', 0.3333),
                               Item(44, 'd', 0.44444)};
  std::vector<Item> source{Item(11), Item(22, 'b'), Item(33, 'c', 0.3333),
                           Item(44, 'd', 0.44444)};

  s21::Vector<Item>::reverse_iterator s21_it = s21_source.rend() - 1;
  std::vector<Item>::reverse_iterator it = source.rend() - 1;

  EXPECT_EQ(*s21_it, *it);
  EXPECT_EQ(*(--s21_it), *(--it));
  EXPECT_EQ(*s21_it, *it);
}
TEST(Vector, T43ReverseIteratorOperatorMinusPostfix) {
  s21::Vector<Item> s21_source{Item(11), Item(22, 'b'), Item(33, 'c', 0.3333),
                               Item(44, 'd', 0.44444)};
  std::vector<Item> source{Item(11), Item(22, 'b'), Item(33, 'c', 0.3333),
                           Item(44, 'd', 0.44444)};

  s21::Vector<Item>::reverse_iterator s21_it = s21_source.rend() - 1;
  std::vector<Item>::reverse_iterator it = source.rend() - 1;

  EXPECT_EQ(*s21_it, *it);
  EXPECT_EQ(*(s21_it--), *(it--));
  EXPECT_EQ(*s21_it, *it);
}
TEST(Vector, T44ReverseIteratorOperatorMinusIterator) {
  s21::Vector<Item> s21_source{Item(11), Item(22, 'b'), Item(33, 'c', 0.3333),
                               Item(44, 'd', 0.44444)};
  std::vector<Item> source{Item(11), Item(22, 'b'), Item(33, 'c', 0.3333),
                           Item(44, 'd', 0.44444)};

  s21::Vector<Item>::size_type s21_size =
      s21_source.rend() - ++s21_source.rbegin();
  std::vector<Item>::size_type size = source.rend() - ++source.rbegin();

  EXPECT_EQ(s21_size, size);
}
TEST(Vector, T45ReverseIteratorOperatorSubscript) {
  s21::Vector<Item> s21_source{Item(11), Item(22, 'b'), Item(33, 'c', 0.3333),
                               Item(44, 'd', 0.44444)};
  std::vector<Item> source{Item(11), Item(22, 'b'), Item(33, 'c', 0.3333),
                           Item(44, 'd', 0.44444)};

  Item s21_item = s21_source.rbegin()[2];
  Item item = source.rbegin()[2];

  EXPECT_EQ(s21_item, item);
}
TEST(Vector, T46ReverseIteratorOperatorSubscript) {
  s21::Vector<Item> s21_source{Item(11), Item(22, 'b'), Item(33, 'c', 0.3333),
                               Item(44, 'd', 0.44444)};
  std::vector<Item> source{Item(11), Item(22, 'b'), Item(33, 'c', 0.3333),
                           Item(44, 'd', 0.44444)};

  Item s21_item = s21_source.rend()[-2];
  Item item = source.rend()[-2];

  EXPECT_EQ(s21_item, item);
}
TEST(Vector, T47ReverseIteratorOperatorLessEqual) {
  s21::Vector<Item> s21_source{Item(11), Item(22, 'b'), Item(33, 'c', 0.3333),
                               Item(44, 'd', 0.44444)};
  std::vector<Item> source{Item(11), Item(22, 'b'), Item(33, 'c', 0.3333),
                           Item(44, 'd', 0.44444)};

  s21::Vector<Item> s21_vector;
  s21::Vector<Item>::reverse_iterator s21_start = s21_source.rbegin();
  s21::Vector<Item>::reverse_iterator s21_stop = s21_source.rend() - 2;
  while (s21_start <= s21_stop) {
    s21_vector.Push_back(*s21_start);
    ++s21_start;
  }

  std::vector<Item> vector;
  std::vector<Item>::reverse_iterator start = source.rbegin();
  std::vector<Item>::reverse_iterator stop = source.rend() - 2;
  while (start <= stop) {
    vector.push_back(*start);
    ++start;
  }

  EXPECT_EQ(s21_vector, vector);
}
TEST(Vector, T48ReverseIteratorOperatorGreaterEqual) {
  s21::Vector<Item> s21_source{Item(11), Item(22, 'b'), Item(33, 'c', 0.3333),
                               Item(44, 'd', 0.44444)};
  std::vector<Item> source{Item(11), Item(22, 'b'), Item(33, 'c', 0.3333),
                           Item(44, 'd', 0.44444)};

  s21::Vector<Item> s21_vector;
  s21::Vector<Item>::reverse_iterator s21_start = s21_source.rend() - 2;
  s21::Vector<Item>::reverse_iterator s21_stop = s21_source.rbegin();
  while (s21_start >= s21_stop) {
    s21_vector.Push_back(*s21_start);
    --s21_start;
  }

  std::vector<Item> vector;
  std::vector<Item>::reverse_iterator start = source.rend() - 2;
  std::vector<Item>::reverse_iterator stop = source.rbegin();
  while (start >= stop) {
    vector.push_back(*start);
    --start;
  }

  EXPECT_EQ(s21_vector, vector);
}
TEST(Vector, T49IteratorOperatorPlusEqual) {
  s21::Vector<Item> s21_source{Item(11), Item(22, 'b'), Item(33, 'c', 0.3333),
                               Item(44, 'd', 0.44444)};
  std::vector<Item> source{Item(11), Item(22, 'b'), Item(33, 'c', 0.3333),
                           Item(44, 'd', 0.44444)};

  s21::Vector<Item> s21_vector;
  s21::Vector<Item>::reverse_iterator s21_start = s21_source.rbegin();
  s21::Vector<Item>::reverse_iterator s21_stop = s21_source.rend() - 2;
  while (s21_start <= s21_stop) {
    s21_vector.Push_back(*s21_start);
    s21_start += 2;
  }

  std::vector<Item> vector;
  std::vector<Item>::reverse_iterator start = source.rbegin();
  std::vector<Item>::reverse_iterator stop = source.rend() - 2;
  while (start <= stop) {
    vector.push_back(*start);
    start += 2;
  }

  EXPECT_EQ(s21_vector, vector);
}
TEST(Vector, T50IteratorOperatorGreaterEqual) {
  s21::Vector<Item> s21_source{Item(11), Item(22, 'b'), Item(33, 'c', 0.3333),
                               Item(44, 'd', 0.44444)};
  std::vector<Item> source{Item(11), Item(22, 'b'), Item(33, 'c', 0.3333),
                           Item(44, 'd', 0.44444)};

  s21::Vector<Item> s21_vector;
  s21::Vector<Item>::reverse_iterator s21_start = s21_source.rend() - 2;
  s21::Vector<Item>::reverse_iterator s21_stop = s21_source.rbegin();
  while (s21_start >= s21_stop) {
    s21_vector.Push_back(*s21_start);
    s21_start -= 2;
  }

  std::vector<Item> vector;
  std::vector<Item>::reverse_iterator start = source.rend() - 2;
  std::vector<Item>::reverse_iterator stop = source.rbegin();
  while (start >= stop) {
    vector.push_back(*start);
    start -= 2;
  }

  EXPECT_EQ(s21_vector, vector);
}

TEST(Vector, T51ConstReverseIteratorOperatorPlus) {
  const s21::Vector<Item> s21_source{
      Item(11), Item(22, 'b'), Item(33, 'c', 0.3333), Item(44, 'd', 0.44444)};
  const std::vector<Item> source{Item(11), Item(22, 'b'), Item(33, 'c', 0.3333),
                                 Item(44, 'd', 0.44444)};

  s21::Vector<Item> s21_vector(++s21_source.rbegin(), s21_source.rend());
  std::vector<Item> vector(++source.rbegin(), source.rend());

  EXPECT_EQ(s21_vector, vector);
}
TEST(Vector, T52ConstReverseIteratorOperatorPlusPostfix) {
  const s21::Vector<Item> s21_source{
      Item(11), Item(22, 'b'), Item(33, 'c', 0.3333), Item(44, 'd', 0.44444)};
  const std::vector<Item> source{Item(11), Item(22, 'b'), Item(33, 'c', 0.3333),
                                 Item(44, 'd', 0.44444)};

  s21::Vector<Item> s21_vector(s21_source.rbegin()++, s21_source.rend());
  std::vector<Item> vector(source.rbegin()++, source.rend());

  EXPECT_EQ(s21_vector, vector);
}
TEST(Vector, T53ConstReverseIteratorOperatorMinus) {
  const s21::Vector<Item> s21_source{
      Item(11), Item(22, 'b'), Item(33, 'c', 0.3333), Item(44, 'd', 0.44444)};
  const std::vector<Item> source{Item(11), Item(22, 'b'), Item(33, 'c', 0.3333),
                                 Item(44, 'd', 0.44444)};

  s21::Vector<Item> s21_vector(s21_source.rbegin(), --s21_source.rend());
  std::vector<Item> vector(source.rbegin(), --source.rend());

  EXPECT_EQ(s21_vector, vector);
}
TEST(Vector, T54ConstReverseIteratorOperatorMinusPostfix) {
  s21::Vector<Item> s21_source{Item(11), Item(22, 'b'), Item(33, 'c', 0.3333),
                               Item(44, 'd', 0.44444)};
  std::vector<Item> source{Item(11), Item(22, 'b'), Item(33, 'c', 0.3333),
                           Item(44, 'd', 0.44444)};

  s21::Vector<Item> s21_vector(s21_source.rbegin(), s21_source.rend()--);
  std::vector<Item> vector(source.rbegin(), source.rend()--);

  EXPECT_EQ(s21_vector, vector);
}
TEST(Vector, T55ConstReverseIteratorOperatorPlus) {
  const s21::Vector<Item> s21_source{
      Item(11), Item(22, 'b'), Item(33, 'c', 0.3333), Item(44, 'd', 0.44444)};
  const std::vector<Item> source{Item(11), Item(22, 'b'), Item(33, 'c', 0.3333),
                                 Item(44, 'd', 0.44444)};

  s21::Vector<Item>::const_reverse_iterator s21_it = s21_source.rbegin();
  std::vector<Item>::const_reverse_iterator it = source.rbegin();

  EXPECT_EQ(*s21_it, *it);
  EXPECT_EQ(*(++s21_it), *(++it));
  EXPECT_EQ(*s21_it, *it);
}
TEST(Vector, T56ConstReverseIteratorOperatorPlusPostfix) {
  const s21::Vector<Item> s21_source{
      Item(11), Item(22, 'b'), Item(33, 'c', 0.3333), Item(44, 'd', 0.44444)};
  const std::vector<Item> source{Item(11), Item(22, 'b'), Item(33, 'c', 0.3333),
                                 Item(44, 'd', 0.44444)};

  s21::Vector<Item>::const_reverse_iterator s21_it = s21_source.rbegin();
  std::vector<Item>::const_reverse_iterator it = source.rbegin();

  EXPECT_EQ(*s21_it, *it);
  EXPECT_EQ(*(s21_it++), *(it++));
  EXPECT_EQ(*s21_it, *it);
}
TEST(Vector, T57ConstReverseIteratorOperatorMinus) {
  const s21::Vector<Item> s21_source{
      Item(11), Item(22, 'b'), Item(33, 'c', 0.3333), Item(44, 'd', 0.44444)};
  const std::vector<Item> source{Item(11), Item(22, 'b'), Item(33, 'c', 0.3333),
                                 Item(44, 'd', 0.44444)};

  s21::Vector<Item>::const_reverse_iterator s21_it = s21_source.rend() - 1;
  std::vector<Item>::const_reverse_iterator it = source.rend() - 1;

  EXPECT_EQ(*s21_it, *it);
  EXPECT_EQ(*(--s21_it), *(--it));
  EXPECT_EQ(*s21_it, *it);
}
TEST(Vector, T58ConstReverseIteratorOperatorMinusPostfix) {
  const s21::Vector<Item> s21_source{
      Item(11), Item(22, 'b'), Item(33, 'c', 0.3333), Item(44, 'd', 0.44444)};
  const std::vector<Item> source{Item(11), Item(22, 'b'), Item(33, 'c', 0.3333),
                                 Item(44, 'd', 0.44444)};

  s21::Vector<Item>::const_reverse_iterator s21_it = s21_source.rend() - 1;
  std::vector<Item>::const_reverse_iterator it = source.rend() - 1;

  EXPECT_EQ(*s21_it, *it);
  EXPECT_EQ(*(s21_it--), *(it--));
  EXPECT_EQ(*s21_it, *it);
}
TEST(Vector, T59ConstReverseIteratorOperatorMinusIterator) {
  const s21::Vector<Item> s21_source{
      Item(11), Item(22, 'b'), Item(33, 'c', 0.3333), Item(44, 'd', 0.44444)};
  const std::vector<Item> source{Item(11), Item(22, 'b'), Item(33, 'c', 0.3333),
                                 Item(44, 'd', 0.44444)};

  s21::Vector<Item>::size_type s21_size =
      s21_source.rend() - ++s21_source.rbegin();
  std::vector<Item>::size_type size = source.rend() - ++source.rbegin();

  EXPECT_EQ(s21_size, size);
}
TEST(Vector, T60ConstReverseIteratorOperatorSubscript) {
  const s21::Vector<Item> s21_source{
      Item(11), Item(22, 'b'), Item(33, 'c', 0.3333), Item(44, 'd', 0.44444)};
  const std::vector<Item> source{Item(11), Item(22, 'b'), Item(33, 'c', 0.3333),
                                 Item(44, 'd', 0.44444)};

  Item s21_item = s21_source.rbegin()[2];
  Item item = source.rbegin()[2];

  EXPECT_EQ(s21_item, item);
}
TEST(Vector, T61ConstReverseIteratorOperatorSubscript) {
  const s21::Vector<Item> s21_source{
      Item(11), Item(22, 'b'), Item(33, 'c', 0.3333), Item(44, 'd', 0.44444)};
  const std::vector<Item> source{Item(11), Item(22, 'b'), Item(33, 'c', 0.3333),
                                 Item(44, 'd', 0.44444)};

  Item s21_item = s21_source.rend()[-2];
  Item item = source.rend()[-2];

  EXPECT_EQ(s21_item, item);
}
TEST(Vector, T62ConstReverseIteratorOperatorLessEqual) {
  const s21::Vector<Item> s21_source{
      Item(11), Item(22, 'b'), Item(33, 'c', 0.3333), Item(44, 'd', 0.44444)};
  const std::vector<Item> source{Item(11), Item(22, 'b'), Item(33, 'c', 0.3333),
                                 Item(44, 'd', 0.44444)};

  s21::Vector<Item> s21_vector;
  s21::Vector<Item>::const_reverse_iterator s21_start = s21_source.rbegin();
  s21::Vector<Item>::const_reverse_iterator s21_stop = s21_source.rend() - 2;
  while (s21_start <= s21_stop) {
    s21_vector.Push_back(*s21_start);
    ++s21_start;
  }

  std::vector<Item> vector;
  std::vector<Item>::const_reverse_iterator start = source.rbegin();
  std::vector<Item>::const_reverse_iterator stop = source.rend() - 2;
  while (start <= stop) {
    vector.push_back(*start);
    ++start;
  }

  EXPECT_EQ(s21_vector, vector);
}
TEST(Vector, T63ConstReverseIteratorOperatorGreaterEqual) {
  const s21::Vector<Item> s21_source{
      Item(11), Item(22, 'b'), Item(33, 'c', 0.3333), Item(44, 'd', 0.44444)};
  const std::vector<Item> source{Item(11), Item(22, 'b'), Item(33, 'c', 0.3333),
                                 Item(44, 'd', 0.44444)};

  s21::Vector<Item> s21_vector;
  s21::Vector<Item>::const_reverse_iterator s21_start = s21_source.rend() - 2;
  s21::Vector<Item>::const_reverse_iterator s21_stop = s21_source.rbegin();
  while (s21_start >= s21_stop) {
    s21_vector.Push_back(*s21_start);
    --s21_start;
  }

  std::vector<Item> vector;
  std::vector<Item>::const_reverse_iterator start = source.rend() - 2;
  std::vector<Item>::const_reverse_iterator stop = source.rbegin();
  while (start >= stop) {
    vector.push_back(*start);
    --start;
  }

  EXPECT_EQ(s21_vector, vector);
}
TEST(Vector, T64ConstReverseIteratorOperatorPlusEqual) {
  const s21::Vector<Item> s21_source{
      Item(11), Item(22, 'b'), Item(33, 'c', 0.3333), Item(44, 'd', 0.44444)};
  const std::vector<Item> source{Item(11), Item(22, 'b'), Item(33, 'c', 0.3333),
                                 Item(44, 'd', 0.44444)};

  s21::Vector<Item> s21_vector;
  s21::Vector<Item>::const_reverse_iterator s21_start = s21_source.rbegin();
  s21::Vector<Item>::const_reverse_iterator s21_stop = s21_source.rend() - 2;
  while (s21_start <= s21_stop) {
    s21_vector.Push_back(*s21_start);
    s21_start += 2;
  }

  std::vector<Item> vector;
  std::vector<Item>::const_reverse_iterator start = source.rbegin();
  std::vector<Item>::const_reverse_iterator stop = source.rend() - 2;
  while (start <= stop) {
    vector.push_back(*start);
    start += 2;
  }

  EXPECT_EQ(s21_vector, vector);
}
TEST(Vector, T65ConstReverseIteratorOperatorGreaterEqual) {
  const s21::Vector<Item> s21_source{
      Item(11), Item(22, 'b'), Item(33, 'c', 0.3333), Item(44, 'd', 0.44444)};
  const std::vector<Item> source{Item(11), Item(22, 'b'), Item(33, 'c', 0.3333),
                                 Item(44, 'd', 0.44444)};

  s21::Vector<Item> s21_vector;
  s21::Vector<Item>::const_reverse_iterator s21_start = s21_source.rend() - 2;
  s21::Vector<Item>::const_reverse_iterator s21_stop = s21_source.rbegin();
  while (s21_start >= s21_stop) {
    s21_vector.Push_back(*s21_start);
    s21_start -= 2;
  }

  std::vector<Item> vector;
  std::vector<Item>::const_reverse_iterator start = source.rend() - 2;
  std::vector<Item>::const_reverse_iterator stop = source.rbegin();
  while (start >= stop) {
    vector.push_back(*start);
    start -= 2;
  }

  EXPECT_EQ(s21_vector, vector);
}

TEST(Vector, T66ConstReverseIteratorOperatorPlus) {
  const s21::Vector<Item> s21_source{
      Item(11), Item(22, 'b'), Item(33, 'c', 0.3333), Item(44, 'd', 0.44444)};
  const std::vector<Item> source{Item(11), Item(22, 'b'), Item(33, 'c', 0.3333),
                                 Item(44, 'd', 0.44444)};

  s21::Vector<Item> s21_vector;
  s21::Vector<Item>::const_reverse_iterator s21_start = s21_source.rend() - 2;
  s21::Vector<Item>::const_reverse_iterator s21_stop = s21_source.rbegin() + 1;
  while (s21_start >= s21_stop) {
    s21_vector.Push_back(*s21_start);
    s21_start -= 2;
  }

  std::vector<Item> vector;
  std::vector<Item>::const_reverse_iterator start = source.rend() - 2;
  std::vector<Item>::const_reverse_iterator stop = source.rbegin() + 1;
  while (start >= stop) {
    vector.push_back(*start);
    start -= 2;
  }

  EXPECT_EQ(s21_vector, vector);
}

TEST(Vector, T67ConstReverseIteratorOperatorCast) {
  const s21::Vector<Item> s21_source{
      Item(11), Item(22, 'b'), Item(33, 'c', 0.3333), Item(44, 'd', 0.44444)};
  // const std::vector<Item> source { Item(11), Item(22, 'b'), Item(33, 'c',
  // 0.3333), Item(44, 'd', 0.44444) };
  const s21::Vector<Item> s21_vector{Item(11), Item(), Item(),
                                     Item(44, 'd', 0.44444)};
  // const std::vector<Item> vector { Item(11), Item(), Item(), Item(44, 'd',
  // 0.44444) };

  s21::Vector<Item>::reverse_iterator s21_start =
      static_cast<s21::Vector<Item>::reverse_iterator>(
          s21_source.rend() -
          2);  // should be able to do that? std does not compile that
  s21::Vector<Item>::const_reverse_iterator s21_stop = s21_source.rbegin() + 1;
  while (s21_start >= s21_stop) {
    *s21_start = Item();
    --s21_start;
  }

  // std::vector<Item>::reverse_iterator start =
  // static_cast<std::vector<Item>::reverse_iterator>(source.rend() - 2); //does
  // not compile std::vector<Item>::const_reverse_iterator stop =
  // source.rbegin() + 1; while (start >= stop) {
  //     *start = Item();
  //     --start;
  // }

  // EXPECT_EQ(s21_vector, vector);
  EXPECT_EQ(s21_source, s21_vector);
}

TEST(Vector, T68IteratorOperatorArrow) {
  const s21::Vector<Item> s21_source1{
      Item(11), Item(22, 'b'), Item(33, 'c', 0.3333), Item(44, 'd', 0.44444)};
  const s21::Vector<Item> s21_source2{
      Item(11), Item(22, 'b'), Item(33, 'c', 0.3333), Item(44, 'd', 0.44444)};
  const s21::Vector<Item> s21_source3{Item(11), Item(22, 'b'),
                                      Item(33, 'c', 0.3333)};
  const s21::Vector<Item> s21_source4{Item(11), Item(22, 'b'),
                                      Item(33, 'c', 0.3333)};
  const s21::Vector<Item> s21_source5{
      Item(11),
      Item(22, 'b'),
  };
  const s21::Vector<Item> s21_source6{
      Item(11),
      Item(22, 'b'),
  };
  const s21::Vector<s21::Vector<Item>> s21_vector{
      s21_source1, s21_source2, s21_source3,
      s21_source4, s21_source5, s21_source6,
  };

  const std::vector<Item> source1{
      Item(11), Item(22, 'b'), Item(33, 'c', 0.3333), Item(44, 'd', 0.44444)};
  const std::vector<Item> source2{
      Item(11), Item(22, 'b'), Item(33, 'c', 0.3333), Item(44, 'd', 0.44444)};
  const std::vector<Item> source3{Item(11), Item(22, 'b'),
                                  Item(33, 'c', 0.3333)};
  const std::vector<Item> source4{Item(11), Item(22, 'b'),
                                  Item(33, 'c', 0.3333)};
  const std::vector<Item> source5{
      Item(11),
      Item(22, 'b'),
  };
  const std::vector<Item> source6{
      Item(11),
      Item(22, 'b'),
  };
  const std::vector<std::vector<Item>> vector{
      source1, source2, source3, source4, source5, source6,
  };

  // EXPECT_EQ(s21_vector, vector);       // TODO: does not compile because of
  // pointers
  EXPECT_EQ(s21_vector.begin()->Size(), vector.begin()->size());
  // vector.begin()->size();
}

}  // namespace

// GCOVR_EXCL_STOP
