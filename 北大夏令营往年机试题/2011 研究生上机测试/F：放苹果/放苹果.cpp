//�ݹ����⣬Ҫ��ϸ���Ƶ�������
//����8��������� 000��
#include<iostream>
using namespace std;
int t;
int M,N;

int f(int M,int N){
    if(M==0||N==1||M==1) return 1;
    else if(M<N) return f(M,M); //��M<Nʱ�������Ͼ��ǽ�M����Ͷ��M�����ӣ������п�
    else return f(M,N-1)+f(M-N,N); //����ĵ�˼·�����Ǵӵݹ������ҪôN-1�����ӷ�M���������пգ���ôһ����N���������涼����
}

int main(){
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>M>>N;
        cout<<f(M,N)<<endl;
    }
    return 0;
}
