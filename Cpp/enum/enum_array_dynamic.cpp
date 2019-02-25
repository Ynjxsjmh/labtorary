#include <vector>
#include <iostream>
using namespace std;

enum Color {red, yellow, blue, white, black}; //声明枚举类型color

int main()
{
    int n = 3;
    vector<Color> arr(n);

    arr.push_back(Color::red);
    arr.push_back(Color::black);

    // now size is 5
    cout<<arr.size()<<endl;

    for (int i = 0; i < arr.size(); i++)
    {
        switch(arr[i])
		{
			case Color::red:
				cout<<"red"<<endl;
				break;
			case Color::yellow:
				cout<<"yellow"<<endl;
				break;
			case Color::blue:
				cout<<"blue"<<endl;
				break;
			case Color::white:
				cout<<"white"<<endl;
				break;
			case Color::black:
				cout<<"black"<<endl;
				break;
		}
    }

    return 0;
}