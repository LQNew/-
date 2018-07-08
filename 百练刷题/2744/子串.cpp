/*
    ����
        ������һЩ��Ӣ���ַ���ɵĴ�Сд���е��ַ���������������ҵ�һ������ַ���x��ʹ�ö����Ѿ��������ַ����е�����һ��y��x������y���Ӵ���
        ����x�е��ַ�����֮��õ������ַ�����y���Ӵ���
    ����
        ����ĵ�һ����һ������t (1 <= t <= 10)��t��ʾ�������ݵ���Ŀ������ÿһ��������ݣ���һ����һ������n (1 <= n <= 100)����ʾ�Ѿ�����n���ַ�����
        ������n�У�ÿ�и���һ��������1��100֮����ַ�����
    ���
        ����ÿһ��������ݣ����һ�У�������Ŀ��Ҫ����ַ���x�ĳ��ȡ�
*/
//����������ȡ�õ����ַ����ȴ洢��������ȥ�ҹ����Ӵ����ص���Ҫ���ӵ���string�����ļ���ģ�庯��:
//      strstr ���ַ�����Ѱ�����ַ��� ; strcpy �����ַ��� ; strncpy �������ַ��� ; strlen �����ַ����ĳ��� ; reverse ������������������

#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
char all_str[100][101]; //��ά���������ڴ洢����������ַ���
char min_str[101]; //���ڴ洢��̳��ȵ��ַ���
char max_substr[101]; //���ڴ洢�Ӵ�
char max_rev_substr[101]; //���ڴ洢�Ӵ���������ʽ
int n,t; //���� t��n

int Find_max_str()
{
    int k=strlen(min_str);
    for(int i=k;i>0;i--)
    {
        for(int j=0;j<=k-i;j++)
        {
            strncpy(max_substr,min_str+j,i); //strncpy ���ƺ����������ַ�����ָ�����ȼ�λ�ô����Ӵ���ָ�����ַ�������
            strncpy(max_rev_substr,min_str+j,i);
            max_substr[i]=max_rev_substr[i]='\0';//���'\0'��ʾΪ�ַ�������
            reverse(max_rev_substr,max_rev_substr+i); //���� algorithm���е� reverse�����������е���������洢
            int cnt=0;
            for(int num=0;num<n;num++)
            {
                if(strstr(all_str[num],max_substr)||strstr(all_str[num],max_rev_substr)) //strstr���� �����ַ������Ƿ�����Ӧ�����ַ���
                    cnt++; //ÿƥ��һ��������+1
            }
            if (cnt==n) //��ƥ����ܸ�������������ַ���������˵��Ϊ�����Ӵ�
                return i;
        }

    }
    return 0;
}

int main()
{
    cin>>t;
    for(int i=0;i<t;i++)
    {
        cin>>n;
        int min_len=101;
        for(int j=0;j<n;j++)
        {
            cin>>all_str[j];
            if(strlen(all_str[j])<min_len) //�ҳ���̳��ȵ��ַ�������Ϊ������Ӵ�һ��Ҫ������̳��ȵ��ַ����У���������ٿ�����
            {
                min_len=strlen(all_str[j]);
                strcpy(min_str,all_str[j]);
            }
        }
        cout<<Find_max_str()<<endl;
    }
    return 0;
}
