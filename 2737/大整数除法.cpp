/*
    ����
        ���������������������̡�
    ����
        ��1���Ǳ���������2���ǳ�����ÿ������������100λ��
    ���
        һ�У���Ӧ���̵���������
*/
//�����������������Ǹ߾��������������ӵ�һ�����㣬���ڴ������ӷ����������˷�����������Ӧ���Ѷ����
//��д�� ������������������򣬶��ڳ������ǴӸ�λ���𣬶���ÿһλ�ĳ������ǲ����˼���������ѭ����������λ��ֵ�������õ���trick���ܽ϶࣬˼·���Ǻ�������д��...
//���������õ��� cstring���е� memeset()���������ʼ����memcpy()����������и������㣻�Լ�algorithm���е�reverse()��������������з�ת����
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
char num1[101]; //�������һ��������
char num2[101]; //���������������
unsigned int division[100];//�������
int minus_1[110]; //�洢������ �������ֵ
int a[110]; //�洢������
int b[200]; //�洢��������Ϊ��������ʹ����һЩСtrick������Ϊ�˱�֤��������У���Ҫ��һ���ϴ�ռ������
int length_minus; //��¼�����������֮��ĳ��Ȳ�ֵ

bool minus_(int length,int flag)
{
    for(int i=0;i<length;i++)
        minus_1[i]=a[i]-b[i+length_minus-flag]; //��λ�������㣬������ͨ��flagȷ�����������0����
    for(int i=0;i<length;i++)
    {
        int c=minus_1[i]; //��������� �Ը���λ�б��Ƿ�����λ���
        if(c<0)
        {
            minus_1[i]+=10;
            minus_1[i+1]-=1;
        }
    }
    if(minus_1[length]<0) //�����λ���ڽ�λʱ��˵���˴μ������㲻����
    {
        memset(minus_1,0,sizeof(minus_1[0])*110);//���洢��ֵ��������0���Է��˴������Ĳ�ֵ���ݽ�������ѭ������ļ��������ֵ����
        return false;
    }
    else //����Ļ����˴μ����������
    {
        memcpy(a,minus_1,sizeof(minus_1[0])*110); //��������������ֵ����a����
        memset(minus_1,0,sizeof(minus_1[0])*110); //���洢��ֵ��������0
        return true;
    }
}

int main()
{
    memset(a,0,sizeof(a[0])*100); //���� a��ʼ��
    memset(b,0,sizeof(b[0])*200); //���� b��ʼ��
    memset(division,0,sizeof(division[0])*100); //����division��ʼ��
    cin>>num1>>num2;
    int length_num1=strlen(num1);
    int length_num2=strlen(num2);
    reverse(num1,num1+length_num1); //��������ַ����������� ����reverse������ʹ�ã��˴�������� num1[0]~num1[len_num1-1]��Ԫ��
    reverse(num2,num2+length_num2); //��������ַ�����������
    length_minus=length_num1-length_num2;//��¼��������������ȵĲ�ֵ����Ϊ���߾�Ϊ�������������Զ��߲�ֵ��С��0���򱻳���С�ڳ�������ô�̶�Ϊ0
    if(length_minus<0)
        cout<<0<<endl;
    else
    {
        for(int i=0;i<length_num1;i++)
            a[i]=num1[i]-48;
        for(int j=0;j<length_num2;j++)
            b[j+length_minus]=num2[j]-48;//ǰlength_minus��λ�ÿ�λΪ0�����ڸ��Ա�ʶ֮������ ����֮��Ӧ������λ0
        for(int i=length_minus;i>=0;i--)
        {
            while(minus_(length_num1,i))
                division[i]++;
        }
        bool judge=true;
        if(length_minus==0&&!division[0])//������߳���һ�£�ͬʱ��δ�б仯��ͬ��˵�� ������С�ڳ�������Ϊ0
            cout<<0<<endl;
        else
        {
            for(int i=length_minus;i>=0;i--)
            {
                if(!division[i]&&judge) //����һ����ʶ�� judge������ȥ���̸�λ��0
                    judge=true;
                else
                {
                    judge=false;
                    cout<<division[i];
                }
            }
        cout<<endl;
        }
    }
}
