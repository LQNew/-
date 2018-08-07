/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//��������Ĳ�������� ����ú�ȫ�棬�����һ���ܺõ���Ŀ��
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(head==NULL || m==n) return head;
        ListNode* dumpy = new ListNode(-1); //�½�һ��ͷ��㣬����������д
        dumpy->next = head;
        int cnt=1;
        ListNode* pNode_pre = dumpy;
        while(cnt<m){
            pNode_pre = pNode_pre->next;
            cnt++;
        }
        //��pNode_pre ��ʶ m�ڵ�ǰ�Ľڵ�
        ListNode* tmpPre = pNode_pre->next; //ָ���m�ڵ�
        ListNode* tmp = tmpPre->next; // ָ���m+1�ڵ�
        ListNode* tmpNext;
        while(cnt<n){
            tmpNext = tmp->next;
            tmp->next = tmpPre;
            tmpPre = tmp;
            tmp = tmpNext;
            cnt++;
        }
        pNode_pre->next->next = tmp;
        pNode_pre->next = tmpPre;
        return dumpy->next;
    }
};
