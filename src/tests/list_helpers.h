#ifndef _TESTS_LIST_HELPERS_H_
#define _TESTS_LIST_HELPERS_H_

#include <iostream>

#include <list>
#include "../s21_list.h"

// GCOVR_EXCL_START

template <typename Type>
bool operator==(s21::List<Type>& s21_list, const std::list<Type>& list) {
    if (s21_list.Size() != list.size())
        return false;

    auto iterator = list.cbegin();
    auto s21_iterator = s21_list.begin();

    while (iterator != list.cend()) {
        if (*iterator != *s21_iterator)
            return false;
        ++iterator;
        ++s21_iterator;
    }    
    
    return true;
}

template <typename Type>
void print(s21::List<Type>& s21_list) {
    for (auto it = s21_list.begin(); it != s21_list.end(); ++it) {
        std::cout << *it << '\n';
    }
}

// GCOVR_EXCL_STOP

#endif  //  _TESTS_LIST_HELPERS_H_