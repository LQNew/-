//������ѧ��ʽ��ת��Ϊ����ʽ�� (b-a)*(c-a)=a^2-1 -->b+c=m+n+2*a������m��nΪ����
#include<iostream>
using namespace std;
long long a; //�ؼ������� ��ͨ�������޷��洢����ֵ�����ǲ���long long �ʹ洢��ע��һ��ʼ�������ʱa������int �ͣ����½���֮��Ļ��ң����������ԭ��...��
             //������Waһ��
int main()
{
    cin>>a;
    long long q,i,sum,min_1;
    q=a*a+1;
    min_1=9999999999;
    for(i=1;i<a+1;i++) //�����ҵ���������
    {
        if(q%i)
            continue;
        sum=q/i+i+2*a;
        if(sum<min_1)
            min_1=sum;
    }
    cout<<min_1<<endl;
    return 0;
}
