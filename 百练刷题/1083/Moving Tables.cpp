/* ���������⣬��ѧ˼ά���͵���
   ����ؼ��Ǽ��㾭��ÿ�Է���Ĵ�����Ȼ��������Ĵ�����ΪŲ�����ӵĴ�������

   ����
   The input consists of T test cases. The number of test cases ) (T is given in the first line of the input file.
   Each test case begins with a line containing an integer N , 1 <= N <= 200, that represents the number of tables to move.
   Each of the following N lines contains two positive integers s and t,
   representing that a table is to move from room number s to room number t each room number appears at most once in the N lines). From the 3 + N -rd
   line, the remaining test cases are listed in the same manner as above.
   ���
   The output should contain the minimum time in minutes to complete the moving, one per line.
*/

#include<iostream>
#include <string.h>
using namespace std;
int main()
{
    int T;
    cin>>T;
    int room[201];
    while(T--)
    {
        memset(room,0,sizeof(room)); //memset������ʹ�ã������������ֵ  Ҫ��string��ĵ���ſ�ʹ��
        int N;
        cin>>N;
        int a,b;
        for(int i=0;i<N;i++)
        {
            cin>>a>>b;
            if(a>b)
                swap(a,b); //���ú��� swap ����������ֵ�ĺ���
            if(a%2)
                a=a/2+1;
            else
                a=a/2;
            if(b%2)
                b=b/2+1;
            else
                b=b/2;
            //�������Ӧ�ķ���ŵ���һ���Գƹ������ܹ�������������������������������ͨ���Ĵ���
            for(int i=a;i<=b;i++)
                room[i]++;
        }
        int max_times=0;
        for(int i=1;i<sizeof(room)/4;i++) //sizeof()�������ص�������ռ�ݵ��ֽ��� ����Ҫ���� /4 ������
            max_times=max(max_times,room[i]);
        int min_time=max_times*10;
        cout<<min_time<<endl;
    }
    return 0;
}
