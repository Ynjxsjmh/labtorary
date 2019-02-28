/* fwrite example : write buffer */
#include <cstdio>
#include <iostream>
using namespace std;

/*
 * size_t fwrite(const void* buffer, size_t size, size_t count, FILE* stream);
 *
 * 返回值：返回实际写入的数据块数目
 *
 *（1）buffer：是一个指针，对 fwrite 来说，是要获取数据的地址；
 *（2）size：要写入内容的单字节数；
 *（3）count: 要进行写入 size 字节的数据项的个数；
 *（4）stream: 目标文件指针；
 *（5）返回实际写入的数据项个数 count。
 */

int main ()
{
    FILE * pFile;
    char buffer[] = { 'x' , 'y' , 'z' };
    pFile = fopen ( "write_array.out" , "wb" );
    fwrite(buffer , sizeof(char), sizeof(buffer) , pFile );
    fclose(pFile);

    cout<<sizeof(buffer)<<endl;
    std::cout << buffer << std::endl;

    char* buf;
    pFile = fopen ( "write_array.out" , "rb" ); // 只能用原来的 pFile, 换一个就出错。不知道问什么
    fread(buf, sizeof(char), sizeof(buffer), pFile);
    fclose(pFile);

    std::cout << buf << std::endl;

    return 0;
}
