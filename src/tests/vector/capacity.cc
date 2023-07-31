#include <gtest/gtest.h>

#include <vector>
#include "../../s21_vector.h"

#include "../item.h"
#include "../vector_helpers.h"

// GCOVR_EXCL_START

namespace
{

TEST(Vector, T0Capacity)
{
    s21::Vector<Item> s21_vector { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333) };
    std::vector<Item> vector { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333) };

    s21_vector.Reserve(100);
    vector.reserve(100);

    EXPECT_EQ(s21_vector.Capacity(), vector.capacity());
}   

TEST(Vector, T1Capacity)
{
    s21::Vector<Item> s21_vector { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333) };

    const auto s21_capacity_old = s21_vector.Capacity();
    s21_vector.Reserve(2);

    EXPECT_EQ(s21_vector.Capacity(), s21_capacity_old);
}

TEST(Vector, T2Size)
{
    s21::Vector<Item> s21_vector { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333) };
    EXPECT_EQ(s21_vector.Size(), 3);
}







TEST(Vector, T3Reserve)
{
    s21::Vector<Item> s21_vector { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333) };
    std::vector<Item> vector { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333) };
    
    s21_vector.Reserve(10);
    vector.reserve(10);

    EXPECT_EQ(s21_vector, vector);
    EXPECT_EQ(s21_vector.Capacity(), vector.capacity());
}

TEST(Vector, T4Reserve)
{
    s21::Vector<Item> s21_vector { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333) };
    std::vector<Item> vector { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333) };
    
    s21_vector.Reserve(2);
    vector.reserve(2);

    EXPECT_EQ(s21_vector, vector);
    EXPECT_EQ(s21_vector.Capacity(), vector.capacity());
}

TEST(Vector, T5Reserve)
{
    s21::Vector<Item> s21_vector { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333) };
    std::vector<Item> vector { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333) };
    
    s21_vector.Reserve(0);
    vector.reserve(0);

    EXPECT_EQ(s21_vector, vector);
    EXPECT_EQ(s21_vector.Capacity(), vector.capacity());
}

TEST(Vector, T6Reserve)
{
    s21::Vector<Item> s21_vector { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333) };
    std::vector<Item> vector { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333) };

    const auto s21_capacity = s21_vector.Capacity();
    const auto capacity = vector.capacity();
    s21_vector.Reserve(s21_capacity);
    vector.reserve(capacity);

    EXPECT_EQ(s21_vector, vector);
    EXPECT_EQ(s21_vector.Capacity(), vector.capacity());
}








TEST(Vector, T7Shrink_to_fit)
{
    s21::Vector<Item> s21_vector { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333) };
    std::vector<Item> vector { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333) };


    s21_vector.Pop_back();
    s21_vector.Pop_back();
    vector.pop_back();
    vector.pop_back();

    s21_vector.Shrink_to_fit();
    vector.shrink_to_fit();


    EXPECT_EQ(s21_vector, vector);
    EXPECT_EQ(s21_vector.Capacity(), vector.capacity());
}

TEST(Vector, T8Shrink_to_fit)
{
    s21::Vector<Item> s21_vector { Item(0), Item(11), Item(22, 'b'), Item(33, 'c', 0.3333) };
    std::vector<Item> vector { Item(0), Item(11), Item(22, 'b'), Item(33, 'c', 0.3333) };


    s21_vector.Pop_back();
    s21_vector.Pop_back();
    vector.pop_back();
    vector.pop_back();

    s21_vector.Shrink_to_fit();
    vector.shrink_to_fit();

    EXPECT_EQ(s21_vector, vector);
    EXPECT_EQ(s21_vector.Capacity(), vector.capacity());
    
    s21_vector.Shrink_to_fit();
    vector.shrink_to_fit();

    EXPECT_EQ(s21_vector, vector);
    EXPECT_EQ(s21_vector.Capacity(), vector.capacity());
}



}  // namespace

// GCOVR_EXCL_STOP
