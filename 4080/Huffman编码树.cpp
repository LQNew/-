/*
    ���ʵ��Huffman�㷨��������С�ⲿ·�������ܺ͡�
*/
//����Huffman��������ⲿ·�����Լ���ͼ���������ʵ���Ǽ����Ҷ�ڵ�֮�����н���Ȩֵ֮��
//�˴����������ȼ�����STL��������ѶȽ��ף�
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
