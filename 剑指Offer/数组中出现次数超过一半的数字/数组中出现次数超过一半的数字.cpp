//�� map��ӳ�䣬���˲��ٿռ����ڴ洢
class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        map<int,int>hash;
        struct Node{
            int value;
            int freq;
        };
        Node node[numbers.size()];
        int cnt = 0;
        for(int i=0;i<numbers.size();i++){
            if(hash.find(numbers[i]) == hash.end()){
                hash[numbers[i]] = cnt;
                node[cnt].value = numbers[i];
                node[cnt].freq = 1;
                cnt++;
            }
            else node[hash[numbers[i]]].freq++;
        }
        for(int i=0;i<cnt;i++){
            if(node[i].freq > numbers.size()/2) return node[i].value;
        }
        return 0;
    }
};
