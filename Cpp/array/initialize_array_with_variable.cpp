#include <iostream>
using namespace std;

// reference [Array[n] vs Array[10] - Initializing array with variable vs real number](https://stackoverflow.com/questions/15013077/arrayn-vs-array10-initializing-array-with-variable-vs-real-number)

int main()
{
    int n = 10;
    double* a = new double[n]; // Don't forget to delete [] a; when you're done!
    delete [] a;

    return 0;
}