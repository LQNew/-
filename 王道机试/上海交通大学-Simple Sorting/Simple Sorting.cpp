//ȥ���ظ��ĸ�������������ͣ�������ٱ���һ�飬���Ӷ�Ϊ n*log(n)+n��С�ڰ���
//�˴��Ƚ϶��ĵĵط������һ����������пո񣬺ܶ��ĵĵط�����Ϊ��ר�ſ���һ������ȥ�洢�Ա�֤��ͨ����û������
#include<iostream>
using namespace std;
int N;
int num[1000];
int store[1000];
int before,now;

int compare(const void*a,const void*b)
{
    return *(int*)a-*(int*)b;
}

int main()
{
    while(cin>>N)
    {
        for(int i=0;i<N;i++)
        {
            cin>>num[i];
        }
        qsort(num,N,sizeof(num[0]),compare);
        int cnt=0;
        before=num[0];
        store[cnt++]=before;
        for(int i=1;i<N;i++)
        {
            now=num[i];
            if(before==now)
                continue;
            else
            {
                store[cnt++]=now;
                before=now;
            }
        }
        for(int i=0;i<cnt-1;i++)
            cout<<store[i]<<" ";
        cout<<store[cnt-1]<<endl;
    }
    return 0;
}
