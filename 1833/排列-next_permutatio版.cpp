//�Ľ��棬ʹ����reverse�������ڽ��������� �Լ�next_permutation��������ֱ�ӻ�ȡ��һ����
#include<iostream>
#include<algorithm>
using namespace std;
int m;
int n,k;
int num[1025];
int flag;//���ڱ�ʶ��ǰӦ�ñ���λ�����

int main()
{
    cin>>m;
    for(int i=0;i<m;i++)
    {
        cin>>n>>k;
        for(int j=1;j<=n;j++)//¼�����ݣ�������cin���� ʱ��ᱬ����ʵ�ʲ�û�г�ʱ
            cin>>num[j];
        for(int m=0;m<k;m++)
        {
            for(flag=n;flag>0;flag--)
            {
                if(num[flag-1]<num[flag]) //�ҵ���Ҫ��λ��λ�� flag
                    break;
            }
            if(flag==1) //�����ʱ�������Ѿ�����������һ������ô���ص�һ������ͷ��ʼ
                reverse(num+1,num+n+1); //reverse������ȡ�� num[1]��num[n+1]����ȫ������
            else
               next_permutation(num+1,num+n+1);//next_permutation�õ���һ������ ��num[1]��num[n]�ҵ���һ����
        }
        for(int i=1;i<=n;i++)
            cout<<num[i]<<" ";
        cout<<endl;
    }
    return 0;
}
