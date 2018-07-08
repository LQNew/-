/*
    ����
        ����ĵ�һ�а�����һ������N����ʾ��N��������ݡ�������N�У�ÿһ�а���һ��ʱ�������ʱ������д������֮���ÿո������
        ʱ���ɱ�׼��a.m./p.m������midnight��ʾ����12�㣨12:00 a.m.����noon��ʾ����12�㣨12:00 p.m.����
    ���
        ���������и�����ʱ�����ڵ�һ��ʱ���еı�׼ʱ�䣬Ҫ��������ʱ���ڵڶ���ʱ���еı�׼ʱ�䡣
*/
//���� �����Ƿ��ӵ��Ǳ���û��ʲô�Ѷ�orz��ע�Ȿ��������һ��Сtrick�����Ǵ˴������������������ڼ���ʱ�����
//Ӧ�˽� c++�� ����������Ŀ�����ʽ����ķ�����
#include<iostream>
#include<cstring>
#include<iomanip> //������������ʽ��ͷ�ļ�!!��Ҫ��ע��˴�һЩ���Ҫ����λ�����ĸ�ʽ��ʽ����
using namespace std;
char zone[32][5] = { "UTC", "GMT", "BST","IST", "WET",
                     "WEST", "CET", "CEST", "EET", "EEST",
                     "MSK", "MSD", "AST", "ADT", "NST",
                     "NDT", "EST", "EDT", "CST", "CDT",
                     "MST", "MDT", "PST", "PDT", "HST",
                     "AKST", "AKDT", "AEST", "AEDT", "ACST",
                     "ACDT", "AWST"};
float time_interval[32] = { 0, 0, 1, 1, 0, 1, 1, 2, 2, 3,
                   3, 4, -4, -3, -3.5, -2.5, -5, -4, -6, -5,
                   -7, -6, -8, -7, -10, -9, -8, 10, 11, 9.5,
                   10.5, 8};
int N;//���������N������N���������
char zone1[5],zone2[5]; //���������ʱ��
char time_2[5];//����ĵ�һ��ʱ��
char AorP[5]; //�ж���a.m. ���� p.m.
int hour,minute; //�����ʱ�䡢����
float time_interval_1; //ʱ����ʱ����
float compute_time_interval() //����ʱ�����
{
    int i,j;
    for(i=0;i<32;i++)
    {
        if(strcmp(zone1,zone[i])==0)
            break;
    }
    for(j=0;j<32;j++)
    {
        if(strcmp(zone2,zone[j])==0)
            break;
    }
    return time_interval[j]-time_interval[i];
}
int find_colon() //�ҵ�:��λ��
{
    for(int i=0;i<strlen(time_2);i++)
    {
        if(time_2[i]==':')
            return i;
    }
}
int main()
{
    cin>>N;
    for(int i=0;i<N;i++)
    {
        cin>>time_2;
        if(time_2[0]=='n') //�����n������Ϊnoon ����
        {
            hour=12;
            minute=0;
        }
        else if(time_2[0]=='m') //�����m ����Ϊ midnight ��ҹ
        {
            hour=0;
            minute=0;
        }
        else
        {
            int j=find_colon();
            if(j==1)
            {
                hour=time_2[0]-48; //ascii��ת��Ϊ��Ӧ�����ε�����
                minute=(time_2[2]-48)*10+(time_2[3]-48);
            }
            else
            {
                 hour=10*(time_2[0]-48)+time_2[1]-48;
                 minute=(time_2[3]-48)*10+time_2[4]-48;
            }
            cin>>AorP; //�ж�Ϊa.m. ���� p.m.
            if(AorP[0]=='p')
            {
                if(hour<12)
                    hour+=12;
            }
            else
            {
                if(hour==12)
                    hour=0;
            }
        }
        cin>>zone1>>zone2;
        time_interval_1=compute_time_interval(); //����ʱ��ʱ��
        int k=time_interval_1*60;
        hour+=k/60;
        minute+=k%60;
        if(minute>=60) //�������>60����λ
        {
            minute-=60;
            hour+=1;
        }
        else if(minute<0)//�������<0����λ
        {
            minute+=60;
            hour-=1;
        }
        if(hour==12&&minute==0)
            cout<<"noon"<<endl;
        else if(hour%24==0&&minute==0)
            cout<<"midnight"<<endl;
        else
        {
            if(hour>=24) //���ʱ�䳬��24Сʱ������Ϊ����
                hour-=24;
            else if(hour<0)//���ʱ��С��0Сʱ������Ϊ����
                hour+=24;
            if(hour<12)
            {
                if(hour<1) //�������㼸�̣���ô��Ӧ��Ӧת��Ϊ 12:~~ a.m.
                    cout<<12<<':'<<setfill('0')<<setw(2)<<minute<<" "<<"a.m."<<endl; //����ʹ��minute�Զ�λ������ʽ���
                else
                    cout<<hour<<':'<<setfill('0')<<setw(2)<<minute<<" "<<"a.m."<<endl;
            }
            else
            {
                if(hour<13)  //�����12�㼴�ɣ���ô��Ӧ��Ӧת��Ϊ 12:~~ p.m.
                    cout<<12<<':'<<setfill('0')<<setw(2)<<minute<<" "<<"p.m."<<endl;
                else
                    cout<<hour-12<<':'<<setfill('0')<<setw(2)<<minute<<" "<<"p.m."<<endl;
            }
        }
    }


}
