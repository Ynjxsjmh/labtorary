#include <cstdio>
#include <iostream>
using namespace std;

int main()
{
    FILE * pFile;

    char a = '9';
    pFile = fopen ( "write_char_read_int.out" , "wb" );
    fwrite(&a , sizeof(int), 1, pFile );
    fflush(pFile);
    fclose(pFile);

    int x;
    pFile = fopen ( "write_char_read_int.out" , "rb" );
    fread(&x , sizeof(int), 1, pFile);
    fflush(pFile);
    fclose(pFile);

    cout<<x<<endl;

    return 0;
}