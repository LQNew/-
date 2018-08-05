class Solution {
public:
    int Partion(vector<int>& nums, int first, int end, int k){
        int i=first;
        int j=end;
        int pivot = nums[i];
        while(i<j){
            while((i<j)&&(nums[j]<=pivot)) j--;
            nums[i]=nums[j];
            while((i<j)&&(nums[i]>=pivot)) i++;
            nums[j]=nums[i];
        }
        nums[i]=pivot; //���pivot��Ӧ�������±���Ǵ������������ڵ� i+1��
        if(i==k) return nums[i];
        else if(i>k) return Partion(nums,first,i-1,k);
        else if(i<k) return Partion(nums,i+1,end,k);
    }
    int findKthLargest(vector<int>& nums, int k) {
        return Partion(nums,0,nums.size()-1,k-1);
    }
};
