//���Ǻܶ����ơ����졢����������Щ��������ϵ...
#include<iostream>
using namespace std;
class A{
    private:
        int value;

    public:
        A(int n){ value=n; }
        A(A other){ value=other.value; }
        void print(){
            cout<<value<<endl;
        }
};
int main(){
    A a=10;
    A b=a;
    b.print();
    return 0;
}
