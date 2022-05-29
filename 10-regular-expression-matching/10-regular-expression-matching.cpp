class Solution {
public:
    int dp[32][32];
    int recursion(string &s, string &p, int i, int j){
        if(i >= s.length() && j >= p.length())
            return 1;
        if(i >= s.length())
            return 0;
        if(j == p.length()){
            if(s[i] == '*')
                return recursion(s, p, i + 2, j);
            return 0;
        }
        if(dp[i][j] != -1)
            return dp[i][j];
         
        if(s[i] == '.')
            return dp[i][j] = recursion(s, p, i + 1, j + 1);
        
        if(s[i] != '*'){
            if(s[i] == p[j])
                return dp[i][j] = recursion(s, p, i + 1, j + 1);
            return dp[i][j] = 0;
        }
        
        bool ans = recursion(s, p, i + 2, j);

        while(j < p.length() && (s[i + 1] == '.' || s[i + 1] == p[j])){
            j++;
            ans = (ans | recursion(s, p, i + 2, j));
        }   
        
        return dp[i][j] = ans;
    }
    
    bool isMatch(string s, string p) {
        reverse(s.begin(), s.end());
        reverse(p.begin(), p.end());
        swap(s, p);
        memset(dp, -1, sizeof(dp));
        return recursion(s, p, 0, 0);
    }
};