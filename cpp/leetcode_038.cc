class Solution {
public:
    string next(string& pre)
    {
        int n=pre.length();
        int i=1;
        string succ;
        if (n==1) return "11";
        while(i<n)
        {
            int count=1;
            while((i<n)&&(pre[i-1]==pre[i]))
            {
                count++;
                i++;
            }
            succ=succ+char(count+'0')+pre[i-1];
            
            i++;
        }
        if (i==n) succ=succ+"1"+pre[i-1];
        
        return succ;
    }
    string countAndSay(int n) {
        string cur="1";
        for (int i=1;i<n;i++)
        {
            cur=next(cur);
        }
        return cur;
    }
};