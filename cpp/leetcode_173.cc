#include<iostream>
#include<stack>
using namespace std;
/**
 * Definition for a binary tree node.
 */
 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class BSTIterator {
private:
    TreeNode* curr;
    stack<TreeNode*> s;
public:
    BSTIterator(TreeNode* root) {
        this->curr=root;
    }
    
    /** @return the next smallest number */
    int next() {
        while(this->curr!=nullptr||!s.empty()){
            while(this->curr!=nullptr){
                this->s.push(this->curr);
                this->curr=this->curr->left;
            }
            if(!s.empty()){
                TreeNode* now=s.top();
                this->s.pop();
                this->curr=now->right;;
                return now->val;
            }
        }
        return -1;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        if(curr!=nullptr||!s.empty()){
            return true;
        }
        return false;
    }
};