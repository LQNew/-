//����ⷨ��TL���˴����ÿ������㷨
//�������е���˼���ᷢ��int����С��0�����Сֵ��ת����Ϊ0��������Ҫ���ǽ����ֱ�ʾ����ʽת��Ϊ��Ŀ��Ա�ʾ����λ������ʽ����unsigned���˴�������long��ȥ��ʾ����λ��
class Solution {
public:
    double myPow(double x, int n) {
        long n1=n;
        long n2;
        if(n<0) n2=-n1;
        else n2=n1;
        double a=1.0;
        while(n2!=0){
            if(n2%2==1) a*=x;
            n2/=2;
            x*=x;
        }
        if(n<0) return 1.0/a;
        else return a;
    }
};
