//���鼯��Ŀ�е����⼶���ˣ��ܺõ���Ŀ���ѶȽϴ���Ҫ˼·ֻ�ж�������֪���Ӻδ����֣���
//�����˲��鼯�������ж��Ƿ���ڴ����Լ�������һ�����������б� �ڵ���Ը��ڵ�ĵȼ�
#include<iostream>
#include<cstring>
using namespace std;
int N,K;
int D,X,Y;
int cnt;
int Tree[50001];
int rank1[50001]; //��¼�ڵ��������ڵ��ƫ������������ֵ������0��ʾ�ڵ�͸��ڵ�ͬ�ࣻ1��ʾ���ڵ�Խڵ㣻2��ʾ�ڵ�Ը��ڵ�
int find_root(int x){
    if(Tree[x]==-1) return x;
    else{
        int tmp=find_root(Tree[x]);
        rank1[x]+=rank1[Tree[x]]; //���� x��ƫ���������Tree[x]��ƫ�Ƶ�����������ĸ��ڵ��ƫ��
        rank1[x]%=3;
        Tree[x]=tmp;
        return tmp;
    }
}
int main(){
    cin>>N>>K;
    memset(Tree,-1,sizeof(Tree));
    memset(rank1,0,sizeof(rank1));
    cnt=0;
    for(int i=0;i<K;i++){
        cin>>D>>X>>Y;
        if(X>N||Y>N){
            cnt++;
            continue;
        }
        int root1=find_root(X);
        int root2=find_root(Y);
        if(root1==root2){
            if(D==1 && rank1[X]!=rank1[Y]) cnt++;
            if(D==2 && (rank1[X]+1)%3!=rank1[Y]) cnt++;
        }
        else{ //X��Y���ڵ㲻һ����˵������֮ǰ������ϵ����ô��ϵ������ο϶��ǳ�����
            if(D==1){
                Tree[root2]=root1;
                rank1[root2]=rank1[X]-rank1[Y]; //�����Լ���ͼȥ������˼·����ΪX��Y�ȼ�һ�£���X���root1�ĵȼ�Ϊrank1[X]��
                //Y���root2�ĵȼ�Ϊrank1[Y]����Ϊroot2�ĸ��ڵ��Ϊ��root1����ôroot2���root1�ĵȼ�ӦΪ rank1[X]-rank1[Y] ����ʹ��֮��Y���root1�ĵȼ�ҲΪrank1[X]��
                rank1[root2]+=3;
                rank1[root2]%=3;
            }
            else{
                Tree[root2]=root1;
                rank1[root2]=rank1[X]-rank1[Y]+1; //ͬ����ķ���~
                rank1[root2]+=3;
                rank1[root2]%=3;
            }
        }
    }
    cout<<cnt<<endl;
    return 0;
}
