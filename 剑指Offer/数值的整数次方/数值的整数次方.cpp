class Solution {
public:
    double Power(double base, int exponent) {
        if(exponent == 1) return base;
        if(exponent == 0) return 1;
        if(base - 0.0 >-0.0000001 && base - 0.0<0.0000001 && exponent<0) return 0.0; // �ж�base �Ƿ�Ϊ0����
        long n1 = exponent;
        bool flag = false;
        if(n1 < 0){
            n1 = -n1;
            flag = true;
        }
        double result = 1.0;
        while(n1){ // ����������
            result *= base;
            n1 = n1 >> 1; // ��������
            base*=base;
        }
        if(flag) return 1.0/result;
        else return result;
    }
};
