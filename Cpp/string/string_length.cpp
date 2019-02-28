#include <cstring>
#include <iostream>
using namespace std;

int main()
{
    string a = "1234567890";
    std::cout << a.length() << std::endl;
    std::cout << sizeof(a) << std::endl;


    const char* ch = a.c_str();
    std::cout << strlen(ch) << std::endl;
    std::cout << sizeof(ch) << std::endl;

    std::cout << ch << std::endl;
    std::cout << "------------------" << std::endl;
    std::cout << sizeof(char) << std::endl;


    return 0;
}