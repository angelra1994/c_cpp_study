/**
* brief: constructor automatically deduce the resulting template class type
C++17能让编译器自动的从所调用的构造函数，推导出模板类型。（c++的类，可以从构造函数推导出类型）
* Created by lzy on 2024-08-28.
*/

#include <tuple>
#include <string>
#include <type_traits>
#include <iostream>

template <typename T1, typename T2, typename T3>
class my_wrapper {
public:
    T1 t1;
    T2 t2;
    T3 t3;

// public:
    // explicit my_wrapper(T1 t1_, T2 t2_, T3 t3_)
    my_wrapper(T1 t1_, T2 t2_, T3 t3_)
        : t1{t1_}, t2{t2_}, t3{t3_}
    {}

    // 添加一个接受初始化列表的构造函数
    /* … */
};

// C++17之前，实现一个工厂函数的方式
template <typename T1, typename T2, typename T3>
my_wrapper<T1, T2, T3> make_wrapper(T1 t1, T2 t2, T3 t3)
{
    return {t1, t2, t3};
}


template <typename T>
struct sum {
    T value;

    // 使用折叠表达式添加到一起
    template <typename ... Ts>
    sum(Ts&& ... values) : value{(values + ...)} {}
};

/*
 * 指导性显式推导，会告诉编译器使用 std::common_type_t 的特性，其能找到适合所有值的共同类型
 * 目的是当提供多个类型（整型、浮点和双浮点），然后让编译器自动选择最合适的类型
 */
template <typename ... Ts>
sum(Ts&& ... ts) -> sum<std::common_type_t<Ts...>>;


int main()
{
    {
        std::pair my_pair (123, "abc"); // std::pair<int, const char*>
        std::cout << my_pair.first << ", " << my_pair.second << std::endl;
        std::tuple my_tuple (123, 12.3, "abc"); //std::tuple<int, double, const char*>
        std::cout << std::get<0>(my_tuple) << ", " << std::get<1>(my_tuple) << ", " << std::get<2>(my_tuple) << std::endl;
    }
    {
        my_wrapper<int, double, const char *> wrapper_cpp11 {123, 1.23, "wrapper_cpp11_abc"};
        std::cout << wrapper_cpp11.t1 << ", " << wrapper_cpp11.t2 << ", " << wrapper_cpp11.t3 << std::endl;
        my_wrapper wrapper_cpp17 {123, 1.23, "wrapper_cpp17_abc"};
        std::cout << wrapper_cpp17.t1 << ", " << wrapper_cpp17.t2 << ", " << wrapper_cpp17.t3 << std::endl;
        my_wrapper wrap (123, 4.56, std::string{"wrap_foo"});
        std::cout << wrap.t1 << ", " << wrap.t2 << ", " << wrap.t3 << std::endl;

        // auto wrapper = make_wrapper(123, 1.23, "make_wrapper_abc");
        auto wrapper (make_wrapper(123, 1.23, "make_wrapper_abc"));
        std::cout << wrapper.t1 << ", " << wrapper.t2 << ", " << wrapper.t3 << std::endl;
    }

    std::pair  pair  (123, std::string{"string"});
    std::tuple tuple (123, 4.56, std::string{"string"});

    // sum对象s(sum<double>), 构造函数的参数（传入的T的类型）类型为 unsigned, double, int 和 float。 std::common_type_t 将返回double 作为共同类型
    sum s          {1u, 2.0, 3, 4.0f};
    // sum对象s(sum<std::string>), 构造函数的参数（传入的T的类型）是std::string instance 实例 和一个C语言风格字符串(C-style string)
    // 编译器推导出 sum string_sum 的实例类型为 sum<std::string>
    sum string_sum {std::string{"abc"}, "def"};

    std::cout << s.value          << '\n'
              << string_sum.value << '\n';
}