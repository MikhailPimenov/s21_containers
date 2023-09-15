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


TEST(Vector, T0Insert_Many)
{
    s21::Vector<Item> s21_vector;
    s21::Vector<Item> vector_expected {Item(-33), Item(44), Item(-55), Item(66)};

    s21_vector.Insert_many_back(Item(-33), Item(44), Item(-55), Item(66));



    EXPECT_EQ(s21_vector, vector_expected);
}

TEST(Vector, T1Insert_Many)
{
    s21::Vector<Item> s21_vector {
        Item(11), Item(22), Item(33), Item(44), Item(55), Item(66),
    };

    s21::Vector<Item> s21_vector_expected {
        Item(11), Item(22), Item(33), Item(44), Item(55), Item(66), Item(666), Item(777),
    };

    
    s21_vector.Insert_many_back(Item(666), Item(777));


    EXPECT_EQ(s21_vector, s21_vector_expected);
}

TEST(Vector, T2Insert_Many_Empty)
{
    s21::Vector<Item> s21_vector;

    s21::Vector<Item> s21_vector_expected {
        Item(11), Item(22), Item(33), Item(44), Item(55), Item(66), Item(666), Item(777),
    };

    
    s21_vector.Insert_many_back(Item(11), Item(22), Item(33), Item(44), Item(55), Item(66), Item(666), Item(777));


    EXPECT_EQ(s21_vector, s21_vector_expected);
}

}  // namespace