/*
    N�����У���Ŵ�0��N-1��M����·����K����·��K��0��ʼ���ĳ���Ϊ2^K������Ϊ0�ĳ��е��������е���̾��룬N(2<=N<=100);M(M<=500)
*/
//�������������ǵ��͵����·�����⣬����Ϊ��2��N�η����ڣ�����Ҫô�ô������㣬���������������˼·��û�г��������...
//�ʶ���������С���������㷨��������֪2^n>��2^k�����Կ���֪�� �����µ�·������������ڵ����һ�������£���ô��������֮���·�����ȿ϶��б�����µ�·��С�Ĵ���
//������������ͬһ���ϵĶ˵㣬˵�������������ڵĵ㣬����֮ǰ�˴�û��·�����ӣ���ô��ʱ���������µĵ�֮��ľ���һ��������̾��룬������Ҫ�����������ϣ�
//�����б˴˶��߹����ĵ�����·��~
//������˼·���ѣ�����ͼ�۵Ŀ���Ҳ�ǱȽ����룬һ��Ҫ������ͼ����֢��ҩ����
#include<iostream>
using namespace std;
int store[500];
int Tree[100];
int value;
int N,M;
int x,y,a,b;
long long ans[100][100]; //��ά����,���ʼֵ��Ϊ��ͼ���ڽӾ���
int find_Root(int x)
{
    if(Tree[x]==-1) return x;
    else
    {
        int tmp=find_Root(Tree[x]);
        Tree[x]=tmp;
        return tmp;
    }
}
int main()
{
    value=1;
    store[0]=1;
    for(int i=1;i<500;i++) //��2��500�η���ֵ�ĺ���λ��һά����洢����~
    {
        value*=2;
        value%=100000;
        store[i]=value;
    }
    while(cin>>N>>M)
    {
        for(int i=0;i<N;i++){ //��ʼ����һ��ʼ���е�·����ʼ��Ϊ-1��ͬһ�ڵ㴦�ľ����ʼ��Ϊ-1
            Tree[i]=-1;
            for(int j=0;j<N;j++){
                ans[i][j]=-1;
            }
            ans[i][i]=0;
        }

        for(int i=0;i<M;i++) //����ͼ���ٽӾ���
        {
            cin>>a>>b;
            x=find_Root(a);
            y=find_Root(b);
            if(x==y) continue;
            //�˴�˼·Ҫϸϸ��⣡��
            for(int initial=0;initial<N;initial++) //���������ڵĵ�֮�����˴˵ľ���~
            {
                if(x==find_Root(initial))
                {
                    for(int ending =0;ending<N;ending++)
                    {
                        if(y==find_Root(ending))
                        {
                            ans[ending][initial]=ans[initial][a]+ans[ending][b]+store[i];
                            ans[initial][ending]=ans[ending][initial];
                        }
                    }
                }
            }
            Tree[y]=x;
        }

        for(int j=1;j<N;j++)
            cout<<ans[0][j]%100000<<endl;
    }
    return 0;
}
