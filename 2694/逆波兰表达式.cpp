/*
    ����
        �沨�����ʽ��һ�ְ������ǰ�õ��������ʽ��������ͨ�ı��ʽ2 + 3���沨����ʾ��Ϊ+ 2 3���沨�����ʽ���ŵ��������֮�䲻�������ȼ���ϵ��
        Ҳ���������Ÿı������������(2 + 3) * 4���沨����ʾ��Ϊ* + 2 3 4����������沨�����ʽ��ֵ���������������+ - * /�ĸ���
    ����
        ����Ϊһ�У������������������֮�䶼�ÿո�ָ����������Ǹ�������
    ���
        ���Ϊһ�У����ʽ��ֵ��
*/
//�������˵����Ǹ��ݹ��⣬�����ö�����ȥ���˼·�����ڵ��Ƿ��ţ�����ÿ�㶼�Ƿ��ţ�ֻ����ײ������֣�Ȼ�󷵻�ȥ���㣬����ײ�����ֱ���㵽���ڵ㴦
//��᱾����ĵݹ�˼�룡 �������õ��� cmath���atof()�������ڻ�ȡ�ַ�������ֵ
#include<iostream>
#include<cmath>
using namespace std;
double calculate()
{
    char symbol[10];
    cin>>symbol;
    if(symbol[0]=='*')
        return calculate()*calculate();
    else if(symbol[0]=='+')
        return calculate()+calculate();
    else if(symbol[0]=='-')
        return calculate()-calculate();
    else if(symbol[0]=='/')
        return calculate()/calculate();
    else
        return atof(symbol);
}
int main()
{
    double ans=calculate();
    printf("%f\n", ans); //���������Ҫ�󡣡���
}
