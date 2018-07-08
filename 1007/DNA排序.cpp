/*
    ����
        ������һЩ������ȵ�DNA����ֻ��ACGT�ĸ���ĸ��ɣ����뽫���ǰ�������Ե�������������
        �����ָ�����ַ���A�е������ַ�A[i]��A[j]������i < j �� A[i] > A[j] �����ʡ����ַ�����ATCG���У�T��C��һ������ԣ�T��G����һ������ԣ�
        ����ַ������������Ϊ2��
    ����
        ��1�У���������n��m��n(0<n<=50)��ʾ�ַ������ȣ�m(0<m<=100)��ʾ�ַ�������
        ��2��m+1�У�ÿ����һ������Ϊn���ַ���
    ���
        ������������ٵ�������ַ������������һ������ַ������������˳�������
*/
//����������������ַ������ȼ������������֮������������Ķ������������������������˼·��Ϊ��������Ҫ�õ��˽ṹ���������ʹ�������ø��Ӽ��~
#include<iostream>
#include<algorithm>
using namespace std;
int m,n;
char str[101][51];
struct Node
{
    int num;
    int subscript;
};
Node node[100];

int find_num(int i) //�ҵ�������
{
    int sum=0;
    for(int j=0;j<n-1;j++)
    {
        for(int k=j+1;k<n;k++)
        {
            if(str[i][j]>str[i][k])
                sum++;
        }
    }
    return sum;
}

int compare(const void*a,const void*b) //����qsort ʹ�õ�compare�������йش�compare��������дӦ���⣡��ʽ����һ�µģ��Լ�Ҫ��Ϥд��~
//�˴����������������������������ȣ�������˳������
{
    Node*p1;
    Node*p2;
    p1=(Node*)a;
    p2=(Node*)b;
    if((*p1).num==(*p2).num)
        return((*p1).subscript-(*p2).subscript);
    else
        return((*p1).num-(*p2).num);
}

int main()
{
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        cin>>str[i];
        node[i].subscript=i;
    }

    for(int i=0;i<m;i++)
    {
        node[i].num=find_num(i);
    }

    qsort(node,m,sizeof(Node),compare); //qsort ���ڽṹ��Ŀ�������!!
    for(int i=0;i<m;i++)
    {
        cout<<str[node[i].subscript]<<endl;
    }
}
