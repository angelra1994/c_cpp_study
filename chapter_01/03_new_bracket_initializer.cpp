/**
* brief: c++11 支持了了新的括号初始化语法 {} 。其不仅允许集合式初始化，而且还是对常规构造函数的调用。
* 但是对于auto类型，c++11 很容易出错，只能使用()。
* C++17增强这一系列初始化规则
* Created by lzy on 2024-08-26.
*/

#include <iostream>
#include <vector>

int main(int argc, char* argv[])
{
    { // C++11 不使用auto声明的括号初始化
        int x1 = 1;
        int x2 {1};
        int x3 (1);
        std::cout << "x1 = " <<  x1 << ", x2 = " <<  x2 << ", x3 = " <<  x3 << std::endl;

        std::vector<int> v1{1, 2, 3}; // Vector with three ints
        std::vector<int> v2 = {1, 2, 3}; // same here
        std::vector<int> v3(10, 20); // Vector with 10 ints, each have value 20

        auto [v1_0, v1_1, v1_2] = std::make_tuple(v1[0], v1[1], v1[2]);
        std::cout << "v1_0 = " << v1_0 << ", v1_1 = " << v1_1 << ", v1_2 = " << v1_2 << std::endl;

        auto [v2_0, v2_1, v2_2] = std::make_tuple(v2[0], v2[1], v2[2]);
        std::cout << "v2_0 = " << v2_0 << ", v2_1 = " << v2_1 << ", v2_2 = " << v2_2 << std::endl;

        int i = 0;
        for (auto e : v3) {
            std::cout << "v3_" << i++ << " = " << e << std::endl;
        }
        std::cout << "v3.size = " << v3.size() << ", i = " << i << std::endl;
    }

    { // C++11 不使用auto声明的括号初始化
        auto v {1}; // v is int
        /*
         auto w {1, 2}; // error: only single elements in direct auto initialization allowed! (this is new)
         */
        /* 当在初始化STL容器时，例如 std::vector ， std::list 等， {} 初始化， 就会去匹配 std::initializer_list (初始化列表)的构造函数，从*/
        auto x = {1}; // x is std::initializer_list<int>
        auto y = {1, 2}; // y is std::initializer_list<int>
        /* deduced conflicting types for parameter 'auto' ('int' and 'double')
         auto z = {1, 2, 3.0}; // error: Cannot deduce element type
         */
        auto z1 = (1, 2, 3.0); // 逗号表达式，z1 = 3.0
        std::cout << "z1 = " << z1 << std::endl;

        /*
         * {} 与 () 调用构造函数初始化的方式，不同点在于 {} 没有类型的隐式转换，
         * int x(1.2); 和 int x = 1.2; 通过静默的对浮点值进行向下取整，然后将其转换为整型，从而将x的值初始化为1
         * int x{1.2}; 将会遇到编译错误，初始化列表中的初始值，需要与变量声明的类型完全匹配。即 1.2 需要是int类型数据
         */

        /*
        auto var_name {one_element}; 将会推导出var_name的类型(与one_element一样)。
        auto var_name {element1, element2, ...}; 是非法的，并且无法通过编译。 只能有有一个变量
        auto var_name = {element1, element2, ...}; 将会使用 std::initializer_list<T> 进行初始化，列表中elementN变量的类型均为T。
         */
    }
}

