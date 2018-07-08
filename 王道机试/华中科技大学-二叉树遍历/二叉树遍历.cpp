/*
    �����ַ������䳤��n��С�ڵ���26����һ��Ϊǰ��������ڶ���Ϊ����������������еĽ�������Դ�д��ĸ��ʾ��A��B��C....���26����㡣
    ���һ�У�Ϊ����������ַ�����
*/
//���������ǵ��͵Ķ������������⣬�ѶȲ��Ǻܴ󣬵���Ҫ��֪���̡���·��������Ҫ����Ķ������̣���
#include<iostream>
#include<cstring>
using  namespace std;
char str1[30],str2[30];
struct Node{
    Node*lchild;//����
    Node*rchild;//�Һ���
    char c;//�ַ�
};
Node node[50];
int loc;
Node*creat(){
    node[loc].lchild=node[loc].rchild=NULL;
    return &node[loc];
}
void postOrder(Node*T){ //����������ĳ��淽�̣�һ��Ҫ�μǣ�
    if(T->lchild!=NULL){ //�ݹ����������
        postOrder(T->lchild);
    }
    if(T->rchild!=NULL){ //�ݹ����������
        postOrder(T->rchild);
    }
    cout<<T->c;
}
Node*build(int s1,int e1,int s2,int e2){
    Node*ret=creat();
    ret->c=str1[s1];
    int root;
    for(int i=s2;i<=e2;i++){
        if(str2[i]==str1[s1]){
            root=i;
            break;
        }
    }
    //��������û�н���r
    if(root!=s2) ret->lchild=build(s1+1,s1+root-s2,s2,root-1); //s1+1~s1+root-s2Ϊǰ����������������;s2Ϊ������������,root-1Ϊ��������
    //����ұ���û�н���
    if(root!=e2) ret->rchild=build(s1+root-s2+1,e1,root+1,e2);
    return ret;
}
int main(){
    while(cin>>str1>>str2){
        loc=0;
        int L1=strlen(str1);
        int L2=strlen(str2);
        Node*T=build(0,L1-1,0,L2-1);
        postOrder(T);
        cout<<endl;
    }
    return 0;
}
