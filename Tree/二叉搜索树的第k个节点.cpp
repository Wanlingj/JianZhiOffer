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
     * @param proot TreeNode类 
     * @param k int整型 
     * @return int整型
     */
//     TreeNode *res = NULL;
//     void midOrder(TreeNode *proot, int &k) {
//         if(!proot || k < 0) return;
//         midOrder(proot->left, k);
//         k--;
//         if(k == 0) {
//             res = proot;
//             res->left = NULL;
//             res->right =NULL;
//         }
//         midOrder(proot->right, k);
//     }
//     int KthNode(TreeNode* proot, int k) {
//         // write code here
//         midOrder(proot, k);
//         return res->val;
//     }
    void preorder(vector<int> &v, TreeNode* proot) {
        if (proot == nullptr) return ; 
        v.push_back(proot->val); 
        preorder(v, proot->left); 
        preorder(v, proot->right); 
    } 
    int KthNode(TreeNode* proot, int k) {
        // write code here 
        if (proot == nullptr) return -1; 
        vector<int> v; 
        preorder(v,proot); 
        if (k < 1 || k > v.size()) 
            return -1; 
        sort (v.begin(), v.end()); 
        return v[k-1]; 
    } 
   
};
