class Solution(object):
    def kthsmallest(self,a,b,m,n,k):
        if (m == 0):
            return b[k - 1]
        if (n == 0):
            return a[k - 1]
        if (k == 1):
            return min(a[0],b[0])
        if (k == m + n):
            return max(a[m - 1], b[n - 1])
        i = int(math.floor(m/ (m + n) * (k - 1)))
        j = k - 1 - i
        if (j >= n):
            j = n - 1
            i = k - n
        if (((i == 0) or(a[i - 1] <= b[j])) and (b[j] <= a[i])):
            return b[j]
        if (((j == 0) or (b[j - 1] <= a[i])) and (a[i] <= b[j])):
            return a[i]
        if (a[i] <= b[j]):
            return self.kthsmallest(a [i + 1:],b,m - i - 1, j, k - i - 1)
        else:
            return self.kthsmallest(a, b[j+1:],i,n - j - 1, k - j - 1)
    def findMedianSortedArrays(self, nums1, nums2):
        if(len(nums1)+len(nums2))%2==1:
            median=self.kthsmallest(nums1,nums2,len(nums1),len(nums2),len(nums1+nums2)/2+1)
        else:
            median=(self.kthsmallest(nums1,nums2,len(nums1),len(nums2),len(nums1+nums2)/2)
            +self.kthsmallest(nums1,nums2,len(nums1),len(nums2),len(nums1+nums2)/2+1))/2.0
        return median

        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: float
        """
        