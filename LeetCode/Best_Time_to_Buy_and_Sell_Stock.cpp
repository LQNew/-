// ��Ʊ���������momenta���Կ����ˣ��ҵ�ʱ��д����O(n)���Ӷȵ��㷨��Ҳ����ok��...
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()<=1) return 0;
        int min1 = prices[0];
        int max1 = 0;
        for(int i=1;i<prices.size();i++){
            if(prices[i]>min1) max1 = max(prices[i]-min1,max1);
            else min1=prices[i];
        }
        return max1;
    }
};
