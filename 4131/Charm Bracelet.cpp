//���͵�0-1�������⣬��Ŀ��Ҫ��Ҫ��⶯��˼·~�ѶȲ���ģ�����ͣ�
#include<iostream>
#include<cstring>
using namespace std;
int N,M;
int weight[4000];
int rating[4000];
int dp[12880]; //dp[j]��ʾǰj������Ŀǰ�������
int main(){
    while(cin>>N>>M){
        for(int i=1;i<=N;i++){
            cin>>weight[i]>>rating[i];
        }
        dp[0]=0;
        memset(dp,0,sizeof(dp[0]*(M+1)));
        for(int i=1;i<=N;i++){
            for(int j=M;j>=weight[i];j--){
                if(dp[j]<dp[j-weight[i]]+rating[i]) dp[j]=dp[j-weight[i]]+rating[i];
            }
        }
        cout<<dp[M]<<endl;
    }
    return 0;
}
