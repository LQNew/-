class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        //��ǰ����ɨ���Լ��Ӻ���ǰɨ����˻�����λ�ã������Լ�ֽ���������¹��ɣ�
        //����˼ά�Ե�һ���⣬����
        vector<int> res;
        int pre=1;
        for(int i=0;i<nums.size();i++){
            res.push_back(pre);
            pre*=nums[i];
        }
        int post=1;
        for(int i=nums.size()-1;i>=0;i--){
            res[i]=res[i]*post;
            post*=nums[i];
        }
        return res;
    }
};
