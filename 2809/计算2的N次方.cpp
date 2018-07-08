/*
    ����
        �������һ��������N(N<=100)������2��n�η���ֵ��
    ����
        ����һ��������N��
    ���
        ���2��N�η���ֵ��
*/
//����:�˵��⼸������ɭ���ǵ�����ȫһ�����ѶȽ�֮��ɭ�����ͣ���Ϊ����N��ֻ��<=100���˴���Ҫ����2��N�η��и����100�η����Ҳ�ͳ���40��λ
//1000��η������300��λ���и��������Ժ���~
//�����Ǵ���ɭ���Ǳ�ֱ�Ӹ���ճ��������������Դ�����˵���������Ƚ�P�ֽ�Ϊ2�Ĵη���ʽ�������������ģ��2^p������������ᷢ��ÿ�γ˻����㶼����һ�ε�
//�����Լ�ƽ�����õ���һ����������һ�������ٺ͵�ǰ�ĳ˻���ˣ��˴�Ӧ���̺��ſ����ݵ�˼�룬����2���ݴΣ���ôP�Ͳ�Ϊ2���ݴ���ʽ�
//���ڴ�ӡ���ݣ��˴���ЩСtrick����Ϊ��λΪ0�������ɴ�ӡ������Ϊ�˴�������ʮ����Ƶ����㣬����5λ�������Ϊ0����ô��λ��Ӧ���㣬��ʱӦ����iomanip���
//etfill()�����Լ�setw()������������������ʹ��һ��Ҫ��Ϥ����Ϊcout��������C�е�printf()�������ڽ���ת��Ҫ����Щ~
#include<iostream>
#include<cstring>
#include<iomanip>
using namespace std;
int p; //����Ĵη�ֵ
int decomposition[7]; //�洢�ֽ������
long long result[100];//�洢������
long long num1[100];//��ǰ�ĳ���
long long mid[101];//����ʱ���ڴ��ݵ��м�ֵ

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

void multiply(long long *num1,long long *num2,long long *mid) //�˴�����֪2��һ�ٴη�����40��λ������500λ������ȥ����������
{
    for(int i=0;i<100;i++)
    {
        for(int j=0;j<100;j++)
        {
            if(i+j<100)
                mid[i+j]+=num1[i]*num2[j]; //��Ӧλ�ĳ˻�
        }
    }
    for(int i=0;i<100;i++)
    {
        if(mid[i]>100000) //���������λ����ô����λֵ���ݸ���һλ
        {
            mid[i+1]+=mid[i]/100000;
            mid[i]=mid[i]%100000;
        }
    }
    memcpy(num1,mid,sizeof(mid[0])*100); //���м�ֵ��������ǰ�ĳ���
    memset(mid,0,sizeof(mid[0])*101);
}

int main()
{
    cin>>p;
    memset(num1,0,sizeof(long long)*100); //�����ʼ��Ϊ0
    memset(result,0,sizeof(long long)*100);
    memset(mid,0,sizeof(long long)*101);
    num1[0]=2; //��һ��ֵΪ2^(2^0)=2
    result[0]=1;
    Decomposition();
    if(decomposition[0]) //�����һλ�з����ôresultΪ1*2=2
        result[0]=2;
    for(int i=1;i<7;i++) //������ˣ�������˼��
    {
        multiply(num1,num1,mid);
        if(decomposition[i])
            multiply(result,num1,mid);
    }
    //�����ӡ
    int j;
    for(j=99;j>=0;j--)
    {
        if(result[j]!=0) //ɸȥ��λ��0��
            break;
    }
    cout<<result[j]; //��һ����λ���벹�����
    j--;
    for(j;j>=0;j--)
    {
        cout<<setfill('0')<<setw(5)<<result[j]; //����λ�����ɽ��в������
    }
    cout<<endl;
}
