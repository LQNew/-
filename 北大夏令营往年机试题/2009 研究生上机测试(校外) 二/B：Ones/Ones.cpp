//�����ͷ��⣬���ǻ�ͦ���˵ģ�Ҫ���Ǹ�˼ά!!
#include<iostream>
using namespace std;
int n;
int main(){
    int cnt,tmp;
    while(cin>>n)
    {
        tmp=1;
        cnt=1;
        while(tmp) //ģ��ÿ�εĳ������㣬��Ϊ���ĵ������������������������ģ�Ҫ����ѧ��ϳ����˼ά!!
        {
            tmp=tmp*10+1;
            cnt++;
            tmp%=n;
        }
        cout<<cnt<<endl;
    }
    return 0;
}
