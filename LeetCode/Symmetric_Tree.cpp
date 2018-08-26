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
    bool Check(TreeNode* root1, TreeNode* root2){
        if(root1 == NULL && root2 == NULL) return true; // �����ָ���˿�ָ�룬˵���Ѿ�������Ҷ�ڵ㴦�Ҳ�δ������symmetic �����
        if(root1 == NULL || root2 == NULL) return false;
        if(root1->val != root2->val) return false;
        return Check(root1->left, root2->right) && Check(root1->right, root2->left); // ��ߺ��ұ߱ȶ� �Լ� �ұߺ���߱ȶ�
    }

    bool isSymmetric(TreeNode* root) {
        return Check(root, root);

    }
};
