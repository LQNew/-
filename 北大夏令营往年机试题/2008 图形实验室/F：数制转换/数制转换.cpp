//�ַ����Ĵ�����Ҫ��Ҫ�����ַ����������õ��� algorithm ���reverse������reverse��������ʼλ����Ҫ���õ�λ�ã�����λ��ȷʵҪ���õ�λ��+1��
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int a,b;
char n[100];
int a1[100];
int transfer[100];
long num1;
long mul1;
int main(){
    cin>>a>>n>>b;
    reverse(&n[0],&n[strlen(n)]); //��ʾ�ӵ�һλ��ʼ�����һλȫ������
    for(int i=0;i<strlen(n);i++){
        if(n[i]>='0'&&n[i]<='9') a1[i]=n[i]-'0';
        else a1[i]=toupper(n[i])-'A'+10;
    }
    mul1=1;
    num1=0;
    num1+=a1[0];
    for(int i=1;i<strlen(n);i++){
        mul1*=a;
        num1+=mul1*a1[i];
    }
    //cout<<num1<<endl;
    int t=0;
    while(num1/b!=0){ //����ȡ����
        transfer[t]=num1%b;
        num1=num1/b;
        t++;
    }
    transfer[t]=num1%b;
    for(t;t>=0;t--){
        if(transfer[t]>9) cout<<char(transfer[t]-10+'A');
        else cout<<transfer[t];
    }
    cout<<endl;
    return 0;
}
