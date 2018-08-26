/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if(s == NULL) return false;
        if(Check(s, t)) return true; // ����s�ڵ��Լ� t�ڵ������Ƿ�Ϊһ������
        return isSubtree(s->left, t) || isSubtree(s->right, t); // �����s������������ ��s������������
    }

    bool Check(TreeNode* root1, TreeNode* root2){
        if(root2 == NULL && root1 == NULL) return true; // ����tΪs��Ҷ�ڵ㴦�������ſɣ�����Ϊ�м�һ���������͵�
        if(root1 == NULL || root2 == NULL) return false;
        if(root1->val != root2->val) return false;
        return Check(root1->left, root2->left) && Check(root1->right, root2->right);
    }
};
