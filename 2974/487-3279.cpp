/*
    ����
        ����ĸ�ʽ�ǣ���һ����һ����������ָ���绰���뱡�к�������������100000����
        ���µ�ÿ����һ���绰���롣ÿ���绰���������֣���д��ĸ������Q��Z���Լ����ӷ���ɡ�ÿ���绰������ֻ��պ���7�����ֻ�����ĸ��
    ���
        ����ÿ�������ظ��ĺ������һ�����������Ǻ���ı�׼��ʽ����һ���ո�Ȼ���������ظ�������
        ������ڶ���ظ��ĺ��룬���պ�����ֵ�����������������������û���ظ��ĺ��룬���һ�У�No duplicates.
*/
/*
������
    ��һ����Ķ�ά�������ڴ洢��������ĵ绰����ת�������ʽ
    ����ת����ĵ绰����������������
    ���������ĵ绰�����������ظ��ĵ绰������Ŀ
*/

#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;
char map[27]="22233344455566677778889999"; //������ĸ������ӳ����ַ�����
char TelNum[100000][9]; //�����еĵ绰����洢��һ����ά�����У�ע��˴��ַ������ַ�����������֮����ַ����ıȶԣ�����һ��Ϊ9����λ�����һ����λ�洢\0
char str[100]; //���ڴ洢����Ļ��������ݣ���λӦ��Ĵ�һЩ��

void Transfer(int n)
{
    int j,k=0;
    for(int i=0;i<strlen(str);i++)
    {
        if(k==3) {TelNum[n][k]='-';k++;}
        if(str[i]=='-')
            continue;
        if(str[i]>='A'&&str[i]<='Z')
            TelNum[n][k++]=map[str[i]-'A'];
        else
            TelNum[n][k++]=str[i];
    }
    TelNum[n][k]='\0';//���ϻ��з�������Ϊÿһ��Ϊһ���ַ���

}

int compare(const void*a,const void*b) //����qsort ʹ�õ�compare�������йش�compare��������дӦ���⣡
{
    return strcmp((char *)a,(char *)b); //ת��Ϊ�ַ�������Ԫ�صıȶԣ�����strcmp������ʹ��
}
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>str;
        Transfer(i); //�����������ת��
    }

    qsort(TelNum,n,9,compare); //����C++ģ���е�������
    /*qsort������ qsort ( ������ ��Ԫ�ظ�����Ԫ��ռ�õĿռ�(sizeof)���ȽϺ���)
      �ȽϺ�����һ���Լ�д�ĺ���  ��ѭ int com(const void *a,const void *b) �ĸ�ʽ��
      ��a b��ϵΪ >  <  = ʱ���ֱ𷵻���ֵ ��ֵ �� �������෴����
      ʹ��a b ʱҪǿ��ת�����ͣ���void * ת����Ӧ�е����ͺ󣬽��в�����
    */

    bool total_repeat= false;
    int i=0,j=0;
    while(i<n)
    {
        bool repeat=false;
        j=i;
        i++;
        //strcmp��������������ͷ�ļ������� <string.h>ͷ�ļ���
        //strcmp(s1,s2) ������s1 ��s2 �ַ�����ͬ�򷵻�0��s1 ������s2 �򷵻ش���0 ��ֵ��s1 ��С��s2 �򷵻�С��0��ֵ��
        while(strcmp(TelNum[i],TelNum[j])==0) //���ڼ����ź����������е��ظ�Ԫ�صĸ������˴�˼·��Ϊ����Լ�Ҫ���մ���˼·~
        {
            i++;
            repeat=true;
            total_repeat=true;
        }
        if(repeat)
            cout<<TelNum[i-1]<<" "<<i-j<<endl;
    }
    if(total_repeat==false)
        cout<<"No duplicates."<<endl;
}
