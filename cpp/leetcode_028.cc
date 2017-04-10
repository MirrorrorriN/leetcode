class Solution {
public:
	vector<int> next;
	int strStr(string haystack, string needle) {
		int m = haystack.length(), n = needle.length();
		if (n == 0) return 0;
		if (m == 0) return -1;
		for (int i = 0; i < m; i++)
		{
			next.push_back(-1);
		}
		getNext(needle);
		int i = 0, j = 0;
		while (i < m && j < n)
		{
			if (j == -1 || haystack[i] == needle[j])
			{
				i++; j++;
			}
			else j = next[j];
		}
		if (j == n)
			return i - j;
		else return -1;
		
	}
	
	void getNext(string needle)
	{
		next[0] = -1;
		int j = -1, i = 0;
		while (i < needle.length())
		{
			if (-1 == j || needle[i] == needle[j])
			{
				i++; j++;
				next[i] = j;
			}
			else
				j = next[j];
		}
	}
		
};
