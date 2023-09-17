#ifndef _TESTS_MULTIMAP_HELPERS_H_
#define _TESTS_MULTIMAP_HELPERS_H_

#include <cmath>
#include <iostream>
#include <map>

#include "../s21_map.h"
#include "../s21_multimap.h"
#include "../s21_vector.h"

// GCOVR_EXCL_START

template <typename Key, typename Type>
bool operator==(const s21::MultiMap<Key, Type>& s21_mmap,
                const std::multimap<Key, Type>& mmap) {
  if (s21_mmap.Size() != mmap.size()) return false;

  auto s21_it = s21_mmap.cbegin();
  auto it = mmap.cbegin();
  while (s21_it != s21_mmap.cend()) {
    if (*s21_it != *it) return false;

    ++s21_it;
    ++it;
  }

  return true;
}

template <typename Key, typename Type>
std::ostream& operator<<(std::ostream& out,
                         const s21::MultiMap<Key, Type>& s21_map) {
  out << "MultiMap " << s21_map.Size() << "\n";
  for (typename s21::MultiMap<Key, Type>::const_iterator it = s21_map.cbegin();
       it != s21_map.cend(); ++it)
    out << "{" << (*it).first << " : " << (*it).second << "} ";

  return out;
}

// GCOVR_EXCL_STOP

#endif  //  _TESTS_MULTIMAP_HELPERS_H_