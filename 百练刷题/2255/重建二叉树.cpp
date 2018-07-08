/*
    ����һ�ö�������ǰ���������������Ľ����������������
*/
//�������ı���һ�����һ������·�������ؽ��������ѵ����ڽ�������ν�����һ���ȽϾ������Ŀ��Ҫϸϸ�ж�����
#include<iostream>
#include<cstring>
using namespace std;
struct Node{
    Node*lchild;
    Node*rchild;
    char c;
};
Node node[50];
int loc;
char str1[30],str2[30];

Node*creat(){ //�½����
    node[loc].lchild=node[loc].rchild=NULL; //��ʼ���������Ҷ���Ϊ��
    return &node[loc++]; //����ָ��
}

void postOrder(Node*T){ //��������Ĳ���
    if(T->lchild!=NULL) postOrder(T->lchild);
    if(T->rchild!=NULL) postOrder(T->rchild);
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
    //��������û�н���
    if(root!=s2) ret->lchild=build(s1+1,s1+root-s2,s2,root-1); //s1+1~s1+root-s2Ϊǰ����������������;s2Ϊ������������,root-1Ϊ��������
    //����ұ���û���н���
    if(root!=e2) ret->rchild=build(s1+root-s2+1,e1,root+1,e2);
    return ret;
}

int main(){
    while(cin>>str1){
        if(strcmp(str1,"EOF")==0) break; //strcmp()�����ַ����ıȶԣ�����ȶԳɹ�����0
        cin>>str2;
        loc=0;
        int L1=strlen(str1);
        int L2=strlen(str2);
        Node*T=build(0,L1-1,0,L2-1);
        postOrder(T);
        cout<<endl;
    }
    return 0;
}
