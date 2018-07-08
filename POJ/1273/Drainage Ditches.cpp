//ʹ��Edmonds Karp�㷨������������
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

const int N = 210;
const int INF = 0x7FFFFFFF;
int n,m,map[N][N],path[N],flow[N],start,end_1;
queue<int> q;

int bfs(){
    int i,t;
    while(!q.empty()) q.pop();
    memset(path,-1,sizeof(path));
    path[start]=0,flow[start]=INF;
    q.push(start);
    while(!q.empty()){
        t=q.front();
        q.pop();
        if(t==end_1) break;
        for(i=1;i<=m;i++){
            if(i!=start && path[i]==-1 && map[t][i]){
                flow[i]=flow[t]<map[t][i]?flow[t]:map[t][i];
                q.push(i);
                path[i]=t;
            }
        }
    }
    if(path[end_1]==-1) return -1;
    return flow[m];                   //һ�α���֮�����������
}
int Edmonds_Karp(){
    int max_flow=0,step,now,pre;
    while((step=bfs())!=-1){          //�Ҳ�����·��ʱ�˳�
        max_flow+=step;
        now=end_1;
        while(now!=start){
            pre=path[now];
            map[pre][now]-=step;      //��������ߵ�ʵ������
            map[now][pre]+=step;      //��ӷ����
            now=pre;
        }
    }
    return max_flow;
}
int main(){
    int i,u,v,cost;
    while(scanf("%d %d",&n,&m)!=EOF){
        memset(map,0,sizeof(map));
        for(i=0;i<n;i++){
            scanf("%d %d %d",&u,&v,&cost);
            map[u][v]+=cost;           //not just only one input
        }
        start=1,end_1=m;
        printf("%d\n",Edmonds_Karp());
    }
    return 0;
}
