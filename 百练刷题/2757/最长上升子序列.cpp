//��ݹ������У����ǱȽϼ򵥵Ķ�̬�滮���⣬����ÿ�ζ���ǰj-1����󳤶�ȥ�ȶԣ��ҳ����ĳ��ȣ���Ϊ�ڵ�jλ��������г���
//���Ϊ�˵ó��ܹ����е�������еĳ��ȣ���Ҫ����ÿһλ�õ���������г����ҵ���������ͺ�~
//dp[1]=1
//dp[i]=max(1,dp[j]+1|dp[i]>dp[j]&&i>j)
#include<iostream>
using namespace std;
int N;
int a[1001];
int dp[1001];
int main(){
    while(cin>>N){
        for(int i=1;i<=N;i++) cin>>a[i];
        dp[1]=1;
        for(int i=2;i<=N;i++){
            int max1=1;
            for(int j=1;j<i;j++){
                if(a[i]>a[j]){
                    if(max1<dp[j]+1) max1=dp[j]+1;
                }
            }
            dp[i]=max1;
        }
        int ans=0;
        for(int i=1;i<=N;i++){
            if(ans<dp[i]) ans=dp[i];
        }
        cout<<ans<<endl;
    }
    return 0;
}
