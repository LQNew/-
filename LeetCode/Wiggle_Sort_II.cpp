//��Ϊ Ҫ����nums[0]<nums[1]>nums[2]...������ʽ������ nums[0]<=nums[1]>=nums[2]...������ʽ�������Ѷ��ϸ��Ǵ���Щ������ �ö����˼·Ҳ���ܽ�����Դ���С�ڵ�����
//���ÿ����ź���󣬴�������м䣨��Сֵ�����Լ������ĩβ(�ϴ�ֵ) ����ɨ���±�Ϊż���������м������ȥ���±�Ϊ����������ĩβ������ȥ�������ܱ�֤����wiggle sort ����ʽ
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        if(nums.size()==0) return;
        vector<int> nums_copy = nums;
        sort(nums_copy.begin(),nums_copy.end());
        int k = (nums.size()+1)/2;
        int j = nums.size();
        for(int i=0; i<nums.size();i++){
            if(i%2 == 0) nums[i] = nums_copy[--k];
            else nums[i] = nums_copy[--j];
        }
    }
};
