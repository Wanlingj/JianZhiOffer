/**
 * struct TreeNode {
 *	int val;
 *	struct TreeNode *left;
 *	struct TreeNode *right;
 *	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * };
 */
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param pRoot TreeNode类 
     * @return TreeNode类
     */
    TreeNode* Mirror(TreeNode* pRoot) {
        // write code here
        if (pRoot==NULL) return NULL;
        TreeNode* tmp=pRoot->left;
        pRoot->left=pRoot->right;
        pRoot->right = tmp;
        if(pRoot->left) pRoot->left=Mirror(pRoot->left);
        if(pRoot->right) pRoot->right=Mirror(pRoot->right);
        return pRoot;
    }
};
