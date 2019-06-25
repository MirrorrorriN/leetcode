import java.util.Set;

class Solution{
    public List<String> wordBreak(String s, List<String> wordDict) {
        Set<String> wordSet=new HashSet<>(wordDict);
        List<String> ans=new ArrayList<>();
        
    }
}

class Solution {
    public List<String> wordBreak(String s, List<String> wordDict) {
        Set<String> wordSet=new HashSet<>(wordDict);
        String curAns="";
        List<String> ans=new ArrayList<>();
        dfs(ans,curAns,0,s,wordSet);
        return ans;
    }
    private void dfs(List<String> ans,String curAns,int pos,String s,Set<String> wordSet){
        if(pos==s.length()){
            ans.add(curAns);
            return;
        }
        for(int i=pos+1;i<=s.length();i++){
            String curWord=s.substring(pos, i);
            if (wordSet.contains(curWord)){
                if(!curAns.isEmpty()){
                    curAns+=" ";
                }
                curAns+=curWord;
                dfs(ans,curAns,i,s,wordSet);
                curAns=curAns.substring(0,curAns.length()-curWord.length());
                if(!curAns.isEmpty()){
                    curAns=curAns.substring(0,curAns.length()-1);
                }
            }
            return;
        }
    }
}