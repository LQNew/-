/*
    ����
        ������������200λ�ķǸ������ĺ͡�
    ����
        �����У�ÿ����һ��������200λ�ķǸ������������ж����ǰ��0��
    ���
        һ�У�����Ӻ�Ľ��������ﲻ���ж����ǰ��0������������342����ô�Ͳ������Ϊ0342��
*/
//������������Ŀ�Ĵ����֮�ⷨһ���ܷ����ϸ�ֱ�ף�û����ô�ɵ�����ˣ����ǵ����ظ�λ��Ӻ��������ÿλ�Ƿ�������λ
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
char num1[201]; //�������
char num2[201]; //�������
unsigned int add[210]; //����ĺ�
int len_num1;
int len_num2;
void add_1()
{
    if(len_num1>len_num2) //����1����>����2����
    {
        for(int i=0;i<len_num2;i++) //����ָ��λ�ļ�����
            add[i]=(num1[i]-48)+(num2[i]-48);
        for(int i=len_num2;i<len_num1;i++)
            add[i]=num1[i]-48;
        for(int k=0;k<len_num1;k++) //�������λ�Ľ�λ
        {
            int a=add[k];
            add[k]=a%10;
            add[k+1]+=a/10;
        }
    }
    else //����1����<����2����
    {
        for(int i=0;i<len_num1;i++) //����ָ��λ�ļ�����
            add[i]=(num1[i]-48)+(num2[i]-48);
        for(int i=len_num1;i<len_num2;i++)
            add[i]=num2[i]-48;
        for(int k=0;k<len_num2;k++) //�������λ�Ľ�λ
        {
            int a=add[k];
            add[k]=a%10;
            add[k+1]+=a/10;
        }
    }
}
int main()
{
    memset(add,0,sizeof(add[0])*210); //������0��ʼ��
    cin>>num1>>num2;
    len_num1=strlen(num1);
    len_num2=strlen(num2);
    reverse(num1,num1+len_num1); //��������ַ����������� ����reverse������ʹ�ã��˴�������� num1[0]~num1[len_num1-1]��Ԫ��
    reverse(num2,num2+len_num2); //��������ַ�����������
    add_1();
    bool c=true; //У�����
    for(int i=max(len_num1,len_num2);i>=0;i--) //�����б�ȥ����λ����ε�0������һЩСtrick�����ǿ��ܻ��и����ķ�ʽ...
    {
        if(add[i]==0&&i>0&&c)
            c=true;
        else
        {
            c=false;
            cout<<add[i];
        }
    }
    cout<<endl;
}

