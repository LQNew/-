//ģ��������������Ĺ��̣��ÿ������������⣡
#include<iostream>
#include<cstring>
using namespace std;
int n;
int node[1000];
int weight;

int compare(const void*a,const void*b) //����qsort ʹ�õ�compare�������йش�compare��������дӦ���⣡
{
    return *(int*)b-*(int*)a;
}
int main(){
    while(cin>>n){
        memset(node,0,sizeof(int)*n);
        for(int i=0;i<n;i++){
            cin>>weight;
            node[i]=weight;
        }
        int ans=0;
        while(n>1){
            qsort(node,n,sizeof(int),compare); //��������п�������
            n--;
            node[n-1]=node[n]+node[n-1]; //��ÿ�εõ������µ�ֵ��������β�����ٽ��п������򣬲���¼�·�Ҷ�ڵ��Ȩֵ
            cout<<node[n-1]<<endl;
            ans+=node[n-1];
        }
        cout<<ans<<endl;
    }
    return 0;
}
