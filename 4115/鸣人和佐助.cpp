/*
    ��֪һ�ŵ�ͼ���Զ�ά�������ʽ��ʾ���Լ����������˵�λ�á���ͼ�ϵ�ÿ��λ�ö������ߵ���ֻ������Щλ�����д���������£�
    ��Ҫ�ȴ�ܴ���������²��ܵ���Щλ�á�������һ�������Ĳ������ÿһ����λ�Ĳ�������Դ��һ������������¡�
    �������˿��������������ĸ������ƶ���ÿ�ƶ�һ��������Ҫ����1����λʱ�䣬��ܴ���������²���Ҫʱ�䡣
    ������˲�����������ˣ���ֻ�����ߵ�û�д��������µ�λ�ã����������ƶ����д��������µ�λ�á������ڴ��ڼ䲻�ƶ��������������Ҳ���ƶ���
    Ҫ���������׷�����������ʱ��
*/
//������էһ�����Ƕ�ά�Ĺ������⣬���� һ��ʼ���մ�˼·WA�ˣ������뵽�鿨��Ҳ����һ����������Ϊ�ڵ�ͼ��ͬ�㴦���ܲ������ͬ����ζ�Ų�ͬ������
//��������һά�������������
#include<iostream>
#include<queue>
using namespace std;
int M,N,T;
int x0,y0;//��ʼʱ���˵�����
char c;//�洢����ĵ�ͼ���ַ�ֵ
char Map[200][200][11]; //��������ά��
bool mark[200][200][11];
struct Node{
    int x; //�ڵ������
    int y; //�ڵ�������
    int t; //�ڵ�Ĳ����
    int res;//�ƶ��Ĳ���
};
queue<Node>Q;
int go[4][2]={ //�����ĸ�������ƶ�
    -1,0,
    0,1,
    0,-1,
    1,0
};

int Bfs(){
    while(!Q.empty()){
        Node now=Q.front();
        Q.pop();
        for(int i=0;i<4;i++){
            int x1=go[i][0]+now.x;
            int y1=go[i][1]+now.y;
            int t1=now.t;
            if(x1<0||x1>=M||y1<0||y1>=N) continue;
            if(mark[x1][y1][t1]) continue;
            if(Map[x1][y1][t1]=='#'){
                if(t1>0) t1-=1;
                else continue;
            }
            mark[x1][y1][t1]=true;
            Node tmp;
            tmp.x=x1;
            tmp.y=y1;
            tmp.t=t1;
            tmp.res=now.res+1; //����+1
            //cout<<tmp.res<<' '<<Map[x1][y1]<<endl;
            Q.push(tmp);
            if(Map[x1][y1][t1]=='+') return tmp.res; //������Ĳ����ά���ϣ�ֻҪ������ͼ�иõ��Ѿ�������������ô��ѯ���
        }
    }
    return -1;
}

int main(){
    while(cin>>M>>N>>T){
        for(int i=0;i<M;i++){
            for(int j=0;j<N;j++){
                cin>>c;
                for(int k=0;k<=T;k++) Map[i][j][k]=c; //����ά�ȳ�ʼ��
                if(c=='@'){
                    x0=i;
                    y0=j;
                }
                for(int k=0;k<=T;k++) mark[i][j][k]=false;
            }
        }
        mark[x0][y0][T]=true;
        Node tmp;
        tmp.x=x0;
        tmp.y=y0;
        tmp.t=T;
        tmp.res=0;
        while(!Q.empty()) Q.pop();
        Q.push(tmp);
        int res=Bfs();
        cout<<res<<endl;
    }
    return 0;
}
