//ˮ�⣬������Ŀ�Ƚ϶��ĵ�������������ǰ�����ݵĴ�С��ϵ����
#include<iostream>
using namespace std;
int i,j;
int program(int x){
    int ans=0;
    while(x!=1){
        if(x%2){
            x=3*x+1;
            ans++;
        }
        else{
            x=x/2;
            ans++;
        }
    }
    return ans+1;
}
int main(){
    while(cin>>i>>j){
        int max1=0;
        for(int k=min(i,j);k<=max(i,j);k++){
            max1=max(max1,program(k));
        }
        cout<<i<<' '<<j<<' '<<max1<<endl;
    }
    return 0;
}
