//���������ǵ��͵�̰�����⣬���Ƕ��Ҷ��ԣ���Ŀ����˼���ѽ�����˼·�����������ĺ���ǿ������ǿ��������AC orz...
//��������ǽ���ǰ������ֵ����յ�ʱ����ڣ��������н�㣬ֱ�������������Ļ���ʱ����������һ��������profit!!
#include<iostream>
#include<cstring>
using namespace std;
int n;
bool visit[10001];
struct Node{
    int profit;
    int deadline;
};
Node node[10000];
int compare(const void* a, const void* b){
    Node* p1;
    Node* p2;
    p1=(Node*)a;
    p2=(Node*)b;
    return (*p2).profit-(*p1).profit;
}
int main(){
    while(cin>>n){
        memset(visit,0,sizeof(visit));
        for(int i=0;i<n;i++) cin>>node[i].profit>>node[i].deadline;
        int ans=0;
        qsort(&node[0],n,sizeof(Node),compare);
        for(int i=0;i<n;i++){
            for(int j=node[i].deadline;j>0;j--){ //�ڹ涨��ʱ����������״̬����������profit!!
                if(!visit[j]){
                    visit[j]=true;
                    ans+=node[i].profit;
                    break;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
