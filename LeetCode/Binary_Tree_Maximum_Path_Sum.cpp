/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//�������ҵĸо���Ҫ�Եݹ����ñȽϺò��ܽ�����ʣ�Ȼ�������û������ر�� orz..
class Solution {
    int ans;
public:
    int maxPathCompute(TreeNode*root){
        if(!root) return 0;
        int left = maxPathCompute(root->left); //���شӵ�ǰ�ڵ���࿴����ֵ
        int right = maxPathCompute(root->right); //���شӵ�ǰ�ڵ���࿴����ֵ
        ans = max(ans,(max(0,left)+max(0,right)+root->val)); //�ȶ�ԭ�е����ֵ�͵�ǰ����·��ֵ
        return root->val+max(0,max(left,right)); //���ش�Ŀǰ�ڵ㿴 ����һ����ֵ
    }
    int maxPathSum(TreeNode* root) {
        ans=0x80000000; //��С�����ı�ʾ��ʽ
        maxPathCompute(root);
        return ans;
    }
};
