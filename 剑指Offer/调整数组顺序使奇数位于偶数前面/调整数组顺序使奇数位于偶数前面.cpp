// �ÿռ任ʱ�䣬O(n) ʱ�临�Ӷȣ� O(n) �ռ临�Ӷ�
class Solution {
public:
    void reOrderArray(vector<int> &array) {
        vector<int> res;
        vector<int> tmp;
        for(int i = 0; i < array.size(); i++){
            if(array[i] % 2 == 1) res.push_back(array[i]);
            else tmp.push_back(array[i]);
        }
        for(int i = 0; i < tmp.size(); i++) res.push_back(tmp[i]);
        array = res;
    }
};
