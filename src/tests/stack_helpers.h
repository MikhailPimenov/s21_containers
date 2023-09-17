#ifndef _TESTS_STACK_HELPERS_H_
#define _TESTS_STACK_HELPERS_H_

#include <iostream>
#include <stack>

#include "../s21_stack.h"

// GCOVR_EXCL_START

template <typename Type, typename s21_Container, typename Container>
bool operator==(s21::Stack<Type, s21_Container> s21_stack,
                std::stack<Type, Container> stack) {
  if (s21_stack.Size() != stack.size()) return false;

  while (!s21_stack.Empty()) {
    if (s21_stack.Top() != stack.top()) return false;

    s21_stack.Pop();
    stack.pop();
  }
  return true;
}

template <typename Type, typename s21_Container, typename Container>
bool operator==(std::stack<Type, Container> stack,
                s21::Stack<Type, s21_Container> s21_stack) {
  return s21_stack == stack;
}

template <typename Type, typename s21_Container>
bool operator==(s21::Stack<Type, s21_Container> left,
                s21::Stack<Type, s21_Container> right) {
  if (left.Size() != right.Size()) return false;

  while (!left.Empty()) {
    if (left.Top() != left.Top()) return false;

    left.Pop();
    right.Pop();
  }
  return true;
}

// GCOVR_EXCL_STOP

#endif  //  _TESTS_STACK_HELPERS_H_