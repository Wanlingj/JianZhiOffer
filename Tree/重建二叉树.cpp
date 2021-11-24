/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* root;
    vector<int> p,i;
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        // 判断这个二叉树的节点是否已经是叶子节点了
        if(pre.size()==0||vin.size()==0){
            return NULL;
        }
        // 不是叶子节点就进行向下递归的操作
        TreeNode* root=new TreeNode(pre[0]);
        for(int i=0;i<vin.size();i++){
            // 找到和当前的先序遍历的头节点权值一样的节点
            if(root->val==vin[i]){
                // 找到之后就利用中序遍历的序列将这个序列分为左右子序列
                vector<int> pre1,pre2,vin1,vin2;
                for(int j=1;j<i+1;j++){//i个是left nodes, starting from 2nd node
                    pre1.push_back(pre[j]);
                }
                for(int j=0;j<i;j++){//i个是left nodes, starting from 1st node
                    vin1.push_back(vin[j]);
                }
                for(int j=i+1;j<pre.size();j++){
                    pre2.push_back(pre[j]);
                }
                for(int j=i+1;j<vin.size();j++){
                    vin2.push_back(vin[j]);
                }
                // 进行递归的操作
                root->left=reConstructBinaryTree(pre1,vin1);
                root->right=reConstructBinaryTree(pre2,vin2);
                break;
            }
        }
        return root;
    }
};
