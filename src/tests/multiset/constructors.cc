#include <gtest/gtest.h>

#include <stack>
#include <list>
#include <vector>
#include <deque>
#include <map>
#include <set>

#include "../../s21_map.h"
#include "../item.h"
#include "../map_helpers.h"

// GCOVR_EXCL_START

namespace
{


class ComparatorItem {
public:
    bool operator()(const Item& left, const Item& right) const {
        return left.number() < right.number();
    }
};

template <typename Key, typename Type, typename Less>
std::ostream& operator<<(std::ostream& out, const std::multimap<Key, Type, Less>& mm) {
    out << "map: " << mm.size() << '\n';
    for (auto it = mm.begin(); it != mm.end(); ++it)
        out << "{" << it->first << " : " << it->second << "}, ";
    return out;
}

TEST(Map, T0DefaultConstructor)
{
    // s21::MultiMap<int, Item> s21_multimap;
    // // std::multiset<Item> multiset;

    // s21_multimap.Insert(std::make_pair(1, Item(1, 'a', 0.1)));
    // s21_multimap.Insert(std::make_pair(1, Item(1, 'a', 0.1)));
    // s21_multimap.Insert(std::make_pair(1, Item(1, 'a', 0.1)));
    // s21_multimap.Insert(std::make_pair(2, Item(2, 'b', 0.2)));
    // s21_multimap.Insert(std::make_pair(3, Item(3, 'c', 0.3)));

    // s21::Set<int, Item> s21_set;
    // s21_set.Insert(Item(1, 'a', 0.1));
    // s21_set.Insert(Item(2, 'b', 0.2));
    // s21_set.Insert(Item(3, 'c', 0.3));



    //EXPECT_EQ(s21_map, map);
}







}  // namespace

// GCOVR_EXCL_STOP
