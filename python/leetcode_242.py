class Solution(object):
    def isAnagram(self,s,t):
        return sorted(str(s)) == sorted(str(t))

class Solution(object):
    def isAnagram(self,s,t):
        dic={}
        for ch in s:
            dic[ch]=dic.get(ch,0)+1
        for key in t:
            if (not key in dic):
                return False
            dic[key]-=1
            if dic[key]==0:
                del dic[key]
        if len(dic):
            return False
        return True

class Solution(object):
    def isAnagram(self,s,t):
        dic1={}
        dic2={}
        for ch in s:
            dic1[ch]=dic1.get(ch,0)+1
        for ch in t:
            dic2[ch]=dic2.get(ch,0)+1
        if (len(dic1)!=len(dic2)):
            return False
        for key in dic1:
            if (not key in dic2) or (dic1[key]!=dic2[key]):
                return False
        return True
