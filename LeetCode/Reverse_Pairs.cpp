//���ǲ��ù鲢���򷽷���������Ϊ�������и�������������Ŀ����ô����ҵ���������Ƚϴ�orz...
int cnt;
class Solution {
public:

    void Merge_pass(vector<int>& A, vector<int>&L, int left_count, vector<int>&R, int right_count){
        int i,j,k;
        i=0;j=0;
        while(i<left_count && j<right_count){ //ר��д�δ������ڱ�ʶָ�룬��������ԣ��������ڵ������Ǹ���ʱ�����������ţ�
            if((long)L[i]<=(long)2*R[j]) i++;
            else{
                cnt+=(left_count-i);
                j++;
            }
        }
        i=0;j=0;k=0;
        while(i<left_count && j<right_count){
            if(L[i]<R[j]) A[k++]=L[i++];
            else A[k++]=R[j++];
        }
        while(i<left_count) A[k++]=L[i++];
        while(j<right_count) A[k++]=R[j++];
    }

    void Merge_sort(vector<int>& A, int cnt1){
        int mid=cnt1/2;
        if(mid==0) return;
        vector<int>L(mid); //��ʼ�����飬�����ĳ�ʼ����ʽ
        vector<int>R(cnt1-mid);
        for(int i=0;i<mid;i++) L[i]=A[i];
        for(int j=mid;j<cnt1;j++) R[j-mid]=A[j];
        Merge_sort(L, mid);
        Merge_sort(R, cnt1-mid);
        Merge_pass(A,L,mid,R,cnt1-mid);
        R.clear();
        L.clear();
    }

    int reversePairs(vector<int>& nums) {
        if(nums.size()==0) return 0;
        cnt=0;
        Merge_sort(nums,nums.size());
        return cnt;
    }
};
