/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    private TreeNode first=null;
    private TreeNode second=null;
    public void recoverTree(TreeNode root) {
        TreeNode prev=null;
        inOrder(root,prev);
        int tmp=first.val;
        first.val=second.val;
        second.val=tmp;
    }
    private void inOrder(TreeNode root,TreeNode prev){
        if(root==null){
            return;
        }
        inOrder(root.left,prev);
        if(prev!=null&&prev.val>root.val){
            if(first==null){
                first=prev;
            }
            second=root;
        }
        prev=root;
        inOrder(root.right,prev);
    }
}