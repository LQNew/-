//�õ�����ѧ�������ȡ����ͬʱ����Բ�������ȶ���Ҫ����~
#include<iostream>
#include<cmath>
using namespace std;
const double Pi=3.1415926;
int N;
double X,Y;
int main(){
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>X>>Y;
        double area=Pi*(X*X+Y*Y)/2.0;
        int year=ceil(area/50.0);
        cout<<"Property "<<i+1<<": This property will begin eroding in year "<<year<<'.'<<endl;
    }
    cout<<"END OF OUTPUT."<<endl;
    return 0;
}
