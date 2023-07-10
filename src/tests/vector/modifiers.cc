#include <gtest/gtest.h>

#include <stack>
#include <list>
#include <vector>
#include <deque>


#include "../../s21_vector.h"
#include "../item.h"
#include "../vector_helpers.h"

// GCOVR_EXCL_START

namespace
{

TEST(Vector, T0PushBackMove)
{
    s21::Vector<Item> s21_vector;
    s21_vector.Push_back(Item(111));
    s21_vector.Push_back(Item(222, 'b'));
    s21_vector.Push_back(Item(333, 'c', 0.333));

    std::vector<Item> vector;
    vector.push_back(Item(111));
    vector.push_back(Item(222, 'b'));
    vector.push_back(Item(333, 'c', 0.333));


    EXPECT_EQ(s21_vector, vector);
}

TEST(Vector, T1PushBackMove)
{
    s21::Vector<Item> s21_vector { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333) };
    std::vector<Item> vector { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333) };

    s21_vector.Push_back(Item(111));
    s21_vector.Push_back(Item(111));
    s21_vector.Push_back(Item(222, 'b'));
    s21_vector.Push_back(Item(222, 'b'));
    s21_vector.Push_back(Item(333, 'c', 0.333));
    s21_vector.Push_back(Item(333, 'c', 0.333));

    vector.push_back(Item(111));
    vector.push_back(Item(111));
    vector.push_back(Item(222, 'b'));
    vector.push_back(Item(222, 'b'));
    vector.push_back(Item(333, 'c', 0.333));
    vector.push_back(Item(333, 'c', 0.333));


    EXPECT_EQ(s21_vector, vector);
}

TEST(Vector, T2PushBack)
{
    const Item item1(111);
    const Item item2(222, 'b');
    const Item item3(333, 'c', 0.333);
    
    s21::Vector<Item> s21_vector;
    s21_vector.Push_back(item1);
    s21_vector.Push_back(item2);
    s21_vector.Push_back(item3);

    std::vector<Item> vector;
    vector.push_back(item1);
    vector.push_back(item2);
    vector.push_back(item3);


    EXPECT_EQ(s21_vector, vector);
}

TEST(Vector, T3PushBack)
{
    const Item item1(111);
    const Item item2(222, 'b');
    const Item item3(333, 'c', 0.333);

    s21::Vector<Item> s21_vector { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333) };
    std::vector<Item> vector { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333) };

    s21_vector.Push_back(item1);
    s21_vector.Push_back(item1);
    s21_vector.Push_back(item2);
    s21_vector.Push_back(item2);
    s21_vector.Push_back(item3);
    s21_vector.Push_back(item3);

    vector.push_back(item1);
    vector.push_back(item1);
    vector.push_back(item2);
    vector.push_back(item2);
    vector.push_back(item3);
    vector.push_back(item3);


    EXPECT_EQ(s21_vector, vector);
}

TEST(Vector, T4EmplaceBack)
{
    s21::Vector<Item> s21_vector { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333) };
    std::vector<Item> vector { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333) };

    s21_vector.Emplace_back(111);
    s21_vector.Emplace_back(111);
    s21_vector.Emplace_back(222, 'b');
    s21_vector.Emplace_back(222, 'b');
    s21_vector.Emplace_back(333, 'c', 0.333);
    s21_vector.Emplace_back(333, 'c', 0.333);

    vector.emplace_back(111);
    vector.emplace_back(111);
    vector.emplace_back(222, 'b');
    vector.emplace_back(222, 'b');
    vector.emplace_back(333, 'c', 0.333);
    vector.emplace_back(333, 'c', 0.333);


    EXPECT_EQ(s21_vector, vector);
}





TEST(Vector, T4Insert)
{
    const Item item1(111);
    const Item item2(222, 'b');
    const Item item3(333, 'c', 0.333);

    s21::Vector<Item> s21_vector { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333) };
    std::vector<Item> vector { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333) };


    s21::Vector<Item>::const_iterator s21_it = s21_vector.cbegin() + 1;
    // s21::Vector<Item>::const_iterator s21_it = s21_vector.begin();  // TODO:  так тоже должно работать, но не работает
    std::vector<Item>::const_iterator it = vector.begin() + 1;

    s21_vector.Insert(s21_it, item1);
    vector.insert(it, item1);

    EXPECT_EQ(s21_vector, vector);
}



}  // namespace

// GCOVR_EXCL_STOP