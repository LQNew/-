// һ�����飬�������������1~n �ڲ��ظ��Ļ�����ô��������֮�� �±�Ϊi��λ���Ͻ������ i+1������
// �������飬��ͷ��βɨ�����飬�±�Ϊi����ֵ(��m��ʾ)���ǲ��ǵ���i+1�������ڵĻ��������͵�m-1�����ֽ��бȽϣ�������͵�m-1��������ȣ���ô�ظ������ҵ�
// ������ǣ��Ѹ���ֵ�͵�m-1����ֵ��������m�ŵ���ȷ��λ���ϣ������ظ����������
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        if(nums.size()==0) return 0;
        for(int i=0;i<nums.size();i++){
            while((nums[i]-1)!=i){
                if(nums[i]==nums[nums[i]-1]) return nums[i];
                else{
                    swap(nums[i],nums[nums[i]-1]);
                }
            }
        }
        return 0;
    }
};
