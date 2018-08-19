/*
struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {

    }
};
*/
// �������������һ�ڵ����⣬��Ϊ��ڵ㡢�ҽڵ㿼�ǣ����ڳ������д���Ͻ���Ҫ��ϸߣ���
class Solution {
public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode)
    {
        if(pNode == NULL) return NULL;
        TreeLinkNode* pNext = NULL;
        if(pNode->right!=NULL){
            pNext = pNode->right;
            while(pNext->left!=NULL) pNext = pNext->left;
        }
        else if(pNode->next!=NULL){ // ��һ���˼·���Ͻ�����
            TreeLinkNode* p_parent = pNode->next;
            pNext = pNode;
            while(p_parent!=NULL && pNext==p_parent->right){
                p_parent = p_parent->next;
                pNext = pNext->next;
            }
            pNext = p_parent;
            //delete p_parent;
        }
        return pNext;
    }
};
