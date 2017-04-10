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
    int minDepth(TreeNode* root) {
        if (!root) return 0;
        deque<TreeNode*> activeNode;
        root->val=1;
        activeNode.push_back(root);
        int ans;
        while(1){
            TreeNode* cur=new TreeNode(0);
            cur=activeNode.front();
            ans=cur->val;
            if (cur->left==NULL && cur->right==NULL){
                return ans;
            }
            if(cur->left) {
                activeNode.push_back(cur->left);
                cur->left->val=ans+1;
            }
            if(cur->right){
                activeNode.push_back(cur->right);
                cur->right->val=ans+1;
            }
            activeNode.pop_front();
        }
    }
};