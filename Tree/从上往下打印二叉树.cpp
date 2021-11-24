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
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        
        queue<TreeNode*> q;
        vector<int> res;
        if (root==NULL) return res;
        q.push(root);
        while(q.size()){
            for(int i=0;i<q.size();i++){
                TreeNode* node=q.front();
                q.pop();
                res.push_back(node->val);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
        }
        return res;
    }
};
