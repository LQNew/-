//�������������꣬�Խ����е㶼�������������������ܹ��ľ���ֵ����С��
//���������Ļ��ǳ�ͨ����˼·�����Ƶģ�ֻ��Ҫ�ȰѸ�����֮��˴˵ľ���ֵ�������Ȼ���ýṹ��洢��֮���ת��Ϊ�˻��ǳ�ͨ�����������
//�������õ���iomanip���setprecision()�����Լ�fixed��cstring���memset()������cmath���sqrt()����
#include<iostream>
#include <cmath>
#include<cstring>
#include<iomanip>
using namespace std;
int n;
float ans;
int a,b;
int Tree[101]; //�洢�ڵ�����Ƚڵ�
struct Node
{
    int a;
    int b;
    float cost;
};
Node node[5000];

struct Point //��¼�ڵ�����
{
    float x;
    float y;
};
Point point[101];

int compare(const void*a,const void*b) //��Խṹ��Ŀ�������
{
    Node*p;
    Node*p1;
    p=(Node*)a;
    p1=(Node*)b;
    if((*p).cost>(*p1).cost)
        return 1;
    else if((*p).cost<(*p1).cost)
        return -1;
    else
        return 0;
}

int find_Root(int x) //�ҵ���ǰ�������Ƚ��
{
    if(Tree[x]==-1) return x;
    else
    {
        int tmp=find_Root(Tree[x]);
        Tree[x]=tmp;
        return tmp;
    }
}

int main()
{
    while(cin>>n)
    {
        ans=0;
        memset(Tree,-1,sizeof(Tree[0])*(n+1));//����ĳ�ʼ��
        for(int i=1;i<=n;i++)
            cin>>point[i].x>>point[i].y;
        int k=0;
        for(int i=1;i<=n;i++)//�����ṹ��node
        {
            for(int j=i+1;j<=n;j++)
            {
                node[k].a=i;
                node[k].b=j;
                node[k].cost=sqrt((point[i].x-point[j].x)*(point[i].x-point[j].x)+(point[i].y-point[j].y)*(point[i].y-point[j].y));//��ȡ�ڵ�֮��˴˵ľ���
                k++;
            }
        }
        qsort(node,(n*(n-1))/2,sizeof(Node),compare);
        /*for(int i=0;i<(n*(n-1))/2;i++) //�������нṹ�壬�ҵ���С������
            cout<<node[i].a<<" "<<node[i].b<<" "<<node[i].cost<<endl;
        */
        for(int i=0;i<(n*(n-1))/2;i++) //�������нṹ�壬�ҵ���С������
        {
            a=find_Root(node[i].a);
            b=find_Root(node[i].b);
            if(a!=b)
            {
                Tree[a]=b;
                ans+=node[i].cost;
            }
        }
        cout<<fixed<<setprecision(2)<<ans<<endl;//����С�������λ���
    }
    return 0;
}
