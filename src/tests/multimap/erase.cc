#include <gtest/gtest.h>

#include <map>

#include "../../s21_multimap.h"
#include "../item.h"
#include "../multimap_helpers.h"
#include "../tree_helpers.h"

// GCOVR_EXCL_START

namespace {

TEST(MultiMap, T0EraseBegin) {
  s21::MultiMap<int, Item> s21_multimap;
  std::multimap<int, Item> multimap;

  s21_multimap.Insert(std::make_pair(4, Item()));
  s21_multimap.Insert(std::make_pair(3, Item()));
  s21_multimap.Insert(std::make_pair(7, Item()));

  std::cout << s21_multimap << '\n';

  multimap.insert(std::make_pair(4, Item()));
  multimap.insert(std::make_pair(3, Item()));
  multimap.insert(std::make_pair(7, Item()));
  std::cout << "Before erase: \n";
  for (auto it = multimap.cbegin(); it != multimap.cend(); ++it)
    std::cout << "{" << it->first << " : " << it->second << "}\n";

  s21::MultiMap<int, Item>::iterator s21_it_result =
      s21_multimap.Erase(s21_multimap.cbegin());
  std::multimap<int, Item>::iterator it_result =
      multimap.erase(multimap.cbegin());

  EXPECT_EQ(*s21_it_result, *it_result);
  std::cout << "After erase: \n";

  for (auto it = s21_multimap.cbegin(); it != s21_multimap.cend(); ++it)
    std::cout << "{" << it->first << " : " << it->second << "}\n";

  EXPECT_EQ(s21_multimap, multimap);
  EXPECT_TRUE(minimalHeightAVL(s21_multimap.Size(), s21_multimap.Height()));

  s21_multimap.Insert(std::make_pair(3, Item()));
  multimap.insert(std::make_pair(3, Item()));
  EXPECT_EQ(s21_multimap, multimap);
  EXPECT_TRUE(minimalHeightAVL(s21_multimap.Size(), s21_multimap.Height()));
}

TEST(MultiMap, T1EraseRBegin) {
  s21::MultiMap<int, Item> s21_multimap;
  s21_multimap.Insert(std::make_pair(4, Item()));
  s21_multimap.Insert(std::make_pair(3, Item()));
  s21_multimap.Insert(std::make_pair(7, Item()));

  std::multimap<int, Item> multimap;
  multimap.insert(std::make_pair(4, Item()));
  multimap.insert(std::make_pair(3, Item()));
  multimap.insert(std::make_pair(7, Item()));

  s21::MultiMap<int, Item>::const_iterator s21_it = s21_multimap.cbegin();
  std::multimap<int, Item>::const_iterator it = multimap.cbegin();
  for (int i = 0; i < 2; i++) {
    ++s21_it;
    ++it;
  }

  s21::MultiMap<int, Item>::iterator s21_it_result = s21_multimap.Erase(s21_it);
  std::multimap<int, Item>::iterator it_result = multimap.erase(it);

  EXPECT_EQ(s21_it_result, s21_multimap.end());
  EXPECT_EQ(it_result, multimap.end());

  std::cout << "After erase: \n";

  for (auto it = s21_multimap.cbegin(); it != s21_multimap.cend(); ++it)
    std::cout << "{" << it->first << " : " << it->second << "}\n";

  EXPECT_EQ(s21_multimap, multimap);
}

TEST(MultiMap, T2EraseRoot) {
  s21::MultiMap<int, Item> s21_multimap;
  s21_multimap.Insert(std::make_pair(4, Item()));
  s21_multimap.Insert(std::make_pair(3, Item()));
  s21_multimap.Insert(std::make_pair(7, Item()));

  std::multimap<int, Item> multimap;
  multimap.insert(std::make_pair(4, Item()));
  multimap.insert(std::make_pair(3, Item()));
  multimap.insert(std::make_pair(7, Item()));

  s21::MultiMap<int, Item>::const_iterator s21_it = s21_multimap.cbegin();
  std::multimap<int, Item>::const_iterator it = multimap.cbegin();
  for (int i = 0; i < 1; i++) {
    ++s21_it;  // SEGMENTATION FAULT!!!!!
    ++it;
  }

  s21::MultiMap<int, Item>::iterator s21_it_result = s21_multimap.Erase(s21_it);
  std::multimap<int, Item>::iterator it_result = multimap.erase(it);

  EXPECT_EQ(*s21_it_result, *it_result);

  std::cout << "After erase: \n";

  for (auto it = s21_multimap.cbegin(); it != s21_multimap.cend(); ++it)
    std::cout << "{" << it->first << " : " << it->second << "}\n";

  EXPECT_EQ(s21_multimap, multimap);
}

TEST(MultiMap, T2_1EraseRoot) {
  s21::MultiMap<int, Item> s21_multimap;
  s21_multimap.Insert(std::make_pair(3, Item()));
  s21_multimap.Insert(std::make_pair(4, Item()));

  std::multimap<int, Item> multimap;
  multimap.insert(std::make_pair(3, Item()));
  multimap.insert(std::make_pair(4, Item()));

  s21::MultiMap<int, Item>::const_iterator s21_it = s21_multimap.cbegin();
  std::multimap<int, Item>::const_iterator it = multimap.cbegin();
  for (int i = 0; i < 1; i++) {
    ++s21_it;  // SEGMENTATION FAULT!!!!!
    ++it;
  }

  s21::MultiMap<int, Item>::iterator s21_it_result = s21_multimap.Erase(s21_it);
  std::multimap<int, Item>::iterator it_result = multimap.erase(it);

  EXPECT_EQ(s21_it_result, s21_multimap.end());
  EXPECT_EQ(it_result, multimap.end());

  std::cout << "After erase: \n";

  for (auto it = s21_multimap.cbegin(); it != s21_multimap.cend(); ++it)
    std::cout << "{" << it->first << " : " << it->second << "}\n";

  EXPECT_EQ(s21_multimap, multimap);
}

TEST(MultiMap, T3RandomErase) {
  // return;
  s21::MultiMap<int, Item> s21_multimap;

  s21_multimap.Insert(std::make_pair(3, Item(3)));
  s21_multimap.Insert(std::make_pair(5, Item(5)));
  s21_multimap.Insert(std::make_pair(5, Item(5)));
  s21_multimap.Insert(std::make_pair(4, Item(4)));

  s21_multimap.Insert(std::make_pair(14, Item(14)));
  s21_multimap.Insert(std::make_pair(11, Item(11)));
  s21_multimap.Insert(std::make_pair(7, Item(7)));
  s21_multimap.Insert(std::make_pair(8, Item(8)));
  s21_multimap.Insert(std::make_pair(-8, Item(-8)));
  s21_multimap.Insert(std::make_pair(7, Item(7)));
  s21_multimap.Insert(std::make_pair(-18, Item(-18)));
  s21_multimap.Insert(std::make_pair(6, Item(6)));
  s21_multimap.Insert(std::make_pair(3, Item(3)));
  s21_multimap.Insert(std::make_pair(29, Item(29)));
  s21_multimap.Insert(std::make_pair(30, Item(30)));
  s21_multimap.Insert(std::make_pair(31, Item(31)));
  s21_multimap.Insert(std::make_pair(34, Item(34)));
  s21_multimap.Insert(std::make_pair(37, Item(37)));

  std::multimap<int, Item> multimap;

  multimap.insert(std::make_pair(3, Item(3)));
  multimap.insert(std::make_pair(5, Item(5)));
  multimap.insert(std::make_pair(5, Item(5)));
  multimap.insert(std::make_pair(4, Item(4)));

  multimap.insert(std::make_pair(14, Item(14)));
  multimap.insert(std::make_pair(11, Item(11)));
  multimap.insert(std::make_pair(7, Item(7)));
  multimap.insert(std::make_pair(8, Item(8)));
  multimap.insert(std::make_pair(-8, Item(-8)));
  multimap.insert(std::make_pair(7, Item(7)));
  multimap.insert(std::make_pair(-18, Item(-18)));
  multimap.insert(std::make_pair(6, Item(6)));
  multimap.insert(std::make_pair(3, Item(3)));
  multimap.insert(std::make_pair(29, Item(29)));
  multimap.insert(std::make_pair(30, Item(30)));
  multimap.insert(std::make_pair(31, Item(31)));
  multimap.insert(std::make_pair(34, Item(34)));
  multimap.insert(std::make_pair(37, Item(37)));

  // std::cout << s21_multimap << "\n\n";
  s21::MultiMap<int, Item>::const_iterator s21_it = s21_multimap.cbegin();
  std::multimap<int, Item>::const_iterator it = multimap.cbegin();
  for (int i = 0; i < 7; ++i) {
    ++s21_it;
    ++it;
  }

  s21::MultiMap<int, Item>::iterator s21_it_result = s21_multimap.Erase(s21_it);
  std::multimap<int, Item>::iterator it_result = multimap.erase(it);

  EXPECT_EQ(*s21_it_result, *it_result);

  EXPECT_EQ(s21_multimap, multimap);
  EXPECT_TRUE(minimalHeightAVL(s21_multimap.Size(), s21_multimap.Height()));
}

TEST(MultiMap, T4RandomErase) {
  // return;
  s21::MultiMap<int, Item> s21_multimap;

  s21_multimap.Insert(std::make_pair(3, Item(3)));
  s21_multimap.Insert(std::make_pair(5, Item(5)));
  s21_multimap.Insert(std::make_pair(5, Item(5)));
  s21_multimap.Insert(std::make_pair(4, Item(4)));

  s21_multimap.Insert(std::make_pair(14, Item(14)));
  s21_multimap.Insert(std::make_pair(11, Item(11)));
  s21_multimap.Insert(std::make_pair(7, Item(7)));
  s21_multimap.Insert(std::make_pair(8, Item(8)));
  s21_multimap.Insert(std::make_pair(-8, Item(-8)));
  s21_multimap.Insert(std::make_pair(7, Item(7)));
  s21_multimap.Insert(std::make_pair(-18, Item(-18)));
  s21_multimap.Insert(std::make_pair(6, Item(6)));
  s21_multimap.Insert(std::make_pair(3, Item(3)));
  s21_multimap.Insert(std::make_pair(29, Item(29)));
  s21_multimap.Insert(std::make_pair(30, Item(30)));
  s21_multimap.Insert(std::make_pair(31, Item(31)));
  s21_multimap.Insert(std::make_pair(34, Item(34)));
  s21_multimap.Insert(std::make_pair(37, Item(37)));

  std::multimap<int, Item> multimap;

  multimap.insert(std::make_pair(3, Item(3)));
  multimap.insert(std::make_pair(5, Item(5)));
  multimap.insert(std::make_pair(5, Item(5)));
  multimap.insert(std::make_pair(4, Item(4)));

  multimap.insert(std::make_pair(14, Item(14)));
  multimap.insert(std::make_pair(11, Item(11)));
  multimap.insert(std::make_pair(7, Item(7)));
  multimap.insert(std::make_pair(8, Item(8)));
  multimap.insert(std::make_pair(-8, Item(-8)));
  multimap.insert(std::make_pair(7, Item(7)));
  multimap.insert(std::make_pair(-18, Item(-18)));
  multimap.insert(std::make_pair(6, Item(6)));
  multimap.insert(std::make_pair(3, Item(3)));
  multimap.insert(std::make_pair(29, Item(29)));
  multimap.insert(std::make_pair(30, Item(30)));
  multimap.insert(std::make_pair(31, Item(31)));
  multimap.insert(std::make_pair(34, Item(34)));
  multimap.insert(std::make_pair(37, Item(37)));

  // std::cout << s21_multimap << "\n\n";
  s21::MultiMap<int, Item>::const_iterator s21_it = s21_multimap.cbegin();
  std::multimap<int, Item>::const_iterator it = multimap.cbegin();
  for (int i = 0; i < 11; ++i) {
    ++s21_it;
    ++it;
  }

  s21::MultiMap<int, Item>::iterator s21_it_result = s21_multimap.Erase(s21_it);
  std::multimap<int, Item>::iterator it_result = multimap.erase(it);

  EXPECT_EQ(*s21_it_result, *it_result);

  EXPECT_EQ(s21_multimap, multimap);
  EXPECT_TRUE(minimalHeightAVL(s21_multimap.Size(), s21_multimap.Height()));
}

TEST(MultiMap, T5RandomErase)  // seems like std::multimap erases not the first
                               // element in the node
{
  // return;
  s21::MultiMap<int, Item> s21_multimap;

  s21_multimap.Insert(std::make_pair(3, Item(3)));
  s21_multimap.Insert(std::make_pair(5, Item(5)));
  s21_multimap.Insert(std::make_pair(5, Item(5)));
  s21_multimap.Insert(std::make_pair(4, Item(4)));

  s21_multimap.Insert(std::make_pair(14, Item(14)));
  s21_multimap.Insert(std::make_pair(11, Item(11)));
  s21_multimap.Insert(std::make_pair(7, Item(7)));
  s21_multimap.Insert(std::make_pair(8, Item(8)));
  s21_multimap.Insert(std::make_pair(-8, Item(-8)));
  s21_multimap.Insert(std::make_pair(7, Item(7)));
  s21_multimap.Insert(std::make_pair(-18, Item(-18)));
  s21_multimap.Insert(std::make_pair(6, Item(6)));
  s21_multimap.Insert(std::make_pair(3, Item(333)));
  s21_multimap.Insert(std::make_pair(29, Item(29)));
  s21_multimap.Insert(std::make_pair(30, Item(30)));
  s21_multimap.Insert(std::make_pair(31, Item(31)));
  s21_multimap.Insert(std::make_pair(34, Item(34)));
  s21_multimap.Insert(std::make_pair(37, Item(37)));

  std::multimap<int, Item> multimap;

  multimap.insert(std::make_pair(3, Item(3)));
  multimap.insert(std::make_pair(5, Item(5)));
  multimap.insert(std::make_pair(5, Item(5)));
  multimap.insert(std::make_pair(4, Item(4)));

  multimap.insert(std::make_pair(14, Item(14)));
  multimap.insert(std::make_pair(11, Item(11)));
  multimap.insert(std::make_pair(7, Item(7)));
  multimap.insert(std::make_pair(8, Item(8)));
  multimap.insert(std::make_pair(-8, Item(-8)));
  multimap.insert(std::make_pair(7, Item(7)));
  multimap.insert(std::make_pair(-18, Item(-18)));
  multimap.insert(std::make_pair(6, Item(6)));
  multimap.insert(std::make_pair(3, Item(333)));
  multimap.insert(std::make_pair(29, Item(29)));
  multimap.insert(std::make_pair(30, Item(30)));
  multimap.insert(std::make_pair(31, Item(31)));
  multimap.insert(std::make_pair(34, Item(34)));
  multimap.insert(std::make_pair(37, Item(37)));

  // std::cout << s21_multimap << "\n\n";
  s21::MultiMap<int, Item>::const_iterator s21_it = s21_multimap.cbegin();
  std::multimap<int, Item>::const_iterator it = multimap.cbegin();
  for (int i = 0; i < 3; ++i) {
    ++s21_it;
    ++it;
  }

  // s21::MultiMap<int, Item>::iterator s21_it_result =
  // s21_multimap.Erase(s21_it); std::multimap<int, Item>::iterator it_result =
  // multimap.erase(it);

  auto s21_it2 = s21_multimap.cbegin();
  auto it2 = multimap.cbegin();
  while (s21_it2 != s21_multimap.cend() && it2 != multimap.cend()) {
    std::cout << "{" << it2->first << " : " << it2->second << "}\t == ";
    std::cout << "{" << s21_it2->first << " : " << s21_it2->second << "}\n";
    ++s21_it2;
    ++it2;
  }

  // EXPECT_EQ(*s21_it_result, *it_result);

  EXPECT_EQ(s21_multimap, multimap);
  EXPECT_TRUE(minimalHeightAVL(s21_multimap.Size(), s21_multimap.Height()));
}

TEST(MultiMap, T6RandomErase) {
  // return;
  s21::MultiMap<int, Item> s21_multimap;

  s21_multimap.Insert(std::make_pair(3, Item(3)));
  s21_multimap.Insert(std::make_pair(5, Item(5)));
  s21_multimap.Insert(std::make_pair(5, Item(5)));
  s21_multimap.Insert(std::make_pair(4, Item(4)));

  s21_multimap.Insert(std::make_pair(14, Item(14)));
  s21_multimap.Insert(std::make_pair(11, Item(11)));
  s21_multimap.Insert(std::make_pair(7, Item(7)));
  s21_multimap.Insert(std::make_pair(8, Item(8)));
  s21_multimap.Insert(std::make_pair(-8, Item(-8)));
  s21_multimap.Insert(std::make_pair(7, Item(7)));
  s21_multimap.Insert(std::make_pair(-18, Item(-18)));
  s21_multimap.Insert(std::make_pair(6, Item(6)));
  s21_multimap.Insert(std::make_pair(3, Item(3)));
  s21_multimap.Insert(std::make_pair(29, Item(29)));
  s21_multimap.Insert(std::make_pair(30, Item(30)));
  s21_multimap.Insert(std::make_pair(31, Item(31)));
  s21_multimap.Insert(std::make_pair(34, Item(34)));
  s21_multimap.Insert(std::make_pair(37, Item(37)));

  std::multimap<int, Item> multimap;

  multimap.insert(std::make_pair(3, Item(3)));
  multimap.insert(std::make_pair(5, Item(5)));
  multimap.insert(std::make_pair(5, Item(5)));
  multimap.insert(std::make_pair(4, Item(4)));

  multimap.insert(std::make_pair(14, Item(14)));
  multimap.insert(std::make_pair(11, Item(11)));
  multimap.insert(std::make_pair(7, Item(7)));
  multimap.insert(std::make_pair(8, Item(8)));
  multimap.insert(std::make_pair(-8, Item(-8)));
  multimap.insert(std::make_pair(7, Item(7)));
  multimap.insert(std::make_pair(-18, Item(-18)));
  multimap.insert(std::make_pair(6, Item(6)));
  multimap.insert(std::make_pair(3, Item(3)));
  multimap.insert(std::make_pair(29, Item(29)));
  multimap.insert(std::make_pair(30, Item(30)));
  multimap.insert(std::make_pair(31, Item(31)));
  multimap.insert(std::make_pair(34, Item(34)));
  multimap.insert(std::make_pair(37, Item(37)));

  // std::cout << s21_multimap << "\n\n";
  s21::MultiMap<int, Item>::const_iterator s21_it = s21_multimap.cbegin();
  std::multimap<int, Item>::const_iterator it = multimap.cbegin();
  for (int i = 0; i < 5; ++i) {
    ++s21_it;
    ++it;
  }

  EXPECT_EQ(s21_multimap, multimap);

  s21::MultiMap<int, Item>::iterator s21_it_result = s21_multimap.Erase(s21_it);
  std::multimap<int, Item>::iterator it_result = multimap.erase(it);

  EXPECT_EQ(*s21_it_result, *it_result);

  EXPECT_EQ(s21_multimap, multimap);
  EXPECT_TRUE(minimalHeightAVL(s21_multimap.Size(), s21_multimap.Height()));
}

TEST(MultiMap, T7RandomEraseRoot) {
  // return;
  s21::MultiMap<int, Item> s21_multimap;

  s21_multimap.Insert(std::make_pair(3, Item(3)));
  s21_multimap.Insert(std::make_pair(5, Item(5)));
  s21_multimap.Insert(std::make_pair(5, Item(5)));
  s21_multimap.Insert(std::make_pair(4, Item(4)));

  s21_multimap.Insert(std::make_pair(14, Item(14)));
  s21_multimap.Insert(std::make_pair(11, Item(11)));
  s21_multimap.Insert(std::make_pair(7, Item(7)));
  s21_multimap.Insert(std::make_pair(8, Item(8)));
  s21_multimap.Insert(std::make_pair(-8, Item(-8)));
  s21_multimap.Insert(std::make_pair(7, Item(7)));
  s21_multimap.Insert(std::make_pair(-18, Item(-18)));
  s21_multimap.Insert(std::make_pair(6, Item(6)));
  s21_multimap.Insert(std::make_pair(3, Item(3)));
  s21_multimap.Insert(std::make_pair(29, Item(29)));
  s21_multimap.Insert(std::make_pair(30, Item(30)));
  s21_multimap.Insert(std::make_pair(31, Item(31)));
  s21_multimap.Insert(std::make_pair(34, Item(34)));
  s21_multimap.Insert(std::make_pair(37, Item(37)));

  std::multimap<int, Item> multimap;

  multimap.insert(std::make_pair(3, Item(3)));
  multimap.insert(std::make_pair(5, Item(5)));
  multimap.insert(std::make_pair(5, Item(5)));
  multimap.insert(std::make_pair(4, Item(4)));

  multimap.insert(std::make_pair(14, Item(14)));
  multimap.insert(std::make_pair(11, Item(11)));
  multimap.insert(std::make_pair(7, Item(7)));
  multimap.insert(std::make_pair(8, Item(8)));
  multimap.insert(std::make_pair(-8, Item(-8)));
  multimap.insert(std::make_pair(7, Item(7)));
  multimap.insert(std::make_pair(-18, Item(-18)));
  multimap.insert(std::make_pair(6, Item(6)));
  multimap.insert(std::make_pair(3, Item(3)));
  multimap.insert(std::make_pair(29, Item(29)));
  multimap.insert(std::make_pair(30, Item(30)));
  multimap.insert(std::make_pair(31, Item(31)));
  multimap.insert(std::make_pair(34, Item(34)));
  multimap.insert(std::make_pair(37, Item(37)));

  EXPECT_EQ(s21_multimap, multimap);
  // std::cout << s21_multimap << "\n\n";
  s21::MultiMap<int, Item>::const_iterator s21_it = s21_multimap.cbegin();
  std::multimap<int, Item>::const_iterator it = multimap.cbegin();
  for (int i = 0; i < 10; ++i) {
    ++s21_it;
    ++it;
  }

  std::cout << "Erase: " << s21_it->first << '\n';
  s21::MultiMap<int, Item>::iterator s21_it_result = s21_multimap.Erase(s21_it);
  std::multimap<int, Item>::iterator it_result = multimap.erase(it);

  EXPECT_EQ(*s21_it_result, *it_result);

  EXPECT_EQ(s21_multimap, multimap);
  EXPECT_TRUE(minimalHeightAVL(s21_multimap.Size(), s21_multimap.Height()));
}

TEST(MultiMap, T8RandomEraseRoot) {
  // return;
  s21::MultiMap<int, Item> s21_multimap;
  s21_multimap.Insert(std::make_pair(60, Item(6)));
  s21_multimap.Insert(std::make_pair(50, Item(5)));
  s21_multimap.Insert(std::make_pair(70, Item(7)));
  s21_multimap.Insert(std::make_pair(45, Item(45)));
  s21_multimap.Insert(std::make_pair(55, Item(55)));
  s21_multimap.Insert(std::make_pair(65, Item(65)));
  s21_multimap.Insert(std::make_pair(80, Item(80)));
  s21_multimap.Insert(std::make_pair(41, Item(41)));
  s21_multimap.Insert(std::make_pair(54, Item(54)));
  s21_multimap.Insert(std::make_pair(58, Item(58)));
  s21_multimap.Insert(std::make_pair(61, Item(61)));
  s21_multimap.Insert(std::make_pair(75, Item(75)));
  s21_multimap.Insert(std::make_pair(85, Item(85)));
  s21_multimap.Insert(std::make_pair(57, Item(57)));
  s21_multimap.Insert(std::make_pair(88, Item(88)));
  s21_multimap.Insert(std::make_pair(90, Item(90)));

  std::multimap<int, Item> multimap;
  multimap.insert(std::make_pair(60, Item(6)));
  multimap.insert(std::make_pair(50, Item(5)));
  multimap.insert(std::make_pair(70, Item(7)));
  multimap.insert(std::make_pair(45, Item(45)));
  multimap.insert(std::make_pair(55, Item(55)));
  multimap.insert(std::make_pair(65, Item(65)));
  multimap.insert(std::make_pair(80, Item(80)));
  multimap.insert(std::make_pair(41, Item(41)));
  multimap.insert(std::make_pair(54, Item(54)));
  multimap.insert(std::make_pair(58, Item(58)));
  multimap.insert(std::make_pair(61, Item(61)));
  multimap.insert(std::make_pair(75, Item(75)));
  multimap.insert(std::make_pair(85, Item(85)));
  multimap.insert(std::make_pair(57, Item(57)));
  multimap.insert(std::make_pair(88, Item(88)));
  multimap.insert(std::make_pair(90, Item(90)));

  EXPECT_EQ(s21_multimap, multimap);
  // std::cout << s21_multimap << "\n\n";
  s21::MultiMap<int, Item>::const_iterator s21_it = s21_multimap.cbegin();
  std::multimap<int, Item>::const_iterator it = multimap.cbegin();
  for (int i = 0; i < 7; ++i) {
    ++s21_it;
    ++it;
  }

  std::cout << "Erase: " << s21_it->first << '\n';
  s21::MultiMap<int, Item>::iterator s21_it_result = s21_multimap.Erase(s21_it);
  std::multimap<int, Item>::iterator it_result = multimap.erase(it);

  EXPECT_EQ(*s21_it_result, *it_result);

  EXPECT_EQ(s21_multimap, multimap);
  EXPECT_TRUE(minimalHeightAVL(s21_multimap.Size(), s21_multimap.Height()));
}

TEST(MultiMap, T9RandomErase) {
  // return;
  s21::MultiMap<int, Item> s21_multimap;

  s21_multimap.Insert(std::make_pair(3, Item(3)));
  s21_multimap.Insert(std::make_pair(5, Item(5)));
  s21_multimap.Insert(std::make_pair(5, Item(5)));
  s21_multimap.Insert(std::make_pair(4, Item(4)));

  s21_multimap.Insert(std::make_pair(14, Item(14)));
  s21_multimap.Insert(std::make_pair(11, Item(11)));
  s21_multimap.Insert(std::make_pair(7, Item(7)));
  s21_multimap.Insert(std::make_pair(8, Item(8)));
  s21_multimap.Insert(std::make_pair(-8, Item(-8)));
  s21_multimap.Insert(std::make_pair(7, Item(7)));
  s21_multimap.Insert(std::make_pair(-18, Item(-18)));
  s21_multimap.Insert(std::make_pair(6, Item(6)));
  s21_multimap.Insert(std::make_pair(3, Item(3)));
  s21_multimap.Insert(std::make_pair(29, Item(29)));
  s21_multimap.Insert(std::make_pair(30, Item(30)));
  s21_multimap.Insert(std::make_pair(31, Item(31)));
  s21_multimap.Insert(std::make_pair(34, Item(34)));
  s21_multimap.Insert(std::make_pair(37, Item(37)));

  std::multimap<int, Item> multimap;

  multimap.insert(std::make_pair(3, Item(3)));
  multimap.insert(std::make_pair(5, Item(5)));
  multimap.insert(std::make_pair(5, Item(5)));
  multimap.insert(std::make_pair(4, Item(4)));

  multimap.insert(std::make_pair(14, Item(14)));
  multimap.insert(std::make_pair(11, Item(11)));
  multimap.insert(std::make_pair(7, Item(7)));
  multimap.insert(std::make_pair(8, Item(8)));
  multimap.insert(std::make_pair(-8, Item(-8)));
  multimap.insert(std::make_pair(7, Item(7)));
  multimap.insert(std::make_pair(-18, Item(-18)));
  multimap.insert(std::make_pair(6, Item(6)));
  multimap.insert(std::make_pair(3, Item(3)));
  multimap.insert(std::make_pair(29, Item(29)));
  multimap.insert(std::make_pair(30, Item(30)));
  multimap.insert(std::make_pair(31, Item(31)));
  multimap.insert(std::make_pair(34, Item(34)));
  multimap.insert(std::make_pair(37, Item(37)));

  // std::cout << s21_multimap << "\n\n";
  s21::MultiMap<int, Item>::const_iterator s21_it = s21_multimap.cbegin();
  std::multimap<int, Item>::const_iterator it = multimap.cbegin();
  for (int i = 0; i < 8; ++i) {
    ++s21_it;
    ++it;
  }

  s21::MultiMap<int, Item>::iterator s21_it_result = s21_multimap.Erase(s21_it);
  std::multimap<int, Item>::iterator it_result = multimap.erase(it);

  EXPECT_EQ(*s21_it_result, *it_result);

  EXPECT_EQ(s21_multimap, multimap);
  EXPECT_TRUE(minimalHeightAVL(s21_multimap.Size(), s21_multimap.Height()));
}

TEST(MultiMap, T0RandomExtract) {
  // return;
  s21::MultiMap<int, Item> s21_multimap;

  s21_multimap.Insert(std::make_pair(3, Item(3)));
  s21_multimap.Insert(std::make_pair(5, Item(5)));
  s21_multimap.Insert(std::make_pair(5, Item(5)));
  s21_multimap.Insert(std::make_pair(4, Item(4)));

  s21_multimap.Insert(std::make_pair(14, Item(14)));
  s21_multimap.Insert(std::make_pair(11, Item(11)));
  s21_multimap.Insert(std::make_pair(7, Item(7)));
  s21_multimap.Insert(std::make_pair(8, Item(8)));
  s21_multimap.Insert(std::make_pair(-8, Item(-8)));
  s21_multimap.Insert(std::make_pair(7, Item(7)));
  s21_multimap.Insert(std::make_pair(-18, Item(-18)));
  s21_multimap.Insert(std::make_pair(6, Item(6)));
  s21_multimap.Insert(std::make_pair(3, Item(3)));
  s21_multimap.Insert(std::make_pair(29, Item(29)));
  s21_multimap.Insert(std::make_pair(30, Item(30)));
  s21_multimap.Insert(std::make_pair(31, Item(31)));
  s21_multimap.Insert(std::make_pair(34, Item(34)));
  s21_multimap.Insert(std::make_pair(37, Item(37)));

  std::multimap<int, Item> multimap;

  multimap.insert(std::make_pair(3, Item(3)));
  multimap.insert(std::make_pair(5, Item(5)));
  multimap.insert(std::make_pair(5, Item(5)));
  multimap.insert(std::make_pair(4, Item(4)));

  multimap.insert(std::make_pair(14, Item(14)));
  multimap.insert(std::make_pair(11, Item(11)));
  multimap.insert(std::make_pair(7, Item(7)));
  multimap.insert(std::make_pair(8, Item(8)));
  multimap.insert(std::make_pair(-8, Item(-8)));
  multimap.insert(std::make_pair(7, Item(7)));
  multimap.insert(std::make_pair(-18, Item(-18)));
  multimap.insert(std::make_pair(6, Item(6)));
  multimap.insert(std::make_pair(3, Item(3)));
  multimap.insert(std::make_pair(29, Item(29)));
  multimap.insert(std::make_pair(30, Item(30)));
  multimap.insert(std::make_pair(31, Item(31)));
  multimap.insert(std::make_pair(34, Item(34)));
  multimap.insert(std::make_pair(37, Item(37)));

  // std::cout << s21_multimap << "\n\n";
  s21::MultiMap<int, Item>::const_iterator s21_it = s21_multimap.cbegin();
  std::multimap<int, Item>::const_iterator it = multimap.cbegin();
  for (int i = 0; i < 8; ++i) {
    ++s21_it;
    ++it;
  }

  s21::MultiMap<int, Item>::node_type s21_it_result =
      s21_multimap.Extract(s21_it);
  std::multimap<int, Item>::node_type it_result = multimap.extract(it);

  EXPECT_EQ(it_result.key(), s21_it_result.Get().first);
  EXPECT_EQ(it_result.mapped(), s21_it_result.Get().second);

  EXPECT_EQ(s21_multimap, multimap);
  EXPECT_TRUE(minimalHeightAVL(s21_multimap.Size(), s21_multimap.Height()));

  // TODO: leaks?
  //    delete &s21_it_result;
  //    delete &it_result;
}

TEST(MultiMap, T1RandomExtract) {
  // return;
  s21::MultiMap<int, Item> s21_multimap;

  s21_multimap.Insert(std::make_pair(3, Item(3)));
  s21_multimap.Insert(std::make_pair(5, Item(5)));
  s21_multimap.Insert(std::make_pair(5, Item(5)));
  s21_multimap.Insert(std::make_pair(4, Item(4)));

  s21_multimap.Insert(std::make_pair(14, Item(14)));
  s21_multimap.Insert(std::make_pair(11, Item(11)));
  s21_multimap.Insert(std::make_pair(7, Item(7)));
  s21_multimap.Insert(std::make_pair(8, Item(8)));
  s21_multimap.Insert(std::make_pair(-8, Item(-8)));
  s21_multimap.Insert(std::make_pair(7, Item(7)));
  s21_multimap.Insert(std::make_pair(-18, Item(-18)));
  s21_multimap.Insert(std::make_pair(6, Item(6)));
  s21_multimap.Insert(std::make_pair(3, Item(3)));
  s21_multimap.Insert(std::make_pair(29, Item(29)));
  s21_multimap.Insert(std::make_pair(30, Item(30)));
  s21_multimap.Insert(std::make_pair(31, Item(31)));
  s21_multimap.Insert(std::make_pair(34, Item(34)));
  s21_multimap.Insert(std::make_pair(37, Item(37)));

  std::multimap<int, Item> multimap;

  multimap.insert(std::make_pair(3, Item(3)));
  multimap.insert(std::make_pair(5, Item(5)));
  multimap.insert(std::make_pair(5, Item(5)));
  multimap.insert(std::make_pair(4, Item(4)));

  multimap.insert(std::make_pair(14, Item(14)));
  multimap.insert(std::make_pair(11, Item(11)));
  multimap.insert(std::make_pair(7, Item(7)));
  multimap.insert(std::make_pair(8, Item(8)));
  multimap.insert(std::make_pair(-8, Item(-8)));
  multimap.insert(std::make_pair(7, Item(7)));
  multimap.insert(std::make_pair(-18, Item(-18)));
  multimap.insert(std::make_pair(6, Item(6)));
  multimap.insert(std::make_pair(3, Item(3)));
  multimap.insert(std::make_pair(29, Item(29)));
  multimap.insert(std::make_pair(30, Item(30)));
  multimap.insert(std::make_pair(31, Item(31)));
  multimap.insert(std::make_pair(34, Item(34)));
  multimap.insert(std::make_pair(37, Item(37)));

  // std::cout << s21_multimap << "\n\n";
  s21::MultiMap<int, Item>::const_iterator s21_it = s21_multimap.cbegin();
  std::multimap<int, Item>::const_iterator it = multimap.cbegin();
  for (int i = 0; i < 4; ++i) {
    ++s21_it;
    ++it;
  }

  // s21::MultiMap<int, Item>::node_type s21_it_result =
  // s21_multimap.Extract(s21_it); std::multimap<int, Item>::node_type it_result
  // = multimap.extract(it);

  // EXPECT_EQ(it_result.key(), s21_it_result.Get().first);
  // EXPECT_EQ(it_result.mapped(), s21_it_result.Get().second);

  EXPECT_EQ(s21_multimap, multimap);
  EXPECT_TRUE(minimalHeightAVL(s21_multimap.Size(), s21_multimap.Height()));
}

}  // namespace

// GCOVR_EXCL_STOP
