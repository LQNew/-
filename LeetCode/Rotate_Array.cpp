//O(n)�Ľⷨ
//û���Ż���ʱ�临�Ӷ�ΪO(1)���ռ临�Ӷ��Ż�Ϊ��O(n)
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int size = nums.size();
        if(size==0) return; //˼·���Ͻ���
        k = k%size;
        if(k==0) return; //˼·���Ͻ���
        vector<int> res;
        for(int j=size-k;j<size;j++) res.push_back(nums[j]);
        for(int j=size-1;j>=k;j--) nums[j]=nums[j-k];
        //memcpy(&nums[0],&res[0],sizeof(int)*k); //������ֵ����
        for(int i=0;i<k;i++) nums[i]=res[i]; //ֱ�Ӹ�ֵ
    }
};
