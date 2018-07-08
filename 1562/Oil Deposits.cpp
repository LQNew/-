/*
    ����ͼ����ͼ����ͨ������Ŀ����һ����������⣬�����������ù��Ѽӱ����ķ�����ȡ���е���ͨ��Ŀ���ⷨ��˼·�ܾ���ֵ��һ������
*/
#include<iostream>
#include<queue>
using namespace std;
int m,n;
char map1[101][101];
bool mark[101][101];
struct Node{
    int x;
    int y;
};
queue<Node>Q;
int go[][2]={
    -1,0,
    0,1,
    0,-1,
    1,0,
    1,1,
    -1,1,
    1,-1,
    -1,-1
};
void Bfs(){ //Bfs�������еĵ�ǰ��������������
    while(!Q.empty()){
        Node new_1=Q.front();
        Q.pop();
        for(int i=0;i<8;i++){
            int nx=new_1.x;
            int ny=new_1.y;
            nx+=go[i][0];
            ny+=go[i][1];
            if(nx<=0||ny<=0||nx>m||ny>n) continue;
            if(map1[nx][ny]=='*') continue;
            if(mark[nx][ny]) continue;
            Node tmp;
            tmp.x=nx;
            tmp.y=ny;
            Q.push(tmp);
            mark[nx][ny]=true;
        }
    }
}
int main(){
    while(cin>>m>>n){
        if(m==0) break;
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                cin>>map1[i][j];
                mark[i][j]=false;
            }
        }
        int ans=0;
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){ //�ҳ�������ͨ��
                if(mark[i][j]) continue;
                if(map1[i][j]=='*') continue;
                Node tmp;
                tmp.x=i;
                tmp.y=j;
                while(!Q.empty()) Q.pop();
                Q.push(tmp);
                Bfs();
                ans++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
