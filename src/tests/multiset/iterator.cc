// TEST(MultiSet, T0ReverseIterator)
// {
//     s21::MultiSet<Item, ComparatorItem> s21_multiset {
//         {Item(3, 'c', 0.3)},
//         {Item(10, 'c', 0.3)},
//         {Item(3, 'c', 0.3)},
//         {Item(3, 'c', 0.3)},
//         {Item(3, 'c', 0.3)},
//         {Item(1, 'a', 0.1)},
//         {Item(1, 'a', 0.1)},
//         {Item(1, 'a', 0.1)},
//         {Item(1, 'a', 0.1)},
//         {Item(1, 'a', 0.1)},
//         {Item(2, 'b', 0.2)},
//         {Item(2, 'b', 0.2)},
//         {Item(2, 'b', 0.2)},
//         {Item(2, 'b', 0.2)},
//         {Item(3, 'c', 0.3)},
//         {Item(3, 'c', 0.3)},
//     };

//     std::multiset<Item, ComparatorItem> multiset {
//         {Item(3, 'c', 0.3)},
//         {Item(10, 'c', 0.3)},
//         {Item(3, 'c', 0.3)},
//         {Item(3, 'c', 0.3)},
//         {Item(3, 'c', 0.3)},
//         {Item(1, 'a', 0.1)},
//         {Item(1, 'a', 0.1)},
//         {Item(1, 'a', 0.1)},
//         {Item(1, 'a', 0.1)},
//         {Item(1, 'a', 0.1)},
//         {Item(2, 'b', 0.2)},
//         {Item(2, 'b', 0.2)},
//         {Item(2, 'b', 0.2)},
//         {Item(2, 'b', 0.2)},
//         {Item(3, 'c', 0.3)},
//         {Item(3, 'c', 0.3)},
//     };

//     // for (auto it = multimap.rbegin(); it != multimap.rend(); ++it) {
//     //     std::cout << "{" << it->first << ", " << it->second << "},  ";
//     // }
//     // std::cout << '\n';

//     EXPECT_EQ(s21_multiset, multiset);

//     s21::MultiSet<Item, ComparatorItem>::reverse_iterator s21_it =
//     s21_multiset.rbegin(); std::multiset<Item,
//     ComparatorItem>::reverse_iterator it = multiset.rbegin();

//     while (s21_it != s21_multiset.rend() && it != multiset.rend()) {
//         EXPECT_EQ(*s21_it, *it);
//         // std::cout << "{" << s21_it->first << ", " << s21_it->second << "}
//         ==  ";
//         // std::cout << "{" << it->first << ", " << it->second << "},  ";
//         // std::cout << '\n';
//         ++s21_it;
//         ++it;
//     }
// }