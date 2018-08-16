class Solution {
public:
    int reverse(int x) {
        const int MIN = 0X80000000;
        const int MAX = 0X7FFFFFFF;
        long long res = 0; // long long�ͱ�֤�����������
        while(x!=0){ // ���ڸ��������ĳ�����ȡ��������Щ����������һ���ģ�
            res = res * 10 + x % 10;
            x /= 10;
        }
        if(res < long(MIN) || res > long(MAX)) return 0;
        else return res;
    }
};
