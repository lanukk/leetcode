class Solution {
public:
    
    int dp[10002][128];
    
    int recursion(int n, int i){
        if(n == 0)
            return 0;
        
        if(n - i * i < 0)
            return 1e5;
        
        if(dp[n][i] != -1)
            return dp[n][i];
        
        return dp[n][i] =  min(1 + recursion(n - i * i, i), recursion(n, i + 1));        
    }
    
    int numSquares(int n) {
        for(int i = 0; i <= n; i++){
            for(int j = 0; j < 128; j++){
                dp[i][j] = -1;
            }
        }
        
        int ans = recursion(n, 1);
        if(ans == 1e5)
            ans = -1;
        
        return ans;
    }
};