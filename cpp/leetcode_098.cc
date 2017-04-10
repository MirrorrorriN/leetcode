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
    bool isValidBST(TreeNode* root) {
        return isValidBST(root,NULL,NULL);
    }
    bool isValidBST(TreeNode* root,TreeNode* maxNode,TreeNode* minNode){
        if(root==nullptr) return true;
        if((minNode && root->val<=minNode->val)||(maxNode&&root->val>=maxNode->val)) return false;
        return isValidBST(root->left,root,minNode)&&isValidBST(root->right,maxNode,root);
    }
};