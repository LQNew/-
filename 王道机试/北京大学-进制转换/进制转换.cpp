/*
    д��һ�����򣬽���һ��ʮ�����Ƶ���ֵ�ַ������������ֵ��ʮ�����ַ�����
*/
//������һ��ʼ��Ϊ�Ǵ������˷��������ֱ�������ǵ��򵥵���Ŀ����û���漰��������...��ô������ˮ�⣬��Ȼ������Ҳ���Գ��ĺ����ѣ���
//���Լ�����ĬĬ������һ�£�������Ǵ�������Ļ�����Ҫÿ�μ����ݴ�ҲӦ�õ��������˷��������ݴε�������Բ��ÿ������㷨���������е�A^B��~
#include<iostream>
#include<cstring>
using namespace std;
char num_sixteen[500];
long long num_ten;
int flag;
void transform_1() //ת�����ƺ���
{
    int num;
    long b=1;
    int len=strlen(num_sixteen);
    for(int i=len-1;i>1;i--)
    {
        if(num_sixteen[i]>='0'&&num_sixteen[i]<='9')
            num=num_sixteen[i]-'0';
        else
            num=num_sixteen[i]-'A'+10;
        num_ten+=num*b;
        b*=16;
    }
}
int main()
{
    while(cin>>num_sixteen)
    {
        transform_1();
        cout<<num_ten<<endl;
        num_ten=0;
    }
    return 0;
}
