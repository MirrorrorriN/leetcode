class Solution {
public:
    int lengthOfLastWord(string s) {
        int n=s.length();
        int ans=0;
        for(int i=n-1;i>=0;i--)
        {
            if(s[i]!=' ')
            {
                while(i>=0 && s[i]!=' '){
                    ans++;
                    i--;
                }
                break;
            }
        }
        return ans;
    }
    
};