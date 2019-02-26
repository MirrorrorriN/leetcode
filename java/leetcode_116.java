/**
 * Definition for binary tree with next pointer.
 * public class TreeLinkNode {
 *     int val;
 *     TreeLinkNode left, right, next;
 *     TreeLinkNode(int x) { val = x; }
 * }
 */
public class Solution {
    public Node connect(Node root){
        preOrder(root);
        return root;
    }

    private void preOrder(Node root){
        if(root==null){
            return;
        }
        if(root.left!=null){
            root.left.next=root.right;
            if(root.next!=null){
                root.right.next=root.next.left;
            }
        }
        preOrder(root.left);
        preOrder(root.right);
    }
}