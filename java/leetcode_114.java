/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */

// interesting problem (optimal solution to be study)
class Solution {
    private TreeNode nextRight=null;
    public void flatten(TreeNode root) {
        if(root==null) return;
        flatten(root.right);
        flatten(root.left);
        root.left=null;
        root.right=nextRight;
        nextRight=root;
    }
    
}