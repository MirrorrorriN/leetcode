/*
 * @lc app=leetcode id=124 lang=java
 *
 * [124] Binary Tree Maximum Path Sum
 */
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
    class Res{
        private int finalRes;
        Res(int finalRes){

        }
        public int getFinalRes(){
            return this.finalRes;
        }
        public void setFinalRes(int finalRes){
            this.finalRes=finalRes;
        }
    }
    public int maxPathSum(TreeNode root) {
        Res res=new Res(Integer.MIN_VALUE);
        this.helpler(root,res);
        return res.getFinalRes();
    }

    public int helpler(TreeNode node,Res res){
        if(node==null){
            return 0;
        }
        int left=Math.max(this.helpler(node.left, new Res(res.getFinalRes())),0);
        int right=Math.max(this.helpler(node.right, new Res(res.getFinalRes())),0);
        res.setFinalRes(Math.max(res.getFinalRes(),left+right+node.val));
        return Math.max(left, right)+node.val;
    }
}

