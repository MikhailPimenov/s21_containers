#include <gtest/gtest.h>

#include <array>
#include "../../s21_array.h"
#include "../../s21_vector.h"

#include "../item.h"
#include "../array_helpers.h"

// GCOVR_EXCL_START

namespace
{

TEST(Vector, T10IteratorOperatorPlus)
{
    s21::Array<Item, 4> s21_source { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333), Item(44, 'd', 0.44444) };
    std::array<Item, 4> source { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333), Item(44, 'd', 0.44444) };
    
    s21::Array<Item, 4>::iterator s21_it = s21_source.begin();
    std::array<Item, 4>::iterator it = source.begin();

    EXPECT_EQ(*s21_it, *it);
    EXPECT_EQ(*(++s21_it), *(++it));
    EXPECT_EQ(*s21_it, *it);

} 
TEST(Vector, T11IteratorOperatorPlusPostfix)
{
    s21::Array<Item, 4> s21_source { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333), Item(44, 'd', 0.44444) };
    std::array<Item, 4> source { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333), Item(44, 'd', 0.44444) };
    
    s21::Array<Item, 4>::iterator s21_it = s21_source.begin();
    std::array<Item, 4>::iterator it = source.begin();

    EXPECT_EQ(*s21_it, *it);
    EXPECT_EQ(*(s21_it++), *(it++));
    EXPECT_EQ(*s21_it, *it);
} 
TEST(Vector, T12IteratorOperatorMinus)
{
    s21::Array<Item, 4> s21_source { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333), Item(44, 'd', 0.44444) };
    std::array<Item, 4> source { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333), Item(44, 'd', 0.44444) };
    
    s21::Array<Item, 4>::iterator s21_it = s21_source.end() - 1;
    std::array<Item, 4>::iterator it = source.end() - 1;

    EXPECT_EQ(*s21_it, *it);
    EXPECT_EQ(*(--s21_it), *(--it));
    EXPECT_EQ(*s21_it, *it);

} 
TEST(Vector, T13IteratorOperatorMinusPostfix)
{
    s21::Array<Item, 4> s21_source { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333), Item(44, 'd', 0.44444) };
    std::array<Item, 4> source { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333), Item(44, 'd', 0.44444) };
    
    s21::Array<Item, 4>::iterator s21_it = s21_source.end() - 1;
    std::array<Item, 4>::iterator it = source.end() - 1;

    EXPECT_EQ(*s21_it, *it);
    EXPECT_EQ(*(s21_it--), *(it--));
    EXPECT_EQ(*s21_it, *it);
} 

TEST(Vector, T15IteratorOperatorSubscript)
{
    s21::Array<Item, 4> s21_source { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333), Item(44, 'd', 0.44444) };
    std::array<Item, 4> source { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333), Item(44, 'd', 0.44444) };
    
    Item s21_item = s21_source.begin()[2];
    Item item = source.begin()[2];

    EXPECT_EQ(s21_item, item);
}
TEST(Vector, T16IteratorOperatorSubscript)
{
    s21::Array<Item, 4> s21_source { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333), Item(44, 'd', 0.44444) };
    std::array<Item, 4> source { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333), Item(44, 'd', 0.44444) };
    
    Item s21_item = s21_source.end()[-2];
    Item item = source.end()[-2];

    EXPECT_EQ(s21_item, item);
}
















