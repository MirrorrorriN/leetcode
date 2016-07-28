#Definition for singly-linked list.

class ListNode(object):

    def __init__(self, x):

        self.val = x

        self.next = None
class LinkedList(object):
    def __init__(self,head):
        self.head=head
    def setList(self,nums):
        self.head=ListNode(nums[0])
        p=self.head
        for i in range(1,len(nums)):
            q=ListNode(nums[i])
            p.next=q
            p=p.next            
    def append(self):
        p=self.head
        nums=[]
        while p:
            nums.append(p.val)
            p=p.next
        return nums

class Solution(object):

    def deleteDuplicates(self, head):

        """

        :type head: ListNode

        :rtype: ListNode

        """
        if not head:
            return None
        p=head
        dic={}
        while p:
            if p.val in dic:
                dic[p.val]+=1
            else:
                dic[p.val]=1
            p=p.next
        p=head
        while p:
            if p.next and dic[p.next.val]>1:
                p.next=p.next.next
            else:
                p=p.next
        if dic[head.val]>1:
            head=head.next
            
        return head            
if __name__=="__main__":
    nums=[1,1,2,2,3,3,3,4,4,4,4,5,6,7,7,7]
    L=LinkedList(None)
    L.setList(nums)
    x=Solution()
    head=x.deleteDuplicates(L.head)
    nL=LinkedList(head)
    num=nL.append()
    print num
