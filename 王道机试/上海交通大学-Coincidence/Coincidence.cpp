/*
    ���������ַ�����������������ַ����������ַ���Ŀ
*/
//���͵��������������Ŀ����Ҫ�������еĵݹ���ʽҪ��⣬���ǳ������·������Ҫ��Ϥ��Ϥ����
#include<iostream>
#include<cstring>
using namespace std;
char str1[101];//������ַ���1
char str2[101];//������ַ���2
int dp[101][101];//���ڼ�¼�м������������е��ַ�����
int main(){
    while(cin>>str1>>str2){
        for(int i=0;i<101;i++){ //��ʼ��
            for(int j=0;j<101;j++) dp[i][j]=0;
        }
        int len1=strlen(str1);
        int len2=strlen(str2);
        for(int i=1;i<=len1;i++){
            for(int j=1;j<=len2;j++){
                if(str1[i-1]==str2[j-1]) dp[i][j]=dp[i-1][j-1]+1;
                else{
                    if(dp[i-1][j]>dp[i][j-1]) dp[i][j]=dp[i-1][j];
                    else dp[i][j]=dp[i][j-1];
                }
            }
        }
        cout<<dp[len1][len2]<<endl;
    }
    return 0;
}
