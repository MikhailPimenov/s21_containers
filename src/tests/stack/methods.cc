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

TEST(StackMethods, T0Top) {
  s21::List<Item> s21_list{Item(11), Item(22), Item(33)};
  s21::Stack<Item> s21_stack(s21_list);

  std::list<Item> list{Item(11), Item(22), Item(33)};
  std::stack<Item, std::list<Item>> stack(list);

  EXPECT_TRUE(s21_stack.Top() == stack.top());
}

TEST(StackMethods, T1Top) {
  s21::List<Item> s21_list{Item(11), Item(22), Item(33)};
  const s21::Stack<Item> s21_stack(s21_list);

  std::list<Item> list{Item(11), Item(22), Item(33)};
  const std::stack<Item, std::list<Item>> stack(list);

  EXPECT_TRUE(s21_stack.Top() == stack.top());
}

TEST(StackMethods, T2Empty) {
  s21::List<Item> s21_list{Item(11), Item(22), Item(33)};
  const s21::Stack<Item> s21_stack(s21_list);

  std::list<Item> list{Item(11), Item(22), Item(33)};
  const std::stack<Item, std::list<Item>> stack(list);

  EXPECT_TRUE(s21_stack.Empty() == stack.empty());
  EXPECT_FALSE(s21_stack.Empty());
}

TEST(StackMethods, T3Empty) {
  s21::Stack<Item> s21_stack;
  std::stack<Item, std::list<Item>> stack;

  EXPECT_TRUE(s21_stack.Empty() == stack.empty());
  EXPECT_TRUE(s21_stack.Empty());
}

TEST(StackMethods, T4Size) {
  s21::List<Item> s21_list{Item(11), Item(22), Item(33)};
  const s21::Stack<Item> s21_stack(s21_list);

  std::list<Item> list{Item(11), Item(22), Item(33)};
  const std::stack<Item, std::list<Item>> stack(list);

  EXPECT_TRUE(s21_stack.Size() == stack.size());
  EXPECT_EQ(s21_stack.Size(), 3ull);
}

TEST(StackMethods, T5Empty) {
  s21::Stack<Item> s21_stack;
  std::stack<Item, std::list<Item>> stack;

  EXPECT_TRUE(s21_stack.Size() == stack.size());
  EXPECT_EQ(s21_stack.Size(), 0ull);
}

TEST(StackMethods, T6Push) {
  const Item item1(1111);
  const Item item2(2222, 'b');
  const Item item3(3333, 'c', 0.3333);

  s21::Stack<Item> s21_stack;
  s21_stack.Push(item1);
  s21_stack.Push(item2);
  s21_stack.Push(item3);

  std::stack<Item, std::list<Item>> stack;
  stack.push(item1);
  stack.push(item2);
  stack.push(item3);

  EXPECT_EQ(s21_stack, stack);
}

TEST(StackMethods, T7Push) {
  std::vector<Item> items1{Item(11), Item(22, 'b', 0.22), Item(33, 'c', 0.33)};
  std::vector<Item> items2{Item(55), Item(66, 'f', 0.666),
                           Item(77, 'g', 0.7777)};

  std::vector<Item> items11(items1);
  std::vector<Item> items22(items2);

  s21::Stack<std::vector<Item>> s21_stack;
  s21_stack.Push(std::move(items1));
  s21_stack.Push(std::move(items2));

  std::stack<std::vector<Item>> stack;
  stack.push(std::move(items11));
  stack.push(std::move(items22));

  EXPECT_EQ(s21_stack, stack);
  EXPECT_TRUE(items1.empty());
  EXPECT_TRUE(items2.empty());
}

TEST(StackMethods, T8Emplace) {
  s21::Stack<Item> s21_stack;
  s21_stack.Emplace(1111);
  s21_stack.Emplace(2222, 'b');
  s21_stack.Emplace(3333, 'c', 0.3333);

  std::stack<Item, std::list<Item>> stack;
  stack.emplace(1111);
  stack.emplace(2222, 'b');
  stack.emplace(3333, 'c', 0.3333);

  EXPECT_EQ(s21_stack, stack);
}

TEST(StackMethods, T9Pop) {
  s21::List<Item> s21_list{Item(11), Item(22), Item(33)};
  s21::Stack<Item> s21_stack(s21_list);

  std::list<Item> list{Item(11), Item(22), Item(33)};
  std::stack<Item, std::list<Item>> stack(list);

  s21_stack.Pop();
  stack.pop();
  EXPECT_EQ(s21_stack, stack);

  s21_stack.Pop();
  stack.pop();
  EXPECT_EQ(s21_stack, stack);

  s21_stack.Pop();
  stack.pop();
  EXPECT_EQ(s21_stack, stack);
}

TEST(StackMethods, T10Swap) {
  s21::List<Item> s21_list1{Item(11), Item(22), Item(33)};
  s21::Stack<Item> s21_stack1(s21_list1);
  const auto s21_copy1(s21_stack1);

  s21::List<Item> s21_list2{Item(66), Item(77), Item(88), Item(99)};
  s21::Stack<Item> s21_stack2(s21_list2);
  const auto s21_copy2(s21_stack2);

  s21_stack1.Swap(s21_stack2);

  EXPECT_EQ(s21_stack1, s21_copy2);
  EXPECT_EQ(s21_stack2, s21_copy1);
}

}  // namespace
   // GCOVR_EXCL_STOP