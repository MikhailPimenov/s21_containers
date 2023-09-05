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
#include "../multimap_helpers.h"

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

TEST(MultiMap, T0DefaultConstructor)
{
    s21::MultiMap<int, Item> s21_multimap;
    std::multimap<int, Item> multimap;

    s21_multimap.Insert(std::make_pair(3, Item(3, 'c', 0.3)));
    s21_multimap.Insert(std::make_pair(1, Item(10, 'a', 0.1)));
    s21_multimap.Insert(std::make_pair(1, Item(100, 'b', 0.1)));
    s21_multimap.Insert(std::make_pair(2, Item(2, 'b', 0.2)));
    s21_multimap.Insert(std::make_pair(2, Item(2, 'b', 0.2)));
    s21_multimap.Insert(std::make_pair(1, Item(1, 'c', 0.1)));
    s21_multimap.Insert(std::make_pair(2, Item(2, 'b', 0.2)));
    s21_multimap.Insert(std::make_pair(3, Item(3, 'c', 0.3)));

    multimap.insert(std::make_pair(3, Item(3, 'c', 0.3)));
    multimap.insert(std::make_pair(1, Item(10, 'a', 0.1)));
    multimap.insert(std::make_pair(1, Item(100, 'b', 0.1)));
    multimap.insert(std::make_pair(2, Item(2, 'b', 0.2)));
    multimap.insert(std::make_pair(2, Item(2, 'b', 0.2)));
    multimap.insert(std::make_pair(1, Item(1, 'c', 0.1)));
    multimap.insert(std::make_pair(2, Item(2, 'b', 0.2)));
    multimap.insert(std::make_pair(3, Item(3, 'c', 0.3)));

    EXPECT_EQ(s21_multimap, multimap);
}



TEST(MultiMap, T1Insert)
{
    s21::MultiMap<int, Item> s21_multimap;
    s21_multimap.Insert(std::make_pair(10, Item(3, 'c', 0.3)));
    s21_multimap.Insert(std::make_pair(10, Item(10, 'c', 0.3)));
    s21_multimap.Insert(std::make_pair(12, Item(3, 'c', 0.3)));
    s21_multimap.Insert(std::make_pair(13, Item(3, 'c', 0.3)));
    s21_multimap.Insert(std::make_pair(3, Item(3, 'c', 0.3)));
    s21_multimap.Insert(std::make_pair(1, Item(1, 'a', 0.1)));
    s21_multimap.Insert(std::make_pair(1, Item(1, 'a', 0.1)));
    s21_multimap.Insert(std::make_pair(1, Item(1, 'a', 0.1)));
    s21_multimap.Insert(std::make_pair(1, Item(1, 'a', 0.1)));
    s21_multimap.Insert(std::make_pair(1, Item(1, 'a', 0.1)));
    s21_multimap.Insert(std::make_pair(2, Item(2, 'b', 0.2)));
    s21_multimap.Insert(std::make_pair(2, Item(2, 'b', 0.2)));
    s21_multimap.Insert(std::make_pair(2, Item(2, 'b', 0.2)));
    s21_multimap.Insert(std::make_pair(2, Item(2, 'b', 0.2)));
    s21_multimap.Insert(std::make_pair(3, Item(3, 'c', 0.3)));
    s21_multimap.Insert(std::make_pair(3, Item(3, 'c', 0.3)));

    std::multimap<int, Item> multimap;
    multimap.insert(std::make_pair(10, Item(3, 'c', 0.3)));
    multimap.insert(std::make_pair(10, Item(10, 'c', 0.3)));
    multimap.insert(std::make_pair(12, Item(3, 'c', 0.3)));
    multimap.insert(std::make_pair(13, Item(3, 'c', 0.3)));
    multimap.insert(std::make_pair(3, Item(3, 'c', 0.3)));
    multimap.insert(std::make_pair(1, Item(1, 'a', 0.1)));
    multimap.insert(std::make_pair(1, Item(1, 'a', 0.1)));
    multimap.insert(std::make_pair(1, Item(1, 'a', 0.1)));
    multimap.insert(std::make_pair(1, Item(1, 'a', 0.1)));
    multimap.insert(std::make_pair(1, Item(1, 'a', 0.1)));
    multimap.insert(std::make_pair(2, Item(2, 'b', 0.2)));
    multimap.insert(std::make_pair(2, Item(2, 'b', 0.2)));
    multimap.insert(std::make_pair(2, Item(2, 'b', 0.2)));
    multimap.insert(std::make_pair(2, Item(2, 'b', 0.2)));
    multimap.insert(std::make_pair(3, Item(3, 'c', 0.3)));
    multimap.insert(std::make_pair(3, Item(3, 'c', 0.3)));


    EXPECT_EQ(s21_multimap, multimap);
}





