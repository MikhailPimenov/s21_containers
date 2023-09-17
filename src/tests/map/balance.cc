#include <gtest/gtest.h>

#include <deque>
#include <list>
#include <map>
#include <stack>
#include <vector>

#include "../../s21_map.h"
#include "../item.h"
#include "../map_helpers.h"
#include "../tree_helpers.h"

// GCOVR_EXCL_START

namespace {

TEST(Map, T0LeftLeftCase) {
  s21::Map<double, Item> s21_map;
  std::cout << "insert 5.0\n";
  s21_map.Insert(std::make_pair(5.0, Item(5)));
  std::cout << s21_map << '\n';
  std::cout << "insert 3.0\n";
  s21_map.Insert(std::make_pair(3.0, Item(5)));
  std::cout << s21_map << '\n';
  std::cout << "insert 2.0\n";
  s21_map.Insert(std::make_pair(2.0, Item(5)));
  std::cout << s21_map << '\n';

  std::cout << "insert 1.0\n";
  s21_map.Insert(std::make_pair(1.0, Item(5, 'D')));
  std::cout << s21_map << '\n';
  std::cout << "insert 2.5\n";
  s21_map.Insert(std::make_pair(2.5, Item(5, 'C')));
  std::cout << s21_map << '\n';
  std::cout << "insert 4.0\n";
  s21_map.Insert(std::make_pair(4.0, Item(5, 'B')));
  std::cout << s21_map << '\n';
  std::cout << "insert 7.0\n";
  s21_map.Insert(std::make_pair(7.0, Item(5, 'A')));
  std::cout << s21_map << '\n';

  EXPECT_TRUE(minimalHeightAVL(s21_map.Size(), s21_map.Height()));
}

TEST(Map, T1RightRightCase) {
  s21::Map<double, Item> s21_map;
  std::cout << "insert 3.0\n";
  s21_map.Insert(std::make_pair(3.0, Item(5)));
  std::cout << s21_map << '\n';
  std::cout << "insert 5.0\n";
  s21_map.Insert(std::make_pair(5.0, Item(5)));
  std::cout << s21_map << '\n';
  std::cout << "insert 7.0\n";
  s21_map.Insert(std::make_pair(7.0, Item(5)));
  std::cout << s21_map << '\n';

  std::cout << "insert 2.5\n";
  s21_map.Insert(std::make_pair(2.5, Item(5, 'A')));
  std::cout << s21_map << '\n';
  std::cout << "insert 4.5\n";
  s21_map.Insert(std::make_pair(4.5, Item(5, 'B')));
  std::cout << s21_map << '\n';
  std::cout << "insert 6.5\n";
  s21_map.Insert(std::make_pair(6.5, Item(5, 'C')));
  std::cout << s21_map << '\n';
  std::cout << "insert 7.5\n";
  s21_map.Insert(std::make_pair(7.5, Item(5, 'D')));
  std::cout << s21_map << '\n';

  EXPECT_TRUE(minimalHeightAVL(s21_map.Size(), s21_map.Height()));
}

TEST(Map, T2LeftRightCase) {
  // return;
  s21::Map<double, Item> s21_map;

  std::cout << "insert 5.0\n";
  s21_map.Insert(std::make_pair(5.0, Item(5)));
  std::cout << s21_map << "\n\n";
  std::cout << "insert 3.0\n";
  s21_map.Insert(std::make_pair(3.0, Item(5)));
  std::cout << s21_map << "\n\n";
  std::cout << "insert 4.0\n";
  s21_map.Insert(std::make_pair(4.0, Item(5)));
  std::cout << s21_map << "\n\n";

  std::cout << "insert 5.5\n";
  s21_map.Insert(std::make_pair(5.5, Item(5, 'A')));
  std::cout << s21_map << "\n\n";
  std::cout << "insert 4.5\n";
  s21_map.Insert(std::make_pair(4.5, Item(5, 'D')));
  std::cout << s21_map << "\n\n";
  std::cout << "insert 3.5\n";
  s21_map.Insert(std::make_pair(3.5, Item(5, 'C')));
  std::cout << s21_map << "\n\n";
  std::cout << "insert 2.5\n";
  s21_map.Insert(std::make_pair(2.5, Item(5, 'B')));
  std::cout << s21_map << "\n\n";

  EXPECT_TRUE(minimalHeightAVL(s21_map.Size(), s21_map.Height()));
}

TEST(Map, T3RightLeftCase) {
  // return;
  s21::Map<double, Item> s21_map;

  std::cout << "insert 3.0\n";
  s21_map.Insert(std::make_pair(3.0, Item(5)));
  std::cout << s21_map << "\n\n";
  std::cout << "insert 5.0\n";
  s21_map.Insert(std::make_pair(5.0, Item(5)));
  std::cout << s21_map << "\n\n";
  std::cout << "insert 4.0\n";
  s21_map.Insert(std::make_pair(4.0, Item(5)));
  std::cout << s21_map << "\n\n";

  std::cout << "insert 2.5\n";
  s21_map.Insert(std::make_pair(2.5, Item(5, 'A')));
  std::cout << s21_map << "\n\n";
  std::cout << "insert 3.5\n";
  s21_map.Insert(std::make_pair(3.5, Item(5, 'D')));
  std::cout << s21_map << "\n\n";
  std::cout << "insert 4.5\n";
  s21_map.Insert(std::make_pair(4.5, Item(5, 'C')));
  std::cout << s21_map << "\n\n";
  std::cout << "insert 5.5\n";
  s21_map.Insert(std::make_pair(5.5, Item(5, 'B')));
  std::cout << s21_map << "\n\n";

  EXPECT_TRUE(minimalHeightAVL(s21_map.Size(), s21_map.Height()));
}

TEST(Map, T4RandomCase) {
  // return;
  s21::Map<int, Item> s21_map;

  s21_map.Insert(std::make_pair(3, Item(3)));
  s21_map.Insert(std::make_pair(5, Item(5)));
  s21_map.Insert(std::make_pair(5, Item(5)));
  s21_map.Insert(std::make_pair(4, Item(4)));

  s21_map.Insert(std::make_pair(14, Item(14)));
  s21_map.Insert(std::make_pair(11, Item(11)));
  s21_map.Insert(std::make_pair(7, Item(7)));
  s21_map.Insert(std::make_pair(8, Item(8)));
  s21_map.Insert(std::make_pair(-8, Item(-8)));
  s21_map.Insert(std::make_pair(7, Item(7)));
  s21_map.Insert(std::make_pair(-18, Item(-18)));
  s21_map.Insert(std::make_pair(6, Item(6)));
  s21_map.Insert(std::make_pair(3, Item(3)));
  s21_map.Insert(std::make_pair(29, Item(29)));
  s21_map.Insert(std::make_pair(30, Item(30)));
  s21_map.Insert(std::make_pair(31, Item(31)));
  s21_map.Insert(std::make_pair(34, Item(34)));
  s21_map.Insert(std::make_pair(37, Item(37)));

  std::cout << s21_map << "\n\n";

  EXPECT_TRUE(minimalHeightAVL(s21_map.Size(), s21_map.Height()));
}

TEST(Map, T5SortedCase) {
  // return;
  s21::Map<int, Item> s21_map;

  for (int i = -10; i < 10; ++i) s21_map.Insert(std::make_pair(i, Item(i)));

  std::cout << s21_map << "\n\n";
  std::cout << "Map: size " << s21_map.Size() << ", height " << s21_map.Height()
            << "\n";

  EXPECT_TRUE(minimalHeightAVL(s21_map.Size(), s21_map.Height()));
}

TEST(Map, T6SortedCase) {
  // return;
  s21::Map<int, Item> s21_map;

  for (int i = -100; i < 100; ++i) s21_map.Insert(std::make_pair(i, Item(i)));

  // std::cout << s21_map << "\n\n";
  std::cout << "Map: size " << s21_map.Size() << ", height " << s21_map.Height()
            << "\n";

  EXPECT_TRUE(minimalHeightAVL(s21_map.Size(), s21_map.Height()));
}

TEST(Map, T7SortedCase) {
  // return;
  s21::Map<int, Item> s21_map;

  for (int i = -100; i < 100; ++i) s21_map.Insert(std::make_pair(-i, Item(i)));

  // std::cout << s21_map << "\n\n";
  std::cout << "Map: size " << s21_map.Size() << ", height " << s21_map.Height()
            << "\n";

  EXPECT_TRUE(minimalHeightAVL(s21_map.Size(), s21_map.Height()));
}

TEST(Map, T8SortedCase) {
  // return;
  s21::Map<int, Item> s21_map;

  for (int i = -1000; i < 1000; ++i) s21_map.Insert(std::make_pair(i, Item(i)));

  // std::cout << s21_map << "\n\n";
  std::cout << "Map: size " << s21_map.Size() << ", height " << s21_map.Height()
            << "\n";

  EXPECT_TRUE(minimalHeightAVL(s21_map.Size(), s21_map.Height()));
}

TEST(Map, T9SortedCase) {
  // return;
  s21::Map<int, Item> s21_map;

  for (int i = -2000; i < 2000; ++i) {
    // std::cout << "insert " << -i << '\n';
    s21_map.Insert(std::make_pair(-i, Item(-i)));
    // std::cout << "Map: size " << s21_map.Size() << ", height " <<
    // s21_map.Height() << "\n"; std::cout << s21_map << "\n\n";

    // // s21_map.Insert(std::make_pair(i / 2, Item(i / 2)));

    // std::cout << "insert " << i << '\n';
    s21_map.Insert(std::make_pair(i, Item(i)));
    // std::cout << "Map: size " << s21_map.Size() << ", height " <<
    // s21_map.Height() << "\n"; std::cout << s21_map << "\n\n";
  }

  std::cout << "Map: size " << s21_map.Size() << ", height " << s21_map.Height()
            << "\n";

  EXPECT_TRUE(minimalHeightAVL(s21_map.Size(), s21_map.Height()));
}

TEST(Map, T10SortedMixedCase) {
  // return;
  s21::Map<int, Item> s21_map;

  for (int i = -2000; i < 2000; ++i) {
    // std::cout << "insert " << -i << '\n';
    s21_map.Insert(std::make_pair(-i, Item(-i)));
    // std::cout << "Map: size " << s21_map.Size() << ", height " <<
    // s21_map.Height() << "\n"; std::cout << s21_map << "\n\n";

    s21_map.Insert(std::make_pair(i * i / 2, Item(i / 2)));

    // std::cout << "insert " << i << '\n';
    s21_map.Insert(std::make_pair(i, Item(i)));
    // std::cout << "Map: size " << s21_map.Size() << ", height " <<
    // s21_map.Height() << "\n"; std::cout << s21_map << "\n\n";
  }

  std::cout << "Map: size " << s21_map.Size() << ", height " << s21_map.Height()
            << "\n";

  EXPECT_TRUE(minimalHeightAVL(s21_map.Size(), s21_map.Height()));
}

TEST(Map, T11SortedMixedCase) {
  s21::Map<int, Item> s21_map;
  std::map<int, Item> map;

  for (int i = -200; i < 200; ++i) {
    // std::cout << "insert " << -i << '\n';
    s21_map.Insert(std::make_pair(-i, Item(-i)));
    map.insert(std::make_pair(-i, Item(-i)));
    // std::cout << "Map: size " << s21_map.Size() << ", height " <<
    // s21_map.Height() << "\n"; std::cout << s21_map << "\n\n";

    s21_map.Insert(std::make_pair(i * i / 2, Item(i / 2)));
    map.insert(std::make_pair(i * i / 2, Item(i / 2)));

    // std::cout << "insert " << i << '\n';
    s21_map.Insert(std::make_pair(i, Item(i)));
    map.insert(std::make_pair(i, Item(i)));
    // std::cout << "Map: size " << s21_map.Size() << ", height " <<
    // s21_map.Height() << "\n"; std::cout << s21_map << "\n\n";
  }

  std::cout << "Map: size " << s21_map.Size() << ", height " << s21_map.Height()
            << "\n";

  EXPECT_TRUE(minimalHeightAVL(s21_map.Size(), s21_map.Height()));
  EXPECT_EQ(s21_map, map);
}

TEST(Map, T12SortedMixedCase) {
  s21::Map<int, Item> s21_map;
  std::map<int, Item> map;

  for (int i = -20000; i < 20000; ++i) {
    s21_map.Insert(std::make_pair(-i, Item(-i)));
    map.insert(std::make_pair(-i, Item(-i)));

    s21_map.Insert(std::make_pair(i * i / 2, Item(i * i / 2)));
    map.insert(std::make_pair(i * i / 2, Item(i * i / 2)));

    s21_map.Insert(std::make_pair(-i * i * i / 2, Item(-i * i * i / 2)));
    map.insert(std::make_pair(-i * i * i / 2, Item(-i * i * i / 2)));

    s21_map.Insert(std::make_pair(i, Item(i)));
    map.insert(std::make_pair(i, Item(i)));
  }

  std::cout << "Map: size " << s21_map.Size() << ", height " << s21_map.Height()
            << "\n";

  EXPECT_TRUE(minimalHeightAVL(s21_map.Size(), s21_map.Height()));
  EXPECT_EQ(s21_map, map);
}

}  // namespace

// GCOVR_EXCL_STOP
