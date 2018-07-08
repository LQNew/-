//�������н��֮��˴˵ľ��룬�������1�Žڵ㵽�������ڵ�����·������
//���ǵ��͵ĵ�Դ���·�����⣬���Բ���Dijkstra�㷨�����㷨��ʵ�ַǳ����䣬����Ϊģ����������⣡��
#include<iostream>
#include<vector>
using namespace std;
int N,M;
int a,b,c;
struct E
{
    int next;
    int cost;
};
vector<E> edge[101];
bool mark[101];
int Dis[101];
int main()
{
    while(cin>>N>>M)
    {
        if(N==0&&M==0) break;
        for(int i=0;i<N;i++) edge[i].clear();
        for(int i=0;i<M;i++) //�������ͼ���ٽӾ����췽��~
        {
            cin>>a>>b>>c;
            E tmp;
            tmp.cost=c;
            tmp.next=b;
            edge[a].push_back(tmp); //�����ٽӾ���
            tmp.next=a;
            edge[b].push_back(tmp);
        }
        for(int i=1;i<=N;i++)
        {
            Dis[i]=-1;
            mark[i]=false;
        }
        Dis[1]=0; //�������ĵ�Ϊ���1�����øõ����������Ϊ0
        mark[1]=true;
        int newP=1;
        for(int i=1;i<N;i++) //ÿһ�ε�ѭ���ҳ�һ����1�������������Ľڵ��·��
        {
            for(int j=0;j<edge[newP].size();j++) //�ҳ������м��㵽��Ŀ��ڵ������·����������·��ֵ
            {
                int t=edge[newP][j].next;
                int cost=edge[newP][j].cost;
                if(mark[t]==true) continue;//�Ѿ�λ�����·����������
                if(Dis[t]==-1||Dis[t]>Dis[newP]+cost) //��ÿһ�ξ�����ǰ�м�ڵ���ת�õ��ľ���ȶԣ��ҳ���1�ڵ㵽�ýڵ�Ŀǰ����Сֵ
                    Dis[t]=Dis[newP]+cost;
            }
            int min_1=99999999;
            for(int j=1;j<=N;j++)//�ҳ�����ѭ��ʱ���·����Ӧ�Ľڵ�
            {
                if(mark[j]==true) continue;
                if(Dis[j]==-1) continue;
                if(Dis[j]<min_1)
                {
                    min_1=Dis[j];
                    newP=j;
                }
            }
            mark[newP]=true;
        }
        cout<<Dis[N]<<endl;
    }
}
