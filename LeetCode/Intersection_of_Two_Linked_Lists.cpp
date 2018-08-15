/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 // �ҵ���������Ĺ����ڵ㣬Ҳ����һ���ļ����Ե��⣡
class Solution {
public:
    unsigned int Get_length(ListNode *a){ // ���������ֵ
        unsigned int cnt = 0;
        while(a!=NULL){
            cnt++;
            a = a->next;
        }
        return cnt;
    }

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // ��ȡ������Ͷ������Լ�������Ͷ�����ĳ��Ȳ�ֵ
        unsigned int headA_length = Get_length(headA);
        unsigned int headB_length = Get_length(headB);
        unsigned int minus = headA_length - headB_length;
        ListNode *long_list = headA;
        ListNode *short_list = headB;
        if(headA_length < headB_length){
            minus = headB_length - headA_length;
            long_list = headB;
            short_list = headA;
        }

        for(int i=0;i<minus;i++) long_list = long_list->next; // �����������ϲ�ֵ������
        while(long_list!=NULL && (long_list!=short_list)){ //֮��ʼ�ȶԺ���������Ƿ�һ��~
            long_list = long_list->next;
            short_list = short_list->next;
        }
        ListNode *common = long_list;
        return common;
    }
};
