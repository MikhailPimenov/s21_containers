#include <gtest/gtest.h>

#include <list>

#include "../../s21_list.h"
#include "../item.h"
#include "../list_helpers.h"

//  GCOVR_EXCL_START

namespace
{
TEST(List, T0Erase)
{
    s21::List<Item> s21_list = {
        Item(11), Item(22), Item(33), Item(44), Item(55), Item(66),
    };
    std::list<Item> list = {
        Item(11), Item(22), Item(33), Item(44), Item(55), Item(66),
    };

    s21::List<Item>::const_iterator s21_pos = s21_list.cbegin();
    ++s21_pos;
    ++s21_pos;
    const auto s21_it = s21_list.Erase(s21_pos);

    std::list<Item>::const_iterator pos = list.cbegin();
    ++pos;
    ++pos;
    const auto it = list.erase(pos);

    EXPECT_TRUE(s21_list == list);
    EXPECT_TRUE(*s21_it == *it);
}

TEST(List, T1Erase)
{
    s21::List<Item> s21_list = {
        Item(11), Item(22), Item(33), Item(44), Item(55), Item(66),
    };
    std::list<Item> list = {
        Item(11), Item(22), Item(33), Item(44), Item(55), Item(66),
    };

    s21::List<Item>::const_iterator s21_pos = s21_list.cend();
    --s21_pos;
    --s21_pos;
    const auto s21_it = s21_list.Erase(s21_pos);

    std::list<Item>::const_iterator pos = list.cend();
    --pos;
    --pos;
    const auto it = list.erase(pos);

    EXPECT_TRUE(s21_list == list);
    EXPECT_TRUE(*s21_it == *it);
}

TEST(List, T2EraseBegin)
{
    s21::List<Item> s21_list = {
        Item(11), Item(22), Item(33), Item(44), Item(55), Item(66),
    };
    std::list<Item> list = {
        Item(11), Item(22), Item(33), Item(44), Item(55), Item(66),
    };

    s21::List<Item>::const_iterator s21_pos = s21_list.cbegin();
    const auto s21_it = s21_list.Erase(s21_pos);

    std::list<Item>::const_iterator pos = list.cbegin();
    const auto it = list.erase(pos);

    EXPECT_TRUE(s21_list == list);
    EXPECT_TRUE(*s21_it == *it);
}

TEST(List, T3EraseEnd)
{
    s21::List<Item> s21_list = {
        Item(11), Item(22), Item(33), Item(44), Item(55), Item(66),
    };
    std::list<Item> list = {
        Item(11), Item(22), Item(33), Item(44), Item(55), Item(66),
    };

    s21::List<Item>::const_iterator s21_pos = s21_list.cend();
    const auto s21_it = s21_list.Erase(--s21_pos);

    std::list<Item>::const_iterator pos = list.cend();
    const auto it = list.erase(--pos);

    EXPECT_TRUE(s21_list == list);
    EXPECT_TRUE(s21_it == s21_list.cend());
    EXPECT_TRUE(it == list.cend());
}

// TEST(List, T4Erase)
// {
//     s21::List<Item> s21_list = {
//         Item(11), Item(22), Item(33), Item(44), Item(55), Item(66),
//     };
//     std::list<Item> list = {
//         Item(11), Item(22), Item(33), Item(44), Item(55), Item(66),
//     };

//     s21::List<Item>::const_iterator s21_pos = s21_list.cbegin();
//     ++s21_pos;
//     ++s21_pos;
//     const auto s21_it = s21_list.Insert(s21_pos, 7, Item(666));

//     std::list<Item>::const_iterator pos = list.cbegin();
//     ++pos;
//     ++pos;
//     const auto it = list.insert(pos, 7, Item(666));

//     EXPECT_TRUE(s21_list == list);
//     EXPECT_TRUE(*s21_it == *it);
// }

// TEST(List, T5InsertPosCountValue)
// {
//     s21::List<Item> s21_list = {
//         Item(11), Item(22), Item(33), Item(44), Item(55), Item(66),
//     };
//     std::list<Item> list = {
//         Item(11), Item(22), Item(33), Item(44), Item(55), Item(66),
//     };

//     s21::List<Item>::const_iterator s21_pos = s21_list.cend();
//     --s21_pos;
//     --s21_pos;
//     const auto s21_it = s21_list.Insert(s21_pos, 7, Item(666));

//     std::list<Item>::const_iterator pos = list.cend();
//     --pos;
//     --pos;
//     const auto it = list.insert(pos, 7, Item(666));

//     EXPECT_TRUE(s21_list == list);
//     EXPECT_TRUE(*s21_it == *it);
// }

// TEST(List, T6InsertPosCountValueBegin)
// {
//     s21::List<Item> s21_list = {
//         Item(11), Item(22), Item(33), Item(44), Item(55), Item(66),
//     };
//     std::list<Item> list = {
//         Item(11), Item(22), Item(33), Item(44), Item(55), Item(66),
//     };

//     s21::List<Item>::const_iterator s21_pos = s21_list.cbegin();
//     const auto s21_it = s21_list.Insert(s21_pos, 7, Item(666));

//     std::list<Item>::const_iterator pos = list.cbegin();
//     const auto it = list.insert(pos, 7, Item(666));

//     EXPECT_TRUE(s21_list == list);
//     EXPECT_TRUE(*s21_it == *it);
// }

// TEST(List, T7InsertPosValueEnd)
// {
//     s21::List<Item> s21_list = {
//         Item(11), Item(22), Item(33), Item(44), Item(55), Item(66),
//     };
//     std::list<Item> list = {
//         Item(11), Item(22), Item(33), Item(44), Item(55), Item(66),
//     };

//     s21::List<Item>::const_iterator s21_pos = s21_list.cend();
//     const auto s21_it = s21_list.Insert(s21_pos, 7, Item(666));

//     std::list<Item>::const_iterator pos = list.cend();
//     const auto it = list.insert(pos, 7, Item(666));

//     EXPECT_TRUE(s21_list == list);
//     EXPECT_TRUE(*s21_it == *it);
// }

// TEST(List, T8InsertPosCountValue)
// {
//     s21::List<Item> s21_list = {
//         Item(11), Item(22), Item(33), Item(44), Item(55), Item(66),
//     };
//     std::list<Item> list = {
//         Item(11), Item(22), Item(33), Item(44), Item(55), Item(66),
//     };

//     s21::List<Item>::const_iterator s21_pos = s21_list.cbegin();
//     ++s21_pos;
//     ++s21_pos;
//     const auto s21_it = s21_list.Insert(s21_pos, 0, Item(666));

//     std::list<Item>::const_iterator pos = list.cbegin();
//     ++pos;
//     ++pos;
//     const auto it = list.insert(pos, 0, Item(666));

//     EXPECT_TRUE(s21_list == list);
//     EXPECT_TRUE(*s21_it == *it);
// }

// TEST(List, T9InsertPosCountValue)
// {
//     s21::List<Item> s21_list = {
//         Item(11), Item(22), Item(33), Item(44), Item(55), Item(66),
//     };
//     std::list<Item> list = {
//         Item(11), Item(22), Item(33), Item(44), Item(55), Item(66),
//     };

//     s21::List<Item>::const_iterator s21_pos = s21_list.cend();
//     --s21_pos;
//     --s21_pos;
//     const auto s21_it = s21_list.Insert(s21_pos, 0, Item(666));

//     std::list<Item>::const_iterator pos = list.cend();
//     --pos;
//     --pos;
//     const auto it = list.insert(pos, 0, Item(666));

//     EXPECT_TRUE(s21_list == list);
//     EXPECT_TRUE(*s21_it == *it);
// }

// TEST(List, T10InsertPosCountValueBegin)
// {
//     s21::List<Item> s21_list = {
//         Item(11), Item(22), Item(33), Item(44), Item(55), Item(66),
//     };
//     std::list<Item> list = {
//         Item(11), Item(22), Item(33), Item(44), Item(55), Item(66),
//     };

//     s21::List<Item>::const_iterator s21_pos = s21_list.cbegin();
//     const auto s21_it = s21_list.Insert(s21_pos, 0, Item(666));

//     std::list<Item>::const_iterator pos = list.cbegin();
//     const auto it = list.insert(pos, 0, Item(666));

//     EXPECT_TRUE(s21_list == list);
//     EXPECT_TRUE(*s21_it == *it);
// }

// TEST(List, T11InsertPosValueEnd)
// {
//     s21::List<Item> s21_list = {
//         Item(11), Item(22), Item(33), Item(44), Item(55), Item(66),
//     };
//     std::list<Item> list = {
//         Item(11), Item(22), Item(33), Item(44), Item(55), Item(66),
//     };

//     s21::List<Item>::const_iterator s21_pos = s21_list.cend();
//     const auto s21_it = s21_list.Insert(s21_pos, 0, Item(666));

//     std::list<Item>::const_iterator pos = list.cend();
//     const auto it = list.insert(pos, 0, Item(666));

//     EXPECT_TRUE(s21_list == list);
//     EXPECT_TRUE(s21_it == s21_pos); // because the exact value cend points to can be different
//     EXPECT_TRUE(it == pos);         // because the exact value cend points to can be different
// }

TEST(List, T0EraseRange)
{
    s21::List<Item> s21_source = {
        Item(111), Item(222), Item(333), Item(444), Item(555), Item(666),
    };

    auto s21_it1 = s21_source.cbegin();
    auto s21_it2 = s21_source.cend();
    ++s21_it1;
    ++s21_it1;
    --s21_it2;
    --s21_it2;

    std::list<Item> source = {
        Item(111), Item(222), Item(333), Item(444), Item(555), Item(666),
    };

    auto it1 = source.cbegin();
    auto it2 = source.cend();
    ++it1;
    ++it1;
    --it2;
    --it2;

   
    
    const auto s21_it = s21_source.Erase(s21_it1, s21_it2);
    const auto it = source.erase(it1, it2);

    EXPECT_TRUE(s21_source == source);
    EXPECT_TRUE(s21_it == s21_it2);
    EXPECT_TRUE(it == it2);
    EXPECT_TRUE(*s21_it == *it);
}

TEST(List, T1EraseRange)
{
    s21::List<Item> s21_source = {
        Item(111), Item(222), Item(333), Item(444), Item(555), Item(666),
    };

    auto s21_it1 = s21_source.cbegin();
    auto s21_it2 = s21_source.cend();


    std::list<Item> source = {
        Item(111), Item(222), Item(333), Item(444), Item(555), Item(666),
    };

    auto it1 = source.cbegin();
    auto it2 = source.cend();
    

   
    const auto s21_it = s21_source.Erase(s21_it1, s21_it2);
    const auto it = source.erase(it1, it2);

    EXPECT_TRUE(s21_source == source);
    EXPECT_TRUE(s21_it == s21_it2);
    EXPECT_TRUE(it == it2);
    EXPECT_TRUE(*s21_it == *it);
}

TEST(List, T2EraseRange)
{
    s21::List<Item> s21_source = {
        Item(111), Item(222), Item(333), Item(444), Item(555), Item(666),
    };

    auto s21_it1 = s21_source.cbegin();
    auto s21_it2 = s21_source.cend();
    ++s21_it1;
    ++s21_it1;
   

    std::list<Item> source = {
        Item(111), Item(222), Item(333), Item(444), Item(555), Item(666),
    };

    auto it1 = source.cbegin();
    auto it2 = source.cend();
    ++it1;
    ++it1;
   

   
    
    const auto s21_it = s21_source.Erase(s21_it1, s21_it2);
    const auto it = source.erase(it1, it2);

    EXPECT_TRUE(s21_source == source);
    EXPECT_TRUE(s21_it == s21_it2);
    EXPECT_TRUE(it == it2);
}

TEST(List, T3EraseRange)
{
    s21::List<Item> s21_source = {
        Item(111), Item(222), Item(333), Item(444), Item(555), Item(666),
    };

    auto s21_it1 = s21_source.cbegin();
    auto s21_it2 = s21_source.cend();
    --s21_it2;
    --s21_it2;

    std::list<Item> source = {
        Item(111), Item(222), Item(333), Item(444), Item(555), Item(666),
    };

    auto it1 = source.cbegin();
    auto it2 = source.cend();
                                                                                                                                                                                                                                                                                   
    --it2;
    --it2;

   
    
    const auto s21_it = s21_source.Erase(s21_it1, s21_it2);
    const auto it = source.erase(it1, it2);

    EXPECT_TRUE(s21_source == source);
    EXPECT_TRUE(s21_it == s21_it2);
    EXPECT_TRUE(it == it2);
    EXPECT_TRUE(*s21_it == *it);
}

// TEST(List, T1InsertReverseIterator)
// {
//     s21::List<Item> s21_source = {
//         Item(111), Item(222), Item(333), Item(444), Item(555), Item(666),
//     };

//     auto s21_it1 = s21_source.crbegin();
//     auto s21_it2 = s21_source.crend();
//     ++s21_it1;
//     ++s21_it1;
//     --s21_it2;
//     --s21_it2;

//     std::list<Item> source = {
//         Item(111), Item(222), Item(333), Item(444), Item(555), Item(666),
//     };

//     auto it1 = source.crbegin();
//     auto it2 = source.crend();
//     ++it1;
//     ++it1;
//     --it2;
//     --it2;

//     s21::List<Item> s21_list = {
//         Item(11), Item(22), Item(33), Item(44), Item(55), Item(66),
//     };
//     s21::List<Item>::const_iterator s21_pos = s21_list.cend();
//     const auto s21_it = s21_list.Insert(s21_pos, s21_it1, s21_it2);

//     std::list<Item> list = {
//         Item(11), Item(22), Item(33), Item(44), Item(55), Item(66),
//     };
//     std::list<Item>::const_iterator pos = list.cend();
//     const auto it = list.insert(pos, it1, it2);

//     EXPECT_TRUE(s21_list == list);
//     EXPECT_TRUE(*s21_it == *it);
// }

// TEST(List, T0InsertInitializer)
// {
//     s21::List<Item> s21_list = {
//         Item(11), Item(22), Item(33), Item(44), Item(55), Item(66),
//     };
//     s21::List<Item>::const_iterator s21_pos = s21_list.cend();
//     --s21_pos;
//     --s21_pos;
//     const auto s21_it = s21_list.Insert(s21_pos, {
//                                                      Item(111),
//                                                      Item(222),
//                                                      Item(333),
//                                                      Item(444),
//                                                      Item(555),
//                                                      Item(666),
//                                                  });

//     std::list<Item> list = {
//         Item(11), Item(22), Item(33), Item(44), Item(55), Item(66),
//     };
//     std::list<Item>::const_iterator pos = list.cend();
//     --pos;
//     --pos;
//     const auto it = list.insert(pos, {
//                                          Item(111),
//                                          Item(222),
//                                          Item(333),
//                                          Item(444),
//                                          Item(555),
//                                          Item(666),
//                                      });

//     EXPECT_TRUE(s21_list == list);
//     EXPECT_TRUE(*s21_it == *it);
// }
} //  namespace

//  GCOVR_EXCL_STOP