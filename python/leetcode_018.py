class Solution(object):
    def fourSum(self,nums,target):
        nums.sort()
        dic={}
        n=len(nums)
        result=[]
        for i in reversed(range(3,n)):
            if (i==n-1) or (nums[i]!=nums[i+1]):
                for j in reversed(range(2,i)):
                    if (j==i-1) or (nums[j]!=nums[j+1]):
                        temp=nums[i]+nums[j]
                        dic[temp]=dic.get(temp,[])+[[j,i]]
        for i in range(0,n-3):
            if (i==0) or (nums[i]!=nums[i-1]):
                for j in range(i+1,n-2):
                    if (j==i+1) or (nums[j]!=nums[j-1]):
                        if target-nums[i]-nums[j] in dic:
                            for index in (dic[target-nums[i]-nums[j]]):
                                if index[0]>j:
                                    result.append([nums[i],nums[j],nums[index[1]],nums[index[0]]])
        return result
if __name__=="__main__":
    nums=[1,0,-1,0,-2,2]
    target=0
    x=Solution()
    ans=x.fourSum(nums,target)
    print ans
