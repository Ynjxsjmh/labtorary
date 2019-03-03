#include <vector>
#include <iostream>
using namespace std;

int main() {
    vector<int> nums;

    for (int i = 0; i < 10; i++) {
        nums.push_back(i);
    }

    nums.erase(nums.begin()+1);

    for (std::vector<int>::iterator it = nums.begin() ; it != nums.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << std::endl;

    return 0;
}