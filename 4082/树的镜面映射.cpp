//�������ľ���ӳ��ͬʱ֮���п��ѣ��ѶȺܴ󣬱������ǽ�����ϵ������ǿд�����ĳ���...
//֮����Լ�ǿ����ȥˢ~
#include<iostream>
#include<stack>
#include<queue>
using namespace std;

struct Node{
    Node* lchild;
    Node* rchild;
    char c;
};
Node node[1000];
char tmp[1000][3];
int loc,cnt,mark;

Node* creat(){ //�½����
    node[loc].lchild=node[loc].rchild=NULL; //��ʼ���������Ҷ���Ϊ��
    return &node[loc++]; //����ָ��
}

Node* build(){//����ǰ������ �������
    //cout<<mark<<' '<<tmp[mark]<<endl;
    Node* ret=creat();
    ret->c=tmp[mark][0];
    mark++;
    if(tmp[mark-1][1]=='0'){ //�����0��β��˵����Ҷ�ڵ㣬��ô���������Һ���
        ret->lchild=build();
        ret->rchild=build();
    }
    return ret;
}

void PreOrder(Node* T){
    cout<<T->c<<' ';
    if(T->lchild!=NULL) PreOrder(T->lchild);
    if(T->rchild!=NULL) PreOrder(T->rchild);
}

void Print(Node* p){ //��������ľ���ת
    stack<Node*> s;
    queue<Node*> Q;
    while(p != NULL){   //�˴��ǹؼ������ݡ��������ֵܡ����ص㣬һֱ���ұ���������ͬһ��Ľ�㶼����ջ��
        if(p->c!= '$') s.push(p);
        p = p->rchild;
    }
    while(!s.empty()){  //��ջ�ڵĽ�����ε�����ѹ����У���ɾ���ת�Ĺ���
        Q.push(s.top());
        s.pop();
    }
    while(!Q.empty()){
        p = Q.front();
        Q.pop();
        cout<<p->c<<' ';
        if(p->lchild != NULL){
            p = p->lchild;
            while(p!= NULL){   //ͬ�������Ǵ�����ڵ�ģ���Ϊ��ʱ���л�Ϊ�գ������Ǵ���ʣ�µ�ȫ�����
                if(p->c!= '$') s.push(p);
                p = p->rchild;
            }
            while(!s.empty()){
                Q.push(s.top());
                s.pop();
            }
        }
    }
}

int main(){
    while(cin>>cnt){
        for(int i=0;i<cnt;i++) cin>>tmp[i];
        loc=0;
        mark=0;
        //cout<<tmp[7];
        Node*root=build();
        //PreOrder(root);
        Print(root);
        cout<<endl;
    }
    return 0;
}
