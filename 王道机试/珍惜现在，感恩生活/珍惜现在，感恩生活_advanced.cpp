//�Ľ��汾�ģ��������ǲ���һ�ָ�Ϊ�м����ԵĲ�֡���ԭ����Ϊ k ����Ʒ���Ϊ�����飬ÿ����Ʒ����һ����Ʒ�����ֵ������Ϊ������������Ʒ�ļ�ֵ�����ܺͣ�
//ÿ����Ʒ������ԭ��Ʒ�����ֱ�Ϊ��Ϊ��1��2��4...2^c������ c Ϊʹ k-(1+2+4+..+2^c)���� 0 ����������� ���ž������������һ������ k-(1+2+4+..+2^c)
//���������ڶ����ƵĲ�֣���������Ʒ������󽵵ͣ�ͬʱͨ������Щ���ɸ�ԭ��Ʒ��ϵõ�����Ʒ�Ĳ�ͬ��ϣ����Եõ� 0 �� k ֮����������Ʒ�ļ�ֵ�����ͣ���������ʱ�临�Ӷ�
#include<iostream>
using namespace std;
int C;
int n,m;
int weight_1,price_1,num1,cnt;
int weight[2001];
int price[2001];
int dp[101];
int main(){
    cin>>C;
    for(int i=0;i<C;i++){
        cin>>n>>m;
        cnt=0;
        for(int i=1;i<=m;i++){
            cin>>price_1>>weight_1>>num1;
            int c=1;
            while(num1-c>0){
                num1-=c;
                cnt++;
                weight[cnt]=weight_1*c;
                price[cnt]=price_1*c;
                c*=2;
            }
            weight[++cnt]=weight_1*num1;
            price[cnt]=price_1*num1;
        }
        for(int i=0;i<=n;i++) dp[i]=0;
        for(int j=1;j<=cnt;j++){
            for(int i=n;i>=price[j];i--) dp[i]=max(dp[i],dp[i-price[j]]+weight[j]);
        }
        cout<<dp[n]<<endl;
    }
    return 0;
}
