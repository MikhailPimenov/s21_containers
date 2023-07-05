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

TEST(Vector, T0PushBack)
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

TEST(Vector, T1PushBack)
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


}  // namespace

// GCOVR_EXCL_STOP
