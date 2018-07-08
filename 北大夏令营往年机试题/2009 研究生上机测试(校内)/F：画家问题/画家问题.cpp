//��׼���ͣ�����Ϩ�����⣬��������һ�����ͣ��ӵ�һ�п�ʼһ����������ѯֱ�����һ�У�������һ��������������ô���ؽ������
//���ǱȽ��ѵ�ö�����⣬ҲҪ���˼������������ͣ�����������ʽ�̶ܹ����й̶������~
#include<iostream>
#include<cstring>
using namespace std;
const int INF=0x7fffffff;
bool map1[17][17];
int a[16];
int b[16];
bool press[16][16];
bool map_copy[17][17];
char symbol;
int ans;
int n;
void decomposition(int x){ //��һ��ʮ�������ֽ���nλ�Ķ�������
    for(int i=1;i<=n;i++){
        a[i]=x%2;
        x=x/2;
    }
}

void press_1(int i){ //����ÿһ�лᱻ���µ������Ȼ��������ڵ�״̬
    for(int j=1;j<=n;j++){
        if(press[i][j]){
            map_copy[i][j]=!map_copy[i][j];
            map_copy[i-1][j]=!map_copy[i-1][j];
            map_copy[i+1][j]=!map_copy[i+1][j];
            map_copy[i][j-1]=!map_copy[i][j-1];
            map_copy[i][j+1]=!map_copy[i][j+1];
        }
    }
}

void decide(int i){ //������һ�е�״̬���ҵ��ǻ�ɫ��ש�飬�����Ӧ����һ��ͬ�� �����Ƿ���Ƹ�ש��
    for(int j=1;j<=n;j++){
        if(!map_copy[i][j]){
            press[i+1][j]=true;
            ans++;
        }
    }
}

int main(){
    int b1=1;
    for(int i=1;i<=15;i++){ //����2^1~2^15������2�Ĵη���
        b1*=2;
        b[i]=b1;
    }
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>symbol;
            if(symbol=='w') map1[i][j]=0; //���������һ��Ԥ��������ɫש����Ϊ0����ɫש����Ϊ1�����ں������ı�д
            else map1[i][j]=1;
        }
    }
    int min1=INF;
    for(int i=0;i<b[n];i++){ //����ÿһ����һ�е���������б������Ƿ����~
        ans=0;
        memset(press,0,sizeof(press));
        memcpy(map_copy,map1,sizeof(map1)); //��ȡ��ǰ��ͼ�ĸ���
        decomposition(i);//���ɵ�һ�еĸ������
        for(int i=1;i<=n;i++){ //��ʼ����һ�����
            if(a[i]){
                press[1][i]=true;
                ans++;
            }
            else press[1][i]=false;
        }
        for(int i=1;i<n;i++){
            press_1(i);
            decide(i);
        }
        press_1(n);
        int cnt=0;
        for(int j=1;j<=n;j++){
            if(map_copy[n][j]) cnt++;
            else break;
        }
        if(cnt==n){ //������һ�м��ȫΪ��ɫש�飬��ô�ôε�һ�еļ������
            min1=min(ans,min1);
        }
    }
    if(min1==INF) cout<<"inf"<<endl;
    else cout<<min1<<endl;
    return 0;
}
