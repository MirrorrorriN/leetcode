import java.util.ArrayList;
import java.util.List;

class Solution {
    public List<List<String>> partition(String s) {
        List<List<String>> ans=new ArrayList<>();
        boolean[][] dp=new boolean[s.length()][s.length()];
        for(int i=0;i<s.length();i++){
            for(int j=i;j<s.length();j++){
                if(isPalindrome(s.substring(i,j+1))){
                    dp[i][j]=true;
                }
            }
        }
        dfs(s,ans,new ArrayList<String>(), 0,dp);
        return ans;
    }

    private void dfs(String s,List<List<String>> curList, List<String> path,int pos,boolean[][] dp){
        if(pos==s.length()){
            curList.add(new ArrayList<>(path));
            return;
        }
        for(int i=pos;i<s.length();i++){
            if(dp[pos][i]){
                path.add(s.substring(pos,i+1));
                dfs(s,curList,path,i+1,dp);
                path.remove(path.size()-1);
            }
        }
    }
    
    private boolean isPalindrome(String s){
        int i=0;
        int j=s.length()-1;
        while(i<j){
            if(s.charAt(i)!=s.charAt(j)){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }

    public static void main(String[] args){
        Solution x=new Solution();
        x.partition("cbbbcc");
    }
}