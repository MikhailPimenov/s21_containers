#include <gtest/gtest.h>

#include <stack>
#include <list>
#include <vector>
#include <deque>
#include <iterator>


#include "../../s21_vector.h"

#include "../../s21_list.h"
#include "../list_helpers.h"
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





TEST(Vector, T5Insert)
{
    const Item item(666);

    s21::Vector<Item> s21_vector { Item(0), Item(111), Item(222), Item(333) };
    std::vector<Item> vector { Item(0), Item(111), Item(222), Item(333) };


    s21::Vector<Item>::const_iterator s21_it = s21_vector.cbegin() + 1;
    // s21::Vector<Item>::const_iterator s21_it = s21_vector.begin();  // TODO:  так тоже должно работать, но не работает
    std::vector<Item>::const_iterator it = vector.cbegin() + 1;

    const s21::Vector<Item>::iterator s21_result = s21_vector.Insert(s21_it, item);
    const std::vector<Item>::iterator result = vector.insert(it, item);

    EXPECT_EQ(s21_vector, vector);
    EXPECT_EQ(*s21_result, *result);
}

TEST(Vector, T6InsertBegin)
{
    const Item item(666);

    s21::Vector<Item> s21_vector { Item(0), Item(111), Item(222), Item(333) };
    std::vector<Item> vector { Item(0), Item(111), Item(222), Item(333) };


    s21::Vector<Item>::const_iterator s21_it = s21_vector.cbegin();
    std::vector<Item>::const_iterator it = vector.cbegin();

    const s21::Vector<Item>::iterator s21_result = s21_vector.Insert(s21_it, item);
    const std::vector<Item>::iterator result = vector.insert(it, item);

    EXPECT_EQ(s21_vector, vector);
    EXPECT_EQ(*s21_result, *result);
}

TEST(Vector, T7InsertEnd)
{
    const Item item(666);

    s21::Vector<Item> s21_vector { Item(0), Item(111), Item(222), Item(333) };
    std::vector<Item> vector { Item(0), Item(111), Item(222), Item(333) };


    s21::Vector<Item>::const_iterator s21_it = s21_vector.cend();
    std::vector<Item>::const_iterator it = vector.cend();

    const s21::Vector<Item>::iterator s21_result = s21_vector.Insert(s21_it, item);
    const std::vector<Item>::iterator result = vector.insert(it, item);

    EXPECT_EQ(s21_vector, vector);
    EXPECT_EQ(*s21_result, *result);
}

TEST(Vector, T8Insert)
{
    const Item item(666);

    s21::Vector<Item> s21_vector { Item(0), Item(111), Item(222), Item(333) };
    std::vector<Item> vector { Item(0), Item(111), Item(222), Item(333) };


    s21::Vector<Item>::const_iterator s21_it = s21_vector.cend() - 2;
    std::vector<Item>::const_iterator it = vector.cend() - 2;

    const s21::Vector<Item>::iterator s21_result = s21_vector.Insert(s21_it, item);
    const std::vector<Item>::iterator result = vector.insert(it, item);

    EXPECT_EQ(s21_vector, vector);
    EXPECT_EQ(*s21_result, *result);
}

TEST(Vector, T9InsertEmptyBegin)
{
    const Item item(666);

    s21::Vector<Item> s21_vector;
    std::vector<Item> vector;


    s21::Vector<Item>::const_iterator s21_it = s21_vector.cbegin();
    std::vector<Item>::const_iterator it = vector.cbegin();

    const s21::Vector<Item>::iterator s21_result = s21_vector.Insert(s21_it, item);
    const std::vector<Item>::iterator result = vector.insert(it, item);

    EXPECT_EQ(s21_vector, vector);
    EXPECT_EQ(*s21_result, *result);
}

TEST(Vector, T10InsertEmptyEnd)
{
    const Item item(666);

    s21::Vector<Item> s21_vector;
    std::vector<Item> vector;


    s21::Vector<Item>::const_iterator s21_it = s21_vector.cend();
    std::vector<Item>::const_iterator it = vector.cend();

    const s21::Vector<Item>::iterator s21_result = s21_vector.Insert(s21_it, item);
    const std::vector<Item>::iterator result = vector.insert(it, item);

    EXPECT_EQ(s21_vector, vector);
    EXPECT_EQ(*s21_result, *result);
}






TEST(Vector, T11InsertMove)
{
    s21::Vector<Item> s21_vector { Item(0), Item(111), Item(222), Item(333) };
    std::vector<Item> vector { Item(0), Item(111), Item(222), Item(333) };

    s21::Vector<Item>::const_iterator s21_it = s21_vector.cbegin() + 1;
    std::vector<Item>::const_iterator it = vector.cbegin() + 1;

    const s21::Vector<Item>::iterator s21_result = s21_vector.Insert(s21_it, Item(666));
    const std::vector<Item>::iterator result = vector.insert(it, Item(666));

    EXPECT_EQ(s21_vector, vector);
    EXPECT_EQ(*s21_result, *result);
}

TEST(Vector, T12InsertMoveBegin)
{
    s21::Vector<Item> s21_vector { Item(0), Item(111), Item(222), Item(333) };
    std::vector<Item> vector { Item(0), Item(111), Item(222), Item(333) };

    s21::Vector<Item>::const_iterator s21_it = s21_vector.cbegin();
    std::vector<Item>::const_iterator it = vector.cbegin();

    const s21::Vector<Item>::iterator s21_result = s21_vector.Insert(s21_it, Item(666));
    const std::vector<Item>::iterator result = vector.insert(it, Item(666));

    EXPECT_EQ(s21_vector, vector);
    EXPECT_EQ(*s21_result, *result);
}

TEST(Vector, T13InsertMoveEnd)
{
    s21::Vector<Item> s21_vector { Item(0), Item(111), Item(222), Item(333) };
    std::vector<Item> vector { Item(0), Item(111), Item(222), Item(333) };

    s21::Vector<Item>::const_iterator s21_it = s21_vector.cend();
    std::vector<Item>::const_iterator it = vector.cend();

    const s21::Vector<Item>::iterator s21_result = s21_vector.Insert(s21_it, Item(666));
    const std::vector<Item>::iterator result = vector.insert(it, Item(666));

    EXPECT_EQ(s21_vector, vector);
    EXPECT_EQ(*s21_result, *result);
}

TEST(Vector, T14InsertNove)
{
    s21::Vector<Item> s21_vector { Item(0), Item(111), Item(222), Item(333) };
    std::vector<Item> vector { Item(0), Item(111), Item(222), Item(333) };

    s21::Vector<Item>::const_iterator s21_it = s21_vector.cend() - 2;
    std::vector<Item>::const_iterator it = vector.cend() - 2;

    const s21::Vector<Item>::iterator s21_result = s21_vector.Insert(s21_it, Item(666));
    const std::vector<Item>::iterator result = vector.insert(it, Item(666));

    EXPECT_EQ(s21_vector, vector);
    EXPECT_EQ(*s21_result, *result);
}

TEST(Vector, T15InsertMoveEmptyBegin)
{
    const Item item(666);

    s21::Vector<Item> s21_vector;
    std::vector<Item> vector;

    s21::Vector<Item>::const_iterator s21_it = s21_vector.cbegin();
    std::vector<Item>::const_iterator it = vector.cbegin();

    const s21::Vector<Item>::iterator s21_result = s21_vector.Insert(s21_it, Item(666));
    const std::vector<Item>::iterator result = vector.insert(it, Item(666));

    EXPECT_EQ(s21_vector, vector);
    EXPECT_EQ(*s21_result, *result);
}

TEST(Vector, T16InsertMoveEmptyEnd)
{
    s21::Vector<Item> s21_vector;
    std::vector<Item> vector;

    s21::Vector<Item>::const_iterator s21_it = s21_vector.cend();
    std::vector<Item>::const_iterator it = vector.cend();

    const s21::Vector<Item>::iterator s21_result = s21_vector.Insert(s21_it, Item(666));
    const std::vector<Item>::iterator result = vector.insert(it, Item(666));

    EXPECT_EQ(s21_vector, vector);
    EXPECT_EQ(*s21_result, *result);
}










TEST(Vector, T17InsertCount)
{
    s21::Vector<Item> s21_vector { Item(0), Item(111), Item(222), Item(333) };
    std::vector<Item> vector { Item(0), Item(111), Item(222), Item(333) };

    s21::Vector<Item>::const_iterator s21_it = s21_vector.cbegin() + 1;
    std::vector<Item>::const_iterator it = vector.cbegin() + 1;

    const Item item(666);
    const s21::Vector<Item>::iterator s21_result = s21_vector.Insert(s21_it, 1, item);
    const std::vector<Item>::iterator result = vector.insert(it, 1, item);

    EXPECT_EQ(s21_vector, vector);
    EXPECT_EQ(*s21_result, *result);
}

