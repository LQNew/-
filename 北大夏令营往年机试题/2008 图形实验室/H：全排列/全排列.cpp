//�������õ���C++�е�stl�⣬��Ҫ��next_pernutation �ĵ��ã�ͬʱע��next_permutation ��ʹ��~
//�������˵����֮ǰ���������Ԫ�����е�������ȣ�˼·���ƣ��ѶȽ�С����Ҫ�������� next_permutation �Լ� qsort ���������ַ���Ԫ�ؽ�������
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
char str[7];

int compare(const void*a,const void*b) //����qsort ʹ�õ�compare�������йش�compare��������дӦ���⣡
{
    return *(char*)a-*(char*)b;
}

int length(int len) //���ȫ����Ԫ�صĸ���
{
    int len_1=1;
    for(int i=len;i>1;i--)
        len_1=len_1*i;
    return len_1;
}
int main()
{
    cin>>str;
    int len=length(strlen(str));
    qsort(str,strlen(str),1,compare); //���ַ������п�������
    cout<<str<<endl;
    for(int i=1;i<len;i++)
    {
        next_permutation(str,str+strlen(str));//next_permutation�õ���һ������ ��str[0]��str[strlen(str)-1]�ҵ���һ����
        cout<<str<<endl;
    }
    return 0;
}
