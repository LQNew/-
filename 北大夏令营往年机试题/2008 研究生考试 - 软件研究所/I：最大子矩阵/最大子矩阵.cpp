//��֪����Ĵ�С����Ϊ����������Ԫ�صĺ͡�����һ����������������ҵ����ķǿ�(��С������1 * 1)�Ӿ���
//������������էһ���޴����֣�������ϸ�����������Ϊ�˵������������������к͵ı������⣬��Ϊ�����Ƕ�ά�ģ�����������ѹ���ķ�ʽ��ÿ��ѡ��i,j��
//Ȼ������ӵ�i�е���j�������е���ֵѹ��Ϊһά��ʽ������˶ε�������������кͣ���Ϊ����i�е���j�е�������~
//ö�ٳ����е�i��j������ȶԾͿ��Եõ����յ�����Ӿ���
#include<iostream>
#include<cstring>
using namespace std;
int matrix[101][101];
int a[101];
int N;

int calculate_1(){ //����������������к͵�ģ��
    int local_sum=a[1];
    int b=0;
    for(int i=1;i<=N;i++){
        if(b>0) b+=a[i];
        else b=a[i];
        if(b>local_sum) local_sum=b;
    }
    return local_sum;
}
int main(){
    cin>>N;
    int max1=0;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++) cin>>matrix[i][j];
    }
    for(int i=1;i<=N;i++){
        memset(a,0,sizeof(a));
        for(int j=i;j<=N;j++){
            for(int k=1;k<=N;k++) a[k]+=matrix[j][k];//�������i�е�j��֮���ÿһ�е���ֵ֮�ͣ�ѹ����һά
            max1=max(max1,calculate_1());
        }
    }
    cout<<max1<<endl;
    return 0;
}
