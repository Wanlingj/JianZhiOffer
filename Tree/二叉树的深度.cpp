/*

描述
输入一棵二叉树，求该树的深度。从根结点到叶结点依次经过的结点（含根、叶结点）形成树的一条路径，最长路径的长度为树的深度，根节点的深度视为 1 。

数据范围：节点的数量满足 0 \le n \le 1000≤n≤100 ，节点上的值满足 0 \le val \le 1000≤val≤100
进阶：空间复杂度 O(1)O(1) ，时间复杂度 O(n)O(n)

假如输入的用例为{1,2,3,4,5,#,6,#,#,7}，那么如下图:
示例1
输入：
{1,2,3,4,5,#,6,#,#,7}

返回值：
4

示例2
输入：
{}
返回值：
0

*/
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
    
    int TreeDepth(TreeNode* pRoot) {
        if (!pRoot) return 0;
        int lval = TreeDepth(pRoot->left);
        int rval = TreeDepth(pRoot->right);
        return max(lval, rval) + 1;
    }
};
