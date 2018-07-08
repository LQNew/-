/*
    ����
        ��һ����һ������n����ʾ��n���������������ÿ�����������
        ���������У�ÿ�б�ʾһ�γ����Ľ�����������Ƚ����ұ��ΪA-L��ÿ�γ����Ľ���������Կո�������ַ�����ʾ����ƽ��߷��õ�Ӳ�� ��ƽ�ұ߷��õ�Ӳ�� ƽ��״̬��
        ����ƽ��״̬��``up'', ``down'', �� ``even''��ʾ, �ֱ�Ϊ�Ҷ˸ߡ��Ҷ˵ͺ�ƽ�⡣��ƽ���ҵ�Ӳ����������ȵġ�
    ���
        �����һ����ŵ������Ǽٱң���˵����������ỹ����(heavy or light)��
*/
//�������������ע���߼��ķ���������12��Ӳ�ң���ô�ܹ���24��״̬�����Բ���ö�ٵķ���������Ų�Ӳ�ҵĿ�����
//������Ľⷨ����ο����鱾���߼��Էǳ��ã����Խ����ע�����ַ������Ƿ����ĳ���ַ���ʱ�����Ե���<cstring>���strchr()����
#include<iostream>
#include<cstring>
using namespace std;
char left_1[3][7]; //������������
char right_1[3][7];//������ұ���ƽ����
char result[3][5];//����Ľ������
char characters[12]={'A','B','C','D','E','F','G','H','I','J','K','L'}; //���е�Ӳ������
int n;
bool light(char x) //�ж�Ӳ���Ƿ����
{
    for(int i=0;i<3;i++)
    {
        if(result[i][0]=='e')
        {
            if(strchr(left_1[i],x)!=NULL||strchr(right_1[i],x)!=NULL)
                return false;
        }
        else if(result[i][0]=='u')
        {
            if(strchr(right_1[i],x)==NULL) //����˴�����д���б����һ��Ҫ���ұ������Ӳ�ң����������Ӳ�Ҳ���λ����ߣ���Ϊ���ܻ����ظ�Ӳ�ҵĿ����ԣ��Ǹ���
                return false;
        }
        else
        {
            if(strchr(left_1[i],x)==NULL)
                return false;
        }
    }
    return true;
}
bool heavy(char x) //�ж�Ӳ���Ƿ����
{
    for(int i=0;i<3;i++)
    {
        if(result[i][0]=='e')
        {
            if(strchr(left_1[i],x)!=NULL||strchr(right_1[i],x)!=NULL)
                return false;
        }
        else if(result[i][0]=='u')
        {
            if(strchr(left_1[i],x)==NULL)
                return false;
        }
        else
        {
            if(strchr(right_1[i],x)==NULL)
                return false;
        }
    }
    return true;
}
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<3;j++)
        {
            cin>>left_1[j]>>right_1[j]>>result[j];
        }
        for(int i=0;i<12;i++)
        {
            if(light(characters[i])) //������б��Ӳ�ҽ��ᣬ��ô���
            {
                cout<<characters[i]<<" is the counterfeit coin and it is light."<<endl;
                break;
            }
            else if(heavy(characters[i]))
            {
                cout<<characters[i]<<" is the counterfeit coin and it is heavy."<<endl;

                break;
            }
        }
    }
    return 0;
}
