#include <iostream>
using namespace std;

enum Color {red, yellow, blue, white, black}; //声明枚举类型color

int main()
{
    Color arr[5] {Color::red, Color::red, Color::yellow, Color::black, Color::yellow};

    for (int i = 0; i < 5; i++)
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
