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

TEST(Vector, T26InsertRangeIteratorsEnd)
{
    s21::Vector<Item> source { Item(111111), Item(222222), Item(333333), Item(444444), Item(555555) };
    
    s21::Vector<Item> s21_vector { Item(0), Item(111), Item(222), Item(333) };
    std::vector<Item> vector { Item(0), Item(111), Item(222), Item(333) };

    s21::Vector<Item>::const_iterator s21_it = s21_vector.cend();
    std::vector<Item>::const_iterator it = vector.cend();

    const s21::Vector<Item>::iterator s21_result = s21_vector.Insert(s21_it, source.cbegin(), source.cend());
    const std::vector<Item>::iterator result = vector.insert(it, source.cbegin(), source.cend());

    EXPECT_EQ(s21_vector, vector);
    EXPECT_EQ(*s21_result, *result);
}

TEST(Vector, T27InsertRangeIteratorsEndEmpty)
{
    s21::Vector<Item> source { Item(111111), Item(222222), Item(333333), Item(444444), Item(555555) };

    s21::Vector<Item> s21_vector { Item(0), Item(111), Item(222), Item(333) };
    std::vector<Item> vector { Item(0), Item(111), Item(222), Item(333) };

    s21::Vector<Item>::const_iterator s21_it = s21_vector.cend();
    std::vector<Item>::const_iterator it = vector.cend();

    const s21::Vector<Item>::iterator s21_result = s21_vector.Insert(s21_it, source.cend(), source.cend());
    const std::vector<Item>::iterator result = vector.insert(it, source.cend(), source.cend());

    EXPECT_EQ(s21_vector, vector);
    EXPECT_EQ(s21_result, s21_it);
    EXPECT_EQ(result, it);
}

TEST(Vector, T28InsertRangeIteratorsEndEmpty)
{
    s21::Vector<Item> source { Item(111111), Item(222222), Item(333333), Item(444444), Item(555555) };

    s21::Vector<Item> s21_vector { Item(0), Item(111), Item(222), Item(333) };
    std::vector<Item> vector { Item(0), Item(111), Item(222), Item(333) };

    s21::Vector<Item>::const_iterator s21_it = s21_vector.cend();
    std::vector<Item>::const_iterator it = vector.cend();

    const s21::Vector<Item>::iterator s21_result = s21_vector.Insert(s21_it, source.begin(), source.begin());
    const std::vector<Item>::iterator result = vector.insert(it, source.begin(), source.begin());

    EXPECT_EQ(s21_vector, vector);
    EXPECT_EQ(s21_result, s21_it);
    EXPECT_EQ(result, it);
}

TEST(Vector, T29InsertRangeIterators)
{
    s21::Vector<Item> source { Item(111111), Item(222222), Item(333333), Item(444444), Item(555555) };

    s21::Vector<Item> s21_vector { Item(0), Item(111), Item(222), Item(333) };
    std::vector<Item> vector { Item(0), Item(111), Item(222), Item(333) };

    s21::Vector<Item>::const_iterator s21_it = s21_vector.cbegin() + 1;
    std::vector<Item>::const_iterator it = vector.cbegin() + 1;

    const s21::Vector<Item>::iterator s21_result = s21_vector.Insert(s21_it, source.begin() + 1, source.begin() + 3);
    const std::vector<Item>::iterator result = vector.insert(it, source.begin() + 1, source.begin() + 3);

    EXPECT_EQ(s21_vector, vector);
    EXPECT_EQ(*s21_result, *result);
}

TEST(Vector, T30InsertRangeIteratorsEmptyDestination)
{
    s21::Vector<Item> source { Item(111111), Item(222222), Item(333333), Item(444444), Item(555555) };

    s21::Vector<Item> s21_vector;
    std::vector<Item> vector;

    s21::Vector<Item>::const_iterator s21_it = s21_vector.cbegin();
    std::vector<Item>::const_iterator it = vector.cbegin();

    const s21::Vector<Item>::iterator s21_result = s21_vector.Insert(s21_it, source.begin() + 1, source.begin() + 3);
    const std::vector<Item>::iterator result = vector.insert(it, source.begin() + 1, source.begin() + 3);

    EXPECT_EQ(s21_vector, vector);
    EXPECT_EQ(*s21_result, *result);
}

