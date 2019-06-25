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
    public int sumNumbers(TreeNode root) {
        if(root==null) return 0;
        return sumTmp(root,root.val);
    }
    private int sumTmp(TreeNode root,int currSum){
        if(root.left==null&&root.right==null){
            return currSum;
        }
        if(root.left==null){
            return sumTmp(root.right,currSum*10+root.right.val);
        }
        if(root.right==null){
            return sumTmp(root.left,currSum*10+root.left.val);
        }
        currSum*=10;
        return sumTmp(root.left,currSum+root.left.val)+sumTmp(root.right,currSum+root.right.val);
    }
}