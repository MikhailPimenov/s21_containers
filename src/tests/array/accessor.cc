#include <gtest/gtest.h>

#include <array>
#include "../../s21_array.h"

#include "../item.h"
#include "../array_helpers.h"

// GCOVR_EXCL_START

namespace
{

TEST(Array, T0Operator)
{
    s21::Array<int, 3> s21_array { 3, 5, 7 };
    std::array<int, 3> array { 3, 5, 7 };

    EXPECT_EQ(s21_array[0], array[0]);
}

TEST(Vector, T1Operator)
{
    s21::Array<double, 4> s21_array { 3.5, 8.77, 9.65, 8.08 };
    std::array<double, 4> array { 3.5, 8.77, 9.65, 8.08 };

    EXPECT_EQ(s21_array[1], array[1]);
}

TEST(Vector, T2Operator)
{
    s21::Array<Item, 3> s21_array { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333) };
    std::array<Item, 3> array { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333) };

    EXPECT_EQ(s21_array[2], array[2]);
}

/*TEST(Vector, T3Operator)
{
    s21::Vector<Item> s21_vector { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333) };
    std::vector<Item> vector { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333) };

    const Item item(666, 'h', 0.666666);
    s21_vector[0]   = item;
    vector[0]       = item;
    EXPECT_EQ(s21_vector, vector);
}

TEST(Vector, T4Operator)
{
    s21::Vector<Item> s21_vector { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333) };
    std::vector<Item> vector { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333) };

    const Item item(666, 'h', 0.666666);
    s21_vector[1]   = item;
    vector[1]       = item;
    EXPECT_EQ(s21_vector, vector);
}

TEST(Vector, T5Operator)
{
    s21::Vector<Item> s21_vector { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333) };
    std::vector<Item> vector { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333) };

    const Item item(666, 'h', 0.666666);
    s21_vector[2]   = item;
    vector[2]       = item;
    EXPECT_EQ(s21_vector, vector);
}







TEST(Vector, T6Operator)
{
    const s21::Vector<Item> s21_vector { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333) };
    const std::vector<Item> vector { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333) };

    EXPECT_EQ(s21_vector[0], vector[0]);
}

TEST(Vector, T7Operator)
{
    const s21::Vector<Item> s21_vector { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333) };
    const std::vector<Item> vector { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333) };

    EXPECT_EQ(s21_vector[1], vector[1]);
}

TEST(Vector, T8Operator)
{
    const s21::Vector<Item> s21_vector { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333) };
    const std::vector<Item> vector { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333) };

    EXPECT_EQ(s21_vector[2], vector[2]);
}






TEST(Vector, T9At)
{
    const s21::Vector<Item> s21_vector { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333) };
    const std::vector<Item> vector { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333) };

    EXPECT_EQ(s21_vector.At(0), vector.at(0));
}

TEST(Vector, T10At)
{
    const s21::Vector<Item> s21_vector { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333) };
    const std::vector<Item> vector { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333) };

    EXPECT_EQ(s21_vector.At(1), vector.at(1));
}

TEST(Vector, T11At)
{
    const s21::Vector<Item> s21_vector { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333) };
    const std::vector<Item> vector { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333) };

    EXPECT_EQ(s21_vector.At(2), vector.at(2));
}

TEST(Vector, T12AtOutOfRange)
{
    const s21::Vector<Item> s21_vector { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333) };
    const std::vector<Item> vector { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333) };

    EXPECT_THROW(s21_vector.At(99), std::out_of_range);
}




TEST(Vector, T13At)
{
    s21::Vector<Item> s21_vector { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333) };
    std::vector<Item> vector { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333) };

    const Item item0(6666, 'h', 0.666666);
    const Item item1(7777, 'j', 0.777777);
    const Item item2(8888, 'k', 0.888888);
    s21_vector.At(0) = item0;
    s21_vector.At(1) = item1;
    s21_vector.At(2) = item2;
    vector.at(0) = item0;
    vector.at(1) = item1;
    vector.at(2) = item2;

    EXPECT_EQ(s21_vector.At(0), vector.at(0));
    EXPECT_EQ(s21_vector, vector);
}

TEST(Vector, T14AtOutOfRange)
{
    s21::Vector<Item> s21_vector { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333) };

    const Item item0(6666, 'h', 0.666666);
    EXPECT_THROW(s21_vector.At(99) = item0, std::out_of_range);
}

TEST(Vector, T15AtOutOfRange)
{
    const s21::Vector<Item> s21_vector { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333) };

    EXPECT_THROW(s21_vector.At(99), std::out_of_range);
}









TEST(Vector, T16At)
{
    s21::Vector<Item> s21_vector { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333) };
    std::vector<Item> vector { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333) };

    EXPECT_EQ(s21_vector.At(0), vector.at(0));
}

TEST(Vector, T17At)
{
    s21::Vector<Item> s21_vector { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333) };
    std::vector<Item> vector { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333) };

    EXPECT_EQ(s21_vector.At(1), vector.at(1));
}

TEST(Vector, T18At)
{
    s21::Vector<Item> s21_vector { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333) };
    std::vector<Item> vector { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333) };

    EXPECT_EQ(s21_vector.At(2), vector.at(2));
}

TEST(Vector, T19AtOutOfRange)
{
    s21::Vector<Item> s21_vector { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333) };
    EXPECT_THROW(s21_vector.At(10), std::out_of_range);
}

TEST(Vector, T20AtOutOfRange)
{
    s21::Vector<Item> s21_vector { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333) };
    EXPECT_THROW(s21_vector.At(-1), std::out_of_range);
}

TEST(Vector, T21AtOutOfRange)
{
    s21::Vector<Item> s21_vector { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333) };
    EXPECT_THROW(s21_vector.At(123), std::out_of_range);
}











TEST(Vector, T22Front)
{
    const s21::Vector<Item> s21_vector { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333) };
    const std::vector<Item> vector { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333) };

    EXPECT_EQ(s21_vector.Front(), vector.front());
}

TEST(Vector, T23Front)
{
    s21::Vector<Item> s21_vector { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333) };
    std::vector<Item> vector { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333) };

    s21_vector.Front() = Item(666);
    vector.front() = Item(666);

    EXPECT_EQ(s21_vector, vector);
}









TEST(Vector, T24Back)
{
    const s21::Vector<Item> s21_vector { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333) };
    const std::vector<Item> vector { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333) };

    EXPECT_EQ(s21_vector.Back(), vector.back());
}   

TEST(Vector, T25Back)
{
    s21::Vector<Item> s21_vector { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333) };
    std::vector<Item> vector { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333) };

    s21_vector.Back() = Item(666);
    vector.back() = Item(666);

    EXPECT_EQ(s21_vector, vector);
}









TEST(Vector, T26Data)
{
    const s21::Vector<Item> s21_vector { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333) };
    const std::vector<Item> vector { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333) };

    const Item* s21_data = s21_vector.Data();
    const Item* data = vector.data();

    EXPECT_EQ(s21_data[0], data[0]);
    EXPECT_EQ(s21_data[1], data[1]);
    EXPECT_EQ(s21_data[2], data[2]);
}   

TEST(Vector, T27Data)
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
}   */



}  // namespace

// GCOVR_EXCL_STOP
