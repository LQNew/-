#include <map>
//����ĵ�˼·���ǲ���mapӳ�䣬���Ȿ���˼·Ҳ�ܺã�����ÿ�μ�¼֮ǰ�Ѿ����ҹ���ֵ������������map��ӳ�䣬��ֵ���±�֮����һ��ӳ�䣬��ѯ
//���õ���mapӳ���ѯ���ú�����ķ�������������ٶȺܿ�Ĳ�ѯ
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
	    map<int, int> hash;
	    vector<int> result;
	    for (int i = 0; i < nums.size(); i++) {
		    int numberToFind = target - nums[i];
		    if (hash.find(numberToFind) != hash.end()) {
                result.push_back(hash[numberToFind]);
                result.push_back(i);
                return result;
		    }
            hash[nums[i]] = i; //�����ֵ���ڱ��У���������ӳ��֮��
	    }
	    return result;
    }
};
