//ˮ�⣬��һ��ʼ˼·������ȷ�ģ����� WA�˺ܶ�Σ�
//������bailian oj�϶��ڶ�����ѭ�����������ر�֧�֣��Ժ�ע��д������Щ��ѭ��ʱ�ٴ�ЩǶ��������������ѭ��ֻ��һ�㣡��
#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
char str1[100];
char str2[100];
char status;
double bonus;
int ans;
int main(){
    ans=0;
    while(cin>>str1){
        if(strlen(str1)==1&&str1[0]=='0'){
            cout<<ans<<endl;
            ans=0;
            continue;
        }
        else if(strlen(str1)==1&&str1[0]=='#') break;
        cin>>str2;
        cin>>bonus>>status;
        if(status=='F') bonus*=2.0;
        else if(status=='B') bonus*=1.5;
        else if(status=='Y'){
            if(bonus<=500) bonus=500;
        }
        ans+=floor(bonus+0.5);
    }
    return 0;
}
