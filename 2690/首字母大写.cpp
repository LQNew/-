//����ĸ��д��˼·��ˮ
//�����õ����������������˽⣬һ����gets()���������ڽ���һ��һ�е�������ַ��������ڿհ׷��������
//��һ���ǽ��ַ���Сдת���ĺ��� toupper()�Լ�tolower()����~
#include<iostream>
#include<cstring>
using namespace std;
char str1[80];
int main(){
    gets(str1);
    //cout<<str1<<endl;
    str1[0]=toupper(str1[0]);
    for(int i=1;i<strlen(str1)-1;i++){
        if(str1[i]==' '||str1[i]=='\t'||str1[i]=='\n'||str1[i]=='\r') str1[i+1]=toupper(str1[i+1]);
    }
    cout<<str1<<endl;
    return 0;
}
