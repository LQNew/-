//������˼ά�ѶȺܴ󣬱��ʵ�ֺ�ˮ�������˼ά��û��ϸ��������µ�˼·�ǣ�ÿ�δ����е������������������ģ�����õ������>����������֮�ͣ���ô���������ĵ���ò��ꣻ
//�������������������������������ô���е�ض��������꣬�����˼·��Ҳ���Ǻ�����...������⵽�˴� orz..
#include <cstring>
#include <iostream>
#include <iomanip>
using namespace std;
int main(){
    int n;
    while(cin >> n)
    {
        int sum = 0;
        int maxn = 0;
        int x;
        for(int i=1;i<= n;i++){
            cin>>x;
            maxn = max(maxn, x);
            sum += x;
        }
        int sum2 = sum-maxn;
        if(sum2 <= maxn) cout<<fixed<<setprecision(1)<<double(sum2)<<endl;
        else cout<<fixed<<setprecision(1)<<double(sum/2.0)<<endl;
    }
    return 0;
}
