/* fwrite example : write buffer */
#include <iostream>
using namespace std;

int main ()
{
    FILE * pFile;
    char buffer[] = { 'x' , 'y' , 'z' };
    pFile = fopen ( "write_buffer.out" , "wb" );
    fwrite(buffer , sizeof(char), sizeof(buffer) , pFile );
    fclose(pFile);

    cout<<sizeof(buffer)<<endl;

    char* buf;
    pFile = fopen ( "write_buffer.out" , "rb" );
    fread(buf, sizeof(char), sizeof(buffer), pFile);
    fclose(pFile);

    cout<<buf;
}
