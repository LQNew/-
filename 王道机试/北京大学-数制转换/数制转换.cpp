#include<iostream>
#include<cstring>
using namespace std;
long a,b,temp;
long num,num1;
char input[100]; //�洢�������
int final[40];//���ڴ洢ת��Ϊ��Ӧ���ƺ����
char transform_1[16]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'}; //������������ת�����
long multiply(long m,long sum,int b) //�߾��ȳ˷�����
{
    if(sum==0)
        return 0;
    while(b--)
    {
        sum=sum*m;
    }
    return sum;
}

int main()
{
    while(cin>>a>>input>>b)
    {
        num=0;
        int j=0;
        for(int i=strlen(input)-1;i>=0;i--) //��ȡ��ӦΪ��ʵ��ʮ������
        {
            if(input[i]>='0'&&input[i]<='9')
                temp=input[i]-'0';
            else if(input[i]>='A'&&input[i]<='F')
                temp=input[i]-'A'+10;
            else
                temp=input[i]-'a'+10;
            num+=multiply(a,temp,j);
            j++;
        }
        int flag=0;
        memset(final,0,sizeof(final[0]));
        if(num==0) //����˴���
        {
            cout<<0<<endl;
            continue;
        }
        num1=num;
        while(num!=0)
        {
            num=num/b;
            final[flag++]=num1%b;
            num1=num;
        }
        for(int i=flag;i--;i>=0)
            cout<<transform_1[final[i]];
        cout<<endl;
    }
    return 0;
}
