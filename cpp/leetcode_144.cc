#include<iostream>
#include<vector>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
#include<iostream>
#include<vector>
#include<stack>
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> nums;
        if(root==nullptr){
            return nums;
        }
        TreeNode* curr=root;
        stack<TreeNode*> s;
        while(!s.empty()||curr!=nullptr){
            while(curr!=nullptr){
                nums.push_back(curr->val);
                s.push(curr);
                curr=curr->left;
            }
            if(!s.empty()){
                curr=s.top()->right;
                s.pop();
            }
        }
        return nums;
    }
};