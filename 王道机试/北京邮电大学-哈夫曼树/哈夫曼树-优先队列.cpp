/*
    ������������һ������һ���� n����ʾҶ���ĸ�������Ҫ����ЩҶ������ɹ������������ݹ��������ĸ����Щ�����Ȩֵ���� weight����Ŀ��Ҫ���
    ���н���ֵ��Ȩֵ�ĳ˻�֮�͡�
*/
//�������ڵ��ֵ��Ȩֵ�ĳ˻�����ϸ�������Է��־������еķ�Ҷ�ڵ��ϵ�Ȩֵ֮��
//���ڹ�����������˴��������ȼ����У�С���ѷ�ʽ���죬�ѶȽ�Ϊ�򵥣����Զ����ᣡ��
//����С���ѣ�����ÿ�ν������ȶ��У���С��ֵ���ڶ���ǰ�������ն�����ʽ�������ȶ���~�Ѷ�Ԫ��Ϊ��Сֵ
//��ʵ��������ϸһ˼��Ҳ���Բ��ÿ�������ʽ�����ǿ������������д����û����ô����~
#include<iostream>
#include<queue>
using namespace std;
priority_queue<int,vector<int>,greater<int>> Q; //С���ѵĹ��췽ʽ�� Ĭ���Ǵ󶥶ѣ�Ҳ���� priority_queue<int>�ͺ�
int n;
int weight;
int main(){
    while(cin>>n){
        while(!Q.empty()) Q.pop();
        for(int i=0;i<n;i++){
            cin>>weight;
            Q.push(weight);
        }
        int ans=0;
        while(Q.size()>1){
            int a=Q.top();
            Q.pop();
            int b=Q.top();
            Q.pop();
            ans+=(a+b);
            Q.push(a+b);
        }
        cout<<ans<<endl;
    }
    return 0;
}
