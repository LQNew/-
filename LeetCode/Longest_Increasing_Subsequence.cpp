// ����������еĽⷨ�����������ǰ�Ե�ǰ�±����Ϊ��β�Ŀɻ�ȡ����������г���
// ����������п����� ģ��ⷨ~
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size()==0) return 0;
        vector<int> dp(nums.size());
        for(int i=0;i<nums.size();i++){ //��������~
            int max1=1;
            for(int j=0;j<i;j++){
                if(nums[j]<nums[i]) max1=max(dp[j]+1,max1);
            }
            dp[i]=max1;
        }
        int ans=1;
        for(int i=0;i<nums.size();i++){
            ans=max(ans,dp[i]);
        }
        return ans;
    }
};
