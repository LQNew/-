//�������������������Ϳ��ֵ�������Ҫ��ƽ�ֿ���
//ʹ����Ԫ�飨x��y��z��t������ʾһ��״̬������ x��y��z �ֱ��ʾ����ƿ���еĿ��������t ��ʾ�ӳ�ʼ״̬����״̬����ı��Ӽ以
//���㵹�Ĵ�����״̬����໥��չ������������Ԫ�龭��ƿ�Ӽ���໥�㵹���õ��������µ���Ԫ��Ĺ��̡���������ƽ�ֵ�״̬��һ�α����������Ժ���״
//̬�б�ʾ�ı����㵹������������
//������ʵ���ϻ����Ժ������������ĸ��Ȼ������BFS���״̬���ѶȲ���ע���㵹����ÿ�ε������ǰ��ĵ���~
#include<iostream>
#include<queue>
using namespace std;
struct Node{
    int a,b,c;
    int t;
};
int S,M,N;
bool mark[101][101][101];
queue<Node>Q;
void exchange(int &a,int sa,int &b,int sb){ //������û�п̶ȵģ�ÿ��ֻ�����������ص���~
    if(sb-b>=a){
        b+=a;
        a=0;
    }
    else{
        a-=(sb-b);
        b=sb;
    }
}
int BFS(){
    while(!Q.empty()){
        Node new_1=Q.front();
        Q.pop();
        //six branches taken in count
        int na=new_1.a;
        int nb=new_1.b;
        int nc=new_1.c;
        exchange(na,S,nb,M);
        if(mark[na][nb][nc]==false){
            mark[na][nb][nc]=true;
            Node tmp;
            tmp.a=na;
            tmp.b=nb;
            tmp.c=nc;
            tmp.t=new_1.t+1;
            if(na==S/2&&nb==S/2) return tmp.t;
            if(na==S/2&&nc==S/2) return tmp.t;
            if(nc==S/2&&nb==S/2) return tmp.t;
            Q.push(tmp);
        }
        na=new_1.a;
        nb=new_1.b;
        nc=new_1.c;
        exchange(na,S,nc,N);
        if(mark[na][nb][nc]==false){
            mark[na][nb][nc]=true;
            Node tmp;
            tmp.a=na;
            tmp.b=nb;
            tmp.c=nc;
            tmp.t=new_1.t+1;
            if(na==S/2&&nb==S/2) return tmp.t;
            if(na==S/2&&nc==S/2) return tmp.t;
            if(nc==S/2&&nb==S/2) return tmp.t;
            Q.push(tmp);
        }
        na=new_1.a;
        nb=new_1.b;
        nc=new_1.c;
        exchange(nb,M,na,S);
        if(mark[na][nb][nc]==false){
            mark[na][nb][nc]=true;
            Node tmp;
            tmp.a=na;
            tmp.b=nb;
            tmp.c=nc;
            tmp.t=new_1.t+1;
            if(na==S/2&&nb==S/2) return tmp.t;
            if(na==S/2&&nc==S/2) return tmp.t;
            if(nc==S/2&&nb==S/2) return tmp.t;
            Q.push(tmp);
        }
        na=new_1.a;
        nb=new_1.b;
        nc=new_1.c;
        exchange(nc,N,na,S);
        if(mark[na][nb][nc]==false){
            mark[na][nb][nc]=true;
            Node tmp;
            tmp.a=na;
            tmp.b=nb;
            tmp.c=nc;
            tmp.t=new_1.t+1;
            if(na==S/2&&nb==S/2) return tmp.t;
            if(na==S/2&&nc==S/2) return tmp.t;
            if(nc==S/2&&nb==S/2) return tmp.t;
            Q.push(tmp);
        }
        na=new_1.a;
        nb=new_1.b;
        nc=new_1.c;
        exchange(nb,M,nc,N);
        if(mark[na][nb][nc]==false){
            mark[na][nb][nc]=true;
            Node tmp;
            tmp.a=na;
            tmp.b=nb;
            tmp.c=nc;
            tmp.t=new_1.t+1;
            if(na==S/2&&nb==S/2) return tmp.t;
            if(na==S/2&&nc==S/2) return tmp.t;
            if(nc==S/2&&nb==S/2) return tmp.t;
            Q.push(tmp);
        }
        na=new_1.a;
        nb=new_1.b;
        nc=new_1.c;
        exchange(nc,N,nb,M);
        if(mark[na][nb][nc]==false){
            mark[na][nb][nc]=true;
            Node tmp;
            tmp.a=na;
            tmp.b=nb;
            tmp.c=nc;
            tmp.t=new_1.t+1;
            if(na==S/2&&nb==S/2) return tmp.t;
            if(na==S/2&&nc==S/2) return tmp.t;
            if(nc==S/2&&nb==S/2) return tmp.t;
            Q.push(tmp);
        }
    }
    return -1;
}
int main(){
    while(cin>>S>>M>>N){
        if(S==0&&M==0&N==0) break;
        if(S%2!=0) cout<<"NO"<<endl;
        else{
            for(int i=0;i<=S;i++){
                for(int j=0;j<=M;j++){
                    for(int k=0;k<=N;k++)
                        mark[i][j][k]=false;
                }
            }
            Node tmp;
            tmp.a=S;
            tmp.b=0;
            tmp.c=0;
            tmp.t=0;
            while(!Q.empty()) Q.pop();
            Q.push(tmp);
            int time=BFS();
            if(time==-1) cout<<"NO"<<endl;
            else cout<<time<<endl;
        }
    }
    return 0;
}
