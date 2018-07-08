//����һ��������N�����N�Ľ׳ˡ�(0<=N<=1000)
//���͵Ĵ����˷����ѶȲ�����Ҫ��ϸ�ڵĵط�����������һֱ��BUG��ԭ����memset�����ĵ��ô����Լ�1000�׳˴�С��һ��ʼ���õ������С�޷���ȫ��ͨ����
//�����ýϴ������������ͨ~
#include<iostream>
#include<cstring>
using namespace std;
int final_1[10000];
int final_2[10000];
int digit[4];
int N;
int flag_1,flag_2;

void decomposition(int n) //�ֽ⺯��
{
    memset(digit,0,sizeof(digit)); //��������ĳ�ʼ����ʽ��Ҫע��memset��ʹ�÷�������
    if(n<10)
    {
        digit[0]=n;
        flag_2=1;
    }
    else if(n>=10&&n<100)
    {
        digit[0]=n%10;
        digit[1]=n/10;
        flag_2=2;
    }
    else if(n>=100&&n<1000)
    {
        digit[0]=n%10;
        n=n/10;
        digit[1]=n%10;
        digit[2]=n/10;
        flag_2=3;
    }
    else
    {
        digit[3]=1;
        digit[2]=digit[1]=digit[0]=0;
        flag_2=4;
    }
}

void multiply(int n)//�����˷�
{
    memset(final_2,0,sizeof(final_2));
    for(int i=0;i<flag_1;i++)
    {
        for(int j=0;j<flag_2;j++)
            final_2[i+j]+=final_1[i]*digit[j];
    }
    for(int i=0;i<flag_1+flag_2-1;i++)
    {
        final_2[i+1]+=final_2[i]/10;
        final_2[i]=final_2[i]%10;
    }
    if(final_2[flag_1+flag_2-1]>0)
        flag_1=flag_1+flag_2;
    else
        flag_1=flag_1+flag_2-1;
}

int main()
{
    while(cin>>N)
    {
        memset(final_1,0,sizeof(final_1));
        decomposition(N);
        flag_1=flag_2;
        for(int i=0;i<flag_2;i++)
            final_1[i]=digit[i];
        N--;
        while(N>1)
        {
            decomposition(N);
            multiply(N);
            memcpy(final_1,final_2,sizeof(final_2[0])*10000);
            N--;
        }
        for(int i=flag_1-1;i>=0;i--)
            cout<<final_1[i];
        cout<<endl;
    }
    return 0;
}
