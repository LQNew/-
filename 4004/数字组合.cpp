/*
    ��n�����������ҳ����к�Ϊt(tҲ��������)�Ŀ��ܵ���Ϸ�ʽ���磺n=5,5�����ֱ�Ϊ1,2,3,4,5��t=5��
    ��ô���ܵ������5=1+4��5=2+3��5=5������Ϸ�ʽ��
*/
//���͵��������⣬���ǻ���ö���Ӽ������ʹ�����ֵΪt�ļ�����Ŀ
#include<iostream>
using namespace std;
int n,t;
int sum;
int ans;
int a[20];
void dfs(int x){ //�Ӽ��ϻ��ֵ���ϸ����~
    if(sum==t){
        ans++; //bingo!������Ŀ+1
        return;
    }
    if(x>=n) return;
    sum+=a[x];
    dfs(x+1);
    sum-=a[x];
    dfs(x+1);
}
int main(){
    while(cin>>n>>t){
        for(int i=0;i<n;i++) cin>>a[i];
        sum=0;
        ans=0;
        dfs(0);
        cout<<ans<<endl;
    }
    return 0;
}
