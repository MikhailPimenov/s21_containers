#ifndef _TESTS_VECTOR_HELPERS_H_
#define _TESTS_VECTOR_HELPERS_H_

#include <array>
#include <iostream>

#include "../s21_array.h"

// GCOVR_EXCL_START

template <typename Type, std::size_t N>
bool operator==(const s21::Array<Type, N>& s21_array,
                const std::array<Type, N>& array) {
  if (s21_array.Size() != array.size()) return false;

  auto s21_it = s21_array.cbegin();
  auto it = array.cbegin();
  while (s21_it != s21_array.cend()) {
    if (*s21_it != *it) return false;
    ++s21_it;
    ++it;
  }

  return true;
}

template <typename Type, std::size_t N>
bool operator==(std::array<Type, N> array, s21::Array<Type, N> s21_array) {
  return s21_array == array;
}

template <typename Type, std::size_t N>
bool operator!=(const s21::Array<Type, N>& s21_array,
                const std::array<Type, N>& array) {
  return !(s21_array == array);
}

template <typename Type, std::size_t N>
bool operator!=(std::array<Type, N> array, s21::Array<Type, N> s21_array) {
  return !(s21_array == array);
}

template <typename Type, std::size_t N>
std::ostream& operator<<(std::ostream& out, const s21::Array<Type, N>& object) {
  out << "Array: ";
  for (const auto& element : object) out << element << ' ';
  return out;
}

// GCOVR_EXCL_STOP

#endif  //  _TESTS_VECTOR_HELPERS_H_