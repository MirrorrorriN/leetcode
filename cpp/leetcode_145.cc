#include<iostream>
#include<vector>
#include<stack>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> nums;
        stack<TreeNode*> s;
        TreeNode* curr=root;
        TreeNode* last_visit=nullptr;
        while(curr!=nullptr||!s.empty()){
            while(curr!=nullptr){
                s.push(curr);
                curr=curr->left;
            }
            curr=s.top();
            if(curr->right==nullptr||curr->right==last_visit){
                nums.push_back(curr->val);
                last_visit=curr;
                s.pop();
                curr=nullptr;
            }else{
                curr=curr->right;
            }
        }
        return nums;
    }
};