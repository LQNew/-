/*
    ����
        һ��ϸ���ķ�ֳ�ٶ���ÿ��ɱ����������磺��һ����10�����ڶ���ͱ��20������������40������������80����������
        ���ڸ�����һ������ں�ϸ����Ŀ��Ҫ��д���������ĳһ���ʱ��ϸ������Ŀ��
    ����
        ��һ����һ������n����ʾ�������ݵ���Ŀ�����n��ÿ����5������������֮����һ���ո��������һ������ʾ��һ����·ݣ��ڶ�������ʾ��һ������ڣ�
        ����������ʾ��һ��ϸ������Ŀ�����ĸ�����ʾҪ�����һ����·ݣ����������ʾҪ�����һ������ڡ�
        ��֪��һ���Ҫ���һ����ͬһ�겢�Ҹ��겻�����꣬Ҫ���һ��һ���ڵ�һ��֮�����ݱ�֤Ҫ���һ���ϸ����Ŀ�ڳ�������long����Χ�ڡ�
    ���
        ����ÿһ��������ݣ����һ�У����а���һ��������ΪҪ���һ���ϸ������
*/
//�����������������ᵽ��֤ϸ����Ŀ�ڳ����ͷ�Χ�ڣ����Կ��Ƕ�����Ŀ�Ĵ洢��long�����ͱ�ʾ
//���ڸ����·ݵ����������㣬��������һ�����齫�·ݵ��������洢�����У��������Խ�ʡʱ�俪����������˵��Ŀ�ѶȲ���
#include<iostream>
using namespace std;
int n;
int initial_month,initial_date,last_month,last_date;
long initial_num;
int month[13]={0,31,28,31,30,31,30,31,31,30,31,30,31}; //�����±�Ϊ0��û�����ã�����㸳ֵ0�����Ԫ��

long Pow(long initial_num,int days) //����ϸ���ķ�ֳ��
{
    while(days--)
        initial_num*=2;
    return initial_num;
}

int compute_days(int initial_month,int initial_date,int last_month,int last_date) //��������������
{
    int days=0;
    if(initial_month==last_month)
    {
        days=last_date-initial_date;
        return days;
    }
    else
    {
        for(int i=initial_month+1;i<last_month;i++)
            days+=month[i];
        days+=month[initial_month]-initial_date+last_date;
        return days;
    }
}
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>initial_month>>initial_date>>initial_num>>last_month>>last_date;
        int days=compute_days(initial_month,initial_date,last_month,last_date);
        long last_num=Pow(initial_num,days);
        cout<<last_num<<endl;
    }
    return 0;
}
