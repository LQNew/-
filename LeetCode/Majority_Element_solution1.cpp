// mapӳ�䣬��һ���ڵ�洢���ѶȲ������Ե�ʱ�����Թٶ��ҵĻظ����Ǻ����⣬���Ҹ��˶��Ի��Ǿ������������ǿ���˵��ͨ��
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int,int>hash;
        struct Node{
            int value;
            int freq;
        };
        Node node[nums.size()];
        int cnt = 0;
        for(int i=0;i<nums.size();i++){
            if(hash.find(nums[i]) == hash.end()){
                hash[nums[i]] = cnt;
                node[cnt].value = nums[i];
                node[cnt].freq = 1;
                cnt++;
            }
            else node[hash[nums[i]]].freq++;
        }
        for(int i=0;i<cnt;i++){
            if(node[i].freq > nums.size()/2) return node[i].value;
        }
        return 0;
    }
};
