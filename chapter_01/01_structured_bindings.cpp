/**
* brief: Using structured bindings to unpack bundled return values
* 结构化绑定可以结合语法糖来自动推到类型，并可以从组对、元组和结构体中提取单独的变量。
* 在其他编程语言中，类似的特性称为解包
* Created by lzy on 2024-08-23.
*/

#include <chrono>
#include <iostream>
#include <map>
#include <tuple>
#include <stdexcept>

bool divide_remainder(int dividend, int divisor, int &fraction, int &remainder)
{
    if (divisor == 0) {
        return false;
    }
    fraction  = dividend / divisor;
    remainder = dividend % divisor;
    return true;
}

std::pair<int, int> divide_remainder(int dividend, int divisor)
{
    if (divisor == 0) {
        throw std::runtime_error{"Attempt to divide by 0"};
    }
    return {dividend / divisor, dividend % divisor};
}

std::tuple<std::string,
std::chrono::system_clock::time_point, unsigned>
stock_info(const std::string &name)
{
    return {std::string(__FILE__) + ":" + name, std::chrono::system_clock::now(), 123};
}

int main(int argc, char* argv[])
{
    {// 传统做法，用指针作为输出参数。经过函数调用后，指针所指向的内存空间记录需要的返回值
        int fraction, remainder;
        bool success = divide_remainder(16, 3, fraction, remainder);
        if (success)
        {
            std::cout << "old school way, 16 / 3 is " << fraction << " with a remainder of " << remainder << "\n";
        }
    }

    {// C++11 方式，使用auto自动推导 result类型。推导成 pair<int, int>
        auto result (divide_remainder(16, 3));
        std::cout << "C++11 way, 16 / 3 is " << result.first << " with a remainder of " << result.second << '\n';
    }

    { // C++11, ignoring fraction part of result; std::tie中可以使用 std::ignore 的值 类似 python中 res, _ = fun();
        // 结构化绑定不具备虚拟变量的功能
        int remainder;
        std::tie(std::ignore, remainder) = divide_remainder(16, 5);
        std::cout << "16 % 5 with a remainder of  " << remainder << "\n";
    }

    { // C++17, use structured bindings
        auto [fraction, remainder] = divide_remainder(16, 3);
        std::cout << "16 / 3 is " << fraction << " with a remainder of " << remainder << "\n";
        // 对于tuple使用结构化绑定
        auto [a, b] = std::make_tuple(1, 2.0);
        std::cout << "a = " << fraction << ", b = "<< b << "\n";

    }

    { // C++17, decompose a tuple into individual vars
        std::tuple<int, float, long> tuple {1, 2.0, 3};
        auto [a, b, c] = tuple;
        std::cout << a << ", " << b << ", " << c << "\n";
    }

    { // C++17, use structured binding in for-loop
        std::map<std::string, size_t> animal_population {
                {"humans",   7000000000},
                {"chickens", 17863376000},
                {"camels",   24246291},
                {"sheep",    1086881528}
            /* … */
        };

        // 从 std::map 容器中获取元素，每次迭代会获得一个 pair<string, size_t> 类型的实例
        for (const auto &[species, count] : animal_population) {
            std::cout << "There are " << count << " " << species << " on this planet.\n";
        }
    }

    {
        const auto [name, now_time, price] = stock_info("你好");
        const std::time_t now_time_t = std::chrono::system_clock::to_time_t(now_time);
        std::cout << "Current time: " << std::ctime(&now_time_t);
    }

}

