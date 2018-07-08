/*
    Ignatius ��ħ��ץ����,��һ��ħ������ȥ��,����� Ignatius �����ĺû���.ħ��ס��һ���Ǳ���,�Ǳ���һ�� A*B*C ��������,���Ա���ʾ�� A �� B*C �ľ�
    ��,�տ�ʼ Ignatius ������(0,0,0)��λ��,�뿪�Ǳ�������(A-1,B-1,C-1)��λ��,����֪��ħ������ T ���Ӻ�ص��Ǳ�,Ignatius ÿ�����ܴ�һ�������ߵ����ڵ�����
    �����е�����һ��.���ڸ���Ǳ��ĵ�ͼ,�������� Ignatius �ܷ���ħ������ǰ�뿪�Ǳ�(ֻҪ�ߵ����ھ����뿪�Ǳ�,����ߵ����ڵ�ʱ��ħ���պû���Ҳ����
    ���ɹ�),��������������Ҫ���ٷ��Ӳ����뿪,������������-1��
*/
//���������Թ�����������˼·ȥ�����������⣬��mark��ǣ�stack�汾
#include<iostream>
#include<stack>
using namespace std;
bool mark[50][50][50];
int maze[50][50][50];
int K,A,B,C,T;
int ret;
struct Node{
    int x;
    int y;
    int z;
    int t;
};
stack<Node> s;
int go[][3]={
    0,0,1,
    0,0,-1,
    0,1,0,
    0,-1,0,
    1,0,0,
    -1,0,0
};
int BFS(int a,int b,int c){
    while(!s.empty()){
        Node new_1=s.top();
        s.pop();
        for(int i=0;i<6;i++){
            int nx=new_1.x+go[i][0];
            int ny=new_1.y+go[i][1];
            int nz=new_1.z+go[i][2];
            if(nx<0||nx>=A||ny<0||ny>=B||nz<0||nz>=C) continue;
            if(maze[nx][ny][nz]==1) continue;
            if(mark[nx][ny][nz]==true) continue;
            Node tmp;
            tmp.x=nx;
            tmp.y=ny;
            tmp.z=nz;
            tmp.t=new_1.t+1;
            s.push(tmp);
            mark[nx][ny][nz]=true;
            if(nx==A-1&&ny==B-1&&nz==C-1) return tmp.t;
        }
    }
}
int main(){
    while(cin>>K){
        for(int cnt=0;cnt<K;cnt++){
            cin>>A>>B>>C>>T;
            for(int i=0;i<A;i++){
                for(int j=0;j<B;j++){
                    for(int k=0;k<C;k++){
                        cin>>maze[i][j][k];
                        mark[i][j][k]=false;
                    }
                }
            }
        }
        while(!s.empty()) s.pop();
        Node tmp;
        tmp.t=tmp.x=tmp.y=tmp.z=0;
        mark[0][0][0]=true;
        s.push(tmp);
        ret=BFS(A,B,C);
        //cout<<ret<<" "<<T<<endl;
        if(ret<=T) cout<<ret<<endl;
        else cout<<-1<<endl;
    }
    return 0;
}
