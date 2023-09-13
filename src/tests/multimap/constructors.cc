#include <gtest/gtest.h>

#include <map>

#include "../../s21_multimap.h"
#include "../item.h"
#include "../multimap_helpers.h"

// GCOVR_EXCL_START

namespace
{


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



TEST(MultiMap, T0Insert)
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





TEST(MultiMap, T0ConstructorInitializer)
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
























TEST(MultiMap, T1Destructor)
{
    s21::MultiMap<int, Item> s21_multimap;
    s21_multimap.Insert(std::make_pair(4, Item()));
    s21_multimap.Insert(std::make_pair(3, Item()));
    s21_multimap.Insert(std::make_pair(5, Item()));
}

TEST(MultiMap, T2Destructor)
{
    s21::MultiMap<int, Item> s21_multimap;
    s21_multimap.Insert(std::make_pair(4, Item()));
    s21_multimap.Insert(std::make_pair(4, Item()));
    s21_multimap.Insert(std::make_pair(4, Item()));
    s21_multimap.Insert(std::make_pair(4, Item()));

    std::multimap<int, Item> multimap;
    multimap.insert(std::make_pair(4, Item()));
    multimap.insert(std::make_pair(4, Item()));
    multimap.insert(std::make_pair(4, Item()));
    multimap.insert(std::make_pair(4, Item()));


    EXPECT_EQ(s21_multimap, multimap);
}





TEST(MultiMap, T1ConstructorInitializer)
{
    s21::MultiMap<int, Item> s21_multimap {
        {3, Item(3, 'c', 0.3)},
        {1, Item(1, 'a', 0.1)},
        {2, Item(2, 'b', 0.2)},
        {3, Item(3, 'c', 0.3)},
        {3, Item(3, 'c', 0.3)},
        {4, Item(4, 'd', 0.4)},
        {5, Item(5, 'e', 0.5)},
        {6, Item(6, 'f', 0.6)},
    };
    std::multimap<int, Item> multimap {
        {3, Item(3, 'c', 0.3)},
        {1, Item(1, 'a', 0.1)},
        {2, Item(2, 'b', 0.2)},
        {3, Item(3, 'c', 0.3)},
        {3, Item(3, 'c', 0.3)},
        {4, Item(4, 'd', 0.4)},
        {5, Item(5, 'e', 0.5)},
        {6, Item(6, 'f', 0.6)},
    };

    EXPECT_EQ(s21_multimap, multimap);
}





TEST(MultiMap, T0CopyConstructor)
{
    const s21::MultiMap<int, Item> s21_source {
        {1, Item(1, 'a', 0.1)},
        {6, Item(6, 'f', 0.6)},
        {2, Item(2, 'b', 0.2)},
        {5, Item(5, 'e', 0.5)},
        {2, Item(2, 'b', 0.2)},
        {4, Item(4, 'd', 0.4)},
        {1, Item(1, 'a', 0.1)},
        {2, Item(2, 'b', 0.2)},
        {3, Item(3, 'c', 0.3)},
        {4, Item(4, 'd', 0.4)},
        {4, Item(4, 'd', 0.4)},
        {4, Item(4, 'd', 0.4)},
        {5, Item(5, 'e', 0.5)},
        {6, Item(6, 'f', 0.6)},
    };
    const std::multimap<int, Item> source {
        {1, Item(1, 'a', 0.1)},
        {6, Item(6, 'f', 0.6)},
        {2, Item(2, 'b', 0.2)},
        {5, Item(5, 'e', 0.5)},
        {2, Item(2, 'b', 0.2)},
        {4, Item(4, 'd', 0.4)},
        {1, Item(1, 'a', 0.1)},
        {2, Item(2, 'b', 0.2)},
        {3, Item(3, 'c', 0.3)},
        {4, Item(4, 'd', 0.4)},
        {4, Item(4, 'd', 0.4)},
        {4, Item(4, 'd', 0.4)},
        {5, Item(5, 'e', 0.5)},
        {6, Item(6, 'f', 0.6)},
    };

    s21::MultiMap<int, Item> s21_copy = s21_source;  // copy constructor, not operator=
    std::multimap<int, Item> copy = source;



    EXPECT_EQ(s21_copy, copy);
}

TEST(MultiMap, T1CopyConstructorEmpty)
{
    const s21::MultiMap<int, Item> s21_source;
    const std::multimap<int, Item> source;

    s21::MultiMap<int, Item> s21_copy = s21_source;  // copy constructor, not operator=
    std::multimap<int, Item> copy = source;

    EXPECT_EQ(s21_copy, copy);
}





TEST(MultiMap, T0CopyAssignmentOperator)
{
    const s21::MultiMap<int, Item> s21_source {
        {6, Item(6, 'f', 0.6)},
        {5, Item(5, 'e', 0.5)},
        {1, Item(1, 'a', 0.1)},
        {2, Item(2, 'b', 0.2)},
        {1, Item(1, 'a', 0.1)},
        {1, Item(1, 'a', 0.1)},
        {1, Item(1, 'a', 0.1)},
        {1, Item(1, 'a', 0.1)},
        {5, Item(5, 'e', 0.5)},
    };
    const std::multimap<int, Item> source {
        {6, Item(6, 'f', 0.6)},
        {5, Item(5, 'e', 0.5)},
        {1, Item(1, 'a', 0.1)},
        {2, Item(2, 'b', 0.2)},
        {1, Item(1, 'a', 0.1)},
        {1, Item(1, 'a', 0.1)},
        {1, Item(1, 'a', 0.1)},
        {1, Item(1, 'a', 0.1)},
        {5, Item(5, 'e', 0.5)},
    };

    s21::MultiMap<int, Item> s21_copy;
    s21_copy = s21_source;  
    std::multimap<int, Item> copy;
    copy = source;

    EXPECT_EQ(s21_copy, copy);
}

TEST(MultiMap, T1CopyAssignmentOperator)
{
    const s21::MultiMap<int, Item> s21_source;
    const std::multimap<int, Item> source;

    s21::MultiMap<int, Item> s21_copy;
    s21_copy = s21_source;
    std::multimap<int, Item> copy;
    copy = source;

    EXPECT_EQ(s21_copy, copy);
}



TEST(MultiMap, T0MoveAssignmentOperator)
{
    s21::MultiMap<int, Item> s21_source {
        {1, Item(1, 'a', 0.1111)},
        {4, Item(4, 'd', 0.44)},
        {1, Item(1, 'a', 0.1)},
        {1, Item(1, 'a', 0.11)},
        {1, Item(1, 'a', 0.111)},
        {2, Item(2, 'b', 0.2)},
        {6, Item(6, 'f', 0.66)},
        {3, Item(3, 'c', 0.3)},
        {3, Item(3, 'c', 0.33)},
        {4, Item(4, 'd', 0.4)},
        {5, Item(5, 'e', 0.5)},
        {6, Item(6, 'f', 0.6)},
    };
    std::multimap<int, Item> source {
        {1, Item(1, 'a', 0.1111)},
        {4, Item(4, 'd', 0.44)},
        {1, Item(1, 'a', 0.1)},
        {1, Item(1, 'a', 0.11)},
        {1, Item(1, 'a', 0.111)},
        {2, Item(2, 'b', 0.2)},
        {6, Item(6, 'f', 0.66)},
        {3, Item(3, 'c', 0.3)},
        {3, Item(3, 'c', 0.33)},
        {4, Item(4, 'd', 0.4)},
        {5, Item(5, 'e', 0.5)},
        {6, Item(6, 'f', 0.6)},
    };



    s21::MultiMap<int, Item> s21_copy {
        {3, Item(3, 'c', 0.3)},
        {3, Item(3, 'c', 0.3)},
        {4, Item(4, 'd', 0.4)},
    };
    s21_copy = std::move(s21_source);  

    std::multimap<int, Item> copy {
        {3, Item(3, 'c', 0.3)},
        {3, Item(3, 'c', 0.3)},
        {4, Item(4, 'd', 0.4)},
    };
    copy = std::move(source);


    EXPECT_EQ(s21_copy, copy);

    const s21::MultiMap<int, Item> s21_empty;
    EXPECT_EQ(s21_source, s21_empty);
    
    const std::multimap<int, Item> empty;
    EXPECT_EQ(source, empty);
}

TEST(MultiMap, T1MoveAssignmentOperator)
{
    s21::MultiMap<int, Item> s21_source;
    std::multimap<int, Item> source;



    s21::MultiMap<int, Item> s21_copy {
        {3, Item(3, 'c', 0.3)},
        {4, Item(4, 'd', 0.4)},
    };
    s21_copy = std::move(s21_source);  

    std::multimap<int, Item> copy {
        {3, Item(3, 'c', 0.3)},
        {4, Item(4, 'd', 0.4)},
    };
    copy = std::move(source);


    EXPECT_EQ(s21_copy, copy);

    const s21::MultiMap<int, Item> s21_empty;
    EXPECT_EQ(s21_source, s21_empty);
    
    const std::multimap<int, Item> empty;
    EXPECT_EQ(source, empty);
}







TEST(MultiMap, T0MoveConstructor)
{
    s21::MultiMap<int, Item> s21_source {
        {1, Item(1, 'a', 0.1)},
        {2, Item(2, 'b', 0.2)},
        {3, Item(3, 'c', 0.3)},
        {4, Item(4, 'd', 0.4)},
        {5, Item(5, 'e', 0.5)},
        {6, Item(6, 'f', 0.6)},
    };
    std::multimap<int, Item> source {
        {1, Item(1, 'a', 0.1)},
        {2, Item(2, 'b', 0.2)},
        {3, Item(3, 'c', 0.3)},
        {4, Item(4, 'd', 0.4)},
        {5, Item(5, 'e', 0.5)},
        {6, Item(6, 'f', 0.6)},
    };



    s21::MultiMap<int, Item> s21_copy = std::move(s21_source);  
    std::multimap<int, Item> copy = std::move(source);


    EXPECT_EQ(s21_copy, copy);

    const s21::MultiMap<int, Item> s21_empty;
    EXPECT_EQ(s21_source, s21_empty);
    
    const std::multimap<int, Item> empty;
    EXPECT_EQ(source, empty);
}

TEST(MultiMap, T1MoveConstructor)
{
    s21::MultiMap<int, Item> s21_source;
    std::multimap<int, Item> source;



    s21::MultiMap<int, Item> s21_copy = std::move(s21_source);  
    std::multimap<int, Item> copy = std::move(source);


    EXPECT_EQ(s21_copy, copy);

    const s21::MultiMap<int, Item> s21_empty;
    EXPECT_EQ(s21_source, s21_empty);
    
    const std::multimap<int, Item> empty;
    EXPECT_EQ(source, empty);
}






















TEST(MultiMap, T0ReverseIterator)
{
    s21::MultiMap<int, Item> s21_multimap {
        {10, Item(3, 'c', 0.3)},
        {4, Item(3, 'c', 0.3)},
        {7, Item(3, 'c', 0.3)},
    };

    std::multimap<int, Item> multimap{
        {10, Item(3, 'c', 0.3)},
        {4, Item(3, 'c', 0.3)},
        {7, Item(3, 'c', 0.3)},
    };

    const auto start = s21_multimap.rbegin();
    const auto finish = s21_multimap.rend();
    for (auto it = s21_multimap.rbegin(); it != s21_multimap.rend(); ++it) {
        std::cout << "{" << it->first << ", " << it->second << "},\n";
    }
    std::cout << '\n';

    EXPECT_EQ(s21_multimap, multimap);

    s21::MultiMap<int, Item>::reverse_iterator s21_it = s21_multimap.rbegin();
    std::multimap<int, Item>::reverse_iterator it = multimap.rbegin();

    while (s21_it != s21_multimap.rend() && it != multimap.rend()) {
        EXPECT_EQ(*s21_it, *it);
        // std::cout << "{" << s21_it->first << ", " << s21_it->second << "}  ==  ";
        // std::cout << "{" << it->first << ", " << it->second << "},  ";
        // std::cout << '\n';
        ++s21_it;
        ++it;
    }
}

TEST(MultiMap, T1ReverseIterator)
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

