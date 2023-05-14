#include <gtest/gtest.h>
#include <list>
#include "../../s21_list.h"

// GCOVR_EXCL_START

template <typename Type>
bool operator==(const s21::List<Type>& s21_list, const std::list<Type>& list) {
    if (s21_list.Size() != list.size())
        return false;

    auto iterator = list.cbegin();
    auto s21_iterator = s21_list.cbegin();

    while (iterator != list.cend()) {
        if (*iterator != *s21_iterator)
            return false;
        ++iterator;
        ++s21_iterator;
    }    
    
    return true;
}

template <typename Type>
void print(const s21::List<Type>& s21_list) {
    for (auto it = s21_list.cbegin(); it != s21_list.cend(); ++it) {
        std::cout << *it << '\n';
    }
}

class Item {
private:
    int number_;

public:
    Item(int number = 0) : number_{number} {};
    Item(const Item& other) : number_{other.number_} {};

    Item& operator=(const Item& other){
        if (this == &other)
            return *this;

        number_ = other.number_;
        return *this;
    };

    bool operator==(const Item& right) const {
        return number_ == right.number_;
    };
    bool operator!=(const Item& right) const {
        return !(*this == right);
    };

    friend std::ostream& operator<<(std::ostream& out, const Item& object) {
        out << "Item(" << object.number_ << ')';
        return out;
    }
};

namespace {
    TEST(List, T0DefaultConstructor) {
        s21::List<Item> s21_list;
        std::list<Item> list;

        EXPECT_TRUE(s21_list == list);
    }

    TEST(List, T0PushBack) {
        std::list<Item> list;
        list.push_back(Item(4));
        s21::List<Item> s21_list;
        s21_list.Push_back(Item(4));

        EXPECT_TRUE(s21_list == list);
    }

    TEST(List, T1PushBack) {
        std::list<Item> list;
        list.push_back(Item(0));
        list.push_back(Item(10));
        // list.push_back(Item(20));
        
        s21::List<Item> s21_list;
        s21_list.Push_back(Item(0));
        s21_list.Push_back(Item(10));
        // s21_list.Push_back(Item(20));

        print(s21_list);

        EXPECT_TRUE(s21_list == list);
    }
}   //  namespace

// GCOVR_EXCL_STOP