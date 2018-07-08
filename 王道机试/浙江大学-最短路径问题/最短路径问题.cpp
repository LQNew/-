/*
    ����n���㣬m������ߣ�ÿ���߶��г���d�ͻ���p���������s�յ�t��Ҫ�������㵽�յ����̾��뼰�仨��.�����̾����ж���·�ߣ�������������ٵġ�
*/
//���������͵����·�����⣬ֻ���������·�����ּ�����С���ѵ�Լ��������ֻ�������·��Դ�����������޸ľͿ��Խ��~
//Dijkstra�����侭�䣬һ��Ҫ�����⣡��
#include<iostream>
#include<vector>
using namespace std;
int N,M;
int a,b,d,p;
int s,t;
struct E
{
    int next;
    int cost;
    int money;
};
vector<E> edge[1001];
bool mark[1001];
int Dis[1001];
int money[1001];
int main()
{
    while(cin>>N>>M)
    {
        if(N==0&&M==0) break;
        for(int i=0;i<N;i++) edge[i].clear();
        for(int i=0;i<M;i++) //�������ͼ���ٽӾ����췽��~
        {
            cin>>a>>b>>d>>p;
            E tmp;
            tmp.cost=d;
            tmp.money=p;
            tmp.next=b;
            edge[a].push_back(tmp); //�����ٽӾ���
            tmp.next=a;
            edge[b].push_back(tmp);
        }
        cin>>s>>t;
        for(int i=1;i<=N;i++)
        {
            Dis[i]=-1;
            money[i]=0;
            mark[i]=false;
        }
        Dis[s]=0; //�������ĵ�Ϊ���1�����øõ����������Ϊ0
        money[s]=0;
        mark[s]=true;
        int newP=s;
        for(int i=1;i<N;i++) //ÿһ�ε�ѭ���ҳ�һ����1�������������Ľڵ��·��
        {
            for(int j=0;j<edge[newP].size();j++) //�ҳ������м��㵽��Ŀ��ڵ������·����������·��ֵ
            {
                int t=edge[newP][j].next;
                int cost=edge[newP][j].cost;
                int money_1=edge[newP][j].money;
                if(mark[t]==true) continue;//�Ѿ�λ�����·����������
                if(Dis[t]==-1||Dis[t]>Dis[newP]+cost) //��ÿһ�ξ�����ǰ�м�ڵ���ת�õ��ľ���ȶԣ��ҳ���1�ڵ㵽�ýڵ�Ŀǰ����Сֵ
                {
                    Dis[t]=Dis[newP]+cost;
                    money[t]=money[newP]+money_1;
                }
                else if(Dis[t]==Dis[newP]+cost&&money[t]>money[newP]+money_1)
                    money[t]=money[newP]+money_1;
            }
            int min_1=999999999;
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
        cout<<Dis[t]<<" "<<money[t]<<endl;
    }
}
