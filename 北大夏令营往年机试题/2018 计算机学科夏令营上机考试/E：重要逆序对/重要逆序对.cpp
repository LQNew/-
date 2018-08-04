//������������Ļ�������΢���˵��б����Σ���Ϊָ�����Ӳ���������Ӱ�쵽�ܵ�ʱ�临�Ӷȣ���������nlog(n)�ĸ��Ӷ�
#include<iostream>
using namespace std;
int a[200000];//��ʼ��������Ԫ�ظ������Ϊ20000
int N;
long long cnt;
void Merge_pass(int *A,int *L,int left_count,int *R,int right_count){
    int i,j,k,pointer;
    i=0;j=0;k=0;pointer=0;
    while(i<left_count && j<right_count){
        if(L[i]<=R[j]) A[k++]=L[i++];
        else{
            while((long)L[pointer]<=(long)2*R[j] && pointer<left_count){
                pointer++;
            }
            if(pointer<left_count) cnt+=(left_count-pointer);
            A[k++]=R[j++];
        }
    }
    while(i<left_count) A[k++]=L[i++];
    while(j<right_count) A[k++]=R[j++];
}

void Merge_sort(int *A, int cnt){
    int mid=cnt/2;
    if(mid==0) return;
    int *L=new int[mid];
    int *R=new int[cnt-mid];
    for(int i=0;i<mid;i++) L[i]=A[i];
    for(int j=mid;j<cnt;j++) R[j-mid]=A[j];
    Merge_sort(L, mid);
    Merge_sort(R, cnt-mid);
    Merge_pass(A,L,mid,R,cnt-mid);
    delete[]R;
    delete[]L;
}

int main(){
    cin>>N;
    if(N<=0) cout<<0<<endl;
    else{
        cnt=0;
        for(int i=0;i<N;i++) cin>>a[i];
        Merge_sort(a,N);
        /*
        for(int i=0;i<N;i++) cout<<a[i]<<' '; //��ӡ���ź��������Ԫ��
        cout<<endl;
        */
        cout<<cnt<<endl;
    }
    return 0;
}
