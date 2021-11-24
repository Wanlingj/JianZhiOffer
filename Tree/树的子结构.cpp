/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    // 函数返回子树 p1 和 p2 是否有相同结构
    bool isSub(TreeNode* p1, TreeNode* p2) {
        if (!p2) return true;
        else if (!p1) return false;
 
        // p1 和 p2 的根节点相同并且 p1 和 p2 的左子树和右子树分别相同
        return p1->val == p2->val && isSub(p1->left, p2->left) && isSub(p1->right, p2->right);
     }
 
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2) {
        if (!pRoot1 || !pRoot2) return false;
        // p1 和 p2 结构相同，或者 p1 左子树或者右子树中有 p2
         return isSub(pRoot1, pRoot2) || HasSubtree(pRoot1->left, pRoot2) || HasSubtree(pRoot1->right, pRoot2);
 
    }
};
