class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        if (nums.size() <= 1) return -1;
        int fast = 0;
        int slow = 0;
        while(true){
        //�����������ķֲ��Ĺ�����ȷ������ֵ��Ϊ�±꽨�������һ�������ѭ��������
            slow = nums[slow];//slow��Ӧ��ָ�룬ÿ���ƶ�һ��
            fast = nums[nums[fast]]; //fast��Ӧ��ָ�룬ÿ���ƶ�����
            if (fast == slow) { //˵��fastָ���Ѿ�����ѭ���У�ѭ���п϶���һ��ֵ���ظ�ֵ�����򲻻�����ѭ��
                fast = 0;
                //�˴���Cycle list II��һ���ĵط��������point ֮ǰ��һ����Ӧ�������ڵ�һ������ȵģ���Ϊ�������ܽ���ѭ�������Դ˴������ҵ���ڴ�ǰһ�����circleֵ��
                while (fast != slow) {
                    fast = nums[fast];
                    slow = nums[slow];
                }
                return fast; //ָ��ѭ������ڴ�
            }
        }
    }
};
