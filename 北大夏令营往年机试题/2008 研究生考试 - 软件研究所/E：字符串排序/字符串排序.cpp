//��Ŀ�ѶȲ��󣬵��ǹ��� cin�� gets()��������ʱ��Ҫע�� ���һ��getchar()����ȥ�������ַ�~
#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;
int n;
char str2[101];
struct Node{
    char str1[101];
    int length;
};
Node node[1000];

int compare(const void* a, const void* b){
    Node* p1;
    Node* p2;
    p1=(Node*)a;
    p2=(Node*)b;
    return (*p1).length-(*p2).length;
}
int main(){
    while(cin>>n){
        getchar();//ȥ��������ַ�
        int i;
        for(i=0;i<n;i++){
            gets(str2);
            if(strcmp(str2,"stop")==0) break;
            memcpy(node[i].str1,str2,sizeof(str2));
            node[i].length=strlen(str2);
        }
        qsort(node,i,sizeof(Node),compare);
        for(int j=0;j<i;j++) cout<<node[j].str1<<endl;
    }
    return 0;
}
