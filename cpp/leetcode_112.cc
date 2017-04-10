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
    bool hasPathSum(TreeNode* root, int sum) {
        if (root==nullptr) return false;
        stack<TreeNode*> branch;
        stack<int> value;
        branch.push(root);
        value.push(sum);
        while(!branch.empty()){
            TreeNode* pos=branch.top();
            int cur=value.top();
            branch.pop();
            value.pop();
            if(pos->left){
                branch.push(pos->left);
                value.push(cur-pos->val);
            }
            if(pos->right){
                branch.push(pos->right);
                value.push(cur-pos->val);
            }
            if(!pos->left && !pos->right && pos->val==cur) return true;
        }
        return false;
    }
};