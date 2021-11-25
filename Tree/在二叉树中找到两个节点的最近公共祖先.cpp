/**
 * struct TreeNode {
 *	int val;
 *	struct TreeNode *left;
 *	struct TreeNode *right;
 * };
 */

class Solution {
public:
    /**
     * 
     * @param root TreeNode类 
     * @param o1 int整型 
     * @param o2 int整型 
     * @return int整型
     */
    int lowestCommonAncestor(TreeNode* root, int o1, int o2) {
        // write code here
         return helper(root, o1, o2)->val;
    }
    TreeNode* helper(TreeNode* root, int o1, int o2) {
    if (root == NULL || root->val == o1 || root->val == o2)
        return root;
    TreeNode* left = helper(root->left, o1, o2);
    TreeNode* right = helper(root->right, o1, o2);
    //如果left为空，说明这两个节点在root结点的右子树上，我们只需要返回右子树查找的结果即可
    if (left == NULL)
        return right;
    //同上
    if (right == NULL)
        return left;
    //如果left和right都不为空，说明这两个节点一个在root的左子树上一个在root的右子树上，
    //我们只需要返回cur结点即可。
    return root;
    }
};
