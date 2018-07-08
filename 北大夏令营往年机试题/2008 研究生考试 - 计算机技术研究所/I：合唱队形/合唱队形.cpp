//����ͷ��ʼ�����ߵ�����������У�Ȼ��ÿ��λ����λ�ñȶ�ѡȡʹ�����������г���֮��Ϊ������Ϊ�ϳ�����~
//����������Ҫ��һ���������������������е�˼·~
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int INF=0x7fffffff;
int N;
int a[101];
int dp_left[101];
int dp_right[101];
int main(){
    cin>>N;
    for(int i=1;i<=N;i++) cin>>a[i];
    memset(dp_left,0,sizeof(dp_left));
    a[0]=0;
    for(int j=1;j<=N;j++){
        for(int i=0;i<j;i++){
            if(a[j]>a[i]) dp_left[j]=max(dp_left[i]+1,dp_left[j]);
        }
    }
    memset(dp_right,0,sizeof(dp_right));
    reverse(&a[1],&a[N+1]);
    for(int j=1;j<=N;j++){
        for(int i=0;i<j;i++){
            if(a[j]>a[i]) dp_right[j]=max(dp_right[i]+1,dp_right[j]);
        }
    }
    reverse(&dp_right[1],&dp_right[N+1]);
    int ans=0;
    for(int i=1;i<=N;i++){
        ans=max(ans,dp_right[i]+dp_left[i]-1);
    }
    cout<<N-ans<<endl;
    return 0;
}
