#include <map>
#include <iostream>
using namespace std;

int main()
{
    std::map<int, int> test;
    test.insert(std::pair<int,int>(1,2));
    test.insert(std::pair<int,int>(4,5));

    if (test.find(3) == test.end())
    {
        std::cout << "3 doesn't exists" << std::endl;
    }

    if (test.find(2) == test.end())
    {
        std::cout << "2 doesn't exists" << std::endl;
    }
    else
    {
        std::cout << "2 does exists" << std::endl;
    }

    return 0;
}