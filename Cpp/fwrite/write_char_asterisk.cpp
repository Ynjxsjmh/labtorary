#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int main()
{
    string test = "xyz";
    const char* buffer = test.c_str();

    std::cout << buffer << std::endl;
    std::cout << strlen(buffer) << std::endl;
    std::cout << sizeof(char) << std::endl;

    FILE* write;
    write = fopen("write_char_asterisk.out", "wb");
    fwrite(buffer, sizeof(char), strlen(buffer), write);
    fclose(write);

    FILE* read;
    char* buf;
    read = fopen("write_char_asterisk.out", "rb");
    // using Dev-C++ is ok
    // using emacs's MinGW crashes
    fread(buf, sizeof(char), strlen(buffer), read);
    fclose(read);
    cout<< buf;

    return 0;
}
