//�������ѶȲ��󣬵���һ��Ҫ��������ӵ����������Щ���̣���ͬʱ�����������֮������������ �ݹ�˼·
#include<iostream>
using namespace std;
int a;
int n;

int split(int x,int n){
    int ans=1;
    for(int i=x;i*i<=n;i++){ //ÿ�δӵ�ǰ����������ӿ�ʼ���㣬Ϊ�˷�ֹ�ظ�����~
        if(n%i==0){
            ans+=split(i,n/i);
        }
    }
    return ans;
}
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a;
        int ans=split(2,a);
        cout<<ans<<endl;
    }
    return 0;
}
