//��������˺ܶ��֦������ȥ�������Ҷ����ѶȽϴ󣬲�����⣬֮������ʱ������ٷ����ж�����
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int N,L;
int total_length;
int lastStickNo;
int sticks[65];
int used[65];

int compare(const void*a,const void*b){
    return *(int*)b - *(int*)a ;
}

bool Dfs(int num,int remain_length,int length){ //length��ʾҪƴ��Ŀ��ľ���ĳ��ȣ�remain_length��ʾ��ǰ����ƴ�Ĺ��Ӻ�length��Ȼ�ȱ�ĳ���
    if(num==0&&remain_length==0) return true;
    if(remain_length==0) remain_length=length; //һ���ո�ƴ�꣬��ʼ�µ�һ��
    int startStickNo=0;
    if(remain_length!=length) startStickNo=lastStickNo+1;
    for(int i=startStickNo;i<N;i++){
        if(!used[i]&& sticks[i]<=remain_length){
            if(i>0){
                if(used[i-1]==0&&sticks[i-1]==sticks[i]) continue;
            }
            used[i]=1;
            lastStickNo=i;
            if(Dfs(num-1,remain_length-sticks[i],length)) return true;
            else{
                used[i]=0;
                if(sticks[i]==remain_length||remain_length==length) return false;
            }
        }
    }
    return false;
}

int main()
{
    while(1)
    {
        cin>>N;
        if(N==0)
            break;
        total_length=0;
        for(int i=0;i<N;i++)
        {
            cin>>sticks[i];
            total_length+=sticks[i];
        }
        qsort(sticks,N,sizeof(sticks[0]),compare); //�������ľ���Ӵ�С����
        for(L=sticks[0];L<=total_length/2;L++)
        {
            if(total_length%L) //���ľ������һ�����ܳ��ȵ����ӣ���ȡ��Ӧ��Ϊ0~
                continue;
            memset(used,0,sizeof(used[0])*N);
            lastStickNo=-1;
            if(Dfs(N,L,L))
            {
                cout<<L<<endl;
                break;
            }
        }
        if(L>total_length/2) cout<<total_length<<endl;
    }
    return 0;
}
