//���͵���ȫ�������⣬��0-1���������ϣ�����ÿ���������Ŀ�������ƣ�����Ϊ�������
//����ÿ��Ǯ�ҵ�����������������࣬���Ը�����Ϊ��ȫ�������⡣�����ڸ����У���ȫ�����������仯�����ȣ�Ҫ��Ĳ��������ֵ������Ϊ����Сֵ��
//���Ҫ��������״̬ת��ʱ���� dp[i]�� dp[i-weight[j]]+value[j] ��ѡ���С��ת��ֵ����Σ�������Ҫ��Ǯ�ҺͿմ���޵�����ǡ�ôﵽ�����������ڱ��������б���Ϊ����ǡ��װ����
//Ϊ�˽����������ǡ��װ���Ĵ�������һ��ʼ����ÿ������������ʼ��Ϊһ�����������ֻ�в�ѯ������������������Ӧ�����ʱ�Ż������ֵ
//��������������������Ҿ���int�Ϳ������ֵΪ 0X7FFFFFFF!
#include<iostream>
using namespace std;
const int INF=0x7fffffff;
int T;
int E,F;
int total_weight;
int N;
int value[501];
int weight[501];
int dp[10001];//dp[i][j]��ʾװǰj��Ӳ�ң�����Ϊiʱ����С��ֵ
int main(){
    cin>>T;
    for(int i=0;i<T;i++){
        cin>>E>>F>>N;
        for(int i=1;i<=N;i++) cin>>value[i]>>weight[i];
        total_weight=F-E;
        for(int i=1;i<=total_weight;i++) dp[i]=INF;
        dp[0]=0;
        for(int j=1;j<=N;j++){
            for(int i=weight[j];i<=total_weight;i++){
                if(dp[i-weight[j]]!=INF) dp[i]=min(dp[i],dp[i-weight[j]]+value[j]);
            }
        }
        if(dp[total_weight]==INF) cout<<"This is impossible."<<endl;
        else cout<<"The minimum amount of money in the piggy-bank is "<<dp[total_weight]<<'.'<<endl;
    }
    return 0;
}
