//��Ŀ���������ܴ���Ҫ���ܴ������ȥ�洢...
//ˮ��
#include<iostream>
#include<cstring>
using namespace std;
char str1[1001];
int a[1001];
int b;
int main(){
    while(cin>>str1){
        if(strlen(str1)==1&&str1[0]=='0') break;
        else{
            memset(a,0,sizeof(a));
            b=0;
            for(int i=0;i<strlen(str1);i++){
                a[i]=str1[i]-'0';
            }
            for(int i=0;i<strlen(str1);i++){
                b+=a[i];
                if(b>=10) b=b/10+b%10;
            }
            cout<<b<<endl;
        }
    }
    return 0;
}
