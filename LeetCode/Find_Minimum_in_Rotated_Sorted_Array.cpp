// �ҳ���ת�����е���Сֵ�����Գ������ͣ�
class Solution {
public:
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
            if(nums[middle] >= nums[index1]) index1 = middle;
            // �����м��±��Ӧ����ֵ ����index1��Ӧ����ֵ��˵��middle�±��ʱ���ڵ��������У�index ָ�������м�
            else index2 = middle; //���middleָ�� ��Ӧ����ֵ С��index1��Ӧ����ֵ��˵��middle�ڵݼ������У�index2 ָ��middle
        }
        return nums[middle];

    }
};
