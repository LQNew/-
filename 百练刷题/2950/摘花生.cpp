/*
    ����
        ����ĵ�һ�а���һ������T����ʾ��������
        ÿ������ĵ�һ�а�������������M, N��K���ÿո��������ʾ������Ĵ�СΪM * N��1 <= M, N <= 50����
        ���ɻ������޶�ʱ��ΪK��0 <= K <= 1000������λʱ�䡣��������M�У�ÿ�а���N���Ǹ�������Ҳ�ÿո��������i + 1�еĵ�j������Pij��0 <= Pij <= 500��
        ��ʾ��������ֲ��(i, j)�»�������Ŀ��0��ʾ��ֲ����û�л�����
    ���
        �������T�У�ÿһ��ֻ����һ�������������޶�ʱ���ڣ���������Բɵ������ĸ�����
*/
//����������ÿ�ε���ָ����λ�ú��б�������һ���᲻����ʱ�䷵��
//ģ�����⣬�����߼����ɣ��˴����ھ���ֵ �ɴ� cmath�⵼��abs����
#include<iostream>
#include <cmath>
using namespace std;
int T;
int M,N,K;
int max_row,max_line; //�����ֵ�������ֵ
int row,line;//��ǰ��ֵ����ֵ
int max_value;//�������Ŀֵ
int value;
int Grid[51][51];

void find_max() //ÿ���ҵ�����л���������һ�������
{
    max_value=0;
    for(int j=1;j<=M;j++)
    {
        for(int k=1;k<=N;k++)
        {
            if(max_value<Grid[j][k])
            {
                max_value=Grid[j][k]; //��ȡ��ǰ���������ֵ
                max_row=j; //�����������
                max_line=k; //�����������
            }
        }
    }
}
int main()
{
    cin>>T;
    for(int i=0;i<T;i++)
    {
        cin>>M>>N>>K;
        for(int j=1;j<=M;j++)
        {
            for(int k=1;k<=N;k++)
                cin>>Grid[j][k];
        }
        find_max();
        int K_1=K;
        row=0;line =max_line;
        K_1-=abs(max_row-row)+abs(max_line-line)+max_row+1; //��ȥ��Ŀ�����ֵ���Լ�����������ʱ��
        while(K_1>=0)
        {
            K-=abs(max_row-row)+abs(max_line-line)+1;//��ȥ��Ŀ�����ֵ��������ʱ��
            K_1=K;
            value+=max_value;
            Grid[max_row][max_line]=0;
            row=max_row;line=max_line;
            find_max();
            if(max_value==0)
                break;
            K_1-=abs(max_row-row)+abs(max_line-line)+max_row+1;
        }
        cout<<value<<endl;
        value=0;
    }

}
