/*
    ����һ�����ַ����������ո񣩣��ٸ��������ַ���������Щ�ַ�����ɾ�������еĶ��ַ����� ��ȥ���ո�,�����
*/
//���������õ��� string stl��ĺ���������������string���find()�����Լ� erase()������Ҫ���˽�~����Ŀ��string�²����Ƚϼ���ǵ��Ƚϵ��͵���Ŀ
//ҲӦ������gets������ʹ�ã������Զ���ո�ֻ���������з��Ż���ֹ��
//�˽�gets�������ص㣬������������gets�����������ζ������������뻺���е�����ֱ�����ֻ��з������������з���������Ѷ��ַ��������ַ������У�
#include <iostream>
#include <string>
using namespace std;
int main () {
    char str[101];
    gets(str); //������ַ���
    string a=str;
    for (int i=0;i<a.size();i++) {
        a[i] = tolower(a[i]); //string �ַ����Ĳ�������a�е��ַ�ȫ���ĳ�Сд
    }
    while(gets(str)) { //ÿ����һ�����ַ�������д���
        string b=str;
        string c = b; //���ַ���������b,c
        for (int i = 0;i < b.size();i ++) {
            b[i] = tolower(b[i]);//��b���ַ�ȫ���ĳ�Сд,�Ա�ƥ��
        }
        int t = b.find(a,0); //��b�в���a��λ��
        while (t != string::npos) { //�����ҳɹ�,���ظ�ѭ��,find�������Ҳ���ָ��ֵ������»᷵��string::npos
            c.erase(t,a.size()); //ɾ��c����Ӧλ���ַ�,cΪԭ��
            b.erase(t,a.size()); //ɾ��b����Ӧλ���ַ�,bΪ��ΪСд�ַ��Ĵ�
            t = b.find(a,t); //��������b����һ�������ַ���a��λ��
        }
        t = c.find(' ',0); //����c�пո�
        while(t != string::npos) {
            c.erase(t,1); //ɾ��c�����пո�
            t = c.find(' ',0);
        }
        cout<<c<<endl; //���
    }
    return 0;
}
