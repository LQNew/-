//����λ���ݴεĺ���λ����ʵ���ڳ˷����㣬����λ���Ǻ���λȥ�˵õ���
//�������ݵ�˼��ܰ��������ô���Ҫ�����ᣡ��
#include<iostream>
using namespace std;
int decomposition[14];//�洢P�ķֽ�ֵ
int A,B;
int Decomposition() //��p�ֽ�Ϊ2������ʽ
{
    int p_1=B;
    int i=0;
    while(p_1!=0)
    {
        if(p_1%2)
        {
            decomposition[i]=1;
            p_1=p_1/2;
        }
        else
        {
            p_1=p_1/2;
            decomposition[i]=0;
        }
        i++;
    }
    return i;
}
int main()
{
    while(cin>>A>>B)
    {
        if(A==0&&B==0)
            break;
        int cnt=Decomposition();
        int ans=A;
        int final=1;
        for(int i=0;i<cnt;i++)
        {
            if(decomposition[i]==1)
            {
                final*=ans;
                final%=1000;
            }
            ans=ans*ans;
            ans%=1000;
        }
        cout<<final<<endl;
    }
    return 0;
}
