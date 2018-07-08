 /*
    ���ļ�������P (1000<P<3100000) ,����2^p-1��λ�������500λ���֣���ʮ���Ƹ߾�������ʾ��
    ����
        �ļ���ֻ����һ������P(1000<P<3100000)
    ���
        ��1�У�ʮ���Ƹ߾�����2^p-1��λ����
        ��2-11�У�ʮ���Ƹ߾�����2^p-1�����500λ���֡���ÿ�����50λ�������10�У�����500λʱ��λ��0��
*/
//���������ÿ�����˼·���2^p-1��ֵ�Լ�log10()�������λ�����������ɿ� ��2���ݴ���ĳ���ע���Լ�word�ܽ�~
#include<iostream>
#include<cmath>
#include<cstring>
#include<iomanip>
using namespace std;
int p; //������ݴ�P
double cnt;//��¼λ��
int decomposition[24];//�洢P�ķֽ�ֵ
long long result[100]; //����������
long long num1[100];//����
long long mid[101]; //�м�ֵ
void Decomposition() //��p�ֽ�Ϊ2������ʽ
{
    int p_1=p;
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
}

void multiply(long long *num1,long long *num2,long long *mid) //��ΪֻҪ��500λ��������ÿ��ֻ��������λ��ֵ
{
    for(int i=0;i<100;i++)
    {
        for(int j=0;j<100;j++)
        {
            if(i+j<100)
                mid[i+j]+=num1[i]*num2[j];
        }
    }
    for(int i=0;i<100;i++)
    {
        if(mid[i]>100000) //�����λ�����
        {
            mid[i+1]+=mid[i]/100000;
            mid[i]=mid[i]%100000;

        }
    }
    memcpy(num1,mid,sizeof(mid[0])*100);
    memset(mid,0,sizeof(mid[0])*101);
}

int main()
{
    cin>>p;
    memset(num1,0,sizeof(long long)*100); //�����ʼ��
    memset(result,0,sizeof(long long)*100);
    memset(mid,0,sizeof(long long)*101);
    num1[0]=2;
    result[0]=1;
    cnt=ceil(p*log(2)/log(10)); //���� ���� 2^p-1��2^p�ĸ�λ����֪������ 2^p��λ����һ��
    Decomposition();
    if(decomposition[0])
        result[0]=2;
    for(int i=1;i<24;i++)
    {
        multiply(num1,num1,mid);
        if(decomposition[i])
            multiply(result,num1,mid);
    }
    cout<<cnt<<endl;
    int i=0;
    for(int j=99;j>0;j--) //�����ӡ����
    {

        if(result[j])
            cout<<setfill('0')<<setw(5)<<result[j]; //����5λ���� ����5λʱ���в������
        else
            cout<<"00000";//���Ϊ0����ӡ��5��0
        i++;
        if(i%10==0) //������û��50λ�����л��в���
            cout<<endl;
    }
    cout<<result[0]-1; //��λ����-1����
    cout<<endl;
}
