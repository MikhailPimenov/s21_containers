#include <gtest/gtest.h>

#include <vector>
#include "../../s21_vector.h"

#include "../item.h"
#include "../vector_helpers.h"

// GCOVR_EXCL_START

namespace
{

TEST(Vector, T0Iterator)
{
    s21::Vector<Item> s21_source { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333), Item(44, 'd', 0.44444) };
    std::vector<Item> source { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333), Item(44, 'd', 0.44444) };
    
    s21::Vector<Item> s21_vector(s21_source.begin(), s21_source.end());
    std::vector<Item> vector(source.begin(), source.end());

    EXPECT_EQ(s21_vector, vector);
}   

TEST(Vector, T1ConstIterator)
{
    const s21::Vector<Item> s21_source { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333), Item(44, 'd', 0.44444) };
    const std::vector<Item> source { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333), Item(44, 'd', 0.44444) };
    
    s21::Vector<Item> s21_vector(s21_source.begin(), s21_source.end());
    std::vector<Item> vector(source.begin(), source.end());

    EXPECT_EQ(s21_vector, vector);
}   



TEST(Vector, T2ConstCIterator)
{
    const s21::Vector<Item> s21_source { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333), Item(44, 'd', 0.44444) };
    const std::vector<Item> source { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333), Item(44, 'd', 0.44444) };
    
    s21::Vector<Item> s21_vector(s21_source.cbegin(), s21_source.cend());
    std::vector<Item> vector(source.cbegin(), source.cend());

    EXPECT_EQ(s21_vector, vector);
}   




TEST(Vector, T3ReverseIterator)
{
    s21::Vector<Item> s21_source { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333), Item(44, 'd', 0.44444) };
    std::vector<Item> source { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333), Item(44, 'd', 0.44444) };
    
    s21::Vector<Item> s21_vector(s21_source.rbegin(), s21_source.rend());
    std::vector<Item> vector(source.rbegin(), source.rend());

    EXPECT_EQ(s21_vector, vector);
}   

TEST(Vector, T4ReverseConstIterator)
{
    const s21::Vector<Item> s21_source { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333), Item(44, 'd', 0.44444) };
    const std::vector<Item> source { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333), Item(44, 'd', 0.44444) };
    
    s21::Vector<Item> s21_vector(s21_source.rbegin(), s21_source.rend());
    std::vector<Item> vector(source.rbegin(), source.rend());

    EXPECT_EQ(s21_vector, vector);
}   



TEST(Vector, T5ReverseConstCIterator)
{
    const s21::Vector<Item> s21_source { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333), Item(44, 'd', 0.44444) };
    const std::vector<Item> source { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333), Item(44, 'd', 0.44444) };
    
    s21::Vector<Item> s21_vector(s21_source.crbegin(), s21_source.crend());
    std::vector<Item> vector(source.crbegin(), source.crend());

    EXPECT_EQ(s21_vector, vector);
}   







TEST(Vector, T6IteratorOperatorPlus)
{
    s21::Vector<Item> s21_source { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333), Item(44, 'd', 0.44444) };
    std::vector<Item> source { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333), Item(44, 'd', 0.44444) };
    
    s21::Vector<Item> s21_vector(++s21_source.begin(), s21_source.end());
    std::vector<Item> vector(++source.begin(), source.end());

    EXPECT_EQ(s21_vector, vector);
} 
TEST(Vector, T7IteratorOperatorPlusPostfix)
{
    s21::Vector<Item> s21_source { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333), Item(44, 'd', 0.44444) };
    std::vector<Item> source { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333), Item(44, 'd', 0.44444) };
    
    s21::Vector<Item> s21_vector(s21_source.begin()++, s21_source.end());
    std::vector<Item> vector(source.begin()++, source.end());

    EXPECT_EQ(s21_vector, vector);
} 
TEST(Vector, T7IteratorOperatorMinus)
{
    s21::Vector<Item> s21_source { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333), Item(44, 'd', 0.44444) };
    std::vector<Item> source { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333), Item(44, 'd', 0.44444) };
    
    s21::Vector<Item> s21_vector(s21_source.begin(), --s21_source.end());
    std::vector<Item> vector(source.begin(), --source.end());

    EXPECT_EQ(s21_vector, vector);
} 
TEST(Vector, T7IteratorOperatorMinusPostfix)
{
    s21::Vector<Item> s21_source { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333), Item(44, 'd', 0.44444) };
    std::vector<Item> source { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333), Item(44, 'd', 0.44444) };
    
    s21::Vector<Item> s21_vector(s21_source.begin(), s21_source.end()--);
    std::vector<Item> vector(source.begin(), source.end()--);

    EXPECT_EQ(s21_vector, vector);
} 
TEST(Vector, T8IteratorOperatorPlus)
{
    s21::Vector<Item> s21_source { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333), Item(44, 'd', 0.44444) };
    std::vector<Item> source { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333), Item(44, 'd', 0.44444) };
    
    s21::Vector<Item>::iterator s21_it = s21_source.begin();
    std::vector<Item>::iterator it = source.begin();

    EXPECT_EQ(*s21_it, *it);
    EXPECT_EQ(*(++s21_it), *(++it));
    EXPECT_EQ(*s21_it, *it);

} 
TEST(Vector, T9IteratorOperatorPlusPostfix)
{
    s21::Vector<Item> s21_source { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333), Item(44, 'd', 0.44444) };
    std::vector<Item> source { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333), Item(44, 'd', 0.44444) };
    
    s21::Vector<Item>::iterator s21_it = s21_source.begin();
    std::vector<Item>::iterator it = source.begin();

    EXPECT_EQ(*s21_it, *it);
    EXPECT_EQ(*(s21_it++), *(it++));
    EXPECT_EQ(*s21_it, *it);
} 
TEST(Vector, T10IteratorOperatorMinus)
{
    s21::Vector<Item> s21_source { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333), Item(44, 'd', 0.44444) };
    std::vector<Item> source { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333), Item(44, 'd', 0.44444) };
    
    s21::Vector<Item>::iterator s21_it = s21_source.end() - 1;
    std::vector<Item>::iterator it = source.end() - 1;

    EXPECT_EQ(*s21_it, *it);
    EXPECT_EQ(*(--s21_it), *(--it));
    EXPECT_EQ(*s21_it, *it);

} 
TEST(Vector, T11IteratorOperatorMinusPostfix)
{
    s21::Vector<Item> s21_source { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333), Item(44, 'd', 0.44444) };
    std::vector<Item> source { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333), Item(44, 'd', 0.44444) };
    
    s21::Vector<Item>::iterator s21_it = s21_source.end() - 1;
    std::vector<Item>::iterator it = source.end() - 1;

    EXPECT_EQ(*s21_it, *it);
    EXPECT_EQ(*(s21_it--), *(it--));
    EXPECT_EQ(*s21_it, *it);
} 







}  // namespace

// GCOVR_EXCL_STOP
