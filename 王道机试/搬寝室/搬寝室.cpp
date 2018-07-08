//���������ҵ�Ҫ�󣬱����Ķ��鷽�̲����ر��������������Ҫ�ǻ������㣺
//1.ѡ�������ŷ����У���ѡ������ϣ�����������Ϊ���������Ʒ�������δ���ƷΪһ�ԡ�������С��Ʒ��������С��ƷΪһ�ԣ������ڽ�����ϵ����
//2.����ÿ����ϣ���Ա�����������������Ʒ��ԣ��������ڽ������û������
//�������϶������ȥ����ݹ鷽�̣�����ѡ��һ����Ԫ������ȥ��ʾ�ݹ��״̬������dp[i][j]�����ú���Ҳ������˼��ָǰj����Ʒ��ѡ��i����Ʒʱ��С��ƣ�Ͷ�
//���j=2*i,��ôj��j-1������ԣ������ j>2*i����ô����ʹ���ˣ�dp[i][j]=dp[i][j-1]
//�����ϣ����鷽��Ϊ dp[i][j]=min{dp[i][j-1],dp[i-1][j-2]+(weight[j]-weight[j-1])^2

#include<iostream>
using namespace std;
const int Max=2000;
int dp[Max/2][Max]; //dp[i][j]��ʾ��ǰj����Ʒ��ѡ��i����Ʒʱ��С��ƣ�Ͷ�
int n,k;
int weight[Max];//��¼ÿ�����������

int compare(const void *a,const void* b ){
    return *(int*)a - *(int*)b;
}

int main(){
    while(cin>>n>>k){
        for(int j=1;j<=n;j++) dp[0][j]=0;
        for(int i=1;i<=n;i++) cin>>weight[i];
        qsort(&weight[1],n,sizeof(weight[0]),compare);
        //����״̬����
        for(int i=1;i<=k;i++){
            for(int j=2*i;j<=n;j++){
                if(j>2*i) dp[i][j]=dp[i][j-1];
                else{
                    dp[i][j]=dp[i-1][j-2]+(weight[j-1]-weight[j])*(weight[j-1]-weight[j]);
                }
            }
        }
        cout<<dp[k][n];
    }
    return 0;
}
