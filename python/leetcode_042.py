class Solution(object):
    def trap(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        trap=0
        n=len(height)
        water=[0]*n
        for i in xrange(1,n-1):
            if height[i]<height[i-1]:
                water[i]=water[i-1]+height[i-1]-height[i]
            else:
                water[i]=max(water[i-1]-(height[i]-height[i-1]),0)
        cur=0
        for i in reversed(xrange(n-1)):
            if height[i]<height[i+1]:
                cur+=height[i+1]-height[i]
                trap+=min(water[i],cur)  
            else:
                cur=max(cur-(height[i]-height[i+1]),0)
                trap+=min(water[i],cur)  
        return trap