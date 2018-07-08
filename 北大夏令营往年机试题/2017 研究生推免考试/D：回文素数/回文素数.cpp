/*
    ����
        һ��������������Ҷ��ʹ����������������ͬ�ģ����������ǻ���������121��1221��15651���ǻ�������
        ����λ��n���ҳ����м��ǻ���������������nλʮ����������ע�������ǳ�����������Χ���������
    ����
        λ��n,����1<=n<=9��
    ���
        ��һ��������������������������ڶ��а��մ�С�����˳�������������������������������֮����һ���ո����֡�
*/
//������������Ŀ�ѶȲ��󣬾��Ƿ��ӣ������ڻ���������⣬�����ȹ����������ͬʱ���Լ���������2���⣬��ż����β��������Ϊ�����Լ���5���⣬��5��β��������Ϊ����
//ͬʱ���и����־��Ƕ��ڳ���11���ż����������������������ЩԼ����������ӣ�������Ч�ؼ���������Ҫ�б��������Ŀ��������������Ȼ�����ڸ��˵����ܲ���ԣ�������û�г�ʱ����Ҫ���ϲ��ԣ�
//�������и��ӵ������η�ʱ��һ��ʼֱ�ӵ�����cmath���pow()�������������ָú����������������������֣������Լ���д��һ����η��ĺ���������pow()�������Ǿ�����Ҫ�ã��ȽϿӣ���
//������һ��ʼ���鿪С�ˣ�֮���������������n=9ʱ�Ļ�������������Ŀ����1w�����ڻ᲻��TLҲ������Ҫ���ǵģ�
#include<iostream>
using namespace std;
int n;
int decomposition[10];
int num[100000];
int final_num[100000];
int power(int j){
    int a=1;
    while(j>0){
        a*=10;
        j--;
    }
    return a;
}
void judge(int cnt){ //�б��Ƿ�Ϊ����
    int cnt_1=0;
    int j;
    for(int i=0;i<cnt;i++){
        j=2;
        for(j;j<=sqrt(num[i]);j++){
            if(num[i]%j==0) break;
        }
        if(j>sqrt(num[i])){
            final_num[cnt_1]=num[i];
            cnt_1++;
        }
    }
    cout<<cnt_1<<endl;
    for(int k=0;k<cnt_1-1;k++)
        cout<<final_num[k]<<" ";
    cout<<final_num[cnt_1-1]<<endl;
}
int main(){
    cin>>n;
    int cnt;
    if(n==1){
        cout<<4<<endl;
        cout<<"2 3 5 7"<<endl;
    }
    else if(n==2){ //���������
        cnt=0;
        for(int i=1;i<10;i+=2){
            if(i==5) continue;
            decomposition[1]=decomposition[n]=i;
            if((decomposition[1]+decomposition[n])%3==0) continue;
            else{
                num[cnt]=0;
                for(int j=n;j>0;j--){
                    num[cnt]+=decomposition[j]*power(j-1);
                }
                cnt++;
            }
        }
        judge(cnt);
    }
    else if(n%2==0){
        cout<<0<<endl;
        cout<<endl;
    }
    else if(n==3){
        cnt=0;
        for(int i=1;i<10;i+=2){
            if(i==5) continue;
            decomposition[1]=decomposition[n]=i;
            for(int z=0;z<10;z++){
                decomposition[2]=z;
                if((decomposition[1]+decomposition[2]+decomposition[n])%3==0) continue;
                else{
                    int a=0;
                    for(int j=1;j<=n;j++){
                        a+=decomposition[j]*power(j-1);
                    }
                    num[cnt++]=a;
                }
            }
        }
        judge(cnt);
    }
    else if(n==5){
        cnt=0;
        for(int i=1;i<10;i+=2){
            if(i==5) continue;
            decomposition[1]=decomposition[n]=i;
            for(int z=0;z<10;z++){
                decomposition[2]=decomposition[4]=z;
                for(int t=0;t<10;t++){
                    decomposition[3]=t;
                    if((decomposition[1]+decomposition[2]+decomposition[3]+decomposition[4]+decomposition[n])%3==0) continue;
                    else{
                        for(int j=n;j>0;j--) num[cnt]+=decomposition[j]*power(j-1);
                            cnt++;
                    }
                }
            }
        }
        judge(cnt);
    }
    else if(n==7){
        cnt=0;
        for(int i=1;i<10;i+=2){
            if(i==5) continue;
            decomposition[1]=decomposition[n]=i;
            for(int z=0;z<10;z++){
                decomposition[2]=decomposition[6]=z;
                for(int t=0;t<10;t++){
                    decomposition[3]=decomposition[5]=t;
                    for(int x=0;x<10;x++){
                        decomposition[4]=x;
                        if((decomposition[1]+decomposition[2]+decomposition[3]+decomposition[4]+decomposition[5]+decomposition[6]+decomposition[n])%3==0) continue;
                        else{
                            for(int j=n;j>0;j--) num[cnt]+=decomposition[j]*power(j-1);
                            cnt++;
                        }
                    }
                }
            }
        }
        judge(cnt);
    }
    else if(n==9){
        cnt=0;
        for(int i=1;i<10;i+=2){
            if(i==5) continue;
            decomposition[1]=decomposition[n]=i;
            for(int z=0;z<10;z++){
                decomposition[2]=decomposition[8]=z;
                for(int t=0;t<10;t++){
                    decomposition[3]=decomposition[7]=t;
                    for(int x=0;x<10;x++){
                        decomposition[4]=decomposition[6]=x;
                        for(int y=0;y<10;y++){
                            decomposition[5]=y;
                            if((decomposition[1]+decomposition[2]+decomposition[3]+decomposition[4]+decomposition[5]+decomposition[6]+decomposition[7]+decomposition[8]+decomposition[n])%3==0) continue;
                            else{
                                for(int j=n;j>0;j--) num[cnt]+=decomposition[j]*power(j-1);
                                cnt++;
                            }
                        }
                    }
                }
            }
        }
        judge(cnt);
    }
    return 0;
}
