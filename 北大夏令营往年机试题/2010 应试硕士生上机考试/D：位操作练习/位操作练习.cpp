//���������ҵ�һ�β�����λ���㣬һ��Ҫ��Ϥ�����������
#include<iostream>
#include<cstring>
using namespace std;
const int standard=0x0000ffff;
int x,y,a;
int n;
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d%d",&x,&y);
        int cnt=0;
        for(int i=0;i<16;i++){
            a=((x>>(16-i))|(x<<i))&(standard); //ѭ����λ�����㣺����16-iλ������iλ���˴��������㣬֮���ٽ�ȡ��16λ
            if(a==y){
                printf("YES\n");
                break;
            }
            else cnt++;
        }
        if(cnt==16) printf("NO\n");
    }
    return 0;
}
