/*
    �� A �� B �����ѣ�B �� C �����ѣ���ô����Ҳ��Ϊ A �� C �����ѡ��ڸ����� N �����ѹ�ϵ��Ҫ�������ҳ�һ�����������ࣩ�ļ��ϣ��ü�
    ������������֮�䶼�����ѻ��߸ü�����ֻ��һ���ˣ���������������
*/
//���������ǲ��鼯���⣬ֻ������Ҫ��������鼯ÿ������Ӧ�Ľڵ���Ŀ���˴��ڹ������鼯ʱ���Զ���ÿ����ǰ�����ڵ��ۼ�����sumֵ��������һ���ײ����
//      ������ϴ���ֵ�ϲ������ʣ������ڵ�Ͷ�Ӧ�������ܽڵ���Ŀ
#include<iostream>
using namespace std;
int Tree[10000001];
int sum[10000001];
int A,B;
int pairs,ans;
int find_Root(int x) //�ҳ��ڵ�����Ƚڵ�
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
    while(cin>>pairs)
    {
        for(int i=1;i<10000001;i++)
        {
            Tree[i]=-1;
            sum[i]=1;
        }
        for(int i=0;i<pairs;i++)
        {
            cin>>A>>B;
            A=find_Root(A);
            B=find_Root(B);
            if(A!=B)
            {
                Tree[A]=B;
                sum[B]+=sum[A];//��ȡ�ڵ�����Ŀ
            }
        }
        ans=0;
        for(int i=1;i<10000001;i++)
        {
            if(Tree[i]==-1&&sum[i]>ans)
                ans=sum[i];
        }
        cout<<ans<<endl;
    }
    return 0;
}
