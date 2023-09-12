#ifndef _S21_COMPARATOR_H_
#define _S21_COMPARATOR_H_

namespace s21 {

// template <typename Type>
// class ComparatorSet {
// public:
//     bool operator()(const Type& left, const Type& right) const {
//         return left < right;
//     }

// };

// template <typename PairValue1, typename PairValue2 = PairValue1>
// class ComparatorMap {
// public:
//     bool operator()(const PairValue1& left, const PairValue2& right) const {
//         return left.first < right.first;
//     }
// };

template <typename Key>
class Less {
public:
    bool operator()(const Key& left, const Key& right) const {
        return left < right;
    };
};

};  //  namespace s21

#endif  //  _S21_COMPARATOR_H_