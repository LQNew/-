//ŷ������㷨�����Լ���Ľⷨ��a��b�����Լ��һ��Ҳ�� b��a%b�����Լ��
//���a��b��bΪ0��aΪ����������ô���Լ��Ϊa���ǳ��õ��㷨˼·~
#include<iostream>
using namespace std;
int a,b;
int main()
{
    while(cin>>a>>b)
    {
        int t;
        while(b!=0)
        {
            t=a;
            a=b;
            b=t%b;
        }
        cout<<a<<endl;
    }
    return 0;
}
