/*
    ���������ַ�����������������ַ����������ַ���Ŀ
*/
//������������ǵ��͵���·�⣬��Ҫ�������еĵݹ���ʽҪ��⣬���ǳ������·������Ҫ��Ϥ��Ϥ����
//dp[i][j]��ʾ�ַ���1��ǰi���ַ����ַ���2��ǰj���ַ�������������еĳ���
//dp[0][j]=0
//dp[i][0]=0
//dp[i][j]=dp[i-1][j-1]+1|str1[i]=str2[j]
//dp[i][j]=max(dp[i][j-1],dp[i-1][j])|str1[i]!=str2[j]
#include<iostream>
#include<cstring>
using namespace std;
char str1[201];//������ַ���1
char str2[201];//������ַ���2
int dp[201][201];//���ڼ�¼�м������������е��ַ�����
int main(){
    while(cin>>str1>>str2){
        for(int i=0;i<strlen(str1);i++){ //��ʼ��
            for(int j=0;j<strlen(str2);j++) dp[i][j]=0;
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
