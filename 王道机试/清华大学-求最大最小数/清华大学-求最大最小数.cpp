/*
    ��Ŀ������
        ����N����N<=10000�����֣������N�������е����ֵ����Сֵ��ÿ�����ֵľ���ֵ������1000000��
    ���룺
        ��������������������ÿ�����������һ������N��ͷ������ȥһ�и���N��������
    �����
        �����������������Ϊ����N�����е����ֵ����Сֵ��
*/
#include<iostream>
#include<algorithm>
using namespace std;
long long int data[10000]; //1000000���� long long int �ʹ洢
int N;
int compare(const void*a,const void*b) //����qsort ʹ�õ�compare�������йش�compare��������дӦ���⣡
{
    return *(int*)a-*(int*)b;
}
int main()
{
    while(cin>>N)
    {
        for(int i=0;i<N;i++)
        {
            cin>>data[i];
        }
        qsort(data,N,sizeof(long long int),compare); //��������п�������
        cout<<data[N-1]<<" "<<data[0]<<endl;
    }
    return 0;
}
