#include <iostream>
using namespace std;

int max_value(int x,int y)
{
    if(x>y)
    {
      return x;
    }

    else
    {
      return y;
    }

}
int main()
{
    int number1,number2;
    cout<<"Enter the 2 Number : ";
    cin>>number1>>number2;
    cout<<number1<<" and "<<number2<<" Max value is : "<<max_value(number1,number2)<<endl;
    return 0;
}
