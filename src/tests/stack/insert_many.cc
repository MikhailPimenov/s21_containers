#include <gtest/gtest.h>

#include "../../s21_stack.h"
#include "../item.h"
#include "../stack_helpers.h"

//  GCOVR_EXCL_START

namespace {
TEST(Stack, T0InsertManyFront) {
  s21::List<Item> s21_list{Item(11), Item(22), Item(33)};
  s21::Stack<Item> s21_stack(s21_list);

  s21::List<Item> s21_list2{
      Item(11), Item(22), Item(33), Item(777), Item(-33),
  };
  s21::Stack<Item> s21_stack_expected(s21_list2);

  s21_stack.Insert_many_front(Item(777), Item(-33));

  EXPECT_EQ(s21_stack, s21_stack_expected);
}

TEST(Queue, T1InsertManyEmptyFront) {
  s21::List<Item> s21_stack;

  s21::List<Item> s21_stack_expected{
      Item(11), Item(22), Item(33),  Item(44),
      Item(55), Item(66), Item(666), Item(777),
  };

  s21_stack.Insert_many_front(Item(11), Item(22), Item(33), Item(44), Item(55),
                              Item(66), Item(666), Item(777));

  EXPECT_EQ(s21_stack, s21_stack_expected);
}

}  // namespace

//  GCOVR_EXCL_STOP