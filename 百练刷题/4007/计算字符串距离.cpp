//�������Ǳ༭�������⣬Ȼ���Ҹо�AC�Ĵ��������⣬�˴����Ҿ�����ȷ����WA�Ĵ��룺
//���ȶ�������һ����������edit(i, j)������ʾ��һ���ַ����ĳ���Ϊi���Ӵ����ڶ����ַ����ĳ���Ϊj���Ӵ��ı༭���롣
//��Ȼ���������¶�̬�滮��ʽ��
// if i == 0 �� j == 0��edit(i, j) = 0
// if i == 0 �� j > 0��edit(i, j) = j
// if i > 0 ��j == 0��edit(i, j) = i
// if i �� 1  �� j �� 1 ��edit(i, j) == min{ edit(i-1, j) + 1, edit(i, j-1) + 1, edit(i-1, j-1) + f(i, j) }��
// ����һ���ַ����ĵ�i���ַ������ڵڶ����ַ����ĵ�j���ַ�ʱ��f(i, j) = 1������f(i, j) = 0��
#include<iostream>
#include<cstring>
using namespace std;
int n;
int flag;
char str1[1001],str2[1001];
int dp[1001][1001];//dp[i][j]����str1��ǰi���ַ���str2��ǰj���ַ��ı༭����
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>str1>>str2;
        for(int i=0;i<=strlen(str1);i++) dp[i][0]=i; //��ʼ���༭����
        for(int j=0;j<=strlen(str2);j++) dp[0][j]=j;
        for(int i=1;i<=strlen(str1);i++){
            for(int j=1;j<=strlen(str2);j++){
                if(str1[i]==str2[j]) flag=0;
                else flag=1;
                dp[i][j]=min(dp[i-1][j]+1,dp[i][j-1]+1);
                dp[i][j]=min(dp[i][j],dp[i-1][j-1]+flag);
            }
        }
        cout<<dp[strlen(str1)][strlen(str2)]<<endl;
    }
    return 0;
}
