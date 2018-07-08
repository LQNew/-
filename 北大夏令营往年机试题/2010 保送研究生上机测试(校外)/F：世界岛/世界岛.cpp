//�������綼��˼·�ˣ���һֱ�ڿ����������ö�ٻ᲻��TL�����⣬������ʵ֤���Ҷ�����...
//���͵���С���������⣬ģ���⣬�˴�����˼�����������Ҫ��С���������λ������������ʱ�����˸�floor+int Сtrick�������Ժ���Ϊ���ͽ���������䣡
#include<iostream>
#include<iomanip>
#include<cstring>
#include<cmath>
#include<queue>
#include<algorithm>
using namespace std;
int T;
int n;
struct Node{
    float x;
    float y;
};
Node node[51];
struct Edge{
    int start;
    int end1;
    float dist;
};
Edge edge[1300];
queue<Edge>Q;
int Tree[51];
int find_root(int x){
    if(Tree[x]==-1) return x;
    else{
        int tmp=find_root(Tree[x]);
        Tree[x]=tmp;
        return tmp;
    }
}
int compare(const void* a, const void* b){
    Edge* p1;
    Edge* p2;
    p1=(Edge*) a;
    p2=(Edge*) b;
    if((*p1).dist>(*p2).dist) return 1;
    else return -1;
}
int mark[50][2];
float distance[50];
int main(){
    cin>>T;
    for(int i=0;i<T;i++){
        cin>>n;
        for(int i=1;i<=n;i++) cin>>node[i].x>>node[i].y;
        double min1=99999999;
        for(int k=1;k<=n;k++){
            int cnt=0;
            for(int i=1;i<=n-1;i++){
                if(k==i) continue;
                for(int j=i+1;j<=n;j++){
                    if(j==k) continue;
                    edge[cnt].start=i;
                    edge[cnt].end1=j;
                    edge[cnt].dist=sqrt((node[i].x-node[j].x)*(node[i].x-node[j].x)+(node[i].y-node[j].y)*(node[i].y-node[j].y));
                    cnt++;
                }
            }
            qsort(&edge[0],cnt,sizeof(Edge),compare);
            float ans=0;
            memset(&Tree[1],-1,sizeof(Tree[0])*n);
            for(int i=0;i<cnt;i++){
                int a=find_root(edge[i].start);
                int b=find_root(edge[i].end1);
                if(a!=b){
                    Tree[a]=b;
                    ans+=edge[i].dist;
                }
            }
            if(ans<min1) min1=ans;
        }
        cout<<fixed<<setprecision(2)<<float(floor(min1*100+0.5)/100)<<endl;
    }
    return 0;
}
