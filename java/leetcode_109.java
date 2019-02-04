/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
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
    public TreeNode sortedListToBST(ListNode head) {
        if(head==null){
            return null;
        }
        if(head.next==null){
            TreeNode subTree= new TreeNode(head.val);
            return subTree;
        }
        ListNode p=head;
        ListNode q=head;
        ListNode pre=new ListNode(0);
        //前置节点
        pre.next=head;
        while(q.next!=null&&q.next.next!=null){
            p=p.next;
            //快慢指针
            q=q.next.next;
            pre=pre.next;
        } 
        TreeNode tree=new TreeNode(p.val);
        // 处理左子树为空的特殊情况
        if(pre.next==head){
            head=null;
        }
        tree.right=sortedListToBST(p.next);
        pre.next=null;
        tree.left=sortedListToBST(head);
        return tree;
    }
}
