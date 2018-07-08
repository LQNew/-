/*
    ��һ�� N*M ���Թ���������� S���յ� D��ǽ X���͵��棬0��ʱ���˹��� S ������ÿ�����ߵ��ĸ��������ڵ�λ���е�һ������ÿ��λ�ñ�
    ����֮�󶼲����ٴ����룬���Ƿ��������һ��·��ʹ���˹��� T ��ʱ�պ��ߵ� D��
*/
//���������͵�������Ŀ�����Ǵ�һ���ڵ�һվ���ף�ֻҪ�ﵽҪ�󼴷��أ�Ҫ���Ϸ����������ܱ�֤���ѹ���˳�����У���
//�˴�����ϸ�ڣ����˹�ÿ��һ��ʱ��������λ�������У�ֻ��һ���������������һ���߼�һ�ĸı䣬��ô������������͵���ż�Խ������仯��������
//�����˹��߹�������ʱ��������λ������͵���ż�Ա���ԭʼλ�ò�ͬ�����߹�ż����ʱ��������͵���ż������㱣�ֲ��䡣����������͵���ż�Ժ��յ�
//������Ͳ�ͬ��������Ҫ����ż����ʹ��պôﵽ����Ȼ�����ǲ����ܵģ���������ֱ���ж���������£����ý�����ж������ܴ������������״̬��������
//�����֣�ֱ����� NO��
#include<iostream>
using namespace std;
int M,N,T;
int ex,ey;
int bx,by;
bool success;
char map1[7][7];
bool mark[7][7];
int go[][2]={
    -1,0,
    1,0,
    0,-1,
    0,1
};
void Dfs(int x,int y,int t){ //���ѣ�һվ���ף�Ҫ������еݹ��Լ���η��ص�ϸ�ڣ�
    for(int i=0;i<4;i++){
        int nx=x+go[i][0];
        int ny=y+go[i][1];
        if(nx<=0||nx>M||ny<=0||ny>N) continue;
        if(mark[nx][ny]) continue;
        if(map1[nx][ny]=='X') continue;
        if(map1[nx][ny]=='D'){
            int time=t+1;
            if(time==T){
                cout<<"YES"<<endl;
                success=true;
            }
            else continue;//˵����ʱ�����˵㲢�����ʣ����Ǳ���������
        }
        else{
            mark[nx][ny]=true;
            Dfs(nx,ny,t+1);
            mark[nx][ny]=false;
        }
        if(success==true) return;
    }
    return;
}
int main(){
    while(cin>>M>>N>>T){
        success=false;
        if(M==0&&N==0&&T==0) break;
        for(int i=1;i<=M;i++){
            for(int j=1;j<=N;j++){
                cin>>map1[i][j];
                mark[i][j]=false;
            }
        }
        for(int i=1;i<=M;i++){ //�ҵ��յ�����
            for(int j=1;j<=N;j++){
                if(map1[i][j]=='D'){
                    ex=i;
                    ey=j;
                }
            }
        }
        for(int i=1;i<=M;i++){ //�ҵ��������
            for(int j=1;j<=N;j++){
                if(map1[i][j]=='S'){
                    bx=i;
                    by=j;
                }
            }
        }
        if((bx+by)%2==(((ex+ey)%2)+T%2)%2){ //���������յ����ż����ʱ��Ĺ�ϵ����
            Dfs(bx,by,0);
            if(!success) cout<<"NO"<<endl;
        }
        else cout<<"NO"<<endl;
    }
    return 0;
}
