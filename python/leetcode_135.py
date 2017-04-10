class Solution(object):
    def candy(self, ratings):
        n=len(ratings)-1
        total,cur,gap,flag=1,1,1,0
        i=1
        while i<=n:
            if ratings[i]>ratings[i-1]:
                flag=1
                if cur>1:
                    total-=(gap-1)*(cur-1)
                elif cur<1:
                    total+=gap*(1-cur)
                cur=1
                gap=1
                while(i<=n)and(ratings[i]>ratings[i-1]):
                    cur+=1
                    total=total+cur
                    i+=1
            elif ratings[i]<ratings[i-1]:
                flag=-1
                gap=1
                while(i<=n)and(ratings[i]<ratings[i-1]):
                    i+=1
                    gap+=1
                    cur-=1
                    total+=cur
            else:
                flag=0
                if cur>1:
                    total-=(gap-1)*(cur-1)
                elif cur<1:
                    total+=gap*(1-cur)
                cur,gap=1,1
                while(i<=n)and(ratings[i]==ratings[i-1]):
                    i+=1
                    total+=cur
        if flag==-1:
            if cur>1:
                total-=(gap-1)*(cur-1)
            elif cur<1:
                total+=gap*(1-cur)
        return total

class Solution(object):
    def candy(self, ratings):
        n=len(ratings)
        candy=[1]*n
        for i in xrange(1,n):
            if ratings[i]>ratings[i-1]:
                candy[i]=candy[i-1]+1
        total=candy[n-1]
        for i in reversed(xrange(n-1)):
            cur=1
            if ratings[i]>ratings[i+1]:
                cur=candy[i+1]+1
            total+=max(cur,candy[i])
            candy[i]=cur
        return total

class Solution(object):
    def candy(self, ratings):
        n=len(ratings)-1
        total,cur,gap=1,1,1
        i=1
        while i<=n:
            if ratings[i]>ratings[i-1]:
                cur=1
                gap=1
                while(i<=n)and(ratings[i]>ratings[i-1]):
                    cur+=1
                    total=total+cur
                    i+=1
            elif ratings[i]<ratings[i-1]:
                flag=-1
                gap=1
                while(i<=n)and(ratings[i]<ratings[i-1]):
                    i+=1
                    gap+=1
                    cur-=1
                    total+=cur
                if cur>1:
                    total-=(gap-1)*(cur-1)
                elif cur<1:
                    total+=gap*(1-cur)
            else:
                cur,gap=1,1
                while(i<=n)and(ratings[i]==ratings[i-1]):
                    i+=1
                    total+=cur
        return totals