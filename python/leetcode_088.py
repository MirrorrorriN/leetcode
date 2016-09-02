class Solution(object):
    def merge(self, nums1, m, nums2, n):
        """
        :type nums1: List[int]
        :type m: int
        :type nums2: List[int]
        :type n: int
        :rtype: void Do not return anything, modify nums1 in-place instead.
        """
        p=m-1
        q=n-1
        r=m+n-1
        if (p<0):
            for i in range(n):
                nums1[i]=nums2[i]
            return
        if (q<0):
            return
        while (r>=0)and(p>=0)and(q>=0):
            if nums1[p]>nums2[q]:
                nums1[r]=nums1[p]
                p-=1
            else:
                nums1[r]=nums2[q]
                q-=1
            r-=1
        if (q>=0):
            for i in range(q+1):
                nums1[i]=nums2[i]
        return
            
if __name__=="__main__":
    num1=[2,4,7,8]
    num2=[1,2,3,7]
    m=3
    n=4
    for i in range(n):
        num1.append(0)
    x=Solution()
    x.merge(num1,m,num2,n)
    print num1[:m+n]
