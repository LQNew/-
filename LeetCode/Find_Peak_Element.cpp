// ����������б�����peakֵ��O(n)�㷨
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.size()<=0) return -1;
        if(nums.size()==1) return 0;
        for(int i=1;i<nums.size();i++){
            if(nums[i]<nums[i-1]) return i - 1; // ���nums[i]<nums[i-1]��˵���������ж��ˣ�nums[i-1]>nums[i]���ʷ��� i-1 �±�
        }
        // ���������β��Ҳû�з��� peakֵ��������Ϊ�϶�����peakֵ������Ϊ�ǵ�����nums[nums.size()] == ������󣬹ʷ���nums.size()-1
        return nums.size()-1;
    }
};
