class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        unsigned int flag = 1; // unsigned �˴�����Ҫ��ͬʱ������Ҫ�����˶������е������
        while(flag){
            if(flag&n) count++;
            flag = flag<<1;
        }
        return count;
    }
};
