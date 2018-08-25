// �ݹ�˼·�����ڵݹ����⣬��д�ò��Ǻ���죬˼·�����е㽩����
#include<iostream>
#include<cstring>
using namespace std;

void Print(char* number){ // ��ӡ�ַ�������ȥ���ײ��Ŀո�
    int i = 0;
    int length = strlen(number);
    bool flag = true;
    while(i<length){
        if(number[i] == '0' && flag){
            flag = true;
            i++;
        }
        else{
            cout<<number[i];
            i++;
            flag = false;
        }
    }
    cout<<' '; // ����ո�
}

void PrintCycle(char* number, int length, int index){ // ѭ����ÿ�δ�ӡ��ȥ��λ���ֵ���������λ��ѭ����
    if(index == length - 1){
        Print(number);
        return;
    }
    for(int i=0;i<10;i++){
        number[index + 1] = i + '0';
        PrintCycle(number, length, index + 1);
    }
}

void PrintToMax(int n){
    if(n <= 0) return;
    char* number = new char[n + 1];
    number[n] = '\0'; // �����ַ���
    for(int i=0;i<10;i++){
        number[0] = i + '0'; // ��ʼ����λ����
        PrintCycle(number, n, 0);
    }
    delete[] number;

}

int main(){
    int n;
    cin>>n;
    PrintToMax(n);
    return 0;
}
