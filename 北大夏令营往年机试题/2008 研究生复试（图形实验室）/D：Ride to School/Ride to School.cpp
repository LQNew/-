/*
    ��ʵֻ���������ʱ��>=0������˵����յ��ʱ��Ϳ����ˣ���Ϊ�������˳���ʱ��>=0�������ȵ���Ļ���ô���϶���׷�����ģ�Ҳ����˵άά���������
    ���ҵ���ʱ����̡�������ʱ��<0�����������ȵ����ôάά�϶�׷���ϡ�����󵽴άά���������������ֻ�ÿ���>=0�ľ�����~
*/
//�������õ���cmath���ceil()����������ȡ�����˺�����ʹ�ÿ����˽���~
#include<iostream>
#include<cmath>
using namespace std;
const int INF=0X7FFFFFFF;
int N;
double vi;
int ti;
int min1;
int main(){
    while(cin>>N){
        if(N==0) break;
        min1=INF;
        for(int i=0;i<N;i++){
            cin>>vi>>ti;
            if(ti<0) continue;
            int t=ti+ceil((4.5/vi)*3600);
            min1=min(min1,t);
        }
        cout<<min1<<endl;
    }
    return 0;
}