TEST(MultiMap, T2ConstructorInitializer)
{
    const s21::MultiMap<int, Item> s21_multimap {
        {10, Item(3, 'c', 0.3)},
        {10, Item(10, 'c', 0.3)},
        {12, Item(3, 'c', 0.3)},
        {13, Item(3, 'c', 0.3)},
        {3, Item(3, 'c', 0.3)},
        {1, Item(1, 'a', 0.1)},
        {1, Item(1, 'a', 0.1)},
        {1, Item(1, 'a', 0.1)},
        {1, Item(1, 'a', 0.1)},
        {1, Item(1, 'a', 0.1)},
        {2, Item(2, 'b', 0.2)},
        {2, Item(2, 'b', 0.2)},
        {2, Item(2, 'b', 0.2)},
        {2, Item(2, 'b', 0.2)},
        {3, Item(3, 'c', 0.3)},
        {3, Item(3, 'c', 0.3)},
    };

    const std::multimap<int, Item> multimap{
        {10, Item(3, 'c', 0.3)},
        {10, Item(10, 'c', 0.3)},
        {12, Item(3, 'c', 0.3)},
        {13, Item(3, 'c', 0.3)},
        {3, Item(3, 'c', 0.3)},
        {1, Item(1, 'a', 0.1)},
        {1, Item(1, 'a', 0.1)},
        {1, Item(1, 'a', 0.1)},
        {1, Item(1, 'a', 0.1)},
        {1, Item(1, 'a', 0.1)},
        {2, Item(2, 'b', 0.2)},
        {2, Item(2, 'b', 0.2)},
        {2, Item(2, 'b', 0.2)},
        {2, Item(2, 'b', 0.2)},
        {3, Item(3, 'c', 0.3)},
        {3, Item(3, 'c', 0.3)},
    };

    EXPECT_EQ(s21_multimap, multimap);
}