TEST(Vector, T31InsertRangeIteratorsEmptyDestination)
{
    s21::Vector<Item> source { Item(111111), Item(222222), Item(333333), Item(444444), Item(555555) };

    s21::Vector<Item> s21_vector;
    std::vector<Item> vector;

    s21::Vector<Item>::const_iterator s21_it = s21_vector.cend();
    std::vector<Item>::const_iterator it = vector.cend();

    const s21::Vector<Item>::iterator s21_result = s21_vector.Insert(s21_it, source.begin() + 1, source.begin() + 3);
    const std::vector<Item>::iterator result = vector.insert(it, source.begin() + 1, source.begin() + 3);

    EXPECT_EQ(s21_vector, vector);
    EXPECT_EQ(*s21_result, *result);
}







TEST(Vector, T32InsertInitializer)
{
    s21::Vector<Item> s21_vector { Item(0), Item(111), Item(222), Item(333) };
    std::vector<Item> vector { Item(0), Item(111), Item(222), Item(333) };

    s21::Vector<Item>::const_iterator s21_it = s21_vector.cbegin() + 1;
    std::vector<Item>::const_iterator it = vector.cbegin() + 1;

    const s21::Vector<Item>::iterator s21_result = s21_vector.Insert(s21_it, { Item(111111), Item(222222), Item(333333), Item(444444), Item(555555) });
    const std::vector<Item>::iterator result = vector.insert(it, { Item(111111), Item(222222), Item(333333), Item(444444), Item(555555) });

    EXPECT_EQ(s21_vector, vector);
    EXPECT_EQ(*s21_result, *result);
}

TEST(Vector, T33InsertInitializer)
{
    s21::Vector<Item> s21_vector { Item(0), Item(111), Item(222), Item(333) };
    std::vector<Item> vector { Item(0), Item(111), Item(222), Item(333) };

    s21::Vector<Item>::const_iterator s21_it = s21_vector.cbegin();
    std::vector<Item>::const_iterator it = vector.cbegin();

    const s21::Vector<Item>::iterator s21_result = s21_vector.Insert(s21_it, { Item(111111), Item(222222), Item(333333), Item(444444), Item(555555) });
    const std::vector<Item>::iterator result = vector.insert(it, { Item(111111), Item(222222), Item(333333), Item(444444), Item(555555) });

    EXPECT_EQ(s21_vector, vector);
    EXPECT_EQ(*s21_result, *result);
}

TEST(Vector, T34InsertInitializer)
{
    s21::Vector<Item> s21_vector { Item(0), Item(111), Item(222), Item(333) };
    std::vector<Item> vector { Item(0), Item(111), Item(222), Item(333) };

    s21::Vector<Item>::const_iterator s21_it = s21_vector.cend();
    std::vector<Item>::const_iterator it = vector.cend();

    const s21::Vector<Item>::iterator s21_result = s21_vector.Insert(s21_it, { Item(111111), Item(222222), Item(333333), Item(444444), Item(555555) });
    const std::vector<Item>::iterator result = vector.insert(it, { Item(111111), Item(222222), Item(333333), Item(444444), Item(555555) });

    EXPECT_EQ(s21_vector, vector);
    EXPECT_EQ(*s21_result, *result);
}

TEST(Vector, T35InsertInitializerEmpty)
{
    s21::Vector<Item> s21_vector { Item(0), Item(111), Item(222), Item(333) };
    std::vector<Item> vector { Item(0), Item(111), Item(222), Item(333) };

    s21::Vector<Item>::const_iterator s21_it = s21_vector.cend();
    std::vector<Item>::const_iterator it = vector.cend();

    const s21::Vector<Item>::iterator s21_result = s21_vector.Insert(s21_it, {});
    const std::vector<Item>::iterator result = vector.insert(it, {});

    EXPECT_EQ(s21_vector, vector);
    EXPECT_EQ(s21_result, s21_it);
    EXPECT_EQ(result, it);
}

TEST(Vector, T36InsertInitializerEmpty)
{
    s21::Vector<Item> s21_vector { Item(0), Item(111), Item(222), Item(333) };
    std::vector<Item> vector { Item(0), Item(111), Item(222), Item(333) };

    s21::Vector<Item>::const_iterator s21_it = s21_vector.cbegin();
    std::vector<Item>::const_iterator it = vector.cbegin();

    const s21::Vector<Item>::iterator s21_result = s21_vector.Insert(s21_it, {});
    const std::vector<Item>::iterator result = vector.insert(it, {});

    EXPECT_EQ(s21_vector, vector);
    EXPECT_EQ(*s21_result, *result);
}

TEST(Vector, T37InsertInitializerEmptyDestination)
{
    s21::Vector<Item> s21_vector;
    std::vector<Item> vector;

    s21::Vector<Item>::const_iterator s21_it = s21_vector.cend();
    std::vector<Item>::const_iterator it = vector.cend();

    const s21::Vector<Item>::iterator s21_result = s21_vector.Insert(s21_it, { Item(111111), Item(222222), Item(333333), Item(444444), Item(555555) });
    const std::vector<Item>::iterator result = vector.insert(it, { Item(111111), Item(222222), Item(333333), Item(444444), Item(555555) });

    EXPECT_EQ(s21_vector, vector);
    EXPECT_EQ(*s21_result, *result);
}

TEST(Vector, T38InsertInitializerEmptyDestination)
{
    s21::Vector<Item> s21_vector;
    std::vector<Item> vector;

    s21::Vector<Item>::const_iterator s21_it = s21_vector.cbegin();
    std::vector<Item>::const_iterator it = vector.cbegin();

    const s21::Vector<Item>::iterator s21_result = s21_vector.Insert(s21_it, { Item(111111), Item(222222), Item(333333), Item(444444), Item(555555) });
    const std::vector<Item>::iterator result = vector.insert(it, { Item(111111), Item(222222), Item(333333), Item(444444), Item(555555) });

    EXPECT_EQ(s21_vector, vector);
    EXPECT_EQ(*s21_result, *result);
}

TEST(Vector, T39InsertInitializerEmptyDestination)
{
    s21::Vector<Item> s21_vector;
    std::vector<Item> vector;

    s21::Vector<Item>::const_iterator s21_it = s21_vector.cbegin();
    std::vector<Item>::const_iterator it = vector.cbegin();

    const s21::Vector<Item>::iterator s21_result = s21_vector.Insert(s21_it, {});
    const std::vector<Item>::iterator result = vector.insert(it, {});

    EXPECT_EQ(s21_vector, vector);
    EXPECT_EQ(s21_result, s21_it);
    EXPECT_EQ(result, it);
}

TEST(Vector, T40InsertInitializerEmptyDestination)
{
    s21::Vector<Item> s21_vector;
    std::vector<Item> vector;

    s21::Vector<Item>::const_iterator s21_it = s21_vector.cend();
    std::vector<Item>::const_iterator it = vector.cend();

    const s21::Vector<Item>::iterator s21_result = s21_vector.Insert(s21_it, {});
    const std::vector<Item>::iterator result = vector.insert(it, {});

    EXPECT_EQ(s21_vector, vector);
    EXPECT_EQ(s21_result, s21_it);
    EXPECT_EQ(result, it);
}







TEST(Vector, T41Emplace)
{
    s21::Vector<Item> s21_vector;
    std::vector<Item> vector;

    s21::Vector<Item>::const_iterator s21_it = s21_vector.cend();
    std::vector<Item>::const_iterator it = vector.cend();

    const s21::Vector<Item>::iterator s21_result = s21_vector.Emplace(s21_it, 666, 'x', 0.666);
    const std::vector<Item>::iterator result = vector.emplace(it, 666, 'x', 0.666);

    EXPECT_EQ(s21_vector, vector);
    EXPECT_EQ(*s21_result, *result);
}

TEST(Vector, T42Emplace)
{
    s21::Vector<Item> s21_vector;
    std::vector<Item> vector;

    s21::Vector<Item>::const_iterator s21_it = s21_vector.cbegin();
    std::vector<Item>::const_iterator it = vector.cbegin();

    const s21::Vector<Item>::iterator s21_result = s21_vector.Emplace(s21_it, 666, 'x', 0.666);
    const std::vector<Item>::iterator result = vector.emplace(it, 666, 'x', 0.666);

    EXPECT_EQ(s21_vector, vector);
    EXPECT_EQ(*s21_result, *result);
}

TEST(Vector, T43Emplace)
{
    s21::Vector<Item> s21_vector { Item(0), Item(111), Item(222), Item(333) };
    std::vector<Item> vector { Item(0), Item(111), Item(222), Item(333) };

    s21::Vector<Item>::const_iterator s21_it = s21_vector.cbegin();
    std::vector<Item>::const_iterator it = vector.cbegin();

    const s21::Vector<Item>::iterator s21_result = s21_vector.Emplace(s21_it, 666, 'x', 0.666);
    const std::vector<Item>::iterator result = vector.emplace(it, 666, 'x', 0.666);

    EXPECT_EQ(s21_vector, vector);
    EXPECT_EQ(*s21_result, *result);
}

TEST(Vector, T44Emplace)
{
    s21::Vector<Item> s21_vector { Item(0), Item(111), Item(222), Item(333) };
    std::vector<Item> vector { Item(0), Item(111), Item(222), Item(333) };

    s21::Vector<Item>::const_iterator s21_it = s21_vector.cend();
    std::vector<Item>::const_iterator it = vector.cend();

    const s21::Vector<Item>::iterator s21_result = s21_vector.Emplace(s21_it, 666, 'x', 0.666);
    const std::vector<Item>::iterator result = vector.emplace(it, 666, 'x', 0.666);

    EXPECT_EQ(s21_vector, vector);
    EXPECT_EQ(*s21_result, *result);
}

TEST(Vector, T45Emplace)
{
    s21::Vector<Item> s21_vector { Item(0), Item(111), Item(222), Item(333) };
    std::vector<Item> vector { Item(0), Item(111), Item(222), Item(333) };

    s21::Vector<Item>::const_iterator s21_it = s21_vector.cend() - 2;
    std::vector<Item>::const_iterator it = vector.cend() - 2;

    const s21::Vector<Item>::iterator s21_result = s21_vector.Emplace(s21_it, 666, 'x', 0.666);
    const std::vector<Item>::iterator result = vector.emplace(it, 666, 'x', 0.666);

    EXPECT_EQ(s21_vector, vector);
    EXPECT_EQ(*s21_result, *result);
}

TEST(Vector, T46Emplace)
{
    s21::Vector<Item> s21_vector { Item(0), Item(111), Item(222), Item(333) };
    std::vector<Item> vector { Item(0), Item(111), Item(222), Item(333) };

    s21::Vector<Item>::const_iterator s21_it = s21_vector.cbegin() + 3;
    std::vector<Item>::const_iterator it = vector.cbegin() + 3;

    const s21::Vector<Item>::iterator s21_result = s21_vector.Emplace(s21_it, 666, 'x', 0.666);
    const std::vector<Item>::iterator result = vector.emplace(it, 666, 'x', 0.666);

    EXPECT_EQ(s21_vector, vector);
    EXPECT_EQ(*s21_result, *result);
}

TEST(Vector, T47Emplace)
{
    s21::Vector<Item> s21_vector { Item(0), Item(111), Item(222), Item(333) };
    std::vector<Item> vector { Item(0), Item(111), Item(222), Item(333) };

    s21::Vector<Item>::const_iterator s21_it = s21_vector.cbegin() + 3;
    std::vector<Item>::const_iterator it = vector.cbegin() + 3;

    const s21::Vector<Item>::iterator s21_result = s21_vector.Emplace(s21_it, 666, 'x');
    const std::vector<Item>::iterator result = vector.emplace(it, 666, 'x');

    EXPECT_EQ(s21_vector, vector);
    EXPECT_EQ(*s21_result, *result);
}

TEST(Vector, T48Emplace)
{
    s21::Vector<Item> s21_vector { Item(0), Item(111), Item(222), Item(333) };
    std::vector<Item> vector { Item(0), Item(111), Item(222), Item(333) };

    s21::Vector<Item>::const_iterator s21_it = s21_vector.cbegin() + 3;
    std::vector<Item>::const_iterator it = vector.cbegin() + 3;

    const s21::Vector<Item>::iterator s21_result = s21_vector.Emplace(s21_it, 666);
    const std::vector<Item>::iterator result = vector.emplace(it, 666);

    EXPECT_EQ(s21_vector, vector);
    EXPECT_EQ(*s21_result, *result);
}

TEST(Vector, T49Emplace)
{
    s21::Vector<Item> s21_vector { Item(0), Item(111), Item(222), Item(333) };
    std::vector<Item> vector { Item(0), Item(111), Item(222), Item(333) };

    s21::Vector<Item>::const_iterator s21_it = s21_vector.cbegin() + 3;
    std::vector<Item>::const_iterator it = vector.cbegin() + 3;

    const s21::Vector<Item>::iterator s21_result = s21_vector.Emplace(s21_it);
    const std::vector<Item>::iterator result = vector.emplace(it);

    EXPECT_EQ(s21_vector, vector);
    EXPECT_EQ(*s21_result, *result);
}


TEST(Vector, T50Erase)
{
    s21::Vector<Item> s21_vector { Item(0), Item(111), Item(222), Item(333) };
    // std::vector<Item> vector { Item(0), Item(111), Item(222), Item(333) };

    s21::Vector<Item>::const_iterator s21_it = s21_vector.cbegin();
    // std::vector<Item>::const_iterator it = vector.cbegin();

    const s21::Vector<Item>::iterator s21_result = s21_vector.Erase(s21_it);
    // const std::vector<Item>::iterator result = vector.erase(it);

    // EXPECT_EQ(s21_vector, vector);
    // EXPECT_EQ(*s21_result, *result);
}


}  // namespace

// GCOVR_EXCL_STOP
