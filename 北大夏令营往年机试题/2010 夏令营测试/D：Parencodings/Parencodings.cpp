//������ջ���ַ������д���
#include<iostream>
#include<cstring>
#include<stack>
using namespace std;
char str[100];
int cnt[100];
int t;
int n;
int a;
stack<int>S;
int main(){
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>n;
        int cnt1=0;//��¼�ַ������ַ�����
        int k=0;
        //�����ַ���
        for(int j=0;j<n;j++){
            cin>>a;
            for(k;k<a;k++){
                str[cnt1]='(';
                cnt1++;
            }
            str[cnt1]=')';
            cnt1++;
        }
        str[cnt1]='\0';
        //��¼ÿ���±��Ӧ���ַ�ǰ�ֶ��ٸ�'('
        int cnt2=0;
        for(int i=0;i<strlen(str);i++){
            if(str[i]=='('){
                cnt2++;
                cnt[i]=cnt2;
            }
            else cnt[i]=cnt2;
        }
        //ջ����
        for(int i=0;i<strlen(str);i++){
            if(str[i]=='(') S.push(i);
            else if(str[i]==')') {
                int num=S.top();
                S.pop();
                cout<<cnt[i]-cnt[num]+1<<' ';
            }
        }
        cout<<endl;
    }
    return 0;
}
