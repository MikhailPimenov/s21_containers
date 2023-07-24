#include <gtest/gtest.h>

#include <vector>
#include "../../s21_vector.h"

#include "../item.h"
#include "../vector_helpers.h"

// GCOVR_EXCL_START

namespace
{

TEST(Vector, T0Operator)
{
    s21::Vector<Item> s21_vector { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333) };
    std::vector<Item> vector { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333) };

    EXPECT_EQ(s21_vector[0], vector[0]);
}

TEST(Vector, T1Operator)
{
    s21::Vector<Item> s21_vector { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333) };
    std::vector<Item> vector { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333) };

    EXPECT_EQ(s21_vector[1], vector[1]);
}

TEST(Vector, T2Operator)
{
    s21::Vector<Item> s21_vector { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333) };
    std::vector<Item> vector { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333) };

    EXPECT_EQ(s21_vector[2], vector[2]);
}










TEST(Vector, T3At)
{
    s21::Vector<Item> s21_vector { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333) };
    std::vector<Item> vector { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333) };

    EXPECT_EQ(s21_vector.At(0), vector.at(0));
}

TEST(Vector, T4At)
{
    s21::Vector<Item> s21_vector { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333) };
    std::vector<Item> vector { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333) };

    EXPECT_EQ(s21_vector.At(1), vector.at(1));
}

TEST(Vector, T5At)
{
    s21::Vector<Item> s21_vector { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333) };
    std::vector<Item> vector { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333) };

    EXPECT_EQ(s21_vector.At(2), vector.at(2));
}

TEST(Vector, T6AtOutOfRange)
{
    s21::Vector<Item> s21_vector { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333) };
    EXPECT_THROW(s21_vector.At(10), std::out_of_range);
}

TEST(Vector, T7AtOutOfRange)
{
    s21::Vector<Item> s21_vector { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333) };
    EXPECT_THROW(s21_vector.At(-1), std::out_of_range);
}

TEST(Vector, T8AtOutOfRange)
{
    s21::Vector<Item> s21_vector { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333) };
    EXPECT_THROW(s21_vector.At(123), std::out_of_range);
}











TEST(Vector, T9Front)
{
    const s21::Vector<Item> s21_vector { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333) };
    const std::vector<Item> vector { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333) };

    EXPECT_EQ(s21_vector.Front(), vector.front());
}

TEST(Vector, T10Front)
{
    s21::Vector<Item> s21_vector { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333) };
    std::vector<Item> vector { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333) };

    s21_vector.Front() = Item(666);
    vector.front() = Item(666);

    EXPECT_EQ(s21_vector, vector);
}









TEST(Vector, T10Back)
{
    const s21::Vector<Item> s21_vector { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333) };
    const std::vector<Item> vector { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333) };

    EXPECT_EQ(s21_vector.Back(), vector.back());
}   

TEST(Vector, T11Back)
{
    s21::Vector<Item> s21_vector { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333) };
    std::vector<Item> vector { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333) };

    s21_vector.Back() = Item(666);
    vector.back() = Item(666);

    EXPECT_EQ(s21_vector, vector);
}









TEST(Vector, T12Data)
{
    const s21::Vector<Item> s21_vector { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333) };
    const std::vector<Item> vector { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333) };

    const Item* s21_data = s21_vector.Data();
    const Item* data = vector.data();

    EXPECT_EQ(s21_data[0], data[0]);
    EXPECT_EQ(s21_data[1], data[1]);
    EXPECT_EQ(s21_data[2], data[2]);
}   

TEST(Vector, T13Data)
{
    s21::Vector<Item> s21_vector { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333) };
    std::vector<Item> vector { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333) };

    Item* s21_data = s21_vector.Data();
    Item* data = vector.data();

    s21_data[1] = Item(666);
    data[1] = Item(666);

    EXPECT_EQ(s21_data[0], data[0]);
    EXPECT_EQ(s21_data[1], data[1]);
    EXPECT_EQ(s21_data[2], data[2]);
}   



}  // namespace

// GCOVR_EXCL_STOP
