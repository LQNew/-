/*
    ����
        ��಻����100�����ݼ���ɡ�ÿ�����ݼ���3������ɣ�
        ��ʼ�У�START
        ������Ϣ����1��200���ַ����һ�У���ʾCaesar������һ����Ϣ
        �����У�END
        �����һ�����ݼ�֮������һ�У�ENDOFINPUT
    ���
        ÿ�����ݼ���Ӧһ�У���Caesar ��ԭʼ��Ϣ��
*/
//������������Ƚϼ򵥣�����Ҫ����Ӧ��ע���ʽ��Ҫ�󣬴˵������� cin.getline()��������
#include <iostream>
#include <string.h>
using namespace std;
char message[201];
char decoding_message[201]; //�洢�������ַ���
char decoding_table[]="VWXYZABCDEFGHIJKLMNOPQRSTU"; //�����

void Decode()
{
    int i=0;
    for(i;i<strlen(message);i++)
    {
        if(message[i]>='A'&&message[i]<='Z')
            decoding_message[i]=decoding_table[message[i]-'A'];
        else
            decoding_message[i]=message[i];
    }
    decoding_message[i]='\0';
    cin.getline(message,200); //����cin.getline()������ʹ�ã����ڰ��н���������cin�������ո���оͶ�ȡ����
    cout<<decoding_message<<endl;
    cin.getline(message,200);
}

int main()
{
    cin.getline(message,200);
    while(strcmp(message,"START")==0) //strcmp�ַ����ȶԺ���
    {
        cin.getline(message,200);
        Decode();
    }
    return 0;
}
