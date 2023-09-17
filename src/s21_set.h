#ifndef _S21_SET_H_
#define _S21_SET_H_

#include "s21_tree.h"
#include "s21_utility.h"

namespace s21 {

template <typename Value, typename Comparator = Utility::Less<Value>>
class Set : public Tree::Tree<Value, Value, Comparator> {
  using Base = Tree::Tree<Value, Value, Comparator>;

 public:
  using node_type = typename Base::node_handler;
  using Base::Base;
};

template <typename Type, typename Comperator>
bool operator==(const s21::Set<Type, Comperator>& left,
                const s21::Set<Type, Comperator>& right) {
  if (left.Size() != right.Size()) return false;

  auto s21_it = left.cbegin();
  auto it = right.cbegin();

  while (s21_it != left.cend()) {
    if (*s21_it != *it) return false;

    ++s21_it;
    ++it;
  }

  return true;
}

}  // namespace s21

#endif  //  _S21_SET_H_