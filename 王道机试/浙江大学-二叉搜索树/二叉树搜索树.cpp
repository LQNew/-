/*
    ��ʼһ����n��(1<=n<=20) ��ʾ��n����Ҫ�жϣ�n= 0 ��ʱ�����������
    ����ȥһ����һ�����У����г���С��10������(0~9)�����֣�û���ظ����֣�����������п��Թ����һ�Ŷ�����������
    ����ȥ��n����n�����У�ÿ�����и�ʽ����һ������һ�������ж������������Ƿ������ͬһ�Ŷ�����������
*/
//������������Ҫ������Ƕ���������ָ���� ���������������ڶ������ı���ֻҪ����+����һ�����б����������������һ�¿���˵���˶�������һ����ͬ��
//�������ѵ�������δ洢״̬���˴��Ҳ�������洢���������εĽ�������ڵ�ÿ�ζ�����գ���Ҫ�洢���Ǳ�����Ľ����
//�������õ���һЩ�ַ����ȶԺ�������strcmp()�����ַ����ıȶԣ�strlen()���ڼ����ַ����ĳ��ȣ�memset()�����ַ����ĳ�ʼ����memcpy()�����ַ����ĸ���
//��Щ���õĺ���һ��Ҫ��Ϥ���������ʱ����ķ�ʱ��...
#include<iostream>
#include<cstring>
using  namespace std;
char num[20];
char str1[30],str2[30];
int n;
struct Node{
    Node*lchild;//����
    Node*rchild;//�Һ���
    char data;//����
};
Node node[20];
int loc;
int loc_target;
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
    str1[loc_target++]=T->data; //�洢�ַ�ֵ
    //cout<<T->data<<' ';
}
void inOrder(Node*T){ //����������ĳ��淽�̣�һ��Ҫ�μǣ�
    if(T->lchild!=NULL){ //�ݹ����������
        inOrder(T->lchild);
    }
    str1[loc_target++]=T->data;
    //cout<<T->data<<' ';
    if(T->rchild!=NULL){ //�ݹ����������
        inOrder(T->rchild);
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
        memset(str2,0,sizeof(char)*20);
        if(n==0) break;
        cin>>num;
        Node*T=NULL;
        loc=0;
        for(int i=0;i<strlen(num);i++) //������
            T=insert_1(T,num[i]);
        loc_target=0;
        postOrder(T);
        inOrder(T);
        memcpy(str2,str1,sizeof(char)*2*strlen(num));//����õı���������Ƶ�str2�У�֮����str1�ٻ�ȡ��ı����������str2�ȶ�
        str2[2*strlen(num)]='\0';//�˴��ַ����Ľ�β���Ͻ�����������Ҫ��һ�㣡��
        for(int i=0;i<n;i++)
        {
            for(int i=0;i<15;i++)
                node[i].lchild=node[i].rchild=NULL;
            cin>>num;
            memset(str1,0,sizeof(char)*2*strlen(num));
            Node*T=NULL;
            loc=0;
            for(int i=0;i<strlen(num);i++) //������
                T=insert_1(T,num[i]);
            loc_target=0;
            postOrder(T);
            inOrder(T);
            str1[2*strlen(num)]='\0';
            if(strcmp(str1,str2)==0)
                cout<<"YES"<<endl;
            else
                cout<<"NO"<<endl;
        }
    }
    return 0;
}