TEST(Vector, T18InsertCount)
{
    s21::Vector<Item> s21_vector { Item(0), Item(111), Item(222), Item(333) };
    std::vector<Item> vector { Item(0), Item(111), Item(222), Item(333) };

    s21::Vector<Item>::const_iterator s21_it = s21_vector.cbegin() + 1;
    std::vector<Item>::const_iterator it = vector.cbegin() + 1;

    const Item item(666);
    const s21::Vector<Item>::iterator s21_result = s21_vector.Insert(s21_it, 2, item);
    const std::vector<Item>::iterator result = vector.insert(it, 2, item);

    EXPECT_EQ(s21_vector, vector);
    EXPECT_EQ(*s21_result, *result);
}

TEST(Vector, T19InsertCount)
{
    s21::Vector<Item> s21_vector { Item(0), Item(111), Item(222), Item(333) };
    std::vector<Item> vector { Item(0), Item(111), Item(222), Item(333) };

    s21::Vector<Item>::const_iterator s21_it = s21_vector.cend() - 2;
    std::vector<Item>::const_iterator it = vector.cend() - 2;

    const Item item(666);
    const s21::Vector<Item>::iterator s21_result = s21_vector.Insert(s21_it, 100, item);
    const std::vector<Item>::iterator result = vector.insert(it, 100, item);

    EXPECT_EQ(s21_vector, vector);
    EXPECT_EQ(*s21_result, *result);
}

TEST(Vector, T20InsertCount)
{
    s21::Vector<Item> s21_vector { Item(0), Item(111), Item(222), Item(333) };
    std::vector<Item> vector { Item(0), Item(111), Item(222), Item(333) };

    s21::Vector<Item>::const_iterator s21_it = s21_vector.cbegin();
    std::vector<Item>::const_iterator it = vector.cbegin();

    const Item item(666);
    const s21::Vector<Item>::iterator s21_result = s21_vector.Insert(s21_it, 100, item);
    const std::vector<Item>::iterator result = vector.insert(it, 100, item);

    EXPECT_EQ(s21_vector, vector);
    EXPECT_EQ(*s21_result, *result);
}

TEST(Vector, T21InsertCount)
{
    s21::Vector<Item> s21_vector { Item(0), Item(111), Item(222), Item(333) };
    std::vector<Item> vector { Item(0), Item(111), Item(222), Item(333) };

    s21::Vector<Item>::const_iterator s21_it = s21_vector.cend();
    std::vector<Item>::const_iterator it = vector.cend();

    const Item item(666);
    const s21::Vector<Item>::iterator s21_result = s21_vector.Insert(s21_it, 100, item);
    const std::vector<Item>::iterator result = vector.insert(it, 100, item);

    EXPECT_EQ(s21_vector, vector);
    EXPECT_EQ(*s21_result, *result);
}

TEST(Vector, T22InsertCountZero)
{
    s21::Vector<Item> s21_vector { Item(0), Item(111), Item(222), Item(333) };
    std::vector<Item> vector { Item(0), Item(111), Item(222), Item(333) };

    s21::Vector<Item>::const_iterator s21_it = s21_vector.cbegin();
    std::vector<Item>::const_iterator it = vector.cbegin();

    const Item item(666);
    const s21::Vector<Item>::iterator s21_result = s21_vector.Insert(s21_it, 0, item);
    const std::vector<Item>::iterator result = vector.insert(it, 0, item);

    EXPECT_EQ(s21_vector, vector);
    EXPECT_EQ(s21_result, s21_it);
    EXPECT_EQ(result, it);
}

TEST(Vector, T23InsertCountZero)
{
    s21::Vector<Item> s21_vector { Item(0), Item(111), Item(222), Item(333) };
    std::vector<Item> vector { Item(0), Item(111), Item(222), Item(333) };

    s21::Vector<Item>::const_iterator s21_it = s21_vector.cend();
    std::vector<Item>::const_iterator it = vector.cend();

    const Item item(666);
    const s21::Vector<Item>::iterator s21_result = s21_vector.Insert(s21_it, 0, item);
    const std::vector<Item>::iterator result = vector.insert(it, 0, item);

    EXPECT_EQ(s21_vector, vector);
    EXPECT_EQ(s21_result, s21_it);
    EXPECT_EQ(result, it);
}

TEST(Vector, T24InsertCountZero)
{
    s21::Vector<Item> s21_vector { Item(0), Item(111), Item(222), Item(333) };
    std::vector<Item> vector { Item(0), Item(111), Item(222), Item(333) };

    s21::Vector<Item>::const_iterator s21_it = s21_vector.cend() - 2;
    std::vector<Item>::const_iterator it = vector.cend() - 2;

    const Item item(666);
    const s21::Vector<Item>::iterator s21_result = s21_vector.Insert(s21_it, 0, item);
    const std::vector<Item>::iterator result = vector.insert(it, 0, item);

    EXPECT_EQ(s21_vector, vector);
    EXPECT_EQ(s21_result, s21_it);
    EXPECT_EQ(result, it);
}










