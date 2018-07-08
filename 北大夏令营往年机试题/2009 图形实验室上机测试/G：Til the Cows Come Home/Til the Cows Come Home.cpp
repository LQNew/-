//���͵����·�����⣬��Ŀ�ѶȲ��󣬵��ǵ�Դ dijkstra�㷨�������е㸴�ӣ������������Ҫ���룡�Է��ٳ��벻������
#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
const int INF=0x7fffffff;
int T,N;
struct Edge{
    int next; //ָ�����һ���ڵ�
    int cost;
};
vector<Edge> edge[1001];
int Dist[1001];
bool mark[1001];
int dst1,dst2;
int cost1;
int main(){
    cin>>T>>N;
    for(int i=1;i<=N;i++) edge[i].clear(); //�����еı����Ӿ����
    for(int i=0;i<T;i++){ //�����ٽ�ͼ
        cin>>dst1>>dst2>>cost1;
        Edge tmp;
        tmp.cost=cost1;
        tmp.next=dst2;
        edge[dst1].push_back(tmp);
        tmp.next=dst1;
        edge[dst2].push_back(tmp);
    }
    memset(Dist,-1,sizeof(Dist));
    memset(mark,0,sizeof(mark));
    Dist[N]=0;
    mark[N]=true;
    int newP=N;
    for(int i=0;i<N;i++){
        for(int j=0;j<edge[newP].size();j++){ //�������Ľڵ����������û��ʲô·�����Ը���
            int t=edge[newP][j].next;
            int c=edge[newP][j].cost;
            if(mark[t]) continue; //�ýڵ��Ѿ�Ϊ�������·���ļ����У����ٲ�
            if(Dist[t]==-1||Dist[t]>Dist[newP]+c){
                Dist[t]=Dist[newP]+c;
            }
        }
        int min1=INF;
        for(int j=1;j<=N;j++){ //�ҵ���ǰ����ʣ���·������̵�·��
            if(mark[j]) continue;
            if(Dist[j]==-1) continue;
            if(Dist[j]<min1){
                min1=Dist[j];
                newP=j;
            }
        }
        mark[newP]=true;
    }
    cout<<Dist[1]<<endl;
}
