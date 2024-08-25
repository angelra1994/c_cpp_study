/**
* brief: Limiting variable scopes to if and switch statements
* C++17中可以在if和switch语句 条件语句中定义变量，减短变量的生命周期。类似语法糖
* Created by lzy on 2024-08-26.
*/

#include <iostream>
#include <cstdio>
#include <map>
#include <string>

template <typename T>
void print_charcount_cpp11(const T &map, char c)
{
    const auto itr (map.find(c));
    if (itr != map.end()) {
        // *itr is valid. Do something with it.
        std::cout << "There are " << itr->second << " " << c << " characters." << "\n";
    } else {
        // itr is invalid, must not be accessed, but is available
        std::cout << "There are " << 0 << " " << c << " characters." << "\n";
    }
    /* itr is not necessarily safe to dereference, but still available
     * 此处的itr仍然可用，但是itr解引用不一定安全；直接通过*itr访问其指向的数据，可能已经超出作用域或者被释放
     */
}

template <typename T>
void print_charcount_cpp17(const T &map, char c)
{
    /* C++17支持在if条件语句中定义变量，并在if语句中访问 */
    if (const auto itr (map.find(c)); itr != map.end()) {
        std::cout << "There are " << itr->second << " " << c << " characters." << "\n";
    } else {
        std::cout << "There are " << 0 << " " << c << " characters." << "\n";
    }
    /* itr is not visible here， 此处 itr 已经不可用了 */
}

int main()
{
    {
        std::map<char, size_t> character_map {{'a', 10}, {'b', 20} /* , ... */};
        print_charcount_cpp11(character_map, 'a');
        print_charcount_cpp11(character_map, 'c');

        print_charcount_cpp17(character_map, 'a');
        print_charcount_cpp17(character_map, 'c');
    }

    {
        std::cout << "Please enter a character: ";
        switch (char c (getchar()); c) {
        case 'a' ... 'z':
            std::cout << "You entered a lower case letter: " << c << "\n";
            break;
        case 'A' ... 'Z':
            std::cout << "You entered an upper case letter: " << c << "\n";
            break;
        default:
            std::cout << "You entered something else: " << c << "\n";
        }
    }
}
