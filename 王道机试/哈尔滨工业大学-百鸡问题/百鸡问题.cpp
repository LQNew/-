/*
    ��С�ڵ���nԪȥ��100ֻ������5Ԫ/ֻ��С��3Ԫ/ֻ,����1/3Ԫÿֻ��һ��С�����ֱ��Ϊxֻ,yֻ,zֻ��������x,y,z���п��ܽ⡣
*/
//ˮ�⣬��Ϊ��100ֻ���޶���ʱ�临�Ӷ�ΪO(n^2) Ҳ���򼶱�����ֱ�ӱ�����������~
#include<iostream>
using namespace std;
int n;
int main(){
    while(cin>>n){
        for(int x=0;x<=100;x++){
            for(int y=0;y<=100;y++){
                double z=x*5+y*3+(100-x-y)/3.0;
                if(z<n)
                    cout<<"x="<<x<<','<<"y="<<y<<','<<"z="<<100-x-y<<','<<endl;
            }
        }
    }
    return 0;
}
