#include <gtest/gtest.h>

#include <deque>
#include <list>
#include <stack>
#include <vector>

#include "../../s21_stack.h"
#include "../item.h"
#include "../stack_helpers.h"

// GCOVR_EXCL_START

namespace {

TEST(Stack, T0DefaultConstructor) {
  s21::Stack<Item> s21_stack;
  std::stack<Item> stack;

  EXPECT_TRUE(s21_stack == stack);
}

TEST(Stack, T1ConstructorContainer) {
  s21::List<Item> s21_list{Item(11), Item(22), Item(33)};
  s21::Stack<Item> s21_stack(s21_list);

  std::list<Item> list{Item(11), Item(22), Item(33)};
  std::stack<Item, std::list<Item>> stack(list);

  EXPECT_TRUE(s21_stack == stack);
}

TEST(Stack, T2ConstructorContainer) {
  s21::List<Item> s21_list;
  s21::Stack<Item> s21_stack(s21_list);

  std::list<Item> list;
  std::stack<Item, std::list<Item>> stack(list);

  EXPECT_TRUE(s21_stack == stack);
}

TEST(Stack, T3ConstructorContainerMove) {
  s21::List<Item> s21_list{Item(11), Item(22), Item(33)};
  s21::Stack<Item> s21_stack(std::move(s21_list));

  std::list<Item> list{Item(11), Item(22), Item(33)};
  std::stack<Item, std::list<Item>> stack(std::move(list));

  EXPECT_TRUE(s21_stack == stack);
  EXPECT_TRUE(s21_list.Empty());
  EXPECT_TRUE(list.empty());
}

TEST(Stack, T4ConstructorCopy) {
  s21::List<Item> s21_list{Item(11), Item(22), Item(33)};
  s21::Stack<Item> s21_source(std::move(s21_list));
  s21::Stack<Item> s21_destination(s21_source);

  std::list<Item> list{Item(11), Item(22), Item(33)};
  std::stack<Item, std::list<Item>> source(std::move(list));
  std::stack<Item, std::list<Item>> destination(source);

  EXPECT_TRUE(s21_source == source);
  EXPECT_TRUE(s21_destination == destination);
}

TEST(Stack, T5ConstructorMove) {
  s21::List<Item> s21_list{Item(11), Item(22), Item(33)};
  s21::Stack<Item> s21_source(std::move(s21_list));
  s21::Stack<Item> s21_copy(s21_source);
  s21::Stack<Item> s21_destination(std::move(s21_source));

  std::list<Item> list{Item(11), Item(22), Item(33)};
  std::stack<Item, std::list<Item>> source(std::move(list));
  std::stack<Item, std::list<Item>> destination(std::move(source));

  EXPECT_TRUE(s21_source.Empty());
  EXPECT_TRUE(s21_destination == s21_copy);
  EXPECT_TRUE(s21_destination == destination);
}

TEST(Stack, T6ConstructorIterator) {
  std::list<Item> source{Item(111), Item(222), Item(333), Item(444)};
  s21::Stack<Item> s21_stack(source.cbegin(), source.cend());

  std::stack<Item, std::list<Item>> stack(source);
  EXPECT_TRUE(s21_stack == stack);
}

TEST(Stack, T7ConstructorIterator) {
  std::vector<Item> source{Item(111), Item(222), Item(333), Item(444)};
  s21::Stack<Item> s21_stack(source.cbegin(), source.cend());

  std::stack<Item, std::vector<Item>> stack(source);
  EXPECT_TRUE(s21_stack == stack);
}

TEST(Stack, T8ConstructorIterator) {
  std::deque<Item> source{Item(111), Item(222), Item(333), Item(444)};
  s21::Stack<Item> s21_stack(source.cbegin(), source.cend());

  std::stack<Item> stack(source);
  EXPECT_TRUE(s21_stack == stack);
}

}  // namespace
   // GCOVR_EXCL_STOP