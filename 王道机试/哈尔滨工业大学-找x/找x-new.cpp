#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int n;
char value[100];
char search_value[100];

struct Node
{

    char value[100];
    int sign;
};
Node node[200];

int compare(const void*a,const void*b)
{
    Node*p;
    Node*p1;
    p=(Node*)a;
    p1=(Node*)b;
    return strcmp((*p).value,(*p1).value); //����ѧ������
}

int main()
{
    while(cin>>n)
    {
        for(int i=0;i<n;i++)
        {
            cin>>node[i].value;
            node[i].sign=i;
        }
        cin>>search_value;
        qsort(node,n,sizeof(Node),compare);
        if(bsearch(&search_value,node,n,sizeof(Node),compare))//Noδ��ѯ��Ԫ�أ�������������ʽ~
        {
             Node*p=(Node*)bsearch(&search_value,node,n,sizeof(Node),compare); //��ȡ��Ӧ�Ľṹ��Ԫ��
             cout<<(*p).sign<<endl;
        }
        else
            cout<<-1<<endl;
    }
    return 0;
}
