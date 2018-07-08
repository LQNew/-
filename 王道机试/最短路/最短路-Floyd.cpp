//�������н��֮��˴˵ľ��룬����������ڵ�֮������·��
//����һ���������ԭʼ�����·���⣬��������Floyd�㷨ģ�����⣬��������һ��ģ�����һ��Ҫ��ס����
#include<iostream>
using namespace std;
int N,M;
int A,B,C;
int ans[101][101]; //��ά����,���ʼֵ��Ϊ��ͼ���ڽӾ���
int main()
{
    while(cin>>N>>M)
    {
        if(N==0&&M==0) break;
        for(int i=1;i<=N;i++)
        {
            for(int j=1;j<=N;j++)
                ans[i][j]=-1;
            ans[i][i]=0;
        }
        for(int i=0;i<M;i++) //����ͼ���ٽӾ���
        {
            cin>>A>>B>>C;
            ans[A][B]=ans[B][A]=C;
        }
        for(int k=1;k<=N;k++) //����Floyd�㷨��������н���˴˵����·��
        {
            for(int i=1;i<=N;i++)
            {
                for(int j=1;j<=N;j++)
                {
                    if(ans[i][k]==-1||ans[k][j]==-1||i==j||i==k||j==k) continue; //�����ǰ i,k����k,j֮�䲻����·������û�����壬���� i==j����ô����һ�������i==k����j==k��Щ���������������
                    if(ans[i][j]==-1||ans[i][k]+ans[k][j]<ans[i][j])
                        ans[i][j]=ans[i][k]+ans[k][j];
                }
            }
        }
        cout<<ans[1][N]<<endl;
    }
    return 0;
}
