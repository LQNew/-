//�����Ĺ�˭���������ʼ��Ϊ-1�ͳ�ʼ��Ϊ0�и�ƨ���𣬵��ǳ�ʼ��Ϊ0����wa...
#include<iostream>
#include<cstring>
using namespace std;
int matrix[6001][6001];
int N;
int a,b;
int main(){
    memset(matrix,-1,sizeof(matrix));
    matrix[0][0]=0;
    int x1=0;
    int y1=0;
    int i;
    for( i=1;i<=11000;i++){
        x1+=1;
        y1+=1;
        if(x1>6000||y1>6000) break;
        matrix[x1][y1]=i;
        i++;
        x1+=1;
        y1-=1;
        if(x1>6000||y1>6000) break;
        matrix[x1][y1]=i;
        i++;
        x1+=1;
        y1+=1;
        if(x1>6000||y1>6000) break;
        matrix[x1][y1]=i;
        i++;
        x1-=1;
        y1+=1;
        if(x1>6000||y1>6000) break;
        matrix[x1][y1]=i;
    }
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>a>>b;
        if(matrix[a][b]==-1) cout<<"No Number"<<endl;
        else cout<<matrix[a][b]<<endl;
    }
    return 0;
}
