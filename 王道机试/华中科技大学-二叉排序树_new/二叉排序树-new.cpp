/*
    ���ڸ���N���ؼ���ֵ������ͬ�Ľڵ㣬Ҫ���㰴˳�����һ����ʼΪ�����Ķ����������У�ÿ�β����ɹ�������Ӧ�ĸ��׽ڵ�Ĺؼ���ֵ��
    ���û�и��׽ڵ㣬�����-1��
*/
//���ڶ����������Ľ������ո��Ѿ��ἰ�����Ǵ�ӡ���׽ڵ㣬��Ϊ���ǹ���ʱ��ȡ�����ݽṹֻ�����ӡ��Һ�����ʽ�����Դ�ӡ���׽ڵ㣬�˴��Ҳ�ȡ�˱Ƚϱ��ķ�����ֱ�ӱ�����...
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
Node*insert_1(Node*T,int x){ //���빹�����������
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
void print(int x,Node*T){ //�������Ҷ������ĸ��ڵ㣬����ӡȨֵ~
    if((T->lchild!=NULL&&T->lchild->data==x)||(T->rchild!=NULL&&T->rchild->data==x))
        cout<<T->data<<endl;
    if(T->lchild!=NULL&&x<T->lchild->data)
        print(x,T->lchild);
    else if(T->lchild!=NULL&&x>T->lchild->data&&x<T->data)
        print(x,T->lchild);
    else if(T->rchild!=NULL&&x<T->rchild->data&&x>T->data)
        print(x,T->rchild);
    else if(T->rchild!=NULL&&x>T->rchild->data)
        print(x,T->rchild);
}
int main(){
    while(cin>>n){
        Node*T=NULL;
        for(int i=0;i<n;i++)
            cin>>num[i];
        loc=0;
        for(int i=0;i<n;i++)
            T=insert_1(T,num[i]);
        cout<<-1<<endl;
        for(int i=1;i<n;i++)
            print(num[i],T);
    }
    return 0;
}
