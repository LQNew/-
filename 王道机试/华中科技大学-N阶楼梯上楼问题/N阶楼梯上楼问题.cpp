/*
    N��¥����¥���⣺һ�ο��������׻�һ�ף����ж�������¥��ʽ��
*/
//�������򵥵ĵݹ����⣬����n��¥�ݵ���¥��ʽ����=F[n-1]+F[n-2]�����ڸ���Ҳ�п�����������⣬����������߼�~
#include<iostream>
using namespace std;
int N;
long long steps[91];
int main(){
    steps[1]=1;
    steps[2]=2;
    for(int i=3;i<=90;i++){
        steps[i]=steps[i-1]+steps[i-2];
    }
    while(cin>>N){
        cout<<steps[N]<<endl;
    }
    return 0;
}
