/*һ������������˼������ӣ�����2ֻ�ţ�������4ֻ�ţ�û�����⣩���Ѿ�֪������������ŵ�����a�����������������ж���ֻ��������ж���ֻ����
  ����:һ��������a
  �����һ�У�������������������һ�������ٵĶ��������ڶ��������Ķ�������������������һ���ո�ֿ�
*/
//˼·������ǣ����ü��õĽ���Ŀ��Ϊż�������ԣ�ȥ�����������ٵĶ�����~
#include<iostream>
using namespace std;
void computer(int num_feet)
{
    if(num_feet%2)
        cout<<0<<" "<<0<<endl;
    else
    {
        if(num_feet%4)
            cout<<num_feet/4+1<<" "<<num_feet/2<<endl;
        else
            cout<<num_feet/4<<" "<<num_feet/2<<endl;
    }
}
int main()
{
    int num_feet;
    while(cin>>num_feet)
    {
        computer(num_feet);
    }
    return 0;
}
