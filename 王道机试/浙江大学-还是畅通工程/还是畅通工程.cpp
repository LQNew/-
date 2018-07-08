/*
    ʡ��������ͨ���̡���Ŀ����ʹȫʡ�κ�������ׯ�䶼����ʵ�ֹ�·��ͨ������һ����ֱ�ӵĹ�·������ֻҪ�ܼ��ͨ����·�ɴＴ�ɣ���
    ��Ҫ������Ĺ�·�ܳ���Ϊ��С���������С�Ĺ�·�ܳ��ȡ�
*/
//���������ǵ����͵���С���������⣬����Kruskal�㷨,ÿ���ҵ�����ͼ�нڵ�����·�����б�ñ��Ƿ��ѻ��ֵ����·���ļ�����
//������Ƕ�˼�������ᷢ�֣�����Ǹ�����+���鼯���⣬ÿ���ҵ������ڵ�ǰ���ϵĵ�ǰ��̱ߣ��ͽ��䲢�����·���У�����¼��Ȩֵ
//���Ȩֵ֮�ͱ��������������Ȩֵ~
#include<iostream>
using namespace std;
int N;
int Tree[101];
int a,b;
int ans;

struct Node
{
    int a;
    int b;
    int cost;
};
Node node[5000];

int compare(const void*a,const void*b) //��Խṹ��Ŀ�������
{
    Node*p;
    Node*p1;
    p=(Node*)a;
    p1=(Node*)b;
    return (*p).cost-(*p1).cost;
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
    while(cin>>N)
    {
        if(N==0) break;
        ans=0;
        for(int i=1;i<=N;i++)
            Tree[i]=-1;
        for(int i=0;i<(N*(N-1))/2;i++)
            cin>>node[i].a>>node[i].b>>node[i].cost;
        qsort(node,(N*(N-1))/2,sizeof(Node),compare);
        for(int i=0;i<(N*(N-1))/2;i++) //�������нṹ�壬�ҵ���С������
        {
            a=find_Root(node[i].a);
            b=find_Root(node[i].b);
            if(a!=b)
            {
                Tree[a]=b;
                ans+=node[i].cost;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
