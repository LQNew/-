//dp���⣬����˼·û�е��͵�ģ��0-1����������룬����⻹��������˼��01���������⣬Ҫ��ӻعˣ������⣬��֤֮���ܿ��ٱ�д������
#include<iostream>
#include<cstring>
using namespace std;
int N,K;
int a[101];
int dp[101][100];
int main(){
    cin>>N>>K;
    for(int i=1;i<=N;i++) cin>>a[i];
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=N;i++){
        for(int j=0;j<K;j++) dp[i][j]=dp[i-1][j];
        for(int j=0;j<K;j++){
            if((dp[i-1][j]==0)&&(j!=0)) continue;
            dp[i][(j+a[i])%K]=max(dp[i][(j+a[i])%K],dp[i-1][j]+a[i]);

        }
    }
    cout<<dp[N][0]<<endl;
    return 0;
}