TEST(Vector, T25InsertRangeIterators)
{
    const s21::List<Item> source { Item(111111), Item(222222), Item(333333), Item(444444), Item(555555) };

    s21::Vector<Item> s21_vector { Item(0), Item(111), Item(222), Item(333) };
    std::vector<Item> vector { Item(0), Item(111), Item(222), Item(333) };

    s21::Vector<Item>::const_iterator s21_it = s21_vector.cend() - 2;
    std::vector<Item>::const_iterator it = vector.cend() - 2;

    const s21::Vector<Item>::iterator s21_result = s21_vector.Insert(s21_it, source.cbegin(), source.cend());
    const std::vector<Item>::iterator result = vector.insert(it, source.cbegin(), source.cend());

    EXPECT_EQ(s21_vector, vector);
    EXPECT_EQ(*s21_result, *result);
}

TEST(Vector, T26InsertRangeIterators)
{
    s21::Vector<Item> source { Item(111111), Item(222222), Item(333333), Item(444444), Item(555555) };
    using IterVector = s21::Vector<Item>::const_iterator;
    static_assert(std::is_same_v<std::iterator_traits<IterVector>::iterator_category, 
                             std::random_access_iterator_tag>);
    static_assert(std::is_same_v<std::iterator_traits<IterVector>::value_type, 
                             Item>);
    using IterList = s21::List<Item>::const_iterator;
    static_assert(std::is_same_v<std::iterator_traits<IterList>::iterator_category, 
                             std::bidirectional_iterator_tag>);
    
    
    // s21::Vector<Item>::iterator::iterator_category a;
    // std::iterator_traits<s21::VectorIterator<s21::Vector<Item>, const Item*, const Item&>>::
    s21::Vector<Item> s21_vector { Item(0), Item(111), Item(222), Item(333) };
    std::vector<Item> vector { Item(0), Item(111), Item(222), Item(333) };

    s21::Vector<Item>::const_iterator s21_it = s21_vector.cend() - 2;
    std::vector<Item>::const_iterator it = vector.cend() - 2;

    const s21::Vector<Item>::iterator s21_result = s21_vector.Insert(s21_it, source.cbegin(), source.cend());
    const std::vector<Item>::iterator result = vector.insert(it, source.cbegin(), source.cend());

    EXPECT_EQ(s21_vector, vector);
    EXPECT_EQ(*s21_result, *result);
}

TEST(Vector, T27InsertRangeIterators)
{
    s21::List<Item> source { Item(111111), Item(222222), Item(333333), Item(444444), Item(555555) };

    s21::List<Item> s21_vector { Item(0), Item(111), Item(222), Item(333) };
    std::list<Item> vector { Item(0), Item(111), Item(222), Item(333) };

    s21::List<Item>::const_iterator s21_it = s21_vector.cend();
    std::list<Item>::const_iterator it = vector.cend();

    const s21::List<Item>::iterator s21_result = s21_vector.Insert(s21_it, source.cbegin(), source.cend());
    const std::list<Item>::iterator result = vector.insert(it, source.cbegin(), source.cend());

    EXPECT_EQ(s21_vector, vector);
    EXPECT_EQ(*s21_result, *result);
}

// TEST(Vector, T15InsertMoveEmptyBegin)
// {
//     const Item item(666);

//     s21::Vector<Item> s21_vector;
//     std::vector<Item> vector;


//     s21::Vector<Item>::const_iterator s21_it = s21_vector.cbegin();
//     std::vector<Item>::const_iterator it = vector.cbegin();

//     const s21::Vector<Item>::iterator s21_result = s21_vector.Insert(s21_it, Item(666));
//     const std::vector<Item>::iterator result = vector.insert(it, Item(666));

//     EXPECT_EQ(s21_vector, vector);
//     EXPECT_EQ(*s21_result, *result);
// }

// TEST(Vector, T16InsertMoveEmptyEnd)
// {
//     s21::Vector<Item> s21_vector;
//     std::vector<Item> vector;

//     s21::Vector<Item>::const_iterator s21_it = s21_vector.cend();
//     std::vector<Item>::const_iterator it = vector.cend();

//     const s21::Vector<Item>::iterator s21_result = s21_vector.Insert(s21_it, Item(666));
//     const std::vector<Item>::iterator result = vector.insert(it, Item(666));

//     EXPECT_EQ(s21_vector, vector);
//     EXPECT_EQ(*s21_result, *result);
// }



















}  // namespace

// GCOVR_EXCL_STOP
