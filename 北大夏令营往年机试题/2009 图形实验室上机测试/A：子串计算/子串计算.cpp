//�ַ����������⣬�о�����������������Ŀ���ַ��������������ѵ�һ����..
//�������ҵ�˼·���ǰ����в��ظ������ַ����������Ϊ�˱�֤���ַ������ظ����ص�����һ��map����ӳ�䱣֤�ظ����ַ������洢��ͬʱ��֤���ַ����ǰ��ֵ��������
//�ַ��������ַ��� �ĺ���.substr()�������÷�һ��Ҫ��Ϥ�����Ǳ�������յĺ�����ͬʱ�����ַ�����ֵ������ʹ��ҲҪ�˽⣬������strncpy()��������������
//��һ�����Ǵ�����ֵ��char�����飬�ڶ���������string�������׵�ַ��������������string������β��ַ+1
//���й����ַ����ȶ��õ���strncmp()���������Ҳ�ǵ�һ��ʹ�ã�Ҳ��������������һ�������Ǳ��Ƚϵ��ַ�������ʼ��ַ���ڶ����ǱȽϵ��ַ������������ǱȽϵ��ַ����ĳ���
//����map�����ı������õ���iterָ�������iterָ�������Ҳ������ɫҪ��Ϥ��
//�ܶ���֮�����������ַ�������������۷��Ѷȣ��Ҿ���Ӧ���ڼӹ��̴���˼·!���а�����
#include<iostream>
#include<string>
#include<map>
#include<cstring>
using namespace std;
string str1;
map<string,int> M;
char substr1[101];
char str2[101];

int cmp(char* str, char* substr1) //�ȶ��Ӵ��ظ�����
{
    int i=0,cnt=0,len1,len2;
    len1=strlen(str);
    len2=strlen(substr1);
    while(i <= len1-len2)
    {
        if(strncmp(str+i,substr1,len2) == 0) cnt++;
        i++;
    }
    return cnt;
}

int main(){
    cin>>str2;
    string str1=str2;
    M.clear();
    int len=str1.length();
    string st;
    int idx=-1;
    for(int i=0;i<len;i++){
        for(int j=1;j<=len-i;j++){
            st=str1.substr(i,j); //substr(i,j) ������ַ�����i��λ�ÿ�ʼ������j���ַ���Ϊ��һ���Ӵ�
            if(M.find(st)==M.end()){ //��mapӳ��������ظ����ַ����޳�
                idx++;
                M[st]=idx;
            }
        }
    }
    //�˴���Ҫע����Ƕ���mapӳ�䣬Ĭ�ϵľ��ǰ���ֵ�и�������Ϊ��string���ͣ�����Ĭ�Ͼ��ǰ��ֵ�����
    map<string, int>::iterator iter; //����map���ָ��
    iter = M.begin();
    while(iter!= M.end()){
        string a=iter->first;
        strncpy(substr1, a.c_str(), a.length()+1); //��string����ת��Ϊchar��
        int ans=cmp(str2,substr1);
        if(ans>1) cout<<substr1<<' '<<ans<<endl;
        iter++;
    }
    return 0;
}
