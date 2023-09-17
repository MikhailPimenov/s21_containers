#ifndef _TESTS_QUEUE_HELPERS_H_
#define _TESTS_QUEUE_HELPERS_H_

#include <queue>

#include "../s21_queue.h"

// GCOVR_EXCL_START

template <typename Type, typename s21_Container, typename Container>
bool operator==(s21::Queue<Type, s21_Container> s21_queue,
                std::queue<Type, Container> queue) {
  if (s21_queue.Size() != queue.size()) return false;

  while (!s21_queue.Empty()) {
    if (s21_queue.Front() != queue.front()) return false;

    s21_queue.Pop();
    queue.pop();
  }
  return true;
}

template <typename Type, typename s21_Container, typename Container>
bool operator==(std::queue<Type, Container> queue,
                s21::Queue<Type, s21_Container> s21_queue) {
  return s21_queue == queue;
}

template <typename Type, typename s21_Container>
bool operator==(s21::Queue<Type, s21_Container> left,
                s21::Queue<Type, s21_Container> right) {
  if (left.Size() != right.Size()) return false;

  while (!left.Empty()) {
    if (left.Front() != left.Front()) return false;

    left.Pop();
    right.Pop();
  }
  return true;
}

// GCOVR_EXCL_STOP

#endif  //  _TESTS_QUEUE_HELPERS_H_