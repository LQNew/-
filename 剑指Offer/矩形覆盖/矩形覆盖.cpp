// ���θ����⣬ʵ����һ�� 쳲������������⣬�ѶȲ�����ô����Ҫ���Լ����ɳ�������ƹ�ϵ��
class Solution {
public:
    int rectCover(int number) {
        if( number <= 0 ) return 0;
        if( number == 1 ) return 1;
        int a = 1;
        int b = 1;
        int c;
        for(int i=2;i<=number;i++){
            c = a + b;
            a = b;
            b = c;
        }
        return c;
    }
};
