/*
    ����
        ����a3= b3 + c3 + d3�ĵ�ʽ����Ϊ����������ʽ������123= 63 + 83 + 103 ����дһ�����򣬶��θ���������N (N��100)��Ѱ�����е���Ԫ��(a, b, c, d)��
        ʹ��a3 = b3 + c3 + d3������a,b,c,d ���� 1, С�ڵ���N����b<=c<=d��
    ����
        һ��������N (N��100)��
    ���
        ÿ�����һ�����������������ʽΪ:Cube = a, Triple = (b,c,d)������a,b,c,d����λ�÷ֱ���ʵ�������Ԫ��ֵ���롣
        �밴��a��ֵ����С�����������������������������ʽ��a��ֵ��ͬ����bֵС���������������ͬ��cֵС���������������ͬ��dֵС���������
*/
//�������������ѶȽ�С�����Ǳ����ҵ�����������Ԫ�ز���ӡ
#include<iostream>
using namespace std;
int cube[101];//�洢<=N������ֵ
int N;
int a,b,c,d;
int main()
{
    cin>>N;
    for(int i=1;i<=N;i++)
        cube[i]=i*i*i;
    for(a=2;a<=N;a++)
    {
        for(b=2;b<a;b++)
        {
            if(cube[a]<cube[b]*3)
                break;
            for(c=b;c<a;c++)
            {
                if(cube[a]<cube[b]+cube[c]*2) break;
                for(d=c;d<a;d++)
                {
                    if(cube[a]<cube[b]+cube[c]+cube[d]) break;
                    if(cube[a]==cube[b]+cube[c]+cube[d])
                        cout<<"Cube = "<<a<<", Triple = ("<<b<<","<<c<<","<<d<<")"<<endl;
                }
            }
        }
    }
    return 0;
}
