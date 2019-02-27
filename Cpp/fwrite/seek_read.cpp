#include <cstdio>
#include <iostream>
using namespace std;

int main ()
{
    FILE * pFile;

    pFile = fopen ( "seek_read.out" , "wb" );
    for (int i = 0; i < 10; i++)
    {
        fwrite(&i , sizeof(int), 1, pFile );
    }
    fclose(pFile);


    pFile = fopen ( "seek_read.out" , "rb" );
    for (int i = 0; i < 10; i++)
    {
        int x = 0;
        fread(&x, sizeof(int), 1, pFile);
        cout<<x<<endl;
    }
    fclose(pFile);


    pFile = fopen ( "seek_read.out" , "rb" );
    fseek(pFile, 4*sizeof(int), SEEK_SET);
    int y = 0;
    fread(&y, sizeof(int), 1, pFile);
    cout<<"----------"<<endl<<y<<endl;
    fclose(pFile);

    // 经过测试，fread 的第三个参数在这里不起作用
    pFile = fopen ( "seek_read.out" , "rb" );
    fseek(pFile, sizeof(int), SEEK_SET);
    fread(&y, sizeof(int), 2, pFile);
    cout<<"----------"<<endl<<y<<endl;
    fclose(pFile);

	return 0;
}
