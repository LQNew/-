//ͨ���������Է��֣�0-1���������״̬ת��֮��ֻ����һ�ε�״̬�йأ��������ǿ��Խ�ǰj����Ʒ���������Եı����Ƴ������Ƕ�ά����ת��Ϊһά��������������˿ռ临�Ӷ�
#include<iostream>
using namespace std;
int T,M;
int time_1[101];
int value[101];
int dp[1001];//dp[i][j]��ʾװǰj����Ʒ��ʱ�䲻����i������ֵ
int main(){
    cin>>T>>M;
    for(int i=1;i<=M;i++) cin>>time_1[i]>>value[i];
    for(int i=0;i<=T;i++) dp[i]=0; //��ʼ����װǰ0����Ʒ����ֵ��Ϊ0����Ϊ�ݹ�ĳ�ʼ����
    for(int j=1;j<=M;j++){
        for(int i=T;i>=time_1[j];i--) dp[i]=max(dp[i],dp[i-time_1[j]]+value[j]);
        for(int i=time_1[j]-1;i>=0;i--) dp[i]=dp[i];
    }
    cout<<dp[T]<<endl;
    return 0;
}
