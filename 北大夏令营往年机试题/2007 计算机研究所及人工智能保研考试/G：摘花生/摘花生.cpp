//ö�ٷ�����Ŀ�򵥣�����˼·Ҫ�㹻�Ͻ���
#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
int T;
int M,N,K;
int P[51][51];
bool mark[51][51];
int main(){
    cin>>T;
    for(int i=0;i<T;i++){
        memset(mark,0,sizeof(mark));
        cin>>M>>N>>K;
        for(int i=1;i<=M;i++){
            for(int j=1;j<=N;j++) cin>>P[i][j];
        }
        int cnt=0;
        //��һ��������ҳ����ֵ������ȥ
        int x0,y0;
        int ans=0;
        for(int i=1;i<=M;i++){
            for(int j=1;j<=N;j++){
                if(P[i][j]>ans&&!mark[i][j]){
                    ans=P[i][j];
                    x0=i;
                    y0=j;
                }
            }
        }
        mark[x0][y0]=true;
        int x1=x0;
        int y1=y0;
        K-=(2*x1+1);
        //�������ȥ��ժ�����ڹ涨ʱ����������
        while(K>=0){
            K+=x1;
            cnt+=ans;
            x0=x1;
            y0=y1;
            ans=0;
            for(int i=1;i<=M;i++){
                for(int j=1;j<=N;j++){
                    if(P[i][j]>ans&&!mark[i][j]){
                        ans=P[i][j];
                        x1=i;
                        y1=j;
                    }
                }
            }
            mark[x1][y1]=true;
            int dis1=abs(x1-x0)+abs(y1-y0)+x1+1;
            K-=dis1;
        }
        cout<<cnt<<endl;
    }
    return 0;
}
