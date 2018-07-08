/*
    ����������һ����������������ӷֽ���ʽ��
    ����
        ����һ������ n (2 <= n < 100)��
    ���
        ��������������ӷֽ���ʽ��
        ���ʽ�и���������С�������С�
        ������������Էֽ������a��b�η�����b����1ʱ��д�� a^b ����b����1ʱ����ֱ��д��a��
*/
//�������ܼ򵥵����ӷֽ����⣬��Ϊn��ֵ��С��������Ŀ�ѶȲ���ֻ��Ҫ��������������ӷֽ��ǰ��ͺ���~
#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
int n;
int decompose[10];
int cnt[10];
int main(){
    while(cin>>n){
        memset(decompose,0,sizeof(decompose));
        memset(cnt,0,sizeof(decompose));
        int j=0;
        int n1=n;
        for(int i=2;i<=sqrt(n);i++){ //����˴�Ӧ��<=sqrt(n)��һ��ʼд����<sqrt(n)��������ЩС���⣡��
            int k=0;
            while(n1%i==0){
                k++;
                n1=n1/i;
            }
            if(k!=0){
                decompose[j]=i;
                cnt[j]=k;
                j++;
            }
        }
        if(n1!=1){
            decompose[j]=n1;
            cnt[j]=1;
            j++;
        }
        for(int i=0;i<j;i++){
            if(i==j-1){
                if(cnt[i]==1) cout<<decompose[i];
                else{
                    cout<<decompose[i]<<'^'<<cnt[i];
                }
            }
            else{
                if(cnt[i]==1) cout<<decompose[i]<<'*';
                else{
                    cout<<decompose[i]<<'^'<<cnt[i]<<'*';
                }
            }
        }
        cout<<endl;
    }
    return 0;
}
