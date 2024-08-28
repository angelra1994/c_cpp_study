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
    T1 t1;
    T2 t2;
    T3 t3;

public:
    // explicit my_wrapper(T1 t1_, T2 t2_, T3 t3_)
    my_wrapper(T1 t1_, T2 t2_, T3 t3_)
        : t1{t1_}, t2{t2_}, t3{t3_}
    {}

    // 添加一个接受初始化列表的构造函数
    /* … */
};



template <typename T>
struct sum {
    T value;

    template <typename ... Ts>
    sum(Ts&& ... values) : value{(values + ...)} {}
};

// 指导性显式推导，会告诉编译器使用 std::common_type_t 的特性，其能找到适合所有值的共同类型
template <typename ... Ts>
sum(Ts&& ... ts) -> sum<std::common_type_t<Ts...>>;

template <typename T1, typename T2, typename T3>
my_wrapper<T1, T2, T3> make_wrapper(T1 t1, T2 t2, T3 t3)
{
    return {t1, t2, t3};
}

int main()
{
    {
        std::pair my_pair (123, "abc"); // std::pair<int, const char*>
        std::cout << my_pair.first << ", " << my_pair.second << std::endl;
        std::tuple my_tuple (123, 12.3, "abc"); //std::tuple<int, double, const char*>
        std::cout << std::get<0>(my_tuple) << ", " << std::get<1>(my_tuple) << ", " << std::get<2>(my_tuple) << std::endl;
    }
    {
        my_wrapper<int, double, const char *> wrapper_cpp11 {123, 1.23, "abc"};
        my_wrapper wrapper_cpp17 {123, 1.23, "abc"};
        // std::cout << wrapper_cpp17.t1 << ", " << wrapper_cpp17.t2 << ", " << wrapper_cpp17.t3 << std::endl;

        auto wrapper (make_wrapper(123, 1.23, "abc"));
        // std::cout << wrapper.t1 << ", " << wrapper.t2 << ", " << wrapper.t3 << std::endl;
    }
    my_wrapper wrap (123, 4.56, std::string{"foo"});

    std::pair  pair  (123, std::string{"string"});
    std::tuple tuple (123, 4.56, std::string{"string"});

    sum s          {1u, 2.0, 3, 4.0f};
    sum string_sum {std::string{"abc"}, "def"};

    std::cout << s.value          << '\n'
              << string_sum.value << '\n';
}