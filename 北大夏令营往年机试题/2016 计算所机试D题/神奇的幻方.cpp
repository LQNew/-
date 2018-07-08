/*
    ����
        �÷���һ���������N*N��������ÿ�С�ÿ����Խ��ߣ������������ֺͶ�����ͬ�ġ�
        ���ǿ���ͨ�����·�������һ���÷���������Ϊ������
        1.��һ������д�ڵ�һ�е��м�
        2.��һ�����֣���д����һ�����ֵ����Ϸ���
            a.����������ڵ�һ�У�����һ������д�����һ�У�����Ϊ�����ֵ���һ��
            b.��������������һ�У�����һ������д�ڵ�һ�У�����Ϊ�����ֵ���һ��
            c.��������������Ͻǣ����߸����ֵ����Ϸ��������֣�����һ������д�ڸ����ֵ��·�
    ����
        һ������N��N<=20��
    ���
        ���Ϸ��������2N-1 * 2N-1�Ļ÷�
*/
//�������������ۣ��Ѹ�������о���ϸ~
#include<iostream>
#include<string.h>
using namespace std;
int Matrix[40][40]; //��һ���������洢���Ϊ39*39�ľ���
int N;
int last_i,last_j; //����һ���������ڼ�¼��һ�ε������

void Fill_grid(int i,int j,int num) //�оٳ���������±������
{
    if(i==1)
    {
        if(j==2*N-1)
        {
            Matrix[i+1][j]=num;
            last_i=i+1;
            last_j=j;
        }
        else{
        Matrix[2*N-1][j+1]=num;
        last_i=2*N-1;
        last_j=j+1;}
    }
    else if(j==2*N-1)
    {
        Matrix[i-1][1]=num;
        last_i=i-1;
        last_j=1;
    }

    else if(Matrix[i-1][j+1])
    {
        Matrix[i+1][j]=num;
        last_i=i+1;
        last_j=j;
    }
    else
    {
        Matrix[i-1][j+1]=num;
        last_i=i-1;
        last_j=j+1;
    }
}

int main()
{
    cin>>N;
    memset(Matrix,0,sizeof(Matrix));
    last_i=1;last_j=N;
    Matrix[1][N]=1;
    for(int num=2;num<=(2*N-1)*(2*N-1);num++)
    {
        Fill_grid(last_i,last_j,num);
    }
    for(int i=1;i<=2*N-1;i++)
    {
        for(int j=1;j<=2*N-1;j++)
        {
            cout<<Matrix[i][j]<<"  ";
        }
        cout<<endl;
    }
    return 0;
}
