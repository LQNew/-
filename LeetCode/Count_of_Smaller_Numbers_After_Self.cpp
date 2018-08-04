//�ڹ鲢����Ļ����϶����һ����ʶ����ȥ��ʶ�±꣬�ȶ���ֵ�����������׵�˼·~
//�����ȽϺ�ʱҲ������...�Ҿ��ÿ������Ҳ����¿����飬����ڴ浼�����������...
class Solution {
public:
    vector<int> count;
    vector<int> flag;
    void Merge_pass(vector<int>& A, vector<int>& nums, vector<int>& L, int left_count, vector<int>& R, int right_count){
        int i,j,k;
        i = 0; j = 0; k = 0;
        while(i<left_count && j<right_count){
            if(nums[L[i]]<=nums[R[j]]) A[k++] = L[i++];
            else{
                for(int z=i;z<left_count;z++) count[L[z]]++;
                A[k++] = R[j++];
            }
        }
        while(i<left_count) A[k++]=L[i++];
        while(j<right_count) A[k++]=R[j++];
    }

    void Merge_sort(vector<int>& A, vector<int>& nums, int cnt1){
        int mid = cnt1/2;
        if(mid==0) return;
        vector<int> L(mid);
        vector<int> R(cnt1-mid);
        for(int i=0;i<mid;i++) L[i] = A[i];
        for(int j=mid;j<cnt1;j++) R[j-mid] = A[j];
        Merge_sort(L,nums,mid);
        Merge_sort(R,nums,cnt1-mid);
        Merge_pass(A,nums,L,mid,R,cnt1-mid);
        L.clear();
        R.clear();
    }

    vector<int> countSmaller(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            flag.push_back(i);
            count.push_back(0);
        }
        Merge_sort(flag,nums,nums.size());
        return count;
    }
};
