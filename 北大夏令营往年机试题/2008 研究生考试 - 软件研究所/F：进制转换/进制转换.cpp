//����ת�����漰���������㣬��Ҫ�Ǵ��������еĳ�������~~
//��������Ҫ�ǿ����߼��ķ�����������Ŀ�����������У�����~
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int a[30];
int b[1000];
char str1[31];
int main(){
    while(cin>>str1){
        int t=0;
        reverse(&str1[0],&str1[strlen(str1)]);
        for(int i=0;i<strlen(str1);i++) a[i]=str1[i]-'0';
        while(1){
            int i;
            for(i=strlen(str1)-1;i>0;i--){
                if(a[i]%2){
                    a[i-1]+=10;
                    a[i]=a[i]/2;
                }
                else a[i]=a[i]/2;
            }
            b[t]=a[i]%2;
            a[i]=a[i]/2;
            t++;
            int ans=0;
            for(int j=0;j<strlen(str1);j++) ans+=a[j];
            if(ans>0) continue; //�б�շת����Ƿ����
            else break;
        }
        for(int i=t-1;i>=0;i--) cout<<b[i];
        cout<<endl;
    }
    return 0;
}
