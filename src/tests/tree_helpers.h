#ifndef _TESTS_TREE_HELPERS_H_
#define _TESTS_TREE_HELPERS_H_

#include <cmath>

// GCOVR_EXCL_START

inline bool minimalHeightAVL(std::size_t size, std::size_t height) {
  // https://en.wikipedia.org/wiki/AVL_tree#Comparison_to_other_structures

  static const double fi = (1.0 + std::sqrt(5.0)) / 2.0;
  static const double c = 1.0 / std::log2(fi);
  static const double b = c / 2.0 * std::log2(5.0) - 2.0;
  const double h = static_cast<double>(height);
  const double s = static_cast<double>(size);

  return h < c * std::log2(s + 2.0) + b;
}

// GCOVR_EXCL_STOP

#endif  //  _TESTS_MAP_HELPERS_H_