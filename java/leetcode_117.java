/*
// Definition for a Node.
class Node {
    public int val;
    public Node left;
    public Node right;
    public Node next;

    public Node() {}

    public Node(int _val,Node _left,Node _right,Node _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
*/
class Solution {
    public Node connect(Node root) {
        if(root==null){
            return root;
        }
        Node prev=null;
        if(root.left!=null){
            prev=root.left;
            if(root.right!=null){
                root.left.next=root.right;
                prev=root.right;
            }
        }else if(root.right!=null){
            prev=root.right;
        }
        Node nextN=root.next;
        while(prev!=null&&nextN!=null){
            if(nextN.left!=null){
                prev.next=nextN.left;
                break;
            }else if(nextN.right!=null){
                prev.next=nextN.right;
                break;
            }
            nextN=nextN.next;
        }
        connect(root.right);
        connect(root.left);
        return root;
    }
}

