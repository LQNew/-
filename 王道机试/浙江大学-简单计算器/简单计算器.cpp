//�������POJ�ϵ�����������ʽ��ȣ��Ѷ�ҪСһЩ�������˴�����Ȼ���ս���׺���ʽת��Ϊ��׺���ʽ��˼��ȥ������Ŀ
//��������������˼��Ҫ�����棡
//���ڴ˵����������ʽ������˼������C�����е�gets()������ȡһ�����ݣ�Ȼ��֮����strcmp()�����ȶԣ�ע��ȶԱ������ַ�����
#include<iostream>
#include<stack>
#include<cstring>
#include<iomanip>
#include<cmath>
using namespace std;
char symbol[201];
char formular[201];
stack<char>mystack;
stack<double>result;
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

void transform_1()
{
    int sum=0;
    int i;
    for(i=0;i<strlen(symbol);i++)
    {
        a=symbol[i];
        if(a==' ')
            continue;
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
        else //����������������ô����ֵ�ͣ����Ǽ����������е���ֵ�ͱ��������������У�����ӿո����ڱ�ʶ�ָ�
        {
            while(a!=' ')
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
            formular[sum++]=' ';
        }
    }
    while(!mystack.empty()) //�����������ջ�е����������ջ
    {
        b=mystack.top();
        formular[sum++]=b;
        mystack.pop();
    }
    formular[sum++]='\0';
}

void calculate()//��������ת������沨�����ʽ
{
    char num[10];
    double num1,num2,result1;
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
    while(gets(symbol))
    {
        if(strcmp("0", symbol)==0) break;
        transform_1();
        calculate();
        cout<<fixed<<setprecision(2)<<result.top()<<endl; //���������ջ��ֻ����һ��double���������£��������յĽ��~������������С����ֻ����λ������˴���������ʽ��
    }
    return 0;
}
