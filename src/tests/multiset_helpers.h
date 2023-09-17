#ifndef _TESTS_MULTISET_HELPERS_H_
#define _TESTS_MULTISET_HELPERS_H_

#include <iostream>
#include <set>

#include "../s21_multiset.h"

// GCOVR_EXCL_START

template <typename Type, typename Comparator>
bool operator==(const s21::MultiSet<Type, Comparator>& s21_multiset,
                const std::multiset<Type, Comparator>& multiset) {
  if (s21_multiset.Size() != multiset.size()) return false;

  auto s21_it = s21_multiset.cbegin();
  auto it = multiset.cbegin();

  while (s21_it != s21_multiset.cend()) {
    if (*s21_it != *it) return false;

    ++s21_it;
    ++it;
  }

  return true;
}

template <typename Type, typename Comparator>
std::ostream& operator<<(std::ostream& out,
                         const s21::MultiSet<Type, Comparator>& s21_map) {
  out << "MultiSet " << s21_map.Size() << ' ' << s21_map.Height() << "\n";
  for (typename s21::MultiSet<Type, Comparator>::const_iterator it =
           s21_map.cbegin();
       it != s21_map.cend(); ++it)
    out << "{" << (*it) << "} ";

  return out;
}

// GCOVR_EXCL_STOP

#endif  //  _TESTS_MULTISET_HELPERS_H_
