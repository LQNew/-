/*
    ����һ������������B����ť�������ض�����ϡ�˳���°�ť�󼴿ɿ�����Ҫ��ť�����ظ����£���(1-2-3)(4)(7-8) ���մ�˳����Դ�������Ҫ�����
    �ܵİ�ť�������ࡢ����
*/
//�������ƹ�ʽӦ�ü�ס��
//1.����� c[i][j]=c[i-1][j-1]+c[i-1][j], c[i][0]=c[i][i]=1
//2.�ڶ���˹������ �����ǵ�p����Ʒ��p���Ե�������һ���ǿռ��ϣ���ʱǰp-1����Ʒ����k-1���ǿյĲ��ɱ��ļ��ϣ�������ΪS(p-1,k-1)��Ҳ����ǰp-1����Ʒ����k���ǿյĲ��ɱ��ļ��ϣ���p����Ʒ��������һ���У�������k*S(p-1,k)�ַ�����
//  s[i][j]=s[i-1][j-1]+j*s[i-1][j],s[i][0]=0,s[i][i]=1 ���� n����ͬ����Ͷ��m����ͬ�ĺ����У����Ӳ���Ϊ�գ���Ϊ���Ӳ�ͬ�����Դ˴�s[i][j]*j! ��ʾ����
//  ��Ҳ�ǰ�����������е�110���⣺��ͬ���򡢲�ͬ�ĺ��ӡ����Ӳ�����Ϊ�յ�����
//���������⣬����֪�����ǿ�����ѡB����ť�� ��i���������ã�������i���ֿ�������<=i����box ȥ������Щ��ť���򵥵���˵����һ��n����ͬ����Ͷ��m����ͬ�ĺ��ӵ��������
//��ʱ��ÿ�������������󣬽����������õĸ������֮�ͱ������ķ���������
//������˼·�ȽϾ����ۺ��ԣ���һ�����⣡��

#include<iostream>
using namespace std;
int N;
int B;
long long s[12][12],c[12][12],a[12]; //�ڶ���˹���������������ȫ�������ļ���
long long total;
int main(){
    s[0][0]=1;
    c[0][0]=1;
    a[0]=1;
    for(int i=1; i<=11; i++){
        a[i]=a[i-1]*i;//����ó�ȫ������
        s[i][0]=0;//�ڶ���˹�������ĳ�ʼ��
        s[i][i]=1;//�ڶ���˹�������ĳ�ʼ��
        c[i][0]=c[i][i]=1;//������ĳ�ʼ��
        for(int j=1; j<i; j++){
            s[i][j]=s[i-1][j-1]+j*s[i-1][j]; //�ݹ�����ڶ���˹������
            //���ǵ�p����Ʒ��p���Ե�������һ���ǿռ��ϣ���ʱǰp-1����Ʒ����k-1���ǿյĲ��ɱ��ļ��ϣ�������ΪS(p-1,k-1)��Ҳ����ǰp-1����Ʒ����k���ǿյĲ��ɱ��ļ��ϣ���p����Ʒ��������һ���У�������k*S(p-1,k)�ַ�����
            c[i][j]=c[i-1][j-1]+c[i-1][j]; //�ݹ���������
        }
    }
    while(cin>>N){
        for(int i=1;i<=N;i++){
            total=0;
            cin>>B;
            for(int i=1;i<=B;i++){
                for(int j=1;j<=i;j++){
                    total+=c[B][i]*s[i][j]*a[j]; //����ÿһ��������Ӧ�ĸ���
                }
            }
            cout<<i<<' '<<B<<' '<<total<<endl;
        }
        break;
    }
    return 0;
}