#include<iostream>
#include<algorithm>
using namespace std;
int N;
int grade[1000];
int search_grade;

int compare(const void*a,const void*b)
{
    return *(int*)a-*(int*)b;
}

int sign;
int main()
{
    while(cin>>N) //�����ʽ�Ǹ������⣡��Ҫע�������ʽ��ѡ��
    {
        if(N==0)
            break;
        for(int i=0;i<N;i++)
        {
            cin>>grade[i];
        }
        cin>>search_grade;
        qsort(grade,N,sizeof(grade[0]),compare);
        if(bsearch(&search_grade,grade,N,sizeof(grade[0]),compare))//search_gradeδ��ѯ��Ԫ�أ�������������ʽ~
        {
             sign=(long(bsearch(&search_grade,grade,N,sizeof(grade[0]),compare))-long(grade))/sizeof(int); //��ȡ��ѯ�����±�~
             int num=1;
             for(int i=sign+1;i<N;i++)
             {
                 if(grade[i]==search_grade)
                    num++;
                 else
                    break;
             }
             for(int i=sign-1;i>=0;i--)
             {
                 if(grade[i]==search_grade)
                    num++;
                 else
                    break;
             }
             cout<<num<<endl;
        }
        else
            cout<<0<<endl;
    }
    return 0;
}
