//����������Ҫ�õ���ջ�Ͷ��и�����˼�����Ѷ��ϲ����ر��ѣ���Ҫ��ÿ�ν�ջ����Ԫ�رȶԣ����ǿ�����ջ��Ӧ��
#include<iostream>
#include<stack>
#include<queue>
using namespace std;
int N;
int a;
queue<int>pop1;
stack<int>push1;
int main(){
    while(cin>>N){
        if(N==0) break;
        while(cin>>a){
            if(a==0) break;
            while(!pop1.empty()) pop1.pop();
            while(!push1.empty()) push1.pop();
            pop1.push(a);
            for(int i=0;i<N-1;i++){
                cin>>a;
                pop1.push(a);
            }
            bool flag=true;
            int a1,b1;
            for(int j=1;j<=N;j++){
                push1.push(j);
                a1=push1.top();
                b1=pop1.front();
                while(a1==b1){
                    push1.pop();
                    pop1.pop();
                    if(push1.empty()) break;
                    a1=push1.top();
                    b1=pop1.front();
                }
            }
            if(!push1.empty()) flag=false;
            if(flag) cout<<"Yes"<<endl;
            else cout<<"No"<<endl;
        }
        cout<<endl;
    }
    return 0;
}
