class Solution(object):
    def intersect(self, nums1, nums2):
        a, b = map(collections.Counter, (nums1, nums2))
        return list((a & b).elements())

class Solution(object):
    def intersect(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: List[int]
        """
        dic1=dict()
        dic2=dict()
        m=len(nums1)
        n=len(nums2)
        i=0
        intersect=list()
        while ((i<m) or (i<n)):
        	if i<m:
        		if nums1[i] in dic2:
        			dic2[nums1[i]]-=1
        			intersect.append(nums1[i])
        			if dic2[nums1[i]]==0:
        				del dic2[nums1[i]]
        		else:
        			dic1[nums1[i]]=dic1.get(nums1[i],0)+1
        	if i<n:
        		if nums2[i] in dic1:
        			dic1[nums2[i]]-=1
        			intersect.append(nums2[i])
        			if dic1[nums2[i]]==0:
        				del dic1[nums2[i]]
        		else:
        			dic2[nums2[i]]=dic2.get(nums2[i],0)+1
        	i+=1
        return intersect