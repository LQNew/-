//��С��������˼����ǣ����a��b�����Լ������a��b��˺󣬳���������Լ������a��b����С������~
#include<iostream>
using namespace std;
int a,b;
int main()
{
    while(cin>>a>>b)
    {
        int t;
        int a1=a;
        int b1=b;
        while(b!=0)
        {
            t=a;
            a=b;
            b=t%b;
        }
        cout<<(a1*b1)/a<<endl;
    }
    return 0;
}
