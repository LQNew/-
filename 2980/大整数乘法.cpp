/*
    ����
        ������������200λ�ķǸ������Ļ���
    ����
        �����У�ÿ����һ��������200λ�ķǸ�������û�ж����ǰ��0��
    ���
        һ�У�����˺�Ľ��������ﲻ���ж����ǰ��0������������342����ô�Ͳ������Ϊ0342��
*/
//���������ڳ˷���������Ҫģ�����ÿλ�ĳ˷��ó��Ľ���ȵ�ָ��λ�Ĳ�����Ȼ����ȥ��������λ���ڽ�λ�����
//��һ��������ȥ�洢�˷���λʱ��ÿλ����ֵ
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
char num1[201]; //����ĳ���1
char num2[201];//����ĳ���2
unsigned int mul[410];//�洢����ĳ˷�֮�͵���������ȥ���� 9*9�����������չ����λ�������������֪����200λ*200λ�ĳ˷����㣬����Ҳ���ǲ���400λ�ĳ˻�
int len_num1; //����ĳ���1�ĳ���
int len_num2;//����ĳ���2�ĳ���
void multiply() //�˷�����
{
    for(int j=0;j<len_num2;j++)
        for(int i=0;i<len_num1;i++)
            mul[i+j]+=(num1[i]-48)*(num2[j]-48); //����ÿ�ζ�Ӧ�ĳ˻�ֵ
    for(int k=0;k<len_num2+len_num1-1;k++)// �����λ
    {
        int a=mul[k];
        mul[k]=a%10;
        mul[k+1]+=a/10;
    }
}
int main()
{
    memset(mul,0,sizeof(mul[0])*410); //����������г�ʼ��
    cin>>num1>>num2;
    len_num1=strlen(num1);
    len_num2=strlen(num2);
    reverse(num1,num1+len_num1); //��������ַ����������� ����reverse������ʹ�ã��˴�������� num1[0]~num1[len_num1-1]��Ԫ��
    reverse(num2,num2+len_num2); //��������ַ�����������
    multiply();
    if(mul[len_num2+len_num1-1]) //����˷������˽�λ
    {
        for(int i=len_num2+len_num1-1;i>=0;i--)//����Ӹ�λ����λ��ӡ����
            cout<<mul[i];
        cout<<endl;
    }
    else
    {
        for(int i=len_num2+len_num1-2;i>=0;i--)//����Ӹ�λ����λ��ӡ����
            cout<<mul[i];
        cout<<endl;
    }
}
