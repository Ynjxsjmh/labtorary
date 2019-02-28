#include <cstring>
#include <cstdio>
#include <iostream>
using namespace std;

int main()
{
    string test = "hello world";

    FILE* write;
    write = fopen("write_string.out", "wb");
    fwrite(test.c_str(), test.length(), 1, write);
    fclose(write);

    char* res;
    FILE* read;
    read = fopen("write_string.out", "rb");
    fread(res, sizeof(char), test.length(), read);
    std::cout << res << std::endl;
    fclose(read);

    return 0;
}