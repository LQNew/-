/*
    A ring is composed of n (even number) circles as shown in diagram.Put natural numbers 1, 2, . . . , n into each circle separately, and the
    sum of numbers in two adjacent circles should be a prime.
    Output
        The output format is shown as sample below. Each row represents a series of circle numbers in the
        ring beginning from 1 clockwisely and anticlockwisely. The order of numbers must satisfy the above
        requirements.
*/
//���������Ǹ�һ�������������⣬û��ʲô��֦����������DFS�������д������Ҫע�⣡��û����ô������д����Ҫ�еݹ��˼�룡��
//��������ڹ��ѣ�������˼ά��Ҫ�����̣���������һ����������ͣ�Ҫϸ�İ�����⣡��
#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;
int n;
int ans[17];
bool mark[17];
bool judge(int x){ //�б��Ƿ�Ϊ����
    if(x==2) return true;
    else{
        for(int i=2;i<=sqrt(double(x));i++){
            if(x%i==0) return false;
        }
    }
    return true;
}
void Dfs(int num){
    if(num==n&&judge(ans[n]+ans[1])){
        for(int i=1;i<n;i++) cout<<ans[i]<<' ';
        cout<<ans[n]<<endl;
    }
    else if(num==n&&!judge(ans[n]+ans[1])) return;
    else{
        for(int i=2;i<=n;i++){
            if(!mark[i]&&judge(i+ans[num])){
                mark[i]=true;
                ans[num+1]=i;
                Dfs(num+1);
                mark[i]=false;
            }
        }
        return;
    }
}
int main(){
    int t=0;
    while(cin>>n){
        if(t!=0) cout<<endl; //ӭ�������ʽ��Ҳ�Ǻܶ��ĵ������ʽҪ����...
        t++;
        ans[1]=1;
        memset(mark,0,sizeof(mark));
        mark[1]==true;
        cout<<"Case "<<t<<':'<<endl;
        Dfs(1);

    }
    return 0;
}
