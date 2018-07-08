//һ��ʼ�������ѧ��˼·ȥ��������⣬����˼·�в�ͨ����
//�������poj �ϵ� Push Botton Lock����Ŀ�����ǣ����� n����ͬ����Ͷ��m����ͬ�ĺ�����ͬʱÿ���������ٺ���K����
//�� poj �ϵ� Push Botton Lock �� n����ͬ����Ͷ��m����ͬ�ĺ�����ͬʱÿ���������ٺ���1����
//����� poj �ϵ� Push Botton Lock ��Ŀ�ǵ��͵ĵڶ���˹���������󷨣�����������Щ��Ľ�����ʵ����ֻ�� (N,M,K)�ض�����µķ����� ������ȽϾ��䣬�������ж���⣡
//f[i][j]=sum(f[i-k][j-1]*c[n-(i-k)][k])-- k: K-i
#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
int M,N,K;
long long c[16][16],f[16][16]; //f[i][j]��ʾ ��i�������j�����ӵķ�����
int main(){
    c[0][0]=1;
    for(int i=1; i<=15; i++)
    {
        c[i][0]=c[i][i]=1;//������ĳ�ʼ��
        for(int j=1; j<i; j++) c[i][j]=c[i-1][j-1]+c[i-1][j]; //�ݹ���������
    }
    while(cin>>N>>M>>K){
        if(N==0&&M==0&&K==0) break;
        memset(f,0,sizeof(f)); //��״̬��ά�����ʼ��
        for(int i=K;i<=N;i++) f[i][1]=c[N][i];
        for(int i=K;i<=N;i++){
            for(int j=2;j<=M;j++){
                for(int t=K;t<=i;t++){
                    if(i-t>=0) f[i][j]+=f[i-t][j-1]*c[N-i+t][t];
                }
            }
        }
        cout<<f[N][M]<<endl;
    }
    return 0;
}
