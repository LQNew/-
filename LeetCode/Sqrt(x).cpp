class Solution {
public:
    //���ֲ��ң���Ϊx��ƽ�����϶�С��x/2������ƽ�������� [1,x/2]֮��
    int mySqrt(int x) {
        if(x==0 || x==1) return x;
        int high = x/2 + 1;
        int low = 1;
        int mid;
        while(high>=low){
            mid = (high+low)/2;
            if(long(mid)*(long)mid==x) return mid;
            else if(long(mid)*long(mid)>x) high = mid-1;
            else low = mid+1;
        }
        return high;
    }
};
