/*
����
�� skew binary��ʾ��, �� k λ��ֵxk��ʾxk*(2^(k+1)-1)�� ÿ��λ�ϵĿ���������0 �� 1�������һ������λ������2, ����, 10120(skew) = 1*(25-1) + 0*(24-1) + 1*(23-1) + 2*(22-1) + 0*(21-1) = 31 + 0 + 7 + 6 + 0 = 44. ǰʮ��skew���� 0��1��2��10��11��12��20��100��101���Լ�102��
����
�������һ�л���У�ÿ�а���һ������n�� ��� n = 0 ��ʾ�������������n��һ��skew ��
���
����ÿһ�����룬�������ʮ���Ʊ�ʾ��ת����ʮ���ƺ� n ������ 2^31-1 = 2147483647
*/
//����������Ƚϼ򵥣�ע������n�ǰ�ʮ�������룬��ôn����Ϊ32λʮ������ʽ����ô��ʹ��long long��Ҳ�޷��洢��������ݣ�����Ҫ���ǵ�ʹ���ַ����洢����
//�����ַ������˴���Ҫ�˽���ǣ������ַ����ĳ���ʱ��������strlen��������ַ����ĳ��ȣ�
#include<iostream>
#include<string.h>
using namespace std;
int factor[31]; //���ڴ洢����λ�ϵ�����
int cnt; //���ڼ�¼�������ݵ�λ��

int Power(int b) //���ݴεĺ���
{
    int res = 1;
    while (b--) res *= 2;
    return res;
}

int Get_value()//����skew��
{
    int value=0;
    for(int i=0;i<cnt;i++)
    {
        value+=factor[i]*(Power(i+1)-1);
    }
    return value;

}

int main()
{
    char skew[32];
    while(cin>>skew)
    {
        cnt=strlen(skew);
        if(cnt==1&&skew[0]=='0') break; //�Ƚ��Ƿ�����Ϊ0
        for(int i=0;i<cnt;i++)
        {
            factor[i]=int(skew[cnt-1-i]-'0'); //�ֽ��ַ�����ת��Ϊ����
        }

        cout<<Get_value()<<endl;
    }
    return 0;
}
