#include "../item.h"

#include <gtest/gtest.h>

#include <deque>
#include <list>
#include <stack>
#include <vector>

#include "../../s21_vector.h"
#include "../vector_helpers.h"

// GCOVR_EXCL_START

namespace {

TEST(ItemTest, T0DefaultConstructor) {
  Item i;
  Item copy;

  EXPECT_EQ(i, copy);
}

TEST(ItemTest, T1Constructor) {
  Item i(666, 'h', 0.666);
  Item copy(i);

  EXPECT_EQ(i, copy);
}

TEST(ItemTest, T2MoveConstructor) {
  Item i(666, 'h', 0.666);
  const Item i2(666, 'h', 0.666);
  Item copy(std::move(i));

  EXPECT_EQ(i2, copy);
  EXPECT_TRUE(i.empty());
}

TEST(ItemTest, T0CopyOperator) {
  const Item i(666, 'h', 0.666);
  Item copy(777, 'g', 0.777);
  copy = i;

  EXPECT_EQ(i, copy);
}

TEST(ItemTest, T1MoveOperator) {
  Item i(666, 'h', 0.666);
  const Item i2(i);
  Item copy(777, 'g', 0.777);
  copy = std::move(i);

  EXPECT_EQ(i2, copy);
  EXPECT_TRUE(i.empty());
}

}  // namespace

// GCOVR_EXCL_STOP