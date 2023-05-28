#include <gtest/gtest.h>

#include <list>

#include "../../s21_list.h"
#include "../item.h"
#include "../list_helpers.h"

// GCOVR_EXCL_START

namespace
{
TEST(List, T0DefaultConstructor)
{
    s21::List<Item> s21_list;
    std::list<Item> list;

    EXPECT_TRUE(s21_list == list);
}

TEST(List, T0ConstructorInitializerList)
{
    s21::List<Item> s21_list = {Item(11), Item(22), Item(33), Item(44), Item(55)};
    std::list<Item> list = {Item(11), Item(22), Item(33), Item(44), Item(55)};

    EXPECT_TRUE(s21_list == list);
}

TEST(List, T1ConstructorInitializerList)
{
    s21::List<Item> s21_list = {};
    std::list<Item> list = {};

    EXPECT_TRUE(s21_list == list);
}

TEST(List, T0Size)
{
    s21::List<Item> s21_list = {Item(11), Item(22), Item(33), Item(44), Item(55)};
    std::list<Item> list = {Item(11), Item(22), Item(33), Item(44), Item(55)};

    EXPECT_TRUE(s21_list.Size() == list.size());
}

TEST(List, T0Empty)
{
    s21::List<Item> s21_list = {Item(11), Item(22), Item(33), Item(44), Item(55)};
    std::list<Item> list = {Item(11), Item(22), Item(33), Item(44), Item(55)};

    EXPECT_TRUE(s21_list.Empty() == list.empty());
}

TEST(List, T1Empty)
{
    s21::List<Item> s21_list;
    std::list<Item> list;

    EXPECT_TRUE(s21_list.Empty() == list.empty());
}

TEST(List, T0Modify)
{
    s21::List<Item> s21_list = {Item(11), Item(22), Item(33), Item(44), Item(55)};
    std::list<Item> list = {Item(11), Item(22), Item(33), Item(44), Item(55)};

    auto it = list.begin();
    ++it;
    ++it;
    *it = Item(666);

    auto s21_it = s21_list.begin();
    ++s21_it;
    ++s21_it;
    *s21_it = Item(666);

    EXPECT_TRUE(s21_list == list);
}

// OPERATOR==
// ///=======================================================================
// OPERATOR==
// ///=======================================================================
// OPERATOR==
// ///=======================================================================

TEST(OperatorEqual, T0Equal)
{
    const s21::List<Item> s21_list1 = {Item(11), Item(22), Item(33), Item(44), Item(55)};
    const s21::List<Item> s21_list2 = {Item(11), Item(22), Item(33), Item(44), Item(55)};

    EXPECT_TRUE(s21_list2 == s21_list1);
    EXPECT_TRUE(s21_list1 == s21_list2);
}

TEST(OperatorEqual, T1Equal)
{
    const s21::List<Item> s21_list1;
    const s21::List<Item> s21_list2;

    const std::list<Item> list1;
    const std::list<Item> list2;

    const bool expected = list1 == list2;

    EXPECT_TRUE(expected);

    EXPECT_TRUE((s21_list2 == s21_list1) == expected);
    EXPECT_TRUE((s21_list1 == s21_list2) == expected);
}

TEST(OperatorEqual, T2NotEqual)
{
    const s21::List<Item> s21_list1 = {
        Item(11),
        Item(22),
    };
    const s21::List<Item> s21_list2 = {Item(11), Item(22), Item(33), Item(44), Item(55)};

    EXPECT_FALSE(s21_list2 == s21_list1);
    EXPECT_FALSE(s21_list1 == s21_list2);
}

TEST(OperatorEqual, T3NotEqual)
{
    const s21::List<Item> s21_list1;
    const s21::List<Item> s21_list2 = {Item(11), Item(22), Item(33), Item(44), Item(55)};

    EXPECT_FALSE(s21_list2 == s21_list1);
    EXPECT_FALSE(s21_list1 == s21_list2);
}

TEST(OperatorEqual, T4EqualSelf)
{
    const s21::List<Item> s21_list1;

    EXPECT_TRUE(s21_list1 == s21_list1);
}

TEST(OperatorEqual, T5EqualSelf)
{
    const s21::List<Item> s21_list1 = {Item(11), Item(22), Item(33), Item(44), Item(55)};

    EXPECT_TRUE(s21_list1 == s21_list1);
}

TEST(OperatorEqual, T6NotEqual)
{
    const s21::List<Item> s21_list1 = {Item(11), Item(22), Item(33), Item(44), Item(666)};
    const s21::List<Item> s21_list2 = {Item(11), Item(22), Item(33), Item(44), Item(55)};

    EXPECT_FALSE(s21_list2 == s21_list1);
    EXPECT_FALSE(s21_list1 == s21_list2);
}

TEST(OperatorEqual, T7NotEqual)
{
    const s21::List<Item> s21_list1 = {Item(11), Item(22), Item(666), Item(44), Item(55)};
    const s21::List<Item> s21_list2 = {Item(11), Item(22), Item(33), Item(44), Item(55)};

    EXPECT_FALSE(s21_list2 == s21_list1);
    EXPECT_FALSE(s21_list1 == s21_list2);
}

// RULE OF 5
// =============================================================================
// RULE OF 5
// =============================================================================
// RULE OF 5
// =============================================================================

TEST(RuleOf5, T0CopyConstructor)
{
    const s21::List<Item> s21_list1 = {Item(11), Item(22), Item(33), Item(44), Item(55)};
    s21::List<Item> s21_list2(s21_list1);

    EXPECT_TRUE(s21_list2 == s21_list1);
}

TEST(RuleOf5, T0MoveConstructor)
{
    s21::List<Item> s21_list1 = {Item(11), Item(22), Item(33), Item(44), Item(55)};
    const s21::List<Item> s21_list_copy(s21_list1);
    s21::List<Item> s21_list2(std::move(s21_list1));

    const s21::List<Item> s21_list_empty;
    EXPECT_TRUE(s21_list2 == s21_list_copy);
    EXPECT_TRUE(s21_list1 == s21_list_empty);
}

TEST(RuleOf5, T0CopyAssignmentOperator)
{
    const s21::List<Item> s21_list1 = {Item(11), Item(22), Item(33), Item(44), Item(55)};
    s21::List<Item> s21_list2;
    s21_list2 = s21_list1;

    EXPECT_TRUE(s21_list2 == s21_list1);
}

TEST(RuleOf5, T1CopyAssignmentOperatorSelf)
{
    s21::List<Item> s21_list1 = {Item(11), Item(22), Item(33), Item(44), Item(55)};
    const s21::List<Item> s21_list_copy(s21_list1);
    s21_list1 = s21_list1;

    EXPECT_TRUE(s21_list1 == s21_list_copy);
}

TEST(RuleOf5, T0MoveAssignmentOperator)
{
    s21::List<Item> s21_list1 = {Item(11), Item(22), Item(33), Item(44), Item(55)};
    const s21::List<Item> s21_list_copy(s21_list1);
    s21::List<Item> s21_list2;
    s21_list2 = std::move(s21_list1);

    const s21::List<Item> s21_list_empty;
    EXPECT_TRUE(s21_list2 == s21_list_copy);
    EXPECT_TRUE(s21_list1 == s21_list_empty);
}

TEST(RuleOf5, T1MoveAssignmentOperatorSelf)
{
    s21::List<Item> s21_list1 = {Item(11), Item(22), Item(33), Item(44), Item(55)};
    const s21::List<Item> s21_list_copy(s21_list1);
    s21_list1 = std::move(s21_list1);

    EXPECT_TRUE(s21_list1 == s21_list_copy);
}

TEST(Constructor, T0ConstructorCount)
{
    const s21::List<Item> s21_list(5);
    const std::list<Item> list(5);

    EXPECT_TRUE(s21_list == list);
}

TEST(Constructor, T0ConstructorCountValue)
{
    const s21::List<Item> s21_list(5, Item(11));
    const std::list<Item> list(5, Item(11));

    EXPECT_TRUE(s21_list == list);
}

TEST(Constructor, T1ConstructorIterator)
{
    const s21::List<Item> s21_source = {
        Item(11), Item(22), Item(33), Item(44), Item(55),
    };
    const std::list<Item> source = {
        Item(11), Item(22), Item(33), Item(44), Item(55),
    };

    s21::List<Item>::const_iterator s21_first = s21_source.cbegin();
    s21::List<Item>::const_iterator s21_last = s21_source.cend();
    --s21_last;
    --s21_last;

    std::list<Item>::const_iterator first = source.cbegin();
    std::list<Item>::const_iterator last = source.cend();
    --last;
    --last;

    const s21::List<Item> s21_list(s21_first, s21_last);
    const std::list<Item> list(first, last);

    EXPECT_TRUE(s21_list == list);
}

TEST(Constructor, T2ConstructorIterator)
{
    const s21::List<Item> s21_source = {
        Item(11), Item(22), Item(33), Item(44), Item(55),
    };
    const std::list<Item> source = {
        Item(11), Item(22), Item(33), Item(44), Item(55),
    };

    s21::List<Item>::const_iterator s21_first = s21_source.cbegin();
    s21::List<Item>::const_iterator s21_last = s21_source.cend();
    --s21_last;
    --s21_last;

    std::list<Item>::const_iterator first = source.cbegin();
    std::list<Item>::const_iterator last = source.cend();
    --last;
    --last;

    const s21::List<Item> s21_list(first, last);
    const std::list<Item> list(s21_first, s21_last);

    EXPECT_TRUE(s21_list == list);
}

TEST(Constructor, T3ConstructorReverseIterator)
{
    const s21::List<Item> s21_source = {
        Item(11), Item(22), Item(33), Item(44), Item(55),
    };
    const std::list<Item> source = {
        Item(11), Item(22), Item(33), Item(44), Item(55),
    };

    s21::List<Item>::const_reverse_iterator s21_first = s21_source.crbegin();
    s21::List<Item>::const_reverse_iterator s21_last = s21_source.crend();
    --s21_last;
    --s21_last;

    std::list<Item>::const_reverse_iterator first = source.crbegin();
    std::list<Item>::const_reverse_iterator last = source.crend();
    --last;
    --last;

    const s21::List<Item> s21_list(s21_first, s21_last);
    const std::list<Item> list(first, last);

    EXPECT_TRUE(s21_list == list);
}

TEST(Constructor, T4ConstructorReverseIterator)
{
    const s21::List<Item> s21_source = {
        Item(11), Item(22), Item(33), Item(44), Item(55),
    };
    const std::list<Item> source = {
        Item(11), Item(22), Item(33), Item(44), Item(55),
    };

    s21::List<Item>::const_reverse_iterator s21_first = s21_source.crbegin();
    s21::List<Item>::const_reverse_iterator s21_last = s21_source.crend();
    --s21_last;
    --s21_last;

    std::list<Item>::const_reverse_iterator first = source.crbegin();
    std::list<Item>::const_reverse_iterator last = source.crend();
    --last;
    --last;

    const s21::List<Item> s21_list(first, last);
    const std::list<Item> list(s21_first, s21_last);

    EXPECT_TRUE(s21_list == list);
}
} //  namespace

// GCOVR_EXCL_STOP