//solution1 ����˼·��O(nlog(n))+O(n)
class Solution {
public:
    void wiggleSort(vector<int> &nums) {
        // write your code here
        if(nums.size()==0) return; // �ж�����Ϊ�յ����
        sort(nums.begin(),nums.end());
        for(int i=1;i<nums.size()-1;i+=2){
            swap(nums[i],nums[i+1]);
        }
    }
};