    for (auto it = multimap.rbegin(); it != multimap.rend(); ++it) {
        std::cout << "{" << it->first << ", " << it->second << "},  ";
    }
    std::cout << '\n';

    EXPECT_EQ(s21_multimap, multimap);

    s21::MultiMap<int, Item>::reverse_iterator s21_it = s21_multimap.rbegin();
    std::multimap<int, Item>::reverse_iterator it = multimap.rbegin();

    while (s21_it != s21_multimap.rend() && it != multimap.rend()) {
        EXPECT_EQ(*s21_it, *it);
        // std::cout << "{" << s21_it->first << ", " << s21_it->second << "}  ==  ";
        // std::cout << "{" << it->first << ", " << it->second << "},  ";
        // std::cout << '\n';
        ++s21_it;
        ++it;
    }
}




TEST(MultiMap, T1IteratorOperatorMinusPrefix)
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
        // std::cout << "{" << s21_it->first << ", " << s21_it->second << "}\t\t==  ";
        // std::cout << "{" << it->first << ", " << it->second << "}\n";
        EXPECT_EQ(*s21_it, *it);
    }

}



TEST(MultiMap, T1ReverseIteratorOperatorMinusPrefix)
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

    s21::MultiMap<int, Item>::reverse_iterator s21_it = s21_multimap.rend();
    std::multimap<int, Item>::reverse_iterator it = multimap.rend();

    while (s21_it != s21_multimap.rbegin() && it != multimap.rbegin()) {
        --s21_it;
        --it;
        // std::cout << "{" << s21_it->first << ", " << s21_it->second << "}\t\t==  ";
        // std::cout << "{" << it->first << ", " << it->second << "}\n";
        EXPECT_EQ(*s21_it, *it);
    }

}


}  // namespace

// GCOVR_EXCL_STOP
