//��һ�����Ǽ���������ݣ����ÿ������������������λ��������ӵ�һ���䵽�ڶ���������ʽ�ǣ�ÿ��ֻ�ܱ�ĳһλ�����֣�������ÿ�α�ɵ����ֱ���Ϊ������
//�������������ǵ��͵�BFS���⣬��һ��ʼ��˼·������ȷ�ģ�û����ʲô��·�����Ǿ���TL�����ǵó�һ��С���ۣ�����mark��ǣ�ֱ�ӱ�Ǹ�λ��״̬����ʣ�����û��TL����
#include<iostream>
#include<cstring>
#include<cmath>
#include<queue>
using namespace std;
bool prime[10000];
bool mark[10][10][10][10];
int cases;
int a,b;
struct Node{
    int value;
    int t;
};
queue<Node>Q;
int BFS(int b){
    while(!Q.empty()){
        Node new_1=Q.front();
        Q.pop();
        int nvalue=new_1.value;
        int nt=new_1.t;
        int nvalue_1;
        int n1=nvalue/1000;
        int n2=(nvalue%1000)/100;
        int n3=(nvalue%100)/10;
        int n4=nvalue%10;
        for(int i=1;i<10;i++){
            if((i+n2+n3+n4)%3==0) continue;
            if(i!=n1){
                if(mark[i][n2][n3][n4]) continue;
                nvalue_1=i*1000+n2*100+n3*10+n4;
                if(prime[nvalue_1]){
                    mark[i][n2][n3][n4]=true;
                    if(nvalue_1==b) return nt+1;
                    Node tmp;
                    tmp.value=nvalue_1;
                    tmp.t=nt+1;
                    Q.push(tmp);
                }
            }
        }
        for(int i=0;i<10;i++){
            if((i+n1+n3+n4)%3==0) continue;
            if(i!=n2){
                if(mark[n1][i][n3][n4]) continue;
                nvalue_1=n1*1000+i*100+n3*10+n4;
                if(prime[nvalue_1]){
                    mark[n1][i][n3][n4]=true;
                    if(nvalue_1==b) return nt+1;
                    Node tmp;
                    tmp.value=nvalue_1;
                    tmp.t=nt+1;
                    Q.push(tmp);
                }
            }
        }
        for(int i=0;i<10;i++){
            if((i+n2+n1+n4)%3==0) continue;
            if(i!=n3){
                if(mark[n1][n2][i][n4]) continue;
                nvalue_1=n1*1000+n2*100+i*10+n4;
                if(prime[nvalue_1]){
                    mark[n1][n2][i][n4]==true;
                    if(nvalue_1==b) return nt+1;
                    Node tmp;
                    tmp.value=nvalue_1;
                    tmp.t=nt+1;
                    Q.push(tmp);
                }
            }
        }
        for(int i=0;i<10;i++){
            if(i%2==0||i==5||(i+n2+n1+n3)%3==0) continue;
            if(i!=n4){
                if(mark[n1][n2][n3][i]) continue;
                nvalue_1=n1*1000+n2*100+n3*10+i;
                if(prime[nvalue_1]){
                    mark[n1][n2][n3][i]==true;
                    if(nvalue_1==b) return nt+1;
                    Node tmp;
                    tmp.value=nvalue_1;
                    tmp.t=nt+1;
                    Q.push(tmp);
                }
            }
        }
    }
    return -1;
}
int main(){
    for(int i=1001;i<10000;i++){ //��ǳ����е���λ��������
        prime[i]=true;
        for(int j=2;j<=sqrt(double(i));j++){
            if(i%j==0){
                prime[i]=false;
                break;
            }
        }
    }
    cin>>cases;
    for(int i=0;i<cases;i++){
        for(int i=0;i<10;i++){
            for(int j=0;j<10;j++){
                for(int k=0;k<10;k++){
                    for(int z=0;z<10;z++) mark[i][j][k][z]=false;
                }
            }
        }
        cin>>a>>b;
        if(a==b) cout<<0<<endl;
        else{
            while(!Q.empty()) Q.pop();
            Node tmp;
            tmp.value=a;
            tmp.t=0;
            Q.push(tmp);
            int rec=BFS(b);
            cout<<rec<<endl;
        }
    }
    return 0;
}
