// �򵥵Ķ���˼·~
// ��С�����𲽻��������յĴ�����~
// f(n) = max(f(i)*f(n-i))
#include<iostream>
using namespace std;
int max_Product(int length){
    if(length < 2) return 0;
    if(length == 2) return 1;
    if(length == 3) return 2;
    int *product = new int[length+1];
    product[0] = 0;
    product[1] = 1; // ��Ϊ����ʱ������Ҫ�ټ�
    product[2] = 2; // ��Ϊ����ʱ������Ҫ�ټ�
    product[3] = 3; // ��Ϊ����ʱ������Ҫ�ټ�
    // �ڳ��� <=4 �������У������ӿɵõ������˻�ֵ�� <= �ܳ��ȱ���ֵ�ģ����԰���Щ��Ϊ���Ƶ�Ԫ������ʼ����
    for(int i=4;i<=length;i++){
        int max1 = 0;
        for(int j=1;j<=i/2;j++){
            int a = product[j]*product[i-j];
            max1 = max(a,max1);
            product[i] = max1;
        }
    }
    int max_value = product[length];
    delete[] product;
    return max_value;
}

int main(){
    int length;
    cin>>length;
    cout<<max_Product(length)<<endl;
    return 0;

}
