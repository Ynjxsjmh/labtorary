#include <cstdio>
#include <iostream>
using namespace std;

int main ()
{
    FILE * pFile;

    pFile = fopen ( "override_write.out" , "wb" );
    for (int i = 0; i < 10; i++)
    {
        fwrite(&i , sizeof(int), 1, pFile );
    }
    fflush(pFile);
    fclose(pFile);

    pFile = fopen ( "override_write.out" , "rb" );
    for (int i = 0; i < 10; i++)
    {
        int x = 0;
        fread(&x, sizeof(int), 1, pFile);
        cout<<x<<endl;
    }
    fflush(pFile);
    fclose(pFile);
	
	cout<<"-----------------"<<endl;

    pFile = fopen ( "override_write.out" , "rb+" );  // Ҫ�����ļ��Ļ���ʹ�� rb+ mode �� 
    fseek(pFile, 0, SEEK_SET);

    for (int i = 0; i < 10; i++)
    {
        int x = 0;
        fread(&x, sizeof(int), 1, pFile);
        cout<<x<<endl;
    }
    cout<<"-----------------"<<endl;

    fseek(pFile, 0, SEEK_SET);
    for (int i = 10; i < 20; i++)   // ����ԭ�ļ� 
    {
        fwrite(&i , sizeof(int), 1, pFile );
    }
    fflush(pFile);
    fclose(pFile);


    pFile = fopen ( "override_write.out" , "rb" );
    fseek(pFile, 0, SEEK_SET);
    for (int i = 100; i < 110; i++)
    {
        int x = 0;
        fread(&x, sizeof(int), 1, pFile);
        cout<<x<<endl;
    }
    fflush(pFile);
    fclose(pFile);

    return 0;
}

