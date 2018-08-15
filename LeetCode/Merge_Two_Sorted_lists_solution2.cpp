/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 // �����ݹ��˼·ȥ����˼·���ѣ������ݹ���뷨��������Ҫ��Щʱ��
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == NULL) return l2;
        else if(l2 == NULL) return l1;
        ListNode* tmp = NULL;
        if(l1->val < l2->val){
            tmp = l1;
            tmp->next = mergeTwoLists(l1->next,l2);
        }
        else{
            tmp = l2;
            tmp->next = mergeTwoLists(l1,l2->next);
        }
        return tmp;
    }
};
