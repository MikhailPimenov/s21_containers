#include <gtest/gtest.h>

#include <set>

#include "../../s21_multiset.h"
#include "../item.h"
#include "../multiset_helpers.h"

// GCOVR_EXCL_START

namespace {

TEST(MultiSet, T0DefaultConstructor) {
  s21::MultiSet<Item, ComparatorItem> s21_multiset;
  std::multiset<Item, ComparatorItem> multimap;

  s21_multiset.Insert(Item(3, 'c', 0.3));
  s21_multiset.Insert(Item(1, 'a', 0.1));
  s21_multiset.Insert(Item(1, 'b', 0.1));
  s21_multiset.Insert(Item(2, 'b', 0.2));
  s21_multiset.Insert(Item(2, 'b', 0.2));
  s21_multiset.Insert(Item(1, 'c', 0.1));
  s21_multiset.Insert(Item(2, 'b', 0.2));
  s21_multiset.Insert(Item(3, 'c', 0.3));

  multimap.insert(Item(3, 'c', 0.3));
  multimap.insert(Item(1, 'a', 0.1));
  multimap.insert(Item(1, 'b', 0.1));
  multimap.insert(Item(2, 'b', 0.2));
  multimap.insert(Item(2, 'b', 0.2));
  multimap.insert(Item(1, 'c', 0.1));
  multimap.insert(Item(2, 'b', 0.2));
  multimap.insert(Item(3, 'c', 0.3));

  EXPECT_EQ(s21_multiset, multimap);
}

TEST(MultiSet, T0Insert) {
  s21::MultiSet<Item, ComparatorItem> s21_multiset;
  s21_multiset.Insert(Item(10, 'c', 0.3));
  s21_multiset.Insert(Item(10, 'c', 0.3));
  s21_multiset.Insert(Item(12, 'c', 0.3));
  s21_multiset.Insert(Item(13, 'c', 0.3));
  s21_multiset.Insert(Item(3, 'c', 0.3));
  s21_multiset.Insert(Item(1, 'a', 0.1));
  s21_multiset.Insert(Item(1, 'a', 0.1));
  s21_multiset.Insert(Item(1, 'a', 0.1));
  s21_multiset.Insert(Item(1, 'a', 0.1));
  s21_multiset.Insert(Item(1, 'a', 0.1));
  s21_multiset.Insert(Item(2, 'b', 0.2));
  s21_multiset.Insert(Item(2, 'b', 0.2));
  s21_multiset.Insert(Item(2, 'b', 0.2));
  s21_multiset.Insert(Item(2, 'b', 0.2));
  s21_multiset.Insert(Item(3, 'c', 0.3));
  s21_multiset.Insert(Item(3, 'c', 0.3));

  std::multiset<Item, ComparatorItem> multimap;
  multimap.insert(Item(10, 'c', 0.3));
  multimap.insert(Item(10, 'c', 0.3));
  multimap.insert(Item(12, 'c', 0.3));
  multimap.insert(Item(13, 'c', 0.3));
  multimap.insert(Item(3, 'c', 0.3));
  multimap.insert(Item(1, 'a', 0.1));
  multimap.insert(Item(1, 'a', 0.1));
  multimap.insert(Item(1, 'a', 0.1));
  multimap.insert(Item(1, 'a', 0.1));
  multimap.insert(Item(1, 'a', 0.1));
  multimap.insert(Item(2, 'b', 0.2));
  multimap.insert(Item(2, 'b', 0.2));
  multimap.insert(Item(2, 'b', 0.2));
  multimap.insert(Item(2, 'b', 0.2));
  multimap.insert(Item(3, 'c', 0.3));
  multimap.insert(Item(3, 'c', 0.3));

  EXPECT_EQ(s21_multiset, multimap);
}

TEST(MultiSet, T0ConstructorInitializer) {
  const s21::MultiSet<Item, ComparatorItem> s21_multiset{
      {Item(10, 'c', 0.3)}, {Item(10, 'c', 0.3)}, {Item(12, 'c', 0.3)},
      {Item(13, 'c', 0.3)}, {Item(3, 'c', 0.3)},  {Item(1, 'a', 0.1)},
      {Item(1, 'a', 0.1)},  {Item(1, 'a', 0.1)},  {Item(1, 'a', 0.1)},
      {Item(1, 'a', 0.1)},  {Item(2, 'b', 0.2)},  {Item(2, 'b', 0.2)},
      {Item(2, 'b', 0.2)},  {Item(2, 'b', 0.2)},  {Item(3, 'c', 0.3)},
      {Item(3, 'c', 0.3)},
  };

  const std::multiset<Item, ComparatorItem> multimap{
      {Item(10, 'c', 0.3)}, {Item(10, 'c', 0.3)}, {Item(12, 'c', 0.3)},
      {Item(13, 'c', 0.3)}, {Item(3, 'c', 0.3)},  {Item(1, 'a', 0.1)},
      {Item(1, 'a', 0.1)},  {Item(1, 'a', 0.1)},  {Item(1, 'a', 0.1)},
      {Item(1, 'a', 0.1)},  {Item(2, 'b', 0.2)},  {Item(2, 'b', 0.2)},
      {Item(2, 'b', 0.2)},  {Item(2, 'b', 0.2)},  {Item(3, 'c', 0.3)},
      {Item(3, 'c', 0.3)},
  };

  EXPECT_EQ(s21_multiset, multimap);
}

TEST(MultiSet, T1Destructor) {
  s21::MultiSet<Item, ComparatorItem> s21_multiset;
  s21_multiset.Insert(Item(4));
  s21_multiset.Insert(Item(3));
  s21_multiset.Insert(Item(5));
}

TEST(MultiSet, T2Destructor) {
  s21::MultiSet<Item, ComparatorItem> s21_multiset;
  s21_multiset.Insert(Item(4));
  s21_multiset.Insert(Item(4));
  s21_multiset.Insert(Item(4));
  s21_multiset.Insert(Item(4));

  std::multiset<Item, ComparatorItem> multimap;
  multimap.insert(Item(4));
  multimap.insert(Item(4));
  multimap.insert(Item(4));
  multimap.insert(Item(4));

  EXPECT_EQ(s21_multiset, multimap);
}

TEST(MultiSet, T1ConstructorInitializer) {
  s21::MultiSet<Item, ComparatorItem> s21_multiset{
      {Item(3, 'c', 0.3)}, {Item(1, 'a', 0.1)}, {Item(2, 'b', 0.2)},
      {Item(3, 'c', 0.3)}, {Item(3, 'c', 0.3)}, {Item(4, 'd', 0.4)},
      {Item(5, 'e', 0.5)}, {Item(6, 'f', 0.6)},
  };
  std::multiset<Item, ComparatorItem> multimap{
      {Item(3, 'c', 0.3)}, {Item(1, 'a', 0.1)}, {Item(2, 'b', 0.2)},
      {Item(3, 'c', 0.3)}, {Item(3, 'c', 0.3)}, {Item(4, 'd', 0.4)},
      {Item(5, 'e', 0.5)}, {Item(6, 'f', 0.6)},
  };

  EXPECT_EQ(s21_multiset, multimap);
}

TEST(MultiSet, T0CopyConstructor) {
  const s21::MultiSet<Item, ComparatorItem> s21_source{
      {Item(1, 'a', 0.1)}, {Item(6, 'f', 0.6)}, {Item(2, 'b', 0.2)},
      {Item(5, 'e', 0.5)}, {Item(2, 'b', 0.2)}, {Item(4, 'd', 0.4)},
      {Item(1, 'a', 0.1)}, {Item(2, 'b', 0.2)}, {Item(3, 'c', 0.3)},
      {Item(4, 'd', 0.4)}, {Item(4, 'd', 0.4)}, {Item(4, 'd', 0.4)},
      {Item(5, 'e', 0.5)}, {Item(6, 'f', 0.6)},
  };
  const std::multiset<Item, ComparatorItem> source{
      {Item(1, 'a', 0.1)}, {Item(6, 'f', 0.6)}, {Item(2, 'b', 0.2)},
      {Item(5, 'e', 0.5)}, {Item(2, 'b', 0.2)}, {Item(4, 'd', 0.4)},
      {Item(1, 'a', 0.1)}, {Item(2, 'b', 0.2)}, {Item(3, 'c', 0.3)},
      {Item(4, 'd', 0.4)}, {Item(4, 'd', 0.4)}, {Item(4, 'd', 0.4)},
      {Item(5, 'e', 0.5)}, {Item(6, 'f', 0.6)},
  };

  s21::MultiSet<Item, ComparatorItem> s21_copy =
      s21_source;  // copy constructor, not operator=
  std::multiset<Item, ComparatorItem> copy = source;

  EXPECT_EQ(s21_copy, copy);
}

TEST(MultiSet, T1CopyConstructorEmpty) {
  const s21::MultiSet<Item, ComparatorItem> s21_source;
  const std::multiset<Item, ComparatorItem> source;

  s21::MultiSet<Item, ComparatorItem> s21_copy =
      s21_source;  // copy constructor, not operator=
  std::multiset<Item, ComparatorItem> copy = source;

  EXPECT_EQ(s21_copy, copy);
}

TEST(MultiSet, T0CopyAssignmentOperator) {
  const s21::MultiSet<Item, ComparatorItem> s21_source{
      {Item(6, 'f', 0.6)}, {Item(5, 'e', 0.5)}, {Item(1, 'a', 0.1)},
      {Item(2, 'b', 0.2)}, {Item(1, 'a', 0.1)}, {Item(1, 'a', 0.1)},
      {Item(1, 'a', 0.1)}, {Item(1, 'a', 0.1)}, {Item(5, 'e', 0.5)},
  };
  const std::multiset<Item, ComparatorItem> source{
      {Item(6, 'f', 0.6)}, {Item(5, 'e', 0.5)}, {Item(1, 'a', 0.1)},
      {Item(2, 'b', 0.2)}, {Item(1, 'a', 0.1)}, {Item(1, 'a', 0.1)},
      {Item(1, 'a', 0.1)}, {Item(1, 'a', 0.1)}, {Item(5, 'e', 0.5)},
  };

  s21::MultiSet<Item, ComparatorItem> s21_copy;
  s21_copy = s21_source;
  std::multiset<Item, ComparatorItem> copy;
  copy = source;

  EXPECT_EQ(s21_copy, copy);
}

TEST(MultiSet, T1CopyAssignmentOperator) {
  const s21::MultiSet<Item, ComparatorItem> s21_source;
  const std::multiset<Item, ComparatorItem> source;

  s21::MultiSet<Item, ComparatorItem> s21_copy;
  s21_copy = s21_source;
  std::multiset<Item, ComparatorItem> copy;
  copy = source;

  EXPECT_EQ(s21_copy, copy);
}

TEST(MultiSet, T0MoveAssignmentOperator) {
  s21::MultiSet<Item, ComparatorItem> s21_source{
      {Item(1, 'a', 0.1111)}, {Item(4, 'd', 0.44)},  {Item(1, 'a', 0.1)},
      {Item(1, 'a', 0.11)},   {Item(1, 'a', 0.111)}, {Item(2, 'b', 0.2)},
      {Item(6, 'f', 0.66)},   {Item(3, 'c', 0.3)},   {Item(3, 'c', 0.33)},
      {Item(4, 'd', 0.4)},    {Item(5, 'e', 0.5)},   {Item(6, 'f', 0.6)},
  };
  std::multiset<Item, ComparatorItem> source{
      {Item(1, 'a', 0.1111)}, {Item(4, 'd', 0.44)},  {Item(1, 'a', 0.1)},
      {Item(1, 'a', 0.11)},   {Item(1, 'a', 0.111)}, {Item(2, 'b', 0.2)},
      {Item(6, 'f', 0.66)},   {Item(3, 'c', 0.3)},   {Item(3, 'c', 0.33)},
      {Item(4, 'd', 0.4)},    {Item(5, 'e', 0.5)},   {Item(6, 'f', 0.6)},
  };

  s21::MultiSet<Item, ComparatorItem> s21_copy{
      {Item(3, 'c', 0.3)},
      {Item(3, 'c', 0.3)},
      {Item(4, 'd', 0.4)},
  };
  s21_copy = std::move(s21_source);

  std::multiset<Item, ComparatorItem> copy{
      {Item(3, 'c', 0.3)},
      {Item(3, 'c', 0.3)},
      {Item(4, 'd', 0.4)},
  };
  copy = std::move(source);

  EXPECT_EQ(s21_copy, copy);

  const s21::MultiSet<Item, ComparatorItem> s21_empty;
  EXPECT_EQ(s21_source, s21_empty);

  const std::multiset<Item, ComparatorItem> empty;
  EXPECT_EQ(source, empty);
}

TEST(MultiSet, T1MoveAssignmentOperator) {
  s21::MultiSet<Item, ComparatorItem> s21_source;
  std::multiset<Item, ComparatorItem> source;

  s21::MultiSet<Item, ComparatorItem> s21_copy{
      {Item(3, 'c', 0.3)},
      {Item(4, 'd', 0.4)},
  };
  s21_copy = std::move(s21_source);

  std::multiset<Item, ComparatorItem> copy{
      {Item(3, 'c', 0.3)},
      {Item(4, 'd', 0.4)},
  };
  copy = std::move(source);

  EXPECT_EQ(s21_copy, copy);

  const s21::MultiSet<Item, ComparatorItem> s21_empty;
  EXPECT_EQ(s21_source, s21_empty);

  const std::multiset<Item, ComparatorItem> empty;
  EXPECT_EQ(source, empty);
}

TEST(MultiSet, T0MoveConstructor) {
  s21::MultiSet<Item, ComparatorItem> s21_source{
      {Item(1, 'a', 0.1)}, {Item(2, 'b', 0.2)}, {Item(3, 'c', 0.3)},
      {Item(4, 'd', 0.4)}, {Item(5, 'e', 0.5)}, {Item(6, 'f', 0.6)},
  };
  std::multiset<Item, ComparatorItem> source{
      {Item(1, 'a', 0.1)}, {Item(2, 'b', 0.2)}, {Item(3, 'c', 0.3)},
      {Item(4, 'd', 0.4)}, {Item(5, 'e', 0.5)}, {Item(6, 'f', 0.6)},
  };

  s21::MultiSet<Item, ComparatorItem> s21_copy = std::move(s21_source);
  std::multiset<Item, ComparatorItem> copy = std::move(source);

  EXPECT_EQ(s21_copy, copy);

  const s21::MultiSet<Item, ComparatorItem> s21_empty;
  EXPECT_EQ(s21_source, s21_empty);

  const std::multiset<Item, ComparatorItem> empty;
  EXPECT_EQ(source, empty);
}

TEST(MultiSet, T1MoveConstructor) {
  s21::MultiSet<Item, ComparatorItem> s21_source;
  std::multiset<Item, ComparatorItem> source;

  s21::MultiSet<Item, ComparatorItem> s21_copy = std::move(s21_source);
  std::multiset<Item, ComparatorItem> copy = std::move(source);

  EXPECT_EQ(s21_copy, copy);

  const s21::MultiSet<Item, ComparatorItem> s21_empty;
  EXPECT_EQ(s21_source, s21_empty);

  const std::multiset<Item, ComparatorItem> empty;
  EXPECT_EQ(source, empty);
}

TEST(MultiSet, T0ReverseIterator) {
  s21::MultiSet<Item, ComparatorItem> s21_multiset{
      {Item(10, 'c', 0.3)},
      {Item(4, 'c', 0.3)},
      {Item(7, 'c', 0.3)},
  };

  std::multiset<Item, ComparatorItem> multimap{
      {Item(10, 'c', 0.3)},
      {Item(4, 'c', 0.3)},
      {Item(7, 'c', 0.3)},
  };

  // for (auto it = s21_multiset.rbegin(); it != s21_multiset.rend(); ++it) {
  //     std::cout << "{" << it->first << ", " << it->second << "},\n";
  // }
  // std::cout << '\n';

  EXPECT_EQ(s21_multiset, multimap);

  s21::MultiSet<Item, ComparatorItem>::reverse_iterator s21_it =
      s21_multiset.rbegin();
  std::multiset<Item, ComparatorItem>::reverse_iterator it = multimap.rbegin();

  while (s21_it != s21_multiset.rend() && it != multimap.rend()) {
    EXPECT_EQ(*s21_it, *it);
    // std::cout << "{" << s21_it->first << ", " << s21_it->second << "}  ==  ";
    // std::cout << "{" << it->first << ", " << it->second << "},  ";
    // std::cout << '\n';
    ++s21_it;
    ++it;
  }
}

TEST(MultiSet, T1ReverseIterator) {
  s21::MultiSet<Item, ComparatorItem> s21_multiset{
      {Item(10, 'c', 0.3)}, {Item(10, 'c', 0.3)}, {Item(12, 'c', 0.3)},
      {Item(13, 'c', 0.3)}, {Item(3, 'c', 0.3)},  {Item(1, 'a', 0.1)},
      {Item(1, 'a', 0.1)},  {Item(1, 'a', 0.1)},  {Item(1, 'a', 0.1)},
      {Item(1, 'a', 0.1)},  {Item(2, 'b', 0.2)},  {Item(2, 'b', 0.2)},
      {Item(2, 'b', 0.2)},  {Item(2, 'b', 0.2)},  {Item(3, 'c', 0.3)},
      {Item(3, 'c', 0.3)},
  };

  std::multiset<Item, ComparatorItem> multimap{
      {Item(10, 'c', 0.3)}, {Item(10, 'c', 0.3)}, {Item(12, 'c', 0.3)},
      {Item(13, 'c', 0.3)}, {Item(3, 'c', 0.3)},  {Item(1, 'a', 0.1)},
      {Item(1, 'a', 0.1)},  {Item(1, 'a', 0.1)},  {Item(1, 'a', 0.1)},
      {Item(1, 'a', 0.1)},  {Item(2, 'b', 0.2)},  {Item(2, 'b', 0.2)},
      {Item(2, 'b', 0.2)},  {Item(2, 'b', 0.2)},  {Item(3, 'c', 0.3)},
      {Item(3, 'c', 0.3)},
  };

  // for (auto it = multimap.rbegin(); it != multimap.rend(); ++it) {
  //     std::cout << "{" << it->first << ", " << it->second << "},  ";
  // }
  // std::cout << '\n';

  EXPECT_EQ(s21_multiset, multimap);

  s21::MultiSet<Item, ComparatorItem>::reverse_iterator s21_it =
      s21_multiset.rbegin();
  std::multiset<Item, ComparatorItem>::reverse_iterator it = multimap.rbegin();

  while (s21_it != s21_multiset.rend() && it != multimap.rend()) {
    EXPECT_EQ(*s21_it, *it);
    // std::cout << "{" << s21_it->first << ", " << s21_it->second << "}  ==  ";
    // std::cout << "{" << it->first << ", " << it->second << "},  ";
    // std::cout << '\n';
    ++s21_it;
    ++it;
  }
}

TEST(MultiSet, T1IteratorOperatorMinusPrefix) {
  s21::MultiSet<Item, ComparatorItem> s21_multiset{
      {Item(10, 'c', 0.3)}, {Item(10, 'c', 0.3)}, {Item(12, 'c', 0.3)},
      {Item(13, 'c', 0.3)}, {Item(3, 'c', 0.3)},  {Item(1, 'a', 0.1)},
      {Item(1, 'a', 0.1)},  {Item(1, 'a', 0.1)},  {Item(1, 'a', 0.1)},
      {Item(1, 'a', 0.1)},  {Item(2, 'b', 0.2)},  {Item(2, 'b', 0.2)},
      {Item(2, 'b', 0.2)},  {Item(2, 'b', 0.2)},  {Item(3, 'c', 0.3)},
      {Item(3, 'c', 0.3)},
  };

  std::multiset<Item, ComparatorItem> multimap{
      {Item(10, 'c', 0.3)}, {Item(10, 'c', 0.3)}, {Item(12, 'c', 0.3)},
      {Item(13, 'c', 0.3)}, {Item(3, 'c', 0.3)},  {Item(1, 'a', 0.1)},
      {Item(1, 'a', 0.1)},  {Item(1, 'a', 0.1)},  {Item(1, 'a', 0.1)},
      {Item(1, 'a', 0.1)},  {Item(2, 'b', 0.2)},  {Item(2, 'b', 0.2)},
      {Item(2, 'b', 0.2)},  {Item(2, 'b', 0.2)},  {Item(3, 'c', 0.3)},
      {Item(3, 'c', 0.3)},
  };

  // for (auto it = multimap.rbegin(); it != multimap.rend(); ++it) {
  //     std::cout << "{" << it->first << ", " << it->second << "},  ";
  // }
  // std::cout << '\n';

  EXPECT_EQ(s21_multiset, multimap);

  s21::MultiSet<Item, ComparatorItem>::iterator s21_it = s21_multiset.end();
  std::multiset<Item, ComparatorItem>::iterator it = multimap.end();

  while (s21_it != s21_multiset.begin() && it != multimap.begin()) {
    --s21_it;
    --it;
    // std::cout << "{" << s21_it->first << ", " << s21_it->second << "}\t\t==
    // "; std::cout << "{" << it->first << ", " << it->second << "}\n";
    EXPECT_EQ(*s21_it, *it);
  }
}

TEST(MultiSet, T1ReverseIteratorOperatorMinusPrefix) {
  s21::MultiSet<Item, ComparatorItem> s21_multiset{
      {Item(10, 'c', 0.3)}, {Item(10, 'c', 0.3)}, {Item(12, 'c', 0.3)},
      {Item(13, 'c', 0.3)}, {Item(3, 'c', 0.3)},  {Item(1, 'a', 0.1)},
      {Item(1, 'a', 0.1)},  {Item(1, 'a', 0.1)},  {Item(1, 'a', 0.1)},
      {Item(1, 'a', 0.1)},  {Item(2, 'b', 0.2)},  {Item(2, 'b', 0.2)},
      {Item(2, 'b', 0.2)},  {Item(2, 'b', 0.2)},  {Item(3, 'c', 0.3)},
      {Item(3, 'c', 0.3)},
  };

  std::multiset<Item, ComparatorItem> multimap{
      {Item(10, 'c', 0.3)}, {Item(10, 'c', 0.3)}, {Item(12, 'c', 0.3)},
      {Item(13, 'c', 0.3)}, {Item(3, 'c', 0.3)},  {Item(1, 'a', 0.1)},
      {Item(1, 'a', 0.1)},  {Item(1, 'a', 0.1)},  {Item(1, 'a', 0.1)},
      {Item(1, 'a', 0.1)},  {Item(2, 'b', 0.2)},  {Item(2, 'b', 0.2)},
      {Item(2, 'b', 0.2)},  {Item(2, 'b', 0.2)},  {Item(3, 'c', 0.3)},
      {Item(3, 'c', 0.3)},
  };

  // for (auto it = multimap.rbegin(); it != multimap.rend(); ++it) {
  //     std::cout << "{" << it->first << ", " << it->second << "},  ";
  // }
  // std::cout << '\n';

  EXPECT_EQ(s21_multiset, multimap);

  s21::MultiSet<Item, ComparatorItem>::reverse_iterator s21_it =
      s21_multiset.rend();
  std::multiset<Item, ComparatorItem>::reverse_iterator it = multimap.rend();

  while (s21_it != s21_multiset.rbegin() && it != multimap.rbegin()) {
    --s21_it;
    --it;
    // std::cout << "{" << s21_it->first << ", " << s21_it->second << "}\t\t==
    // "; std::cout << "{" << it->first << ", " << it->second << "}\n";
    EXPECT_EQ(*s21_it, *it);
  }
}

}  // namespace

// GCOVR_EXCL_STOP
