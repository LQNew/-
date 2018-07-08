/*
    �������µ���������ַ����� ABC##DE#G##F### ���С�#����ʾ���ǿո񣬿ո��ַ����������������˶������Ժ��ٶԶ������������������������������
*/
//���������ǵ��͵Ķ������������⣬�ѶȲ��Ǻܴ󣬵���Ҫ��֪���̡���·��������Ҫ����Ķ������̣���ͬʱҪ�����Ŀ��˼~
#include<iostream>
#include<cstring>
using  namespace std;
int s1,e1;
char str1[100];
struct Node{
    Node*lchild;//����
    Node*rchild;//�Һ���
    char c;//�ַ�
};
Node node[100];
int loc;
Node*creat(){
    node[loc].lchild=node[loc].rchild=NULL;
    return &node[loc++];
}
void inOrder(Node*T){ //����������ĳ��淽�̣�һ��Ҫ�μǣ�
    if(T->lchild!=NULL){ //�ݹ����������
        inOrder(T->lchild);
    }
    cout<<T->c<<' ';
    if(T->rchild!=NULL){ //�ݹ����������
        inOrder(T->rchild);
    }
}
Node*build(){ //���ո������ҵı�����ʽ�����õ������ڵݹ����д���Ƚϲ�����ᣬһ��Ҫ���Ķ������������ԭ����

    if((s1<=e1&&str1[s1]=='#')||s1>e1){
        s1++;
        return NULL;
    }
    Node*ret=creat();
    ret->c=str1[s1];
    s1++;
    ret->lchild=build();
    ret->rchild=build();
    return ret;
}
int main(){
    while(cin>>str1){
        loc=0;
        s1=0;
        e1=strlen(str1);
        Node*T=build();
        inOrder(T);
        cout<<endl;
    }
    return 0;
}
