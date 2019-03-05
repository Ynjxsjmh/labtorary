#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    std::vector<int> v;

    for (int i = 10; i > 0; i--) {
    	v.push_back(i);
	}

    std::vector<int>::iterator smallest = std::min_element(v.begin(), v.end());
    std::cout << "Min element is " << *smallest<< " at position " << std::endl;

    std::cout << *smallest + 2 << std::endl;

    return 0;
}
