//�����������ı����⣬��Ŀ�ѶȲ��󣬵��Ǳ����Լ����˸��ӣ�������compare��������д�ϣ���Ϊ�Ƚϵ���double��������compare���ص���int���������Գ���Щ���⣬
//����double�����ķ��������д��Ӧ���Լ�ȥд������������������Ŀǰ�Ľⷨ������������ѧϰ��
#include<iostream>
#include<cmath>
#include<cstring>
#include<iomanip>
using namespace std;
int n;
struct Node{
    double x;
    double y;
};
struct Edge{
    int id1;
    int id2;
    double cost;
};
Node node[100];
Edge edge[10000];
int tree[100];

int find_root(int x){
    if(tree[x]==-1) return x;
    else{
        int tmp=find_root(tree[x]);
        tree[x]=tmp;
        return tmp;
    }
}

int compare(const void* a, const void* b){
    Edge*p1;
    Edge*p2;
    p1=(Edge*)a;
    p2=(Edge*)b;
    if((*p1).cost>(*p2).cost) return 1; //��������һ��ϸ����Ҫע�⣡������Ϊ������double�����㣬���Է������Ϊint�͵Ļ�һЩdouble��ת��������⣬���Թ���double�Ϳ��ŵ���дһ��Ҫ������
    else return -1;
}

int main(){
    cin>>n;
    for(int i=0;i<n;i++) cin>>node[i].x>>node[i].y;
    int cnt=0;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            edge[cnt].id1=i;
            edge[cnt].id2=j;
            edge[cnt].cost=sqrt((node[i].x-node[j].x)*(node[i].x-node[j].x)+(node[i].y-node[j].y)*(node[i].y-node[j].y));
            cnt++;
        }
    }
    qsort(&edge[0],cnt,sizeof(Edge),compare);
    memset(tree,-1,sizeof(tree));
    double ans=0.0;
    for(int i=0;i<cnt;i++){
        int root1=find_root(edge[i].id1);
        int root2=find_root(edge[i].id2);
        if(root1!=root2){ //Ϊ�˱���ɻ���
            tree[root1]=root2;
            ans+=edge[i].cost;
        }
    }
    cout<<fixed<<setprecision(2)<<ans<<endl;
    return 0;
}
