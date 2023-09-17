#ifndef _TESTS_VECTOR_HELPERS_H_
#define _TESTS_VECTOR_HELPERS_H_

#include <iostream>
#include <vector>

#include "../s21_vector.h"

// GCOVR_EXCL_START

template <typename Type>
bool operator==(const s21::Vector<Type>& s21_vector,
                const std::vector<Type>& vector) {
  if (s21_vector.Size() != vector.size()) return false;

  auto s21_it = s21_vector.cbegin();
  auto it = vector.cbegin();
  while (s21_it != s21_vector.cend()) {
    if (*s21_it != *it) return false;
    ++s21_it;
    ++it;
  }

  return true;
}

template <typename Type>
bool operator==(std::vector<Type> vector, s21::Vector<Type> s21_vector) {
  return s21_vector == vector;
}

template <typename Type>
bool operator!=(const s21::Vector<Type>& s21_vector,
                const std::vector<Type>& vector) {
  return !(s21_vector == vector);
}

template <typename Type>
bool operator!=(std::vector<Type> vector, s21::Vector<Type> s21_vector) {
  return !(s21_vector == vector);
}

template <typename Type>
std::ostream& operator<<(std::ostream& out, const s21::Vector<Type>& object) {
  out << "Vector: ";
  for (const auto& element : object) out << element << ' ';
  return out;
}

// GCOVR_EXCL_STOP

#endif  //  _TESTS_VECTOR_HELPERS_H_