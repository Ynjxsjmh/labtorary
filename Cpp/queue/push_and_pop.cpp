#include <queue>
#include <iostream>
using namespace std;

int main() {
    queue<int> q;

    for (int i = 0; i < 10; i++) {
        q.push(i);
    }

    while (!q.empty())
    {
        std::cout << ' ' << q.front();
        q.pop();
    }

    if (q.empty()) {
        std::cout << endl << "queue is empty now" << std::endl;
    }

    return 0;
}
