//��Ҫ���õ��˳���ķ�ת�������~
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* pReversedHead;
        ListNode* pNode = head; // ���浱ǰ���
        ListNode* pPrev = NULL; // ����ǰһ�ڵ�
        ListNode* pNext; // ��¼��һ�ڵ�
        while(pNode!=NULL){
            pNext=pNode->next;
            if(pNext==NULL) pReversedHead = pNode;
            pNode->next = pPrev;
            pPrev = pNode;
            pNode = pNext;
        }
        return pReversedHead;
    }
};
