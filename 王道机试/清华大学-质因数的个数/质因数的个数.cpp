//ע��int�ͷ�Χһ��Ϊ -21�ڵ�21������
//������Ϊ10�ڣ��ڷ�Χ֮��
//�ֽ���������POJ��Ҳ�д������ͣ��ѶȲ��󣬽ⷨ�뱾����ⷨ˼·��ͬ������ֱ�ӱ���ȥ��
//��������˸�Ԥ����ʱ�临�Ӷ�ΪO(n)+100000*�����ڹ�ϣ��һ�����Ӷȣ���Ȼ���Ӷ�С�ڰ��򼶱𣬿�������Ϊ�ǿ��ʱ�临�Ӷ���Ծ��̫���orz...
//��ʵPOJ�ϵĳ�����⣬����ֱ�ӱ��������Ӷ�ΪO(sqrt(n))*һ�������ʱ�临�Ӷȸ���...
#include<iostream>
#include<cstring>
using namespace std;
int N;
bool mark[100001];
int prime[100000];
int initial() //Ԥ����
{
    memset(mark,0,sizeof(mark[0]));
    memset(prime,0,sizeof(prime[0]));//����ĳ�ʼ����
    int cnt=0;
    for(int i=2;i<=100000;i++)
    {
        if(mark[i]==true) continue;
        prime[cnt++]=i;
        mark[i]=true;
        if(i>=1000) continue;
        for(int k=i*i;k<=100000;k+=i)
        {
            mark[k]=true;
        }
    }
    return cnt;
}
int main()
{
    int cnt=initial();
    while(cin>>N)
    {
        int sum=0;
        for(int i=0;i<cnt;i++)
        {
            if(prime[i]>N) break;
            else
            {
                while((N%prime[i]==0)&&N!=1)
                {
                    N=N/prime[i];
                    sum++;
                }
            }
            if(N==1)
                break;
        }
        if(N!=1)
        {
            prime[cnt++]=N;
            cout<<sum+1<<endl;
        }
        else
            cout<<sum<<endl;
    }
    return 0;
}
