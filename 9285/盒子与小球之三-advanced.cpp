//����ǰ׺��ȥ���� dp[i][j]=dp[i-1][j]+dp[i][j-1]-dp[i-1][j-k-1] ��������ǰ׺�͵õ�����͹�ʽ~
//����ԭʼ��˼·�ϸĽ��ģ�����ֻ�ܹ�8����������2������û����ͨ��������Ǻ���ԭ��...
#include<iostream>
using namespace std;
int dp[5001][5001];
int N,M,K;
const int mod=1000007;
int main(){
    while(cin>>N>>M>>K){
        dp[0][0]=1;
        for(int j=1;j<=N;j++){
            dp[0][j]=0;
            dp[j][0]=1;
        }
        for(int i=1;i<=M;i++){
            for(int j=1;j<=N;j++){
                if(j<=K) dp[i][j]=(dp[i-1][j]+dp[i][j-1])%mod;
                else dp[i][j]=((dp[i-1][j]+dp[i][j-1])%mod+mod-dp[i-1][j-K-1])%mod;
            }
        }
        cout<<dp[M][N]<<endl;
    }
    return 0;
}
