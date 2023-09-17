#include <gtest/gtest.h>

#include <map>

#include "../../s21_multiset.h"
#include "../../s21_vector.h"
#include "../item.h"
#include "../multiset_helpers.h"

//  GCOVR_EXCL_START

namespace {
TEST(MultiSet, T0InsertMany) {
  s21::MultiSet<Item, ComparatorItem> s21_multiset{
      Item(11), Item(22), Item(33), Item(44), Item(55), Item(66),
  };

  s21::MultiSet<Item, ComparatorItem> s21_multiset_expected{
      Item(11), Item(22), Item(33),  Item(44),
      Item(55), Item(66), Item(666), Item(777),
  };

  s21_multiset.Insert_many(Item(666), Item(777));

  EXPECT_EQ(s21_multiset, s21_multiset_expected);
}

TEST(MultiSet, T1InsertManyEmpty) {
  s21::MultiSet<Item, ComparatorItem> s21_multiset;

  s21::MultiSet<Item, ComparatorItem> s21_multiset_expected{
      Item(11), Item(22), Item(33),  Item(44),
      Item(55), Item(66), Item(666), Item(777),
  };

  s21::Vector<std::pair<s21::MultiSet<Item, ComparatorItem>::iterator, bool>>
      s21_result =
          s21_multiset.Insert_many(Item(11), Item(22), Item(33), Item(44),
                                   Item(55), Item(66), Item(666), Item(777));

  EXPECT_EQ(s21_multiset, s21_multiset_expected);
}

TEST(MultiSet, T2InsertMany) {
  s21::MultiSet<Item, ComparatorItem> s21_multiset;
  s21::MultiSet<Item, ComparatorItem> s21_multiset2 = s21_multiset;

  s21::MultiSet<Item, ComparatorItem> s21_multiset_expected{
      Item(11), Item(22), Item(33),  Item(44),
      Item(55), Item(66), Item(666), Item(777),
  };

  s21::Vector<std::pair<s21::MultiSet<Item, ComparatorItem>::iterator, bool>>
      s21_result_expected;
  s21_result_expected.Push_back(s21_multiset2.Insert(Item(11)));
  s21_result_expected.Push_back(s21_multiset2.Insert(Item(22)));
  s21_result_expected.Push_back(s21_multiset2.Insert(Item(33)));
  s21_result_expected.Push_back(s21_multiset2.Insert(Item(44)));
  s21_result_expected.Push_back(s21_multiset2.Insert(Item(55)));
  s21_result_expected.Push_back(s21_multiset2.Insert(Item(66)));
  s21_result_expected.Push_back(s21_multiset2.Insert(Item(666)));
  s21_result_expected.Push_back(s21_multiset2.Insert(Item(777)));

  s21::Vector<std::pair<s21::MultiSet<Item, ComparatorItem>::iterator, bool>>
      s21_result =
          s21_multiset.Insert_many(Item(11), Item(22), Item(33), Item(44),
                                   Item(55), Item(66), Item(666), Item(777));

  EXPECT_EQ(s21_multiset, s21_multiset_expected);
  EXPECT_EQ(s21_multiset2, s21_multiset_expected);

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

TEST(MultiSet, T3InsertMany) {
  s21::MultiSet<Item, ComparatorItem> s21_multiset{
      Item(44, 'a'),
      Item(55),
  };
  s21::MultiSet<Item, ComparatorItem> s21_multiset2 = s21_multiset;

  s21::MultiSet<Item, ComparatorItem> s21_multiset_expected{
      Item(11), Item(22), Item(33), Item(44, 'a'), Item(44),
      Item(55), Item(55), Item(66), Item(666),     Item(777),
  };

  s21::Vector<std::pair<s21::MultiSet<Item, ComparatorItem>::iterator, bool>>
      s21_result_expected;
  s21_result_expected.Push_back(s21_multiset2.Insert(Item(11)));
  s21_result_expected.Push_back(s21_multiset2.Insert(Item(22)));
  s21_result_expected.Push_back(s21_multiset2.Insert(Item(33)));
  s21_result_expected.Push_back(s21_multiset2.Insert(Item(44)));
  s21_result_expected.Push_back(s21_multiset2.Insert(Item(55)));
  s21_result_expected.Push_back(s21_multiset2.Insert(Item(66)));
  s21_result_expected.Push_back(s21_multiset2.Insert(Item(666)));
  s21_result_expected.Push_back(s21_multiset2.Insert(Item(777)));

  s21::Vector<std::pair<s21::MultiSet<Item, ComparatorItem>::iterator, bool>>
      s21_result =
          s21_multiset.Insert_many(Item(11), Item(22), Item(33), Item(44),
                                   Item(55), Item(66), Item(666), Item(777));

  EXPECT_EQ(s21_multiset, s21_multiset_expected);
  EXPECT_EQ(s21_multiset2, s21_multiset_expected);

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

TEST(MultiSet, T4InsertMany) {
  s21::MultiSet<Item, ComparatorItem> s21_multiset{
      Item(111, 's', 0.111),
      Item(44, 'a'),
      Item(55),
  };
  s21::MultiSet<Item, ComparatorItem> s21_multiset2 = s21_multiset;

  s21::MultiSet<Item, ComparatorItem> s21_multiset_expected{
      Item(111, 's', 0.111),
      Item(11),
      Item(22),
      Item(33),
      Item(44, 'a'),
      Item(44),
      Item(55),
      Item(55),
      Item(66),
      Item(666),
      Item(777),
  };

  s21::Vector<std::pair<s21::MultiSet<Item, ComparatorItem>::iterator, bool>>
      s21_result_expected;
  s21_result_expected.Push_back(s21_multiset2.Insert(Item(11)));
  s21_result_expected.Push_back(s21_multiset2.Insert(Item(22)));
  s21_result_expected.Push_back(s21_multiset2.Insert(Item(33)));
  s21_result_expected.Push_back(s21_multiset2.Insert(Item(44)));
  s21_result_expected.Push_back(s21_multiset2.Insert(Item(55)));
  s21_result_expected.Push_back(s21_multiset2.Insert(Item(66)));
  s21_result_expected.Push_back(s21_multiset2.Insert(Item(666)));
  s21_result_expected.Push_back(s21_multiset2.Insert(Item(777)));

  s21::Vector<std::pair<s21::MultiSet<Item, ComparatorItem>::iterator, bool>>
      s21_result =
          s21_multiset.Insert_many(Item(11), Item(22), Item(33), Item(44),
                                   Item(55), Item(66), Item(666), Item(777));

  EXPECT_EQ(s21_multiset, s21_multiset_expected);
  EXPECT_EQ(s21_multiset2, s21_multiset_expected);

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