/*
    ������������ȷ��һ��������߳��ȣ����Ұ��˳��ȶԿ���е����߽����и�ܹ��õ�ָ�����������ߡ�
*/
//����һ���ߣ�ÿ���ߵĳ���Ҳ���ˣ���Ҫȷ��һ������и����߳��ȣ����˳����и���ܴﵽָ���������ߡ�
//����էһ������˼·�����������ᵽ�˶��ַ��������ȼٶ�������߳�����һ����������̵����߳���+1���������ö��ַ�ȥ���ϱƽ����������󾫶�С��0.01�Ļ���Ȼû�п��н�
//��ô������˳�����0�����ڶ��ַ���ʹ���Ǳ����һ����ɫ֮����ͬʱ���ó��������ΪС�������λ���ص㣬�Ƚ��г�100����֮����ַ������ó����Ž⣡��
//���������˼ά�ԣ��Ƕ��ַ���һ���ܺõ�Ӧ�ã�Ҫ����˽⣡
#include<iostream>
#include<iomanip>
using namespace std;
int N,K;
int a[10000];
int low,high,mid;
int num;
double b;
int main(){
    cin>>N>>K;
    high=0;
    for(int i=0;i<N;i++){
        cin>>b;
        a[i]=b*100;
        if(high<a[i]) high=a[i];
    }
    high+=1;
    low=0;
    while(low<high-1){
        num=0;
        mid=(low+high)/2;
        if(mid==0) break;
        for(int i=0;i<N;i++){
            num+=a[i]/mid;
        }
        if(num>=K)  low=mid;
        else high=mid;
    }
    if(mid==0) cout<<fixed<<setprecision(2)<<0<<endl;
    else cout<<fixed<<setprecision(2)<<double(low)/100.0<<endl;
    return 0;
}