TEST(Vector, T25ConstIteratorOperatorPlus)
{
    const s21::Array<Item, 4> s21_source { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333), Item(44, 'd', 0.44444) };
    const std::array<Item, 4> source { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333), Item(44, 'd', 0.44444) };
    
    s21::Array<Item, 4>::const_iterator s21_it = s21_source.begin();
    std::array<Item, 4>::const_iterator it = source.begin();

    EXPECT_EQ(*s21_it, *it);
    EXPECT_EQ(*(++s21_it), *(++it));
    EXPECT_EQ(*s21_it, *it);

} 
TEST(Vector, T26ConstIteratorOperatorPlusPostfix)
{
    const s21::Array<Item, 4> s21_source { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333), Item(44, 'd', 0.44444) };
    const std::array<Item, 4> source { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333), Item(44, 'd', 0.44444) };
    
    s21::Array<Item, 4>::const_iterator s21_it = s21_source.begin();
    std::array<Item, 4>::const_iterator it = source.begin();

    EXPECT_EQ(*s21_it, *it);
    EXPECT_EQ(*(s21_it++), *(it++));
    EXPECT_EQ(*s21_it, *it);
} 
TEST(Vector, T27ConstIteratorOperatorMinus)
{
    const s21::Array<Item, 4> s21_source { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333), Item(44, 'd', 0.44444) };
    const std::array<Item, 4> source { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333), Item(44, 'd', 0.44444) };
    
    s21::Array<Item, 4>::const_iterator s21_it = s21_source.end() - 1;
    std::array<Item, 4>::const_iterator it = source.end() - 1;

    EXPECT_EQ(*s21_it, *it);
    EXPECT_EQ(*(--s21_it), *(--it));
    EXPECT_EQ(*s21_it, *it);

} 
TEST(Vector, T28ConstIteratorOperatorMinusPostfix)
{
    const s21::Array<Item, 4> s21_source { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333), Item(44, 'd', 0.44444) };
    const std::array<Item, 4> source { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333), Item(44, 'd', 0.44444) };
    
    s21::Array<Item, 4>::const_iterator s21_it = s21_source.end() - 1;
    std::array<Item, 4>::const_iterator it = source.end() - 1;

    EXPECT_EQ(*s21_it, *it);
    EXPECT_EQ(*(s21_it--), *(it--));
    EXPECT_EQ(*s21_it, *it);
} 

TEST(Vector, T30ConstIteratorOperatorSubscript)
{
    const s21::Array<Item, 4> s21_source { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333), Item(44, 'd', 0.44444) };
    const std::array<Item, 4> source { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333), Item(44, 'd', 0.44444) };
    
    Item s21_item = s21_source.begin()[2];
    Item item = source.begin()[2];

    EXPECT_EQ(s21_item, item);
}
TEST(Vector, T31IteratorOperatorSubscript)
{
    const s21::Array<Item, 4> s21_source { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333), Item(44, 'd', 0.44444) };
    const std::array<Item, 4> source { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333), Item(44, 'd', 0.44444) };
    
    Item s21_item = s21_source.end()[-2];
    Item item = source.end()[-2];

    EXPECT_EQ(s21_item, item);
}


























