#include <gtest/gtest.h>

#include <deque>
#include <list>
#include <queue>
#include <vector>

#include "../../s21_queue.h"
#include "../item.h"
#include "../queue_helpers.h"

// GCOVR_EXCL_START

namespace {

TEST(QueueMethods, T0Back) {
  s21::List<Item> s21_list{Item(11), Item(22), Item(33)};
  s21::Queue<Item> s21_queue(s21_list);

  std::list<Item> list{Item(11), Item(22), Item(33)};
  std::queue<Item, std::list<Item>> queue(list);

  EXPECT_TRUE(s21_queue.Back() == queue.back());
}

TEST(QueueMethods, T1Back) {
  s21::List<Item> s21_list{Item(11), Item(22), Item(33)};
  const s21::Queue<Item> s21_queue(s21_list);

  std::list<Item> list{Item(11), Item(22), Item(33)};
  const std::queue<Item, std::list<Item>> queue(list);

  EXPECT_TRUE(s21_queue.Back() == queue.back());
}

TEST(QueueMethods, T2Empty) {
  s21::List<Item> s21_list{Item(11), Item(22), Item(33)};
  const s21::Queue<Item> s21_queue(s21_list);

  std::list<Item> list{Item(11), Item(22), Item(33)};
  const std::queue<Item, std::list<Item>> queue(list);

  EXPECT_TRUE(s21_queue.Empty() == queue.empty());
  EXPECT_FALSE(s21_queue.Empty());
}

TEST(QueueMethods, T3Empty) {
  s21::Queue<Item> s21_queue;
  std::queue<Item, std::list<Item>> queue;

  EXPECT_TRUE(s21_queue.Empty() == queue.empty());
  EXPECT_TRUE(s21_queue.Empty());
}

TEST(QueueMethods, T4Size) {
  s21::List<Item> s21_list{Item(11), Item(22), Item(33)};
  const s21::Queue<Item> s21_queue(s21_list);

  std::list<Item> list{Item(11), Item(22), Item(33)};
  const std::queue<Item, std::list<Item>> queue(list);

  EXPECT_TRUE(s21_queue.Size() == queue.size());
  EXPECT_EQ(s21_queue.Size(), 3ull);
}

TEST(QueueMethods, T5Empty) {
  s21::Queue<Item> s21_queue;
  std::queue<Item, std::list<Item>> queue;

  EXPECT_TRUE(s21_queue.Size() == queue.size());
  EXPECT_EQ(s21_queue.Size(), 0ull);
}

TEST(QueueMethods, T6Push) {
  const Item item1(1111);
  const Item item2(2222, 'b');
  const Item item3(3333, 'c', 0.3333);

  s21::Queue<Item> s21_queue;
  s21_queue.Push(item1);
  s21_queue.Push(item2);
  s21_queue.Push(item3);

  std::queue<Item, std::list<Item>> queue;
  queue.push(item1);
  queue.push(item2);
  queue.push(item3);

  EXPECT_EQ(s21_queue, queue);
}

TEST(QueueMethods, T7Push) {
  std::vector<Item> items1{Item(11), Item(22, 'b', 0.22), Item(33, 'c', 0.33)};
  std::vector<Item> items2{Item(55), Item(66, 'f', 0.666),
                           Item(77, 'g', 0.7777)};

  std::vector<Item> items11(items1);
  std::vector<Item> items22(items2);

  s21::Queue<std::vector<Item>> s21_queue;
  s21_queue.Push(std::move(items1));
  s21_queue.Push(std::move(items2));

  std::queue<std::vector<Item>> queue;
  queue.push(std::move(items11));
  queue.push(std::move(items22));

  EXPECT_EQ(s21_queue, queue);
  EXPECT_TRUE(items1.empty());
  EXPECT_TRUE(items2.empty());
}

TEST(QueueMethods, T8Emplace) {
  s21::Queue<Item> s21_queue;
  s21_queue.Emplace(1111);
  s21_queue.Emplace(2222, 'b');
  s21_queue.Emplace(3333, 'c', 0.3333);

  std::queue<Item, std::list<Item>> queue;
  queue.emplace(1111);
  queue.emplace(2222, 'b');
  queue.emplace(3333, 'c', 0.3333);

  EXPECT_EQ(s21_queue, queue);
}

TEST(QueueMethods, T9Pop) {
  s21::List<Item> s21_list{Item(11), Item(22), Item(33)};
  s21::Queue<Item> s21_queue(s21_list);

  std::list<Item> list{Item(11), Item(22), Item(33)};
  std::queue<Item, std::list<Item>> queue(list);

  s21_queue.Pop();
  queue.pop();
  EXPECT_EQ(s21_queue, queue);

  s21_queue.Pop();
  queue.pop();
  EXPECT_EQ(s21_queue, queue);

  s21_queue.Pop();
  queue.pop();
  EXPECT_EQ(s21_queue, queue);
}

TEST(QueueMethods, T10Swap) {
  s21::List<Item> s21_list1{Item(11), Item(22), Item(33)};
  s21::Queue<Item> s21_queue1(s21_list1);
  const auto s21_copy1(s21_queue1);

  s21::List<Item> s21_list2{Item(66), Item(77), Item(88), Item(99)};
  s21::Queue<Item> s21_queue2(s21_list2);
  const auto s21_copy2(s21_queue2);

  s21_queue1.Swap(s21_queue2);

  EXPECT_EQ(s21_queue1, s21_copy2);
  EXPECT_EQ(s21_queue2, s21_copy1);
}

TEST(QueueMethods, T11Front) {
  s21::List<Item> s21_list{Item(11), Item(22), Item(33)};
  s21::Queue<Item> s21_queue(s21_list);

  std::list<Item> list{Item(11), Item(22), Item(33)};
  std::queue<Item, std::list<Item>> queue(list);

  EXPECT_TRUE(s21_queue.Front() == queue.front());
}

TEST(QueueMethods, T12Front) {
  s21::List<Item> s21_list{Item(11), Item(22), Item(33)};
  const s21::Queue<Item> s21_queue(s21_list);

  std::list<Item> list{Item(11), Item(22), Item(33)};
  const std::queue<Item, std::list<Item>> queue(list);

  EXPECT_TRUE(s21_queue.Front() == queue.front());
}

}  // namespace
   // GCOVR_EXCL_STOP