#ifndef _TESTS_SET_HELPERS_H_
#define _TESTS_SET_HELPERS_H_

#include <iostream>
#include <set>

#include "../s21_set.h"

// GCOVR_EXCL_START

template <typename Type, typename Comparator>
bool operator==(const s21::Set<Type, Comparator>& s21_set,
                const std::set<Type, Comparator>& set) {
  if (s21_set.Size() != set.size()) return false;

  auto s21_it = s21_set.cbegin();
  auto it = set.cbegin();

  while (s21_it != s21_set.cend()) {
    if (*s21_it != *it) return false;

    ++s21_it;
    ++it;
  }

  return true;
}

// GCOVR_EXCL_STOP

#endif  //  _TESTS_SET_HELPERS_H_
