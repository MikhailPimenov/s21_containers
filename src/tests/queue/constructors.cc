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

TEST(Queue, T0DefaultConstructor) {
  s21::Queue<Item> s21_queue;
  std::queue<Item> queue;

  EXPECT_TRUE(s21_queue == queue);
}

TEST(Queue, T1ConstructorContainer) {
  s21::List<Item> s21_list{Item(11), Item(22), Item(33)};
  s21::Queue<Item> s21_queue(s21_list);

  std::list<Item> list{Item(11), Item(22), Item(33)};
  std::queue<Item, std::list<Item>> queue(list);

  EXPECT_TRUE(s21_queue == queue);
}

TEST(Queue, T2ConstructorContainer) {
  s21::List<Item> s21_list;
  s21::Queue<Item> s21_queue(s21_list);

  std::list<Item> list;
  std::queue<Item, std::list<Item>> queue(list);

  EXPECT_TRUE(s21_queue == queue);
}

TEST(Queue, T3ConstructorContainerMove) {
  s21::List<Item> s21_list{Item(11), Item(22), Item(33)};
  s21::Queue<Item> s21_queue(std::move(s21_list));

  std::list<Item> list{Item(11), Item(22), Item(33)};
  std::queue<Item, std::list<Item>> queue(std::move(list));

  EXPECT_TRUE(s21_queue == queue);
  EXPECT_TRUE(s21_list.Empty());
  EXPECT_TRUE(list.empty());
}

TEST(Queue, T4ConstructorCopy) {
  s21::List<Item> s21_list{Item(11), Item(22), Item(33)};
  s21::Queue<Item> s21_source(std::move(s21_list));
  s21::Queue<Item> s21_destination(s21_source);

  std::list<Item> list{Item(11), Item(22), Item(33)};
  std::queue<Item, std::list<Item>> source(std::move(list));
  std::queue<Item, std::list<Item>> destination(source);

  EXPECT_TRUE(s21_source == source);
  EXPECT_TRUE(s21_destination == destination);
}

TEST(Queue, T5ConstructorMove) {
  s21::List<Item> s21_list{Item(11), Item(22), Item(33)};
  s21::Queue<Item> s21_source(std::move(s21_list));
  s21::Queue<Item> s21_copy(s21_source);
  s21::Queue<Item> s21_destination(std::move(s21_source));

  std::list<Item> list{Item(11), Item(22), Item(33)};
  std::queue<Item, std::list<Item>> source(std::move(list));
  std::queue<Item, std::list<Item>> destination(std::move(source));

  EXPECT_TRUE(s21_source.Empty());
  EXPECT_TRUE(s21_destination == s21_copy);
  EXPECT_TRUE(s21_destination == destination);
}

TEST(Queue, T6ConstructorIterator) {
  std::list<Item> source{Item(111), Item(222), Item(333), Item(444)};
  s21::Queue<Item> s21_queue(source.cbegin(), source.cend());

  std::queue<Item, std::list<Item>> queue(source);
  EXPECT_TRUE(s21_queue == queue);
}

// TEST(Queue, T7ConstructorIterator)
// {
//     std::vector<Item> source { Item(111), Item(222), Item(333), Item(444) };
//     s21::Queue<Item> s21_queue(source.cbegin(), source.cend());

//     std::queue<Item, std::vector<Item>> queue(source);
//     EXPECT_TRUE(s21_queue == queue);
// }

TEST(Queue, T8ConstructorIterator) {
  std::deque<Item> source{Item(111), Item(222), Item(333), Item(444)};
  s21::Queue<Item> s21_queue(source.cbegin(), source.cend());

  std::queue<Item> queue(source);
  EXPECT_TRUE(s21_queue == queue);
}

}  // namespace
   // GCOVR_EXCL_STOP