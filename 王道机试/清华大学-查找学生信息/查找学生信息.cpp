#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int N,M;
char No[100];

struct Node
{
    char No[100];
    char name[100];
    char sex[10];
    int age;
};
Node node[1000];

int compare(const void*a,const void*b)
{
    Node*p;
    Node*p1;
    p=(Node*)a;
    p1=(Node*)b;
    return strcmp((*p).No,(*p1).No); //����ѧ������
}

int main()
{
    cin>>N;
    for(int i=0;i<N;i++)
    {
        cin>>node[i].No>>node[i].name>>node[i].sex>>node[i].age;
    }
    qsort(node,N,sizeof(Node),compare);
    cin>>M;
    for(int i=0;i<M;i++)
    {
        cin>>No;
        if(bsearch(&No,node,N,sizeof(Node),compare))//Noδ��ѯ��Ԫ�أ�������������ʽ~
        {
             Node*p=(Node*)bsearch(&No,node,N,sizeof(Node),compare); //��ȡ��Ӧ�Ľṹ��Ԫ��
             cout<<(*p).No<<" "<<(*p).name<<" "<<(*p).sex<<" "<<(*p).age<<endl;
        }
        else
            cout<<"No Answer!"<<endl;
        }
    return 0;
}
