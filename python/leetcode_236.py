# Definition for a binary tree node.

class TreeNode(object):

    def __init__(self, x,left = None,right = None):

        self.val = x

        self.left = left

        self.right = right



class Solution(object):

    def lowestCommonAncestor(self, root, p, q):

        """

        :type root: TreeNode

        :type p: TreeNode

        :type q: TreeNode

        :rtype: TreeNode

        """
        """
        if root in (None,p,q):
            return root
        left,right = (self.lowestCommonAncestor(kid,p,q) 
                      for kid in (root.left,root.right))
        return root if left and right else left or right
        """
        if root in (None,p,q):
            return root
        left=self.lowestCommonAncestor(root.left,p,q)
        right=self.lowestCommonAncestor(root.right,p,q)
        if left and right:
            return root
        return left or right
if __name__=="__main__":
    d=TreeNode(4)
    e=TreeNode(5)
    b=TreeNode(2,d,e)
    c=TreeNode(3)
    root=TreeNode(1,b,c)
    
    x=Solution()
    ans=x.lowestCommonAncestor(root,b,e)
    print ans.val
