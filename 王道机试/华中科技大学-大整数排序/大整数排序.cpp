/*
    ��N��������ɴﵽ1000������������
    ��������:
        �����һ��Ϊһ������N��(1<=N<=100)��
        ��������N��ÿ����һ���������ĳ��ȷ�ΧΪ1<=len<=1000��
        ÿ��������һ�����������ұ�֤������ǰ׺�㡣
    �������:
        �����ж���������ݣ�����ÿ�����ݣ���������N������С�������������������Ľ����ÿ����ռһ�С�
*/
//���������ת��Ϊ�ַ����������⣬�ýṹ��洢�ټ��Ͽ���������������AC��
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int N;
struct Node
{
    char Num[1001];
};
Node node[100];

int compare(const void*a,const void*b)
{
    Node*p;
    Node*p1;
    p=(Node*)a;
    p1=(Node*)b;
    if(strlen((*p).Num)==strlen((*p1).Num))
        return strcmp((*p).Num,(*p1).Num); //����ѧ������
    else
        return strlen((*p).Num)-strlen((*p1).Num);
}

int main()
{
    while(cin>>N)
    {
        for(int i=0;i<N;i++)
            cin>>node[i].Num;
        qsort(node,N,sizeof(Node),compare);
        for(int i=0;i<N;i++)
            cout<<node[i].Num<<endl;
    }

}