TEST(MultiMap, T0ReverseIterator)
{
    s21::MultiMap<int, Item> s21_multimap {
        {10, Item(3, 'c', 0.3)},
        {10, Item(10, 'c', 0.3)},
        {12, Item(3, 'c', 0.3)},
        {13, Item(3, 'c', 0.3)},
        {3, Item(3, 'c', 0.3)},
        {1, Item(1, 'a', 0.1)},
        {1, Item(1, 'a', 0.1)},
        {1, Item(1, 'a', 0.1)},
        {1, Item(1, 'a', 0.1)},
        {1, Item(1, 'a', 0.1)},
        {2, Item(2, 'b', 0.2)},
        {2, Item(2, 'b', 0.2)},
        {2, Item(2, 'b', 0.2)},
        {2, Item(2, 'b', 0.2)},
        {3, Item(3, 'c', 0.3)},
        {3, Item(3, 'c', 0.3)},
    };

    std::multimap<int, Item> multimap{
        {10, Item(3, 'c', 0.3)},
        {10, Item(10, 'c', 0.3)},
        {12, Item(3, 'c', 0.3)},
        {13, Item(3, 'c', 0.3)},
        {3, Item(3, 'c', 0.3)},
        {1, Item(1, 'a', 0.1)},
        {1, Item(1, 'a', 0.1)},
        {1, Item(1, 'a', 0.1)},
        {1, Item(1, 'a', 0.1)},
        {1, Item(1, 'a', 0.1)},
        {2, Item(2, 'b', 0.2)},
        {2, Item(2, 'b', 0.2)},
        {2, Item(2, 'b', 0.2)},
        {2, Item(2, 'b', 0.2)},
        {3, Item(3, 'c', 0.3)},
        {3, Item(3, 'c', 0.3)},
    };

    // for (auto it = multimap.rbegin(); it != multimap.rend(); ++it) {
    //     std::cout << "{" << it->first << ", " << it->second << "},  ";
    // }
    // std::cout << '\n';

    EXPECT_EQ(s21_multimap, multimap);

    s21::MultiMap<int, Item>::reverse_iterator s21_it = s21_multimap.rbegin();
    std::multimap<int, Item>::reverse_iterator it = multimap.rbegin();

    while (s21_it != s21_multimap.rend() && it != multimap.rend()) {
        // EXPECT_EQ(*s21_it, *it);
        std::cout << "{" << s21_it->first << ", " << s21_it->second << "}  ==  ";
        std::cout << "{" << it->first << ", " << it->second << "},  ";
        std::cout << '\n';
        ++s21_it;
        ++it;
    }
}




TEST(MultiMap, T1IteratorOperatorMinusPre)
{
    s21::MultiMap<int, Item> s21_multimap {
        {10, Item(3, 'c', 0.3)},
        {10, Item(10, 'c', 0.3)},
        {12, Item(3, 'c', 0.3)},
        {13, Item(3, 'c', 0.3)},
        {3, Item(3, 'c', 0.3)},
        {1, Item(1, 'a', 0.1)},
        {1, Item(1, 'a', 0.1)},
        {1, Item(1, 'a', 0.1)},
        {1, Item(1, 'a', 0.1)},
        {1, Item(1, 'a', 0.1)},
        {2, Item(2, 'b', 0.2)},
        {2, Item(2, 'b', 0.2)},
        {2, Item(2, 'b', 0.2)},
        {2, Item(2, 'b', 0.2)},
        {3, Item(3, 'c', 0.3)},
        {3, Item(3, 'c', 0.3)},
    };

    std::multimap<int, Item> multimap{
        {10, Item(3, 'c', 0.3)},
        {10, Item(10, 'c', 0.3)},
        {12, Item(3, 'c', 0.3)},
        {13, Item(3, 'c', 0.3)},
        {3, Item(3, 'c', 0.3)},
        {1, Item(1, 'a', 0.1)},
        {1, Item(1, 'a', 0.1)},
        {1, Item(1, 'a', 0.1)},
        {1, Item(1, 'a', 0.1)},
        {1, Item(1, 'a', 0.1)},
        {2, Item(2, 'b', 0.2)},
        {2, Item(2, 'b', 0.2)},
        {2, Item(2, 'b', 0.2)},
        {2, Item(2, 'b', 0.2)},
        {3, Item(3, 'c', 0.3)},
        {3, Item(3, 'c', 0.3)},
    };

    // for (auto it = multimap.rbegin(); it != multimap.rend(); ++it) {
    //     std::cout << "{" << it->first << ", " << it->second << "},  ";
    // }
    // std::cout << '\n';

    EXPECT_EQ(s21_multimap, multimap);

    s21::MultiMap<int, Item>::iterator s21_it = s21_multimap.end();
    std::multimap<int, Item>::iterator it = multimap.end();

    while (s21_it != s21_multimap.begin() && it != multimap.begin()) {
        --s21_it;
        --it;
        EXPECT_EQ(*s21_it, *it);
    }
}




}  // namespace

// GCOVR_EXCL_STOP
