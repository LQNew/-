//3Sum ���ǹ̶�һ��Ԫ�أ�����two sum �Ķ��ֲ��ҵ�˼·ȥ�����Ų�~
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int cnt = nums.size();
        vector<vector<int>> result;
        if(cnt<3) return result;
        sort(nums.begin(),nums.end()); // ���򣬰���С���������������
        int j,k;
        for(int i=0;i<cnt-2;i++){
            if(i==0 || nums[i]>nums[i-1]){ //ѡ������һ��Ԫ����flag��־�ȶԣ���Ҫ��֤���ظ�!
                int tmp = -nums[i];
                j = i + 1;
                k = cnt - 1;
                while(j<k){
                    if(nums[j]+nums[k]==tmp){
                        vector<int> result1;
                        result1.push_back(nums[i]);
                        result1.push_back(nums[j]);
                        result1.push_back(nums[k]);
                        result.push_back(result1);
                        j++;
                        k--;
                        while(j<k && nums[j]==nums[j-1]) j++;
                        while(j<k && nums[k]==nums[k+1]) k--;
                    }
                    else if(nums[j]+nums[k]<tmp) j++;
                    else k--;
                }
            }
        }
        return result;
    }
};
