class Solution {
public:
    int dp[128];
    int recursion(string &s, int i){
        if(i == s.length())
            return 1;
        
        if(s[i] == '0')
            return 0;
        
        if(dp[i] != -1)
            return dp[i];
        
        int ans = recursion(s, i + 1);
        
        if(i + 1 < s.length()){
            if(s[i] == '1'){
                ans += recursion(s, i + 2);
            } else if(s[i] == '2' && s[i + 1] <= '6'){
                ans += recursion(s, i + 2);
            }
        }
        
        return dp[i] = ans;
    }
    
    int numDecodings(string s) {
        for(int i = 0; i <=(int)s.length(); i++)
            dp[i] = -1;
        return recursion(s, 0);
    }
};