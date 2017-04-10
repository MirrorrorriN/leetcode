class Solution
{
public:
	string convert(string s,int numRows)
	{
		if(numRows<=1)
        return s;
		//vetor<string> matrix(numRows);
		vector<string> row_strs(numRows);
        int  flag=0;
        for(int i=0;i<s.size();i++)
		{
			row_strs[flag]+=s[i];
		    if(i/(numRows-1)%2==0)
				flag++;
			else flag--;
		}
		string result;
		for (int i=0;i<numRows;i++)
			result+=row_strs[i];
		return result;
		//for (string & str:row_strs)
        //   result += str;
        //return result;
	}
};