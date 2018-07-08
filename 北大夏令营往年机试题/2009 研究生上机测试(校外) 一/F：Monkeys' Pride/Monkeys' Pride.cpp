//������о���ˮ�������ҵ�˼·ʼ��û�򿪣���ô�򵥵��߼��⾹Ȼ������ô�ã���Ӧ�ã���
#include<iostream>
using namespace std;
struct Node{
    int x;
    int y;
};
int N;
Node node[50000];

int compare(const void* a, const void* b){
    Node* p1;
    Node* p2;
    p1=(Node*)a;
    p2=(Node*)b;
    if((*p1).x>(*p2).x) return 1;
    else if((*p1).x==(*p2).x) return (*p1).y-(*p2).y;
    else return -1;
}

int main(){
    while(cin>>N){
        if(N==0) break;
        for(int i=0;i<N;i++){
            cin>>node[i].x>>node[i].y;
        }
        qsort(&node[0],N,sizeof(Node),compare);
        int max1=node[N-1].y; //���ҵ��󣬼�Xֵ�Ӵ�С��һ����yֵ�Ǳ�֮ǰ�����Ķ�����ôans++
        int ans=1;
        for(int i=N-2;i>=0;i--){
            if(node[i].y>max1){
                ans++;
                max1=node[i].y;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
