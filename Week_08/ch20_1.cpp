#include <iostream>
#include <stdexcept>
#include <vector>
#include <algorithm>
#include <list>
#include <array>
#include <string>

template<typename C>
void print_elements(const C& c, const std::string& s = "")
{
    std::cout << s << '\t'; //string
    for (auto& a : c) //array
        std::cout << a << ' ';
    std::cout << '\n';
}

template<typename C>
void Increase_value(C& c, int n = 1)
{
    for (auto& a : c)
        a += n;
}

// 6os coppy operation
template<typename Iter_1, typename Iter_2>
    // requires Input_iterator<Iter_1>() && Output_iterator<Iter_2>()
Iter_2 my_copy(Iter_1 f1, Iter_1 e1, Iter_2 f2)
{
    for (Iter_1 p = f1; p != e1; ++p)
        *f2++ = *p;
    return f2;
}

int main()
try {
    constexpr int size = 10; //ha már mindegyiknél 10 kell

    // 1es (10 int-et tartalmazó array létrehozása)
    int arr[size]; 
    for (int i = 0; i < size; ++i) arr[i] = i;
    print_elements(arr, "array[10]: ");
    std::cout << "\n";
    // 1es csak most az std array-el
    std::array<int, size> ai;
    std::copy(arr, arr + size, ai.begin());
    print_elements(ai, "std::array: ");

    // 2es (vector 10 elemmel)
    std::vector<int> vi(size);
    std::copy(arr, arr + size, vi.begin());
    print_elements(vi, "std::vector: ");

    // 3as (lista 10 elemmel)
    std::list<int> li(size);
    std::copy(arr, arr + size, li.begin());
    print_elements(li, "std::list: ");

    std::cout << '\n';

    // 4es (array, vector és list másolása)
    std::array<int, size> ai2 = ai;
    std::vector<int> vi2 = vi;
    std::list<int> li2 = li;
    print_elements(ai2, "array copy: ");
    print_elements(vi2, "vector copy: ");
    print_elements(li2, "list copy: ");

    std::cout << '\n';

    // 5ös (values: array +2, vector +3, list +5)
    Increase_value(ai2, 2);
    Increase_value(vi2, 3);
    Increase_value(li2, 5);
    print_elements(ai2, "array +2val: ");
    print_elements(vi2, "vector +3 val: ");
    print_elements(li2, "list +5 val: ");

    std::cout << '\n';

    // 7es (my_copy --> coppy array, vector, list)
    my_copy(ai2.begin(), ai2.end(), vi2.begin());
    my_copy(li2.begin(), li2.end(), ai2.begin());
    print_elements(ai2, "array copied: ");
    print_elements(vi2, "vector copied: ");
    print_elements(li2, "list copied: ");

    // 8as (find)
    std::vector<int>::iterator vector_iter;
    vector_iter = std::find(vi2.begin(), vi2.end(), 3);
    if (vector_iter != vi2.end())
        std::cout << "Found at: " << std::distance(vi2.begin(), vector_iter) << '\n';
    else
        std::cout << "Not found..\n";

    std::list<int>::iterator list_iter;
    list_iter = std::find(li2.begin(), li2.end(), 27);
    if (list_iter != li2.end())
        std::cout << "Found at: " << std::distance(li2.begin(), list_iter) << '\n';
    else
        std::cout << "Not found..\n";
}
catch(std::exception& e) {
    std::cerr << "Exception: " << e.what() << '\n';
    return 1;
}
catch(...) {
    std::cerr << "Unknown exception\n";
    return 2;
}