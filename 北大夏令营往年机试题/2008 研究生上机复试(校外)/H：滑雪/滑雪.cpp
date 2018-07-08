//��ѩ���⣬���͵ĵݹ�+�������⣬����ʵ���������Ƕ�ά����ݼ����������⣬˼·�õ��˵ݹ�˼·����̫����˼��...
//��������·�����ԣ�Ҳ�Ǻܾ�������⣬Ҫ�ڼ�˼������
#include<iostream>
using namespace std;
int R,C;
int cnt;
int map1[101][101];
int dp[101][101];
int go[4][2]={
    -1,0,
    1,0,
    0,-1,
    0,1
};
int DP(int i, int j){ //���ѵ�˼·����
    if (dp[i][j]!=-1) return dp[i][j];
    dp[i][j] = 1;
    for(int k = 0; k < 4; k++){
        int x = i + go[k][0];
        int y = j + go[k][1];
        if(x<1||x>R||y<1||y>C) continue;
        if(map1[x][y]<map1[i][j]) dp[i][j] = max(dp[i][j], DP(x, y)+1);
    }
    return dp[i][j];
}
int main(){
    cin>>R>>C;
    for(int i=1;i<=R;i++){
        for(int j=1;j<=C;j++){
            cin>>map1[i][j];
            dp[i][j]=-1;
        }
    }
    int ans=0;
    for(int i=1;i<=R;i++){
        for(int j=1;j<=C;j++){
            cnt=0;
            ans=max(ans,DP(i,j));
        }
    }
    cout<<ans<<endl;
    return 0;
}
