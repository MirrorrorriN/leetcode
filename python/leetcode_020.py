class Solution(object):

    def isValid(self, s):
        stack=[]
        n=-1
        dic1='([{';
        dic2=')]}';
        for i in range(len(s)):
            if (s[i] in dic1):
                if n==-1 or (stack[n] in dic1):
                    stack.append(s[i])
                    n+=1
                else:
                    return False
            else:
                if n==-1:
                    return False
                if (stack[n]=='(' and s[i]==')') or (stack[n]=='[' and s[i]==']') or (stack[n]=='{' and s[i]=='}'):
                    stack.pop()
                    n-=1
                else:
                    return False
        if n!=-1:
            return False
        return True