#include <vector>
#include <typeinfo>
#include <string.h>
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    vector<string> right;
    ifstream fin;
    fin.open(".\\ifstream_handle_csv_like.in");
    string str;

    while (!fin.eof())
    {
        getline(fin, str);
//        cout<<typeid(str.c_str()).name()<<"--"<<endl;  // PKc | pointer (P) to const (K) char (c) | const char*
        char* p = (char*)str.c_str();
        char* temp = strtok(p, ",");
        while(temp != NULL)
        {
        	cout<<temp<<" "<<typeid(temp).name()<<" ";
        	right.push_back(temp);
            temp = strtok(NULL, ",");
        }
        cout<<endl;
    }

    fin.close();

	cout<<right.size()<<endl;
    for (int i = 0; i < right.size(); i++)
    {
        cout<<right[i]<<"-----------"<<endl;
    }

    return 0;
}
