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
    vector<int> inorderTraversal(TreeNode* root) {
        if(!root) return {};
        vector<int> res;
        stack<TreeNode*> s;
        TreeNode* cur=root;
        while(cur!=NULL||!s.empty()){
            while(cur!=NULL){
                s.push(cur);
                cur=cur->left;
            }
            if(!s.empty()){
                cur=s.top();
                res.push_back(cur->val);
                s.pop();
                cur=cur->right;
            }
        }
        return res;
    }
};