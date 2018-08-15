/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// ɾ��ָ������⣬��Ҫ��˼����ָ��������Ҫ��Ҫ���ָ��Ĳ��뼰ɾ����
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* pNext = node->next; // ��ʾ�˱�ɾ���Ľڵ㲻��β�ڵ㣬��ô�ҵ� ��ɾ�ڵ����һ�ڵ㣬����һ�ڵ��ֵ���������ٽ���һ�ڵ��next������ǰ�ڵ�
        node->val = pNext->val;
        node->next=pNext->next;
        delete pNext;
    }
};
