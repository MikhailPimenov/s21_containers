#ifndef _S21_COMPARATOR_H_
#define _S21_COMPARATOR_H_

namespace s21 {

template <typename Type>
class ComparatorSet {
public:
    bool operator()(const Type& left, const Type& right) const {
        return left < right;
    }

};

template <typename PairValue>
class ComparatorMap {
public:
    bool operator()(const PairValue& left, const PairValue& right) const {
        return left.first < right.first;
    }
};

};  //  namespace s21

#endif  //  _S21_COMPARATOR_H_