#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int main()
{
    string test = "hello world";
    const char* buffer = test.c_str();
    int x = 10;

    FILE* write;
    write = fopen("write_char_asterisk_and_any_other.out", "wb");
    fwrite(buffer, sizeof(char), strlen(buffer), write);
    fwrite(&x, sizeof(int), 1, write);
    fclose(write);


    FILE* read;
    int y = 0;
    char* buf;
    read = fopen("write_char_asterisk_and_any_other.out", "rb");
    fread(buf, sizeof(char), strlen(buffer), read);
    fread(&y, sizeof(int), 1, read);
    fclose(read);

    std::cout << buf << std::endl;
    std::cout << y << std::endl;

    return 0;
}