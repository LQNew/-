//1003 ����
//In general you can make n cards overhang by 1/2 + 1/3 + 1/4 + ... + 1/(n + 1) card lengths,
//where the top card overhangs the second by 1/2, the second overhangs tha third by 1/3, the third overhangs the fourth by 1/4, etc.,
//and the bottom card overhangs the table by 1/(n + 1).
//��Ƭ����Ԫ��λΪ1����������ܿ�Ƭ���ȣ���������˶����ſ�Ƭ~
#include<iostream>
using namespace std;
int main()
{
	float input;
	while (cin >> input)
	{
		if (input == 0.00)
			break;
		float total = 0.00;
		int i = 1;
		while (total < input)
		{
			i = i + 1;
			total = total + 1.0 / i; //�˴���ʽ����ת����ע��/���ߵ��������ͣ���
		}
		cout << i-1 <<" "<<"card(s)"<< endl;
	}
	return 0;
}
