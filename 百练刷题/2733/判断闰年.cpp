/*
    ����
        �ж�ĳ���Ƿ������ꡣ
    ����
        ����ֻ��һ�У�����һ������a(0 < a < 3000)
    ���
        һ�У������Ԫa�����������Y���������N
*/
//ˮ��
#include<iostream>
using namespace std;
int a;
int main()
{
    cin>>a;
    if(a%4==0)
    {
        if(a%100==0&&a%400!=0)
            cout<<"N"<<endl;
        else
            cout<<"Y"<<endl;
    }
    else
        cout<<"N"<<endl;
    return 0;
}
