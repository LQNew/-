/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// �ϲ���������������ǳ��������Ŀ��һ��Ҫ��Ϥ��
// ����ķǵݹ�˼·ȥ����ʱ�临�Ӷ�һ�����Ƚ�����д�������ܳ��������ԡ��ɶ��Բ���ݹ�˼·
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* total = NULL;

        if(l1==NULL){
            total = l2;
            return total;
        }
        else if(l2==NULL){
            total = l1;
            return total;
        }
        ListNode* total_store = NULL;
        if(l1->val < l2 ->val){
            total = l1;
            total_store = total;
            l1 = l1->next;
        }
        else{
            total = l2;
            total_store = total;
            l2 = l2->next;
        }
        while(l1!=NULL && l2!=NULL){
            if(l1->val < l2->val){
                total->next = l1;
                total = total->next;
                l1 = l1->next;
            }
            else{
                total->next = l2;
                total = total->next;
                l2 = l2->next;
            }
        }
        if(l1==NULL && l2==NULL) total->next = NULL;
        else if(l1==NULL) total->next = l2;
        else total->next = l1;
        return total_store;
    }
};
