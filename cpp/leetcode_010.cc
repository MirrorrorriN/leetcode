class Solution {
public:
	bool isMatch(string s, string p) {
		int m = s.size(), n = p.size();
		vector<vector<bool>> f(m + 1, vector<bool>(n + 1, false));
		f[0][0] = true;
		// 默认值全false，不需要再处理一遍
		// for (int i = 1; i <= m; i++)
		// {
		// 	f[i][0] = false;
		// }
		
		for (int j = 1; j <= n; j++)
		{
			f[0][j] = j > 1 && p[j - 1] == '*' && f[0][j - 2];
		}
		for (int i = 1; i <= m; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (p[j - 1] != '*')
				{
					f[i][j] = f[i - 1][j - 1] && (p[j - 1] == s[i - 1] || p[j - 1] == '.');
				}
				else
				    // j>1条件其实不需要（j==1时后续条件不可能成立）加上能短路判断更快
					f[i][j] = j>1 && (f[i][j - 2] || (s[i - 1] == p[j - 2] || p[j - 2] == '.') && f[i - 1][j]);
			}
		}
		return f[m][n];
	}
};