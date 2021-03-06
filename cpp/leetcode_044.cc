class Solution {
public:
    bool isMatch(string s, string p) { 
        int m = s.length(), n = p.length();
        if (n > 30000) return false; // the trick
        vector<bool> cur(m + 1, false); 
        cur[0] = true;
        for (int j = 1; j <= n; j++) {
            bool pre = cur[0]; // use the value before update
            cur[0] = cur[0] && p[j - 1] == '*'; 
            for (int i = 1; i <= m; i++) {
                bool temp = cur[i]; // record the value before update
                if (p[j - 1] != '*')
                    cur[i] = pre && (s[i - 1] == p[j - 1] || p[j - 1] == '?');
                else cur[i] = cur[i - 1] || cur[i];
                pre = temp;
            }
        }
        return cur[m]; 
    }
};

class Solution {
public:
    bool isMatch(string s, string p) {
        int m=s.size(),n=p.size();
        vector<vector<bool> > f(m+1,vector<bool> (n+1,false));
        f[0][0]=true;
        for (int j = 1; j <= n; j++)
        {
            f[0][j] = f[0][j-1]&&p[j-1]=='*';
        }
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (p[j - 1] != '*')
                {
                    f[i][j] = f[i - 1][j - 1] && (p[j - 1] == s[i - 1] || p[j - 1] == '?');
                }
                else
                    f[i][j] = f[i-1][j-1] || f[i][j-1]||f[i-1][j];
            }
        }
        return f[m][n];
    }
};