class Solution {
public:
    int majorityElement(vector<int>& nums) {
        if(nums.size()==0) return 0;
        if(nums.size()==1) return nums[0];
        int temp = nums[0];
        int count = 1;
        // �������Ҫ�ҵ����ֳ��ֵĴ����������������ֳ��ֵĴ���֮�ͻ�Ҫ�࣬��ôҪ�ҵ����ֿ϶������һ�ΰ�count��Ϊ1ʱ������
        for(int i=1;i<nums.size();i++){
            if(temp == nums[i] ) count++;
            else{
                count--;
                if(count == 0){
                    temp = nums[i];
                    count=1;
                }
            }
        }
        count = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==temp) count++;
        }
        if(count>nums.size()/2) return temp;
        else return 0;
    }
};
