//��Ŀ�ѶȲ��󣬲������ڻ��з���ζ����Һ���֣��о����з����ǰ��س�����ֹorz..
//��������Ҫ���õ���gets()������ȡһ���ַ����Լ� toupper()��������ĸ��д~
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
