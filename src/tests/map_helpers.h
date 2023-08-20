#ifndef _TESTS_MAP_HELPERS_H_
#define _TESTS_MAP_HELPERS_H_

#include <iostream>
#include <map>
#include <cmath>

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

template<typename Key, typename Type>
std::ostream& operator<<(std::ostream& out, const s21::Map<Key, Type>& s21_map) {
    out << "Map " << s21_map.Size() << "\n";
    for (typename s21::Map<Key, Type>::const_iterator it = s21_map.cbegin(); it != s21_map.cend(); ++it)
        out << "{" << (*it).first << '-' << it.LeftHeight() << '-' << it.RightHeight() <<  " : " << (*it).second << "} ";

    return out;
}

inline bool minimalHeight(std::size_t size, std::size_t height) {
    return height < std::log2(static_cast<double>(size) + 1.0);
}

// GCOVR_EXCL_STOP

#endif //  _TESTS_MAP_HELPERS_H_