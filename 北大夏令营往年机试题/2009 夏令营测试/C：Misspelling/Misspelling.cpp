//ˮ�⣬��string stl���������⣬�Ѷ���СһЩ��
#include<iostream>
#include<string>
using namespace std;
int N;
int num1;
char str1[100];
int main(){
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>num1;
        cin>>str1;
        string a=str1;
        a.erase(num1-1,1); //������ַ����±� num1-1 ��ʼ��1���ַ���
        cout<<i+1<<' '<<a<<endl;
    }
    return 0;
}
