#include <stdlib.h>
#include <iostream>
using namespace std;

struct HeaderInfo
{
    unsigned  fl_id:16,   // 位域  https://zh.cppreference.com/w/cpp/language/bit_field
              tuple_num:16,  // 占几 bit
              fl_offset:32;
};

int main(void)
{
    HeaderInfo write_info;
    write_info.fl_id = 0x101;  // 十六进制
    write_info.tuple_num = 32;
    write_info.fl_offset = 0x0012;

    cout<<write_info.fl_id<<endl;
    cout<<write_info.tuple_num<<endl;
    cout<<write_info.fl_offset<<endl;
    cout<<"---------"<<endl;

    FILE* f_write = fopen("write_struct.txt", "wb");
    fwrite(&write_info, sizeof(HeaderInfo), 1, f_write);
    fclose(f_write);

    HeaderInfo read_info;
    FILE* f_read = fopen("write_struct.txt", "rb");
    fread(&read_info, sizeof(HeaderInfo), 1, f_read);
    fclose(f_read);
    printf("%d\n", read_info.tuple_num);
//	printf("%x\n", read_info.tuple_num); // 十六进制输出

    cout<<"---------"<<endl;

    cout<<read_info.fl_id<<endl;
    cout<<read_info.tuple_num<<endl;
    cout<<read_info.fl_offset<<endl;

	return 0;
}

