//��ͳ�ⷨ����ʵ�ҵĴ�������Ѿ��ܽӽ�����ʵ�����������Ǳ���nλ��ʱ����һλΪ0����������������(n-1)λ����ֵ�������һλΪ1����ô�ڶ�λһ��Ϊ0������������
//�Ϳ�����(n-2)λ����ֵ��
#include<iostream>
using namespace std;
long long a[46];
int cnt;
int x;
int main(){
    a[1]=2;
    a[2]=3;
    for(int i=3;i<46;i++){
        a[i]=a[i-1]+a[i-2];
    }
    cin>>cnt;
    for(int i=0;i<cnt;i++){
        cin>>x;
        cout<<"Scenario #"<<i+1<<":"<<endl;
        cout<<a[x]<<endl;
        cout<<endl;
    }
    return 0;
}
