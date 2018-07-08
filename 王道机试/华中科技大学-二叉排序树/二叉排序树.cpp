/*
    ����һϵ������������������������������ǰ�����򣬺��������
*/
//���������ڱ�������д�Ѿ�����Ϥ�ˣ��ǳ�ģ������ͣ����Ƕ����������Ľ�������֮ǰ�Ķ�������������Ϊ��һ����Ҳ����Ҫע��ģ�
#include<iostream>
#include<cstring>
using  namespace std;
int num[101];
int n;
int flag;
struct Node{
    Node*lchild;//����
    Node*rchild;//�Һ���
    int data;//����
};
Node node[100];
int loc;
Node*creat(){
    node[loc].lchild=node[loc].rchild=NULL;
    return &node[loc++];
}
void postOrder(Node*T){ //����������ĳ��淽�̣�һ��Ҫ�μǣ�
    if(T->lchild!=NULL){ //�ݹ����������
        postOrder(T->lchild);
    }
    if(T->rchild!=NULL){ //�ݹ����������
        postOrder(T->rchild);
    }
    cout<<T->data<<' ';
}
void inOrder(Node*T){ //����������ĳ��淽�̣�һ��Ҫ�μǣ�
    if(T->lchild!=NULL){ //�ݹ����������
        inOrder(T->lchild);
    }
    cout<<T->data<<' ';
    if(T->rchild!=NULL){ //�ݹ����������
        inOrder(T->rchild);
    }
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
    return T;
}
int main(){
    while(cin>>n){
        Node*T=NULL;
        for(int i=0;i<n;i++)
            cin>>num[i];
        for(int i=0;i<n;i++) //������
            T=insert_1(T,num[i]);
        loc=0;
        preOrder(T);
        cout<<endl;
        inOrder(T);
        cout<<endl;
        postOrder(T);
        cout<<endl;
    }
    return 0;
}
