/*
    ����һ�����У�ѡ�����������ҷǿյ�һ��ʹ����κ����
*/
//��������b[j]��ʾ��λ�� j Ϊ�յ�������������к�����һ������������
//��jΪ�յ����������������λ��j-1,����j-1Ϊ�յ������������Ȼ���������С�
//���b[j-1] >0, ��ô��Ȼb[j] = b[j-1] + a[j]����֮ǰ����һ������a[j]���ɣ���Ϊa[j]���������
//���b[j-1]<=0,��ôb[j] = a[j] ,��Ϊ��Ȼ���ǰ��ĸ�����Ȼ����ʹ�����
#include<iostream>
using namespace std;
int a[100001];
int n;
int maxsum(){ //��������������еı�׼dp�㷨������ÿ�������ǰ���ñȽϴ��ֵ���������֮ǰ��b<=0,��ô�㵽a[i]ʱ���϶���bֱ�Ӹ�ֵΪa[i]��ֱ��
    int local_sum=a[1];
    int b=0;
    for(int i=1;i<=n;i++){
        if(b>0) b+=a[i];
        else b=a[i];
        if(b>local_sum) local_sum=b;
    }
    return local_sum;
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    cout<<maxsum()<<endl;
    return 0;
}
