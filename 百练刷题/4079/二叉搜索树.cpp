/*
    �����������Ĺ��죬�ǵ�����·�⣬Ҫ�����Ŀ�ô��ĸ���·�����ȥ��~
*/
#include<iostream>
using namespace std;
struct Node{
    Node*lchild;
    Node*rchild;
    int data;
};
Node node[1000];
int num[1000];
int loc;

Node* creat(){
    node[loc].lchild=node[loc].rchild=NULL;
    return &node[loc++];//����ָ��ṹ���ָ��
}

void preOrder(Node*T){ //ǰ��������ĳ��淽�̣�һ��Ҫ�μǣ�
    cout<<T->data<<' ';
    if(T->lchild!=NULL){ //�ݹ����������
        preOrder(T->lchild);
    }
    if(T->rchild!=NULL){ //�ݹ����������
        preOrder(T->rchild);
    }
}

Node*insert_1(Node*T,int x){ //�������Ľ�������¼�˽ڵ��Լ�Ȩֵ�������ķ�ʽ����·��һ��Ҫ��Ϥ��
    if(T==NULL){
        T=creat();
        T->data=x;
        return T;
    }
    else if(x<T->data){
        T->lchild=insert_1(T->lchild,x);
    }
    else if(x>T->data){
        T->rchild=insert_1(T->rchild,x);
    }
    return T; //ÿ�ζ����ص��ʼ�ĸ��ڵ�
}

int main(){
    int i=0;
    loc=0;
    Node*T=NULL;
    while(cin>>num[i]) T=insert_1(T,num[i]);
    preOrder(T);
    cout<<endl;
    return 0;
}