TEST(Vector, T40ReverseIteratorOperatorPlus)
{
    s21::Array<Item, 4> s21_source { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333), Item(44, 'd', 0.44444) };
    std::array<Item, 4> source { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333), Item(44, 'd', 0.44444) };
    
    s21::Array<Item, 4>::reverse_iterator s21_it = s21_source.rbegin();
    std::array<Item, 4>::reverse_iterator it = source.rbegin();

    EXPECT_EQ(*s21_it, *it);
    EXPECT_EQ(*(++s21_it), *(++it));
    EXPECT_EQ(*s21_it, *it);

} 
TEST(Vector, T41ReverseIteratorOperatorPlusPostfix)
{
    s21::Array<Item, 4> s21_source { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333), Item(44, 'd', 0.44444) };
    std::array<Item, 4> source { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333), Item(44, 'd', 0.44444) };
    
    s21::Array<Item, 4>::reverse_iterator s21_it = s21_source.rbegin();
    std::array<Item, 4>::reverse_iterator it = source.rbegin();

    EXPECT_EQ(*s21_it, *it);
    EXPECT_EQ(*(s21_it++), *(it++));
    EXPECT_EQ(*s21_it, *it);
} 
TEST(Vector, T42ReverseIteratorOperatorMinus)
{
    s21::Array<Item, 4> s21_source { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333), Item(44, 'd', 0.44444) };
    std::array<Item, 4> source { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333), Item(44, 'd', 0.44444) };
    
    s21::Array<Item, 4>::reverse_iterator s21_it = s21_source.rend() - 1;
    std::array<Item, 4>::reverse_iterator it = source.rend() - 1;

    EXPECT_EQ(*s21_it, *it);
    EXPECT_EQ(*(--s21_it), *(--it));
    EXPECT_EQ(*s21_it, *it);

} 
TEST(Vector, T43ReverseIteratorOperatorMinusPostfix)
{
    s21::Array<Item, 4> s21_source { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333), Item(44, 'd', 0.44444) };
    std::array<Item, 4> source { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333), Item(44, 'd', 0.44444) };
    
    s21::Array<Item, 4>::reverse_iterator s21_it = s21_source.rend() - 1;
    std::array<Item, 4>::reverse_iterator it = source.rend() - 1;

    EXPECT_EQ(*s21_it, *it);
    EXPECT_EQ(*(s21_it--), *(it--));
    EXPECT_EQ(*s21_it, *it);
} 
TEST(Vector, T44ReverseIteratorOperatorMinusIterator)
{
    s21::Array<Item, 4> s21_source { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333), Item(44, 'd', 0.44444) };
    std::array<Item, 4> source { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333), Item(44, 'd', 0.44444) };
    
    s21::Array<Item, 4>::size_type s21_size = s21_source.rend() - ++s21_source.rbegin();
    std::array<Item, 4>::size_type size = source.rend() - ++source.rbegin();

    EXPECT_EQ(s21_size, size);
} 
TEST(Vector, T45ReverseIteratorOperatorSubscript)
{
    s21::Array<Item, 4> s21_source { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333), Item(44, 'd', 0.44444) };
    std::array<Item, 4> source { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333), Item(44, 'd', 0.44444) };
    
    Item s21_item = s21_source.rbegin()[2];
    Item item = source.rbegin()[2];

    EXPECT_EQ(s21_item, item);
}
TEST(Vector, T46ReverseIteratorOperatorSubscript)
{
    s21::Array<Item, 4> s21_source { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333), Item(44, 'd', 0.44444) };
    std::array<Item, 4> source { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333), Item(44, 'd', 0.44444) };
    
    Item s21_item = s21_source.rend()[-2];
    Item item = source.rend()[-2];

    EXPECT_EQ(s21_item, item);
}



 
TEST(Vector, T55ConstReverseIteratorOperatorPlus)
{
    const s21::Array<Item, 4> s21_source { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333), Item(44, 'd', 0.44444) };
    const std::array<Item, 4> source { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333), Item(44, 'd', 0.44444) };
    
    s21::Array<Item, 4>::const_reverse_iterator s21_it = s21_source.rbegin();
    std::array<Item, 4>::const_reverse_iterator it = source.rbegin();

    EXPECT_EQ(*s21_it, *it);
    EXPECT_EQ(*(++s21_it), *(++it));
    EXPECT_EQ(*s21_it, *it);

} 
TEST(Vector, T56ConstReverseIteratorOperatorPlusPostfix)
{
    const s21::Array<Item, 4> s21_source { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333), Item(44, 'd', 0.44444) };
    const std::array<Item, 4> source { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333), Item(44, 'd', 0.44444) };
    
    s21::Array<Item, 4>::const_reverse_iterator s21_it = s21_source.rbegin();
    std::array<Item, 4>::const_reverse_iterator it = source.rbegin();

    EXPECT_EQ(*s21_it, *it);
    EXPECT_EQ(*(s21_it++), *(it++));
    EXPECT_EQ(*s21_it, *it);
} 
TEST(Vector, T57ConstReverseIteratorOperatorMinus)
{
    const s21::Array<Item, 4> s21_source { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333), Item(44, 'd', 0.44444) };
    const std::array<Item, 4> source { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333), Item(44, 'd', 0.44444) };
    
    s21::Array<Item, 4>::const_reverse_iterator s21_it = s21_source.rend() - 1;
    std::array<Item, 4>::const_reverse_iterator it = source.rend() - 1;

    EXPECT_EQ(*s21_it, *it);
    EXPECT_EQ(*(--s21_it), *(--it));
    EXPECT_EQ(*s21_it, *it);

} 
TEST(Vector, T58ConstReverseIteratorOperatorMinusPostfix)
{
    const s21::Array<Item, 4> s21_source { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333), Item(44, 'd', 0.44444) };
    const std::array<Item, 4> source { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333), Item(44, 'd', 0.44444) };
    
    s21::Array<Item, 4>::const_reverse_iterator s21_it = s21_source.rend() - 1;
    std::array<Item, 4>::const_reverse_iterator it = source.rend() - 1;

    EXPECT_EQ(*s21_it, *it);
    EXPECT_EQ(*(s21_it--), *(it--));
    EXPECT_EQ(*s21_it, *it);
} 
TEST(Vector, T59ConstReverseIteratorOperatorMinusIterator)
{
    const s21::Array<Item, 4> s21_source { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333), Item(44, 'd', 0.44444) };
    const std::array<Item, 4> source { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333), Item(44, 'd', 0.44444) };
    
    s21::Array<Item, 4>::size_type s21_size = s21_source.rend() - ++s21_source.rbegin();
    std::array<Item, 4>::size_type size = source.rend() - ++source.rbegin();

    EXPECT_EQ(s21_size, size);
} 
TEST(Vector, T60ConstReverseIteratorOperatorSubscript)
{
    const s21::Array<Item, 4> s21_source { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333), Item(44, 'd', 0.44444) };
    const std::array<Item, 4> source { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333), Item(44, 'd', 0.44444) };
    
    Item s21_item = s21_source.rbegin()[2];
    Item item = source.rbegin()[2];

    EXPECT_EQ(s21_item, item);
}
TEST(Vector, T61ConstReverseIteratorOperatorSubscript)
{
    const s21::Array<Item, 4> s21_source { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333), Item(44, 'd', 0.44444) };
    const std::array<Item, 4> source { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333), Item(44, 'd', 0.44444) };
    
    Item s21_item = s21_source.rend()[-2];
    Item item = source.rend()[-2];

    EXPECT_EQ(s21_item, item);
}
  




