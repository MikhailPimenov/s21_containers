#ifndef _TESTS_MAP_HELPERS_H_
#define _TESTS_MAP_HELPERS_H_

#include <iostream>
#include <map>

#include "../s21_map.h"

// GCOVR_EXCL_START

template<typename Key, typename Type>
bool operator==(const s21::Map<Key, Type>& s21_map, const std::map<Key, Type>& map) {
    if(s21_map.Size() != map.size())
        return false;
    
    auto s21_it = s21_map.cbegin();
    auto it = map.cbegin();

    while(s21_it != s21_map.cend()) {
        if(*s21_it != *it) 
            return false;
        
        s21_it++;
        it++;
        
    }

    return true;   
}



// GCOVR_EXCL_STOP

#endif //  _TESTS_MAP_HELPERS_H_