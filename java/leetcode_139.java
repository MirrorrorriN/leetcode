class Solution {
    public boolean wordBreak(String s, List<String> wordDict) {
        Set<String> dict=new HashSet<>();
        for(String word:wordDict){
            dict.add(word);
        }
        int N=s.length();
        boolean[] dp=new boolean[N+1];
        dp[0]=true;
        for(int i=1;i<=N;i++){
            for(int j=0;j<i;j++){
                if(dp[j]&&dict.contains(s.substring(j,i))){
                    dp[i]=true;
                    break;
                }
            }
        }
        return dp[N];
    }
}