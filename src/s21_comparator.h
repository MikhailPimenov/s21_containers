#ifndef _S21_COMPARATOR_H_
#define _S21_COMPARATOR_H_

namespace s21 {

    template <typename NodePointer, typename ValueReference>
    class Handler {
    private:
        NodePointer pointer_;
    
    public:
        Handler(NodePointer pointer) : pointer_{pointer} {}

        Handler(const Handler& other) = delete; // запретили создавать копированием

        Handler& operator=(const Handler& other) = delete; // запретили копировать 

        Handler(Handler&& other) noexcept : pointer_{other.pointer_} {
            other.pointer_ = nullptr;
        }

        NodePointer operator->() {
            return pointer_;
        }
        NodePointer operator->() const {
            return pointer_;
        }

        ValueReference Get() {
            return pointer_->value_;
        }
        const ValueReference Get() const {
            return pointer_->value_;
        }

        Handler& operator=(Handler&& other) noexcept {
            if(this == &other)
                return *this;

            this->~Handler();
            pointer_ = other.pointer_;
            other.pointer_ = nullptr;
            return *this;
        }

        ~Handler() {
            // pointer_->~NodePointer();
            // delete reinterpret_cast<char*>(pointer_);
            delete pointer_;
        }
    }; /// smart ass

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


template<typename Key>
class KeyGetterSet {
public:
    const Key& operator()(const Key& value) const {
        return value;
    }
};

template<typename Key, typename Pair>
class KeyGetterMap {
public:
    const Key& operator()(const Pair& pair) const {
        return pair.first;
    }
};



}   //  namespace s21

#endif  //  _S21_COMPARATOR_H_