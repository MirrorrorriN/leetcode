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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int> > paths;
        vector<int> path;
        findPaths(root, sum, path, paths);
        return paths;  
    }
private:
    void findPaths(TreeNode* node, int sum, vector<int>& path, vector<vector<int> >& paths) {
        if (!node) return;
        path.push_back(node -> val);
        if (!(node -> left) && !(node -> right) && sum == node -> val)
            paths.push_back(path);
        findPaths(node -> left, sum - node -> val, path, paths);
        findPaths(node -> right, sum - node -> val, path, paths);
        path.pop_back();
    }
};

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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int> > res{};
        if (root==nullptr) return res;
        stack<TreeNode*> branch;
        stack<int> value;
        stack<vector<int> > path;
        branch.push(root);
        value.push(sum);
        path.push({root->val});
        while(!branch.empty()){
            TreeNode* pos=branch.top();
            int cur=value.top();
            vector<int> curPath=path.top();
            branch.pop();
            value.pop();
            path.pop();
            if(pos->left){
                branch.push(pos->left);
                value.push(cur-pos->val);
                vector<int> newPath=curPath;
                newPath.push_back(pos->left->val);
                path.push(newPath);
            }
            if(pos->right){
                branch.push(pos->right);
                value.push(cur-pos->val);
                vector<int> newPath=curPath;
                newPath.push_back(pos->right->val);
                path.push(newPath);
            }
            if(!pos->left && !pos->right && pos->val==cur) res.push_back(curPath);
        }
        return res;
    }
};