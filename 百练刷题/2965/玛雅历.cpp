/*
���������⣬�����Ǻܼ򵥵����⣬������Ŀ��Щ�����ƣ�����������Ϸ������
*/
//������ ��һ��������ʽת��Ϊ��һ��������ʽ��������ѧ�ϵĴ�������Ҫע����ǣ��˵�����ΪWA�������Σ������������⣡
//1������ʱ��Ķ�ȡ������һ���ַ�ȥ�н�
//2���������е�19�£�������ӡ���
//3�����ʱҲ����������һ��
//4������ȡ����һЩϸ���ϵ�С����û˼����
#include<iostream>
#include<cstring>
using namespace std;
int cnt;
char month[10];
char dot='.';
int date;
int year;
int Tzolkin_date;
char Tzolkin_month[10];
int Tzolkin_year;
char Haab[19][10]={"pop", "no", "zip", "zotz", "tzec", "xul", "yoxkin", "mol", "chen",
                    "yax", "zac", "ceh","mac", "kankin", "muan", "pax", "koyab", "cumhu","uayet"};
char Tzolkin[20][10]={"ahau","imix", "ik", "akbal", "kan", "chicchan", "cimi", "manik", "lamat", "muluk", "ok",
                        "chuen", "eb","ben", "ix", "mem", "cib", "caban", "eznab", "canac"};
int com_month() //�����������µ��·�
{
    int j;
    for(j=0;j<19;j++)
    {
        if(strcmp(month,Haab[j])==0)
            return j;
    }
}
int main()
{
    cin>>cnt;
    cout<<cnt<<endl;
    for(int i=0;i<cnt;i++)
    {
        cin>>date>>dot>>month>>year;
        int months=com_month();
        int days=year*365+months*20+date+1;
        if(days%13) //�˴�����ȡ��Ҫע��13�ı��������ϵ�trick��
            Tzolkin_date=days%13;
        else
            Tzolkin_date=13;
        strcpy(Tzolkin_month,Tzolkin[days%20]);
        Tzolkin_year=(days-1)/260;
        cout<<Tzolkin_date<<" "<<Tzolkin_month<<" "<<Tzolkin_year<<endl;
    }
    return 0;
}
