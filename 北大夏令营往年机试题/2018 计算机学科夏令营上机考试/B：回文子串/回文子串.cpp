//�ַ����������⣬��Ҫ�õ���reverse������substr()���������Ӵ��Ľ�ȡ��Ȼ������map����һ��ӳ�䣬��ʵ�˴�û��Ҫ��ӳ��ģ�����һ��string�����洢�ͺ��ˣ����Ǳ��ʱ��û�����Ӿ���ô����
//���������²��������������ģ�����û������ȷ��AC
#include<iostream>
#include<string>
#include<algorithm>
#include<map>
using namespace std;
int n;
string str1;
map<int, string> M;
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>str1;
        string c;
        string b;
        int max1=0;
        M.clear();
        for(int i=0;i<str1.size()-1;i++){
            for(int j=str1.size()-i;j>max1;j--){
                c=str1.substr(i,j);
                b=c;
                reverse(c.begin(),c.end());
                if(b==c){
                    if(M.find(j)==M.end()){
                        M[j]=c;
                    }
                    max1=j;
                }
            }
        }
        if(max1==0) cout<<str1<<endl;
        else cout<<M[max1]<<endl;
    }
    return 0;
}
