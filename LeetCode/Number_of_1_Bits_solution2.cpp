// �õ���һ����������������ʣ���һ��������ȥ1���ԭ����������λ�����㣬�õ��Ľ���൱�ڰ������Ķ����Ʊ�ʾ�� ���ұߵ�1���0~
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        while(n){
            count++;
            n = (n-1) & n;
        }
        return count;
    }
};
