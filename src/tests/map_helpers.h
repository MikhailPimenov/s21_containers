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
        
        ++s21_it;
        ++it; 
    }

    return true;   
}

template<typename Key, typename Type>
std::ostream& operator<<(std::ostream& out, const s21::Map<Key, Type>& s21_map) {
    out << "Map " << s21_map.Size()  << ' '  << s21_map.Height() << "\n";
    for (typename s21::Map<Key, Type>::const_iterator it = s21_map.cbegin(); it != s21_map.cend(); ++it)
        out << "{" << (*it).first << '-' << it.LeftHeight() << '-' << it.RightHeight() <<  " : " << (*it).second << "} ";

    return out;
}

inline bool minimalHeightAVL(std::size_t size, std::size_t height) {
    // https://en.wikipedia.org/wiki/AVL_tree#Comparison_to_other_structures

    static constexpr double fi = (1.0 + std::sqrt(5.0)) / 2.0;
    static constexpr double c = 1.0 / std::log2(fi);
    static constexpr double b = c / 2.0 * std::log2(5.0) - 2.0;
    const double h = static_cast<double>(height);
    const double s = static_cast<double>(size);

    return h < c * std::log2(s + 2.0) + b;


    // return static_cast<double>(height) < std::log2(static_cast<double>(size) + 1.0) + 2.0;
}

// GCOVR_EXCL_STOP

#endif //  _TESTS_MAP_HELPERS_H_