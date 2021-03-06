/*
    小智和皮卡丘来到了小精灵狩猎场，里面有很多珍贵的野生宠物小精灵。小智也想收服其中的一些小精灵。然而，野生的小精灵并不那么容易被收服。
    对于每一个野生小精灵而言，小智可能需要使用很多个精灵球才能收服它，而在收服过程中，野生小精灵也会对皮卡丘造成一定的伤害（从而减少皮卡丘的体力）。
    当皮卡丘的体力小于等于0时，小智就必须结束狩猎（因为他需要给皮卡丘疗伤），而使得皮卡丘体力小于等于0的野生小精灵也不会被小智收服。
    当小智的精灵球用完时，狩猎也宣告结束。
    小智的目标有两个：主要目标是收服尽可能多的野生小精灵；如果可以收服的小精灵数量一样，小智希望皮卡丘受到的伤害越小（剩余体力越大）。
*/
//分析：因为本道题有两个约束条件，一个最优目标，一开始试图套一维 0-1背包模板，发现思路打不开，后来从二维背包问题思索，开二维数组去解此问，问题成功求解！
#include<iostream>
using namespace std;
int N,M,K;
int strength[101];
int cnt[101];
int dp[1001][501]; //dp[i][j] 目前为止有i个精灵球，以及皮卡丘有j体力值时收复的最多精灵数目
int main(){
    while(cin>>N>>M>>K){
        for(int i=1;i<=K;i++) cin>>cnt[i]>>strength[i];
        for(int i=0;i<=N;i++){
            for(int j=0;j<=M;j++){
                dp[i][j]=0;
            }
        }
        for(int i=1;i<=K;i++){
            for(int j=N;j>=cnt[i];j--){
                for(int t=M;t>=strength[i];t--){
                    dp[j][t]=max(dp[j][t],dp[j-cnt[i]][t-strength[i]]+1); //二维背包递归
                }
            }
        }
        int res=dp[N][M]; //获取可以解放的精灵最大数目
        int j;
        for(j=M;j>=0;j--){
            if(res!=dp[N][j]) break; //递归寻求消耗的最小的皮卡丘体力值
        }
        cout<<res<<' '<<M-j-1<<endl;//打印出剩余的皮卡丘最大体力值
    }
    return 0;
}
