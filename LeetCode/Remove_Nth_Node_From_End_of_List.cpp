/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// �ٶ�������n����һ�������Һ�������ǰ����
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL || n == 0) return NULL;
        ListNode* fNode = head;
        ListNode* bNode = NULL;
        for(int i=0;i<n-1;i++) fNode = fNode->next;
        bNode = head;
        while(fNode->next!=NULL){
            fNode = fNode->next;
            bNode = bNode->next;
        }
        if(bNode->next == NULL){ // ��� ��ɾ���Ľڵ�Ϊβ�ڵ�
            if(head == bNode) return NULL; // ����ֻ��һ���ڵ㣬����β�ڵ�����ͷ���
            else{ //�����ж���ڵ㣬ɾ��β�ڵ�
                ListNode* tmp = head;
                while(tmp->next != bNode){
                    tmp = tmp->next;
                }
                tmp->next = bNode->next;
                delete bNode;
                bNode = NULL;
                return head;
            }
        }
        else{ //��������µĴ�ɾ���ڵ�
            ListNode* tmp = bNode->next;
            bNode->val = tmp->val;
            bNode->next = tmp->next;
            delete tmp;
            tmp  = NULL;
            return head;
        }
    }
};
