/**
* brief:
* Created by lzy on 2024-08-30.
*/

#include <string>
#include <stdio.h>
#include <iostream>

struct C {
#if 1
    static const inline std::string N {"abc"};
};
#else
    static std::string& N() {
        static std::string s {"abc"};
        return s;
    }
};
#endif

int main()
{
    printf("%s\n", C::N.c_str());
    std::cout << C::N <<std::endl;
}

/*
 *  g++ -E 06_inline_variable.cpp > 06_inline_variable(g++ -E).txt
 *  gcc --save 06_inline_variable.cpp --save-temps
 */