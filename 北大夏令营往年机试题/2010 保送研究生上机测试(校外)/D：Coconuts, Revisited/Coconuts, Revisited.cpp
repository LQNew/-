//��������Ҫע��������ӵķ��䣡��һֱ��Ϊ����ӦС��sqrt(n),������˼ά�����������ж��Ƿ�Ϊ�����ķ������ô��˵ط���������������ģ��+����ac���Ѷ�һ��
//���ǿ���������Ҫ�����£��е������ˣ�..
#include<iostream>
#include<cmath>
using namespace std;
int n;
int main(){
    while(cin>>n){
        if(n==-1) return 0;
        n-=1;
        int i;
        for(i=n;i>=2;i--){
            if(n%i!=0) continue;
            int num=((i-1)*n)/i;
            int j=0;
            for(j;j<i-1;j++){
                num-=1;
                if(num%i!=0) break;
                else num=((i-1)*num)/i;
            }
            if(j==i-1){
                if(num%i==0){
                    cout<<n+1<<" coconuts, "<<i<<" people and 1 monkey"<<endl;
                    break;
                }
                else continue;
            }
        }
        if(i<2) cout<<n+1<<" coconuts, no solution"<<endl;
    }
    return 0;
}
