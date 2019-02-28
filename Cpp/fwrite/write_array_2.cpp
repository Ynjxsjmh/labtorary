#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int main ()
{
    FILE *fp;
    char msg[] = "file content";
    char buf[20];

    fp = fopen("write_array_2.out","wb");
    if (NULL == fp)
    {
        std::cout <<  "The file doesn't exist!" << std::endl;
        return -1;
    }
    fwrite(msg,strlen(msg),1,fp);      //把字符串内容写入到文件

    FILE* pread;
    pread = fopen("write_array_2.out","rb");
    fseek(fp,0,SEEK_SET);              //定位文件指针到文件开始位置
    fread(buf,strlen(msg),1,pread);    //把文件内容读入到缓存
    buf[strlen(msg)] = '\0';           //删除缓存内多余的空间

    std::cout << "buf = " << buf << std::endl;
    std::cout << "strlen(buf) = " << strlen(buf) << std::endl;

    fclose(fp);
    fclose(pread);
    return 0;
}