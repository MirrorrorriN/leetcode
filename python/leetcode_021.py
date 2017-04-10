class Solution(object):
    def mergeTwoLists(self,l1,l2):
        if not l1:
            return l2
        if not l2:
            return l1
        p=l1
        q=l2
        if p.val>q.val:
            head=ListNode(q.val)
            q=q.next
        else:
            head=ListNode(p.val)
            p=p.next
        r=head
        while p and q:
            if p.val>q.val:
               temp=ListNode(q.val)
               q=q.next
            else:
               temp=ListNode(p.val)
               p=p.next
            r.next=temp
            r=r.next
        if p:
            while p:
                temp=ListNode(p.val)
                p=p.next
                r.next=temp
                r=r.next
        elif q:
            while q:
                temp=ListNode(q.val)
                q=q.next
                r.next=temp
                r=r.next
        return head
