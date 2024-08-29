/**
* brief: C++17 comes with constexpr-if expressions, which simplify the code for template type specializations
* 特化模板类型。C++17的 constexpr-if 表达式，可以在模板编程的情况下简化代码编译。（模板的泛化可能会导致大量的代码分支）
* 普通的 if 语句是在运行时进行条件判断，所有分支的代码都会被编译，但只有满足条件的分支在运行时会被执行。而 if constexpr 是在编译时进行条件判断，其条件必须是在编译时可确定的常量表达式。
* 常量表达式可以包括字面值、常量变量、以及由这些元素通过常量运算组成的表达式。eg: std::is_integral(标准库中的类型特征函数)，来判断模板参数的类型是否为整数类型
* 1. constexpr-if 的条件必须是在编译时可确定的常量表达式，这样条件的真假在编译时就能够被确定。编译器只会编译条件为真的分支
* 2. if constexpr 不支持短路规则
* 在优化方面，当知道特定条件总是为真或假时，可以使用 if constexpr 来优化代码。可以减少最终生成的可执行文件大小，提高编译效率，并且避免了运行时不必要的条件判断开销
* Created by lzy on 2024-08-30.
*/

#include <cassert>
#include <string>
#include <vector>
#include <iostream>

template <typename T>
class addable_0
{
    T val;

public:
    addable_0(T v) : val{v} {}

    template <typename U>
    T add(U x) const {
        return val + x;
    }

    /* std::is_same<T, std::vector<U>>。T类型是一个 vector，其每个元素都是 U 类型 */
    template <typename U>
    T add_1(U x)
    {
        auto copy (val); // Get a copy of the vector member
        for (auto& n : copy)
        {
            n += x;
        }
        return copy;
    }


    template<typename U>
    void process(U value)
    {
        if constexpr(std::is_integral<U>::value)
        { // 当 T 是整数类型时
            std::cout << val << ", 传入的U是整数类型，<U(int)>::value = " << value << std::endl;
        }
        else
        { // 当 T 不是整数类型时
            std::cout << val << ", 传入的U非整数类型，<U>::value = " << value << std::endl;
        }
    }
};



template <typename T>
class addable
{
    T val;

public:
    addable(T v) : val{v} {}

#if 0
    /* The C++11 way
    * 表达式，std::enable_if_t<condition, type> ，
    * 如果条件为真，那么就为 type 类型，反之 std::enable_if_t 表达式不会做任何事。这通常被认为是一个错误，
    * 不过我们能解释为什么什么都没做
    */
    template <typename U>
    std::enable_if_t<!std::is_same<T, std::vector<U>>::value, T>
    add(U x) const { return val + x; }

    template <typename U>
    std::enable_if_t<std::is_same<T, std::vector<U>>::value, std::vector<U>>
    add(U x) const {
        auto copy = val;
        for (auto &n : copy) {
            n += x;
        }
        return copy;
    }
#else
    // The C++17 way
    template <typename U>
    T add(U x) const {
        if constexpr (std::is_same_v<T, std::vector<U>>) {
            auto copy = val;
            for (auto &n : copy) {
                n += x;
            }
            return copy;
        } else {
            return val + x;
        }
    }
#endif

};

int main()
{
    using namespace std::string_literals;

    addable_0<int>{0}.process(5);
    addable_0 {0.1}.process(std::string{"abc"});
    addable_0 {0.2}.process("def");
    addable_0 {0.3}.process("ghi"s);
    std::pair my_pair (123, "abc");
    addable_0 {0.4}.process(my_pair.first);
    addable_0 {0.4}.process(my_pair.second);

    std::pair my_pair2 {321, std::string("def")};
    addable_0 {0.5}.process(my_pair2.first);
    addable_0 {0.45}.process(my_pair2.second);

    assert(addable<int>{2}.add(3) == 5);
    assert(addable<float>{1.f}.add(2) == 3);
    assert(addable<std::string>{"aa"s}.add("bb"s) == "aabb"s);

    std::vector<int> v1 {1, 2, 3};
    std::vector<int> v2 {11, 12, 13};
    assert(addable<std::vector<int>>{v1}.add(10) == v2);

    std::vector<std::string> sv1 {"a", "b", "c"};
    std::vector<std::string> sv2 {"az", "bz", "cz"};
    assert(addable<std::vector<std::string>>{sv1}.add("z"s) == sv2);
}