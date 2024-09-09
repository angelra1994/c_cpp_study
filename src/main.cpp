#include <iostream>

int main()
{
    std::cout << "Hello, World! " << PROJECT_NAME << std::endl;
    int n = 10;
    int array[10];
    for ( int i = 0; i < n; i++)
    {
        array[i] = i + 1;
    }
    for ( int i = 0; i < n; i++)
    {
        std::cout << array[i] <<" \n"[i==n-1];
    }
    return 0;
}
