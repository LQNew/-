//���⣺n+1����Ȼ��������m��ȷ���ģ�����n������������m,�ж����ַ���ʹ�� a1*x1+a2*x2+...+an*xn+M*xn+1 = 1 �н⣬
//����gcd (a1, a2, ..., an, M) = 1����������M���������ӷֽ⣬Ȼ���ų������ӷ�1���������

/*������
�������۵�֪ʶ��n���������Լ���涨Ϊ��n�������Ժ͵���С��Ȼ�������Դ������Ҫ�����Լ��Ϊ1�����еĸ������������£�
1�����m��������Լ����������k�������n + 1���������Լ������1��m���ٺ���һ����Լ���������Լ��Ҳ��ǰn������Լ��
2�����е��ܸ���Ϊ m ^ n;
3����t(n)��ʾ �ܹ���������n��m����Լ����<=m�����ĸ���
�����ݳ�ԭ���֪��Լ����Ϊ1�����еĸ���Ϊ f = t(1) - t(2) + t(3) - ... + (-1) ^ (k - 1) t(k) (�ݳ�ԭ�����ż��)
4) ����Ҫ������и���Ϊ m ^ n - f
*/

#include<iostream>
using namespace std;
typedef long long ll; //����M^n����Ϊ��������M����Ϊ�ϴ�ֵ������Ҫ���峤������������Ϊ���ֽ�
int M; //��Ƭ�������M
int N; //��Ƭ�����ǰ��N����ֵ<=M�Ŀ�Ƭ
int factor[65]; //���ڴ洢�ֽ����������
int factor_for_dfs[65]; //������dfs�����д洢������
int total_cnt; //���ڼ�¼Mһ���ж��ٸ�������
ll part_num;//���ڼ�����num����ͬ������ʱ�������
ll f; //���ڼ��� f = t(1) - t(2) + t(3) - ... + (-1) ^ (k - 1) t(k)

void Divide(int M) //����õ�M���е�������
{
    total_cnt=0; //���ڼ�¼
    for(int i=2;i*i<=M;i++)
    {
        if(M%i==0)
            factor[total_cnt++]=i;
        while(M%i==0)
            M=M/i;
    }
    if (M>1) factor[total_cnt++]=M;
    //���ʣ�µĳ�������һ����Ϊ>1��������ô���������һ���������� i.e: 30=2*3*5 ,����δ�������һ����֮ǰ��i^2�϶���С�ڵ�ǰM��ֻ�п��ܳ������һ������ʱi^2>��ǰM
}

ll Power(int a,int b) //��� a^b��ֵ
{
    ll res = 1;
    while (b--) res *= a;
    return res;
}

void dfs(int pos ,int cnt , int num)  //����������������� M����ǰn����һ��n+1��������num����ͬ������ �������
{
    int x;
    if(cnt == num)
    {
        x=M;
        for(int i=0;i<num;i++)
            x=x/factor_for_dfs[i];
        part_num+=Power(x,N);
    }
    else //dfs �ݹ�˼���벻��...
    {
        for(int i=pos;i<total_cnt;i++)
        {
            factor_for_dfs[cnt]=factor[i];
            dfs(i+1,cnt+1,num);
        }
    }

}

int main()
{
    while(cin>>N>>M)
    {
        Divide(M);
        f=Power(M,N); //���� M^N
        for(int i=1;i<=total_cnt;i++) //���� M^N-t(1)+t(2)-t(3)+.....
        {
            part_num=0;
            dfs(0,0,i);
            if(i%2==0)
                f+=part_num;
            else
                f-=part_num;

        }
        cout<<f<<endl;
    }
    return 0;

}
