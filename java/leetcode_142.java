/**
 * Definition for singly-linked list. class ListNode { int val; ListNode next;
 * ListNode(int x) { val = x; next = null; } }
 */
public class Solution {
    public ListNode detectCycle(ListNode head) {
        if (head == null) {
            return null;
        }
        ListNode p = head;
        ListNode q = head;
        boolean flag = false;
        while (p != null && q != null && q.next != null) {
            if (q.next != null) {
                p = p.next;
                q = q.next.next;
                if (p == q) {
                    flag = true;
                    break;
                }
            }
        }
        if (!flag) {
            return null;
        }
        p = head;
        while (p != q) {
            p = p.next;
            q = q.next;
        }
        return p;
    }
}
