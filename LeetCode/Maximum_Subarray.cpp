// ������������ֵ��Ҳ�ǵ��͵���·�⣡ O(n) ���Ӷ�
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size()==0) return 0;
        int temp_max = 0;
        int max1 = 0;
        int max_minus = 0x80000000; //��ʶ��Сֵ
        for(int i=0;i<nums.size();i++){
            temp_max += nums[i];
            if(temp_max < 0) temp_max = 0; // �����ǰ��ֵС��0����temp_max ����Ϊ0
            else max1 = max(max1,temp_max); // ���temp_max ����0��max1 �ȶ�����
        }
        if(max1!=0) return max1;
        else{ // ���ȫΪ��ֵ���ҵ����ֵ
            for(int i=0;i<nums.size();i++) max_minus = max(nums[i],max_minus);
            return max_minus;
            // return *max_element(nums.begin(),nums.end()); //��������ܿ죡
        }

    }
};
