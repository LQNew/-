//�߾������㣬����շת�����ȥ���~
//�������� С��10�������Ǿ���ĸ߾��ȳ�������
#include<iostream>
#include<cstring>
using namespace std;
int c[30];
int a[30];
char str1[31];
int main(){
    cin>>str1;
    bool flag=false;
    for(int i=0;i<strlen(str1);i++) c[i]=str1[i]-'0';
    for(int k=2;k<=9;k++){
        memcpy(a,c,sizeof(c));
        for(int i=0;i<strlen(str1)-1;i++){
            a[i+1]+=(a[i]%k)*10;
            a[i]=a[i]/k;
        }
        if(a[strlen(str1)-1]%k==0){
            cout<<k<<' ';
            flag=true;
        }
    }
    if(!flag) cout<<"none"<<endl;
    else cout<<endl;
    return 0;
}
