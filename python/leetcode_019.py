# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None
class LinkList(object):
    def __init__(self):
        self.head=None
    def initlist(self,data):
        self.head=ListNode(data[0])
        p=self.head
        for i in (data[1:]):
            node=ListNode(i)
            p.next=node
            p=p.next

class Solution(object):
    def removeNthFromEnd(self, head, n):
        """
        :type head: ListNode
        :type n: int
        :rtype: ListNode
        """
        note=[]
        if (n<=0):
            return head
        p=head
        while p:
            note.append(p)
            p=p.next
        m=len(note)
        if (n>m):
            return head
        if (m==n):
            return head.next
        if (n==1):
            note[m-2].next=None
            #note[m-1]=None WA???
            return head
        note[m-n-1].next=note[m-n+1]
        return head
if __name__=="__main__":
    n=1
    data=[1,2]
    x=Solution()
    L=LinkList()
    L.initlist(data)
    head=L.head
    ans=x.removeNthFromEnd(L.head,n)
    
