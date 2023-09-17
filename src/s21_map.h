#ifndef _S21_MAP_H_
#define _S21_MAP_H_

#include "s21_tree.h"
#include "s21_utility.h"

namespace s21 {
namespace Utility {

template <typename Key, typename Pair, typename ComparatorKey>
class ComparatorMap {
 private:
  ComparatorKey comparator_;

 public:
  bool operator()(const Pair& left, const Pair& right) const {
    return comparator_(left.first, right.first);
  }
  bool operator()(const Key& left, const Pair& right) const {
    return comparator_(left, right.first);
  }
  bool operator()(const Pair& left, const Key& right) const {
    return comparator_(left.first, right);
  }
};
}  // namespace Utility

template <typename Key, typename Value,
          typename Comparator = Utility::Less<const Key>>
class Map : public Tree::Tree<
                Key, std::pair<const Key, Value>,
                Utility::ComparatorMap<const Key, std::pair<const Key, Value>,
                                       Comparator>> {
  using Base =
      Tree::Tree<Key, std::pair<const Key, Value>,
                 Utility::ComparatorMap<const Key, std::pair<const Key, Value>,
                                        Comparator>>;

 public:
  using node_type = typename Base::node_handler;
  using Base::Base;
};

template <typename Key, typename Type>
bool operator==(const s21::Map<Key, Type>& left,
                const s21::Map<Key, Type>& right) {
  if (left.Size() != right.Size()) return false;

  auto it_left = left.cbegin();
  auto it_right = right.cbegin();

  while (it_left != left.cend()) {
    if (*it_left != *it_right) return false;

    ++it_left;
    ++it_right;
  }

  return true;
}

}  // namespace s21

#endif  //  _S21_MAP_H_
