//�������ѶȲ���ʱ�临�Ӷ�ΪO(n)+O(n/10)*O(sqrt(n)),����n<10000����������Ҳ����ʮ�򼶱�С�ڰ��򼶱�����û��~
#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;
int n;
int prime[10000];
bool judge(int m)
{
    for(int i=2;i<=sqrt(m);i++)
        if(m%i==0) return false;
    return true;
}
int main()
{
    while(cin>>n)
    {
        memset(prime,0,sizeof(prime[0]));
        int j=0;
        for(int i=2;i<n;i++)
        {
            if(i%10!=1) continue;
            else
                if(judge(i))  prime[j++]=i;
        }
        if(j==0) cout<<-1<<endl;
        else
        {
            for(int i=0;i<j-1;i++)
                cout<<prime[i]<<" ";
            cout<<prime[j-1]<<endl;
        }
    }
    return 0;
}
