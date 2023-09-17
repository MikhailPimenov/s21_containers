#include <gtest/gtest.h>

#include <array>
#include "../../s21_array.h"

#include "../item.h"
#include "../array_helpers.h"

// GCOVR_EXCL_START

namespace
{

TEST(Array, T0OperatorEqual)
{
    s21::Array<Item, 4> s21_source { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333), Item(44, 'd', 0.44444) };
    std::array<Item, 4> source { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333), Item(44, 'd', 0.44444) };
    
    EXPECT_EQ(s21_source, source);
}   

TEST(Array, T1OperatorEqual)
{
    s21::Array<Item, 4> s21_source { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333), Item(44, 'd', 0.44444) };
    std::array<Item, 4> source { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333), Item(55, 'e', 0.55555555) };  

    EXPECT_NE(s21_source, source);
}   

TEST(Array, T2OperatorEqual)
{
    s21::Array<Item, 4> s21_source { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333), Item(44, 'd', 0.44444) };
    std::array<Item, 4> source { Item(6666), Item(22, 'b'), Item(33, 'c', 0.3333), Item(44, 'd', 0.44444) };

    EXPECT_TRUE(s21_source != source);
}   

TEST(Array, T2OperatorEqual)
{
    s21::Array<Item, 4> s21_source { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333), Item(44, 'd', 0.44444) };
    std::array<Item, 3> source { Item(6666), Item(22, 'b'), Item(44, 'd', 0.44444) };

    EXPECT_TRUE(s21_source != source);
} 

TEST(Vector, T4OperatorEqual)
{
    s21::Array<Item, 4> s21_source { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333), Item(44, 'd', 0.44444) };
    s21::Array<Item, 4> source { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333), Item(44, 'd', 0.44444), Item(55, 'e', 0.55555555) };
    
    s21::Array<Item, 4> s21_vector(s21_source.begin(), s21_source.end());
    s21::Array<Item, 4> vector(source.begin(), source.end());

    EXPECT_FALSE(s21_vector == vector);
}   

TEST(Vector, T5OperatorEqual)
{
    s21::Array<Item, 4> s21_source { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333), Item(44, 'd', 0.44444) };
    s21::Array<Item, 4> source { Item(6666), Item(22, 'b'), Item(33, 'c', 0.3333), Item(44, 'd', 0.44444) };
    
    s21::Array<Item, 4> s21_vector(s21_source.begin(), s21_source.end());
    s21::Array<Item, 4> vector(source.begin(), source.end());

    EXPECT_FALSE(s21_vector == vector);
}   



TEST(Vector, T6OperatorNotEqual)
{
    s21::Array<Item, 4> s21_source { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333), Item(44, 'd', 0.44444) };
    s21::Array<Item, 4> source { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333), Item(44, 'd', 0.44444) };
    
    s21::Array<Item, 4> s21_vector(s21_source.begin(), s21_source.end());
    s21::Array<Item, 4> vector(source.begin(), source.end());

    EXPECT_FALSE(s21_vector != vector);
}   

TEST(Vector, T7OperatorNotEqual)
{
    s21::Array<Item, 4> s21_source { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333), Item(44, 'd', 0.44444) };
    s21::Array<Item, 4> source { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333), Item(44, 'd', 0.44444), Item(55, 'e', 0.55555555) };
    
    s21::Array<Item, 4> s21_vector(s21_source.begin(), s21_source.end());
    s21::Array<Item, 4> vector(source.begin(), source.end());

    EXPECT_TRUE(s21_vector != vector);
}   

TEST(Vector, T8OperatorNotEqual)
{
    s21::Array<Item, 4> s21_source { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333), Item(44, 'd', 0.44444) };
    s21::Array<Item, 4> source { Item(6666), Item(22, 'b'), Item(33, 'c', 0.3333), Item(44, 'd', 0.44444) };
    
    s21_vector= s21_source.begin();//, s21_source.end());
     vector= source.begin();//, source.end());

    EXPECT_TRUE(s21_vector != vector);
}   


TEST(Array, T0Swap0)
{
    s21::Array<Item, 9> s21_array1 { Item(0), Item(111), Item(222, 'q', 0.222), Item(333), Item(444), Item(555), Item(666), Item(777), Item(888) };
    s21::Array<Item, 9> s21_array2 { Item(0), Item(111), Item(222), Item(333), Item(444), Item(555), Item(666), Item(777), Item(888) };
    
    const s21::Array<Item, 9> s21_array1_copy = s21_array1;
    const s21::Array<Item, 9> s21_array2_copy = s21_array2;

    s21_array1.Swap(s21_array2);

    EXPECT_EQ(s21_array1, s21_array2_copy);
    EXPECT_EQ(s21_array2, s21_array1_copy);
}


}  // namespace

// GCOVR_EXCL_STOP
