/*
    ����һ���ַ��������ַ������ҵ���һ��������������k�ε��ַ���
*/
//ˮ�⣡
#include<iostream>
#include<cstring>
using namespace std;
int k;
char a;
int cnt;
char str[1001];
int main(){
    cin>>k>>str;
    //cout<<strlen(str)<<endl;
    cnt=0;
    int i;
    for(i=0;i<strlen(str);i++){
        if(cnt==0){
            a=str[i];
            cnt++;
            continue;
        }
        if(a==str[i]) cnt++;
        else{
            if(cnt>=k){
                cout<<a<<endl;
                break;
            }
            else cnt=0;
        }
    }
    if(i==strlen(str)&&cnt<k) cout<<"No"<<endl;
    else if(i==strlen(str)&&cnt>=k) cout<<a<<endl;
    return 0;
}
