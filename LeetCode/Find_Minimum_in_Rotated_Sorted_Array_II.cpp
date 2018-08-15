// ��ת���������С������Ŀ�����ѵ���ʽ�������ˣ���Ҫ�Ƕ���duplicate numbers�����index1,index2,middle ����ֵ����ȵĻ�����ô���ƶ��϶���������ѭ������ʱ����Ҫ˳�����һ����orz
class Solution {
public:
    int ordered_search(vector<int>& nums, int index1, int index2){ // ˳�����
        int result = nums[index1];
        for(int i = index1 + 1 ;i <= index2; i++){
            if(nums[i]<result) result = nums[i];
        }
        return result;
    }

    int findMin(vector<int>& nums) {
        if(nums.size()<=0) return -1;
        if(nums.size()==1) return nums[0];
        int index1 = 0;
        int index2 = nums.size() - 1;
        int middle = index1; // Ϊ��Ӧ�������ǵ������еĳ�ʼ������ʽ
        // ���ֲ��ҵ�˼·
        while(nums[index1]>=nums[index2]){
            if(index2 - index1 == 1) return nums[index2];
            middle = (index1 + index2) / 2;
            if(nums[middle]==nums[index1] && nums[index1]==nums[index2]) return ordered_search(nums,index1,index2); // ����duplicate number�Ĵ���ʽ��
            if(nums[middle] >= nums[index1]) index1 = middle;
            // �����м��±��Ӧ����ֵ ����index1��Ӧ����ֵ��˵��middle�±��ʱ���ڵ��������У�index ָ�������м�
            else index2 = middle; //���middleָ�� ��Ӧ����ֵ С��index1��Ӧ����ֵ��˵��middle�ڵݼ������У�index2 ָ��middle
        }
        return nums[middle];
    }
};
