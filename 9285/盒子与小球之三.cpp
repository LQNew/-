//������Ķ��鷽�̣����ǳ�ʱ..
//˼·�ܼ򵥣�����dp[i][j]����ʾǰi����������j������ô���ֿ��ܵ���Ŀ��ʵ�Ƕ���ǰi-1���������� j-k~j����ĸ��ʣ���Ȼ�и��������������� �˴������
// ��Ϊ���ܱ���j��С��k������Ҫ�и������С����
#include<iostream>
using namespace std;
int dp[5001][5001];
int N,M,K;
int mod=1000007;
int main(){
    while(cin>>N>>M>>K){
        dp[0][0]=1;
        for(int j=1;j<=N;j++) dp[0][j]=0;
        for(int i=1;i<=M;i++){
            for(int j=1;j<=N;j++){
                dp[i][j]=0;
                for(int p=0;p<=min(j,K);p++){
                    dp[i][j]=(dp[i][j]+dp[i-1][j-p])%mod;
                }
            }
        }
        cout<<dp[M][N]<<endl;
    }
    return 0;
}