TEST(Vector, T67ConstReverseIteratorOperatorCast)
{
    const s21::Array<Item, 4> s21_source { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333), Item(44, 'd', 0.44444) };
    // const std::vector<Item> source { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333), Item(44, 'd', 0.44444) };
    const s21::Array<Item, 4> s21_vector { Item(11), Item(), Item(), Item(44, 'd', 0.44444) };
    // const std::vector<Item> vector { Item(11), Item(), Item(), Item(44, 'd', 0.44444) };
    
 
    s21::Array<Item, 4>::reverse_iterator s21_start = static_cast<s21::Array<Item, 4>::reverse_iterator>(s21_source.rend() - 2);    // should be able to do that? std does not compile that 
    s21::Array<Item, 4>::const_reverse_iterator s21_stop = s21_source.rbegin() + 1;
    while (s21_start >= s21_stop) {
        *s21_start = Item();
        --s21_start;    
    }

    // std::vector<Item>::reverse_iterator start = static_cast<std::vector<Item>::reverse_iterator>(source.rend() - 2); //does not compile
    // std::vector<Item>::const_reverse_iterator stop = source.rbegin() + 1;
    // while (start >= stop) {
    //     *start = Item();
    //     --start;    
    // }
    
    // EXPECT_EQ(s21_vector, vector);
    EXPECT_EQ(s21_source, s21_vector);
}





// TEST(Vector, T68IteratorOperatorArrow)
// {
//     const s21::Array<Item, 4> s21_source1 { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333), Item(44, 'd', 0.44444) };
//     const s21::Array<Item, 4> s21_source2 { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333), Item(44, 'd', 0.44444) };
//     const s21::Array<Item, 3> s21_source3 { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333) };
//     const s21::Array<Item, 3> s21_source4 { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333) };
//     const s21::Array<Item, 2> s21_source5 { Item(11), Item(22, 'b'), };
//     const s21::Array<Item, 2> s21_source6 { Item(11), Item(22, 'b'), };
//     const s21::Vector<s21::Array<Item, 3>> s21_vector { 
//         s21_source1,
//         s21_source2,
//         s21_source3,
//         s21_source4,
//         s21_source5,
//         s21_source6,
//     };
    
//     const std::array<Item, 4> source1 { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333), Item(44, 'd', 0.44444) };
//     const std::array<Item, 4> source2 { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333), Item(44, 'd', 0.44444) };
//     const std::array<Item, 3> source3 { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333) };
//     const std::array<Item, 3> source4 { Item(11), Item(22, 'b'), Item(33, 'c', 0.3333) };
//     const std::array<Item, 2> source5 { Item(11), Item(22, 'b'), };
//     const std::array<Item, 2> source6 { Item(11), Item(22, 'b'), };
//     const std::array<std::vector<Item>> vector { 
//         source1,
//         source2,
//         source3,
//         source4,
//         source5,
//         source6,
//     };
     
    // EXPECT_EQ(s21_vector, vector);       // TODO: does not compile because of pointers
    // EXPECT_EQ(s21_vector.begin()->Size(), vector.begin()->size());
    // vector.begin()->size();
// }


}  // namespace

// GCOVR_EXCL_STOP
