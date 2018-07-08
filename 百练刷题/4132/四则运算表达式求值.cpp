/*
    ����
        ��һ�����Դ����ŵ�Сѧ��������������ʽ��ֵ
    ����
        һ�У�һ������������ʽ��'*'��ʾ�˷���'/'��ʾ����
    ���
        һ�У��ñ��ʽ��ֵ������С���������λ
*/
//��������������������ʽ����ֵ����һ���������⣬���Ľⷨͨ������׺���ʽת��Ϊ��׺���ʽ��
//a + b*c + (d * e + f) * g -->a b c * + d e * f  + g * + ����׺���ʽ�ֱ���Ϊ�沨�����ʽ���������ң����ʽÿ��Ԫ��������ջ��������ֵ��ֱ�ӽ�ջ
//���ڷ��ţ����Ƕ�Ӧ�� ��ǰջ��Ԫ�����ջ��Ԫ�ذ��շ������㷨������
//�ʱ�����ĺ�������ν�ǰ׺���ʽת��Ϊ��׺���ʽ������˵�����Ƕ�����ֵ�͵�ֱ������������ڷ����ͣ���Ҫ�Ƚ����ȼ����������ϸ�Ľ�������ͣ�
//https://blog.csdn.net/sgbfblog/article/details/8001651
//�����и�����ͼʾ�����Ǳ��ʵ��ʱ����Ҫ����ջ�ṹ�Լ��ַ�����ȥ�洢������沨�����ʽ��ͬʱ����Ϊ������֮���double��������ȡ�������������ʱ��������˿ո������Ϊ�����ı�־
//�������ת���������֮���ٰ����沨�����ʽ�� ����ջ�ṹ������ֵ
//�������ѶȽϴ󣬿��ǵ�ϸ�ںܶ࣬��Ҫ������stack���һϵ����ջ����ջ�����ǿա�ȡջ��ֵ�Ⱥ���
//iomanip���setprecision()�Լ�fixed()�����������������С���㾫�ȣ�cstring��memset()�������ڳ�ʼ�����飻cmath���atof()�������ڽ��ַ�����ת��Ϊ��Ӧ��double�ͱ���
#include<iostream>
#include<iomanip>
#include<stack>
#include<cstring>
#include<cmath>
using namespace std;
stack<char>mystack;
stack<double>result;
char formular[300];
char symbol[300];
char a,b;

bool compare(char a,char b) //�Ƚ�����������ȼ������ȼ��ͻ���һ��ʱ����ǰջ�ڵ������������+��-���ȼ���ͣ�*��/�����ȼ����� +��-
{
    if(b=='+'||b=='-')
    {
        if(a=='+'||a=='-')
            return false;
    }
    else if(b=='*'||b=='/')
    {
        if(a=='+'||a=='-'||a=='*'||a=='/')
            return false;
    }
    return true;
}

void transform_1()//����׺���ʽת��Ϊ��׺���ʽ
{
    int sum=0;//���ڼ�����׺���ʽ��λ��
    int i;
    for(i=0;i<strlen(symbol);i++)
    {
        a=symbol[i];
        if(a=='+'||a=='-')
        {
            if(mystack.empty()) //���ջ����ѹ��
                mystack.push(a);
            else
            {
                b=mystack.top();
                if(compare(a,b)) //����ǰ���������ջ����������Ƚ����ȼ���������ȼ�����ֱ��ѹ��ջ
                {
                    mystack.push(a);
                }
                else
                {
                    while(!compare(a,b)) //����Ļ��Ƚ����ȼ���ֱ���������Լ����ȼ��͵ĲŰ��֣���Ȼ�˴�������������ţ���ô���Ż�ֱ��ѹ��
                    {
                        formular[sum++]=b;
                        mystack.pop();
                        if(mystack.empty())
                            break;
                        b=mystack.top();
                    }
                    mystack.push(a);
                }
            }
        }
        else if(a=='*'||a=='/')
        {
            if(mystack.empty())
                mystack.push(a);
            else
            {
                b=mystack.top();
                if(compare(a,b))
                {
                    mystack.push(a);
                }
                else
                {
                    while(!compare(a,b))
                    {
                        formular[sum++]=b;
                        mystack.pop();
                        if(mystack.empty())
                            break;
                        b=mystack.top();
                    }
                    mystack.push(a);
                }
            }
        }
        else if(a=='(') //����������ţ�ֱ��ѹ��
            mystack.push(a);
        else if(a==')') //����������ţ���ô����߲�ѯ���ҵ������ţ��м�����������ӡ����
        {
            b=mystack.top();
            while(b!='(')
            {
                mystack.pop();
                formular[sum++]=b;
                b=mystack.top();
            }
            mystack.pop();
        }
        else //����������������ô����ֵ�ͣ����Ǽ����������е���ֵ�ͱ��������������У�����ӿո����ڱ�ʶ�ָ�
        {
            while(a!='-'&&a!='+'&&a!='*'&&a!='/'&&a!='('&&a!=')') //�������������ʱ����ǰȫ������ֵ�ͱ���
            {
                formular[sum++]=a;
                i++;
                if(i==strlen(symbol))//�����ѯ����׺���ʽ��ʽβ��������
                    break ;
                a=symbol[i];
            }
            if(i==strlen(symbol)) //�����ѯ�������Ҫ���һ���ո��
            {
                formular[sum++]=' ';
                break;
            }
            i--;
            formular[sum++]=' ';
        }
    }
    while(!mystack.empty()) //�����������ջ�е����������ջ
    {
        b=mystack.top();
        formular[sum++]=b;
        mystack.pop();
    }
}

void calculate()//��������ת������沨�����ʽ
{
    char num[10];
    double num1,num2,result;
    int i=0;
    for(i=0;i<strlen(formular);i++)
    {
        a=formular[i];
        if(a=='+') //���ڲ�ͬ�������ִ�в�ͬ���������
        {
            num1=result.top();
            result.pop();
            num2=result.top();
            result.pop();
            result1=num1+num2;
            result.push(result1);
        }
        else if(a=='-')
        {
            num1=result.top();
            result.pop();
            num2=result.top();
            result.pop();
            result1=num2-num1;
            result.push(result1);
        }
        else if(a=='*')
        {
            num1=result.top();
            result.pop();
            num2=result.top();
            result.pop();
            result1=num1*num2;
            result.push(result1);
        }
        else if(a=='/')
        {
            num1=result.top();
            result.pop();
            num2=result.top();
            result.pop();
            result1=num2/num1;
            result.push(result1);
        }
        else //���Ϊ��ֵ����ô����ǰ����һ��ֵ������������������char������洢���������atof()��������ת��Ϊdouble����ֵ
        {
            memset(num,0,sizeof(int)); //num����ÿ�ζ�Ӧ��ʼ��
            int flag=0;
            while(a!=' ')
            {
                num[flag++]=a;
                i++;
                if(i==strlen(formular))
                    break;
                a=formular[i];
            }
            result.push(atof(num));
        }
    }
}

int main()
{
    cin>>symbol;
    transform_1();
    calculate();
    cout<<fixed<<setprecision(2)<<result.top()<<endl; //���������ջ��ֻ����һ��double���������£��������յĽ��~������������С����ֻ����λ������˴���������ʽ��
    return 0;
}
