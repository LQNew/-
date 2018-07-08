//���������о���ָÿ����������������:A��B�����߿��Խ�ĳ����һ�ţ����߲�����~
//���Ǽ򵥵�������⣬��A����ͬ�������N����ͬ�ĺ����У�ÿ�����ӿ��Է�һ��A����߲��ţ���ʵ���൱�� ��A������N������Ȼ��ѡ��N���������ƥ����
//������ ��Ҫע��ײ����ʱ��ֵ����������⣬���ͼ����Ļ�����ֱ��дһ�������˷����˴�����long long �ͳ��������ݴ洢���~
#include<iostream>
using namespace std;
int N,A,B;

long long computer_hierarchy_up(int n,int a){
    long long  total=1;
    for(int i=n-a+1;i<=n;i++) total*=i;
    return total;
}
long long computer_hierarchy_down(int n){
    long long  total=1;
    for(int i=2;i<=n;i++) total*=i;
    return total;
}
int main(){
    while(cin>>N>>A>>B){
        long long a=computer_hierarchy_up(N+A,A)/computer_hierarchy_down(A);
        long long b=computer_hierarchy_up(N+B,B)/computer_hierarchy_down(B);
        cout<<a*b<<endl;
    }
    return 0;
}
