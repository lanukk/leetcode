class Solution {
public:
    /*
    
    3 * 3
    
    (0, 0) --> (0, 1)
      |
      v
    (1, 0)
      
    */
    
    int dp[128][128];
    
    int recursion(int i, int j, int &n, int &m){
        
        if(i == n - 1 && j == m - 1)
            return 1;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        int ans = 0;
        if(i + 1 < n)
            ans += recursion(i + 1, j, n, m);
        if(j + 1 < m)
            ans += recursion(i, j + 1, n, m);
        
        return dp[i][j] = ans;
    }
    
    int uniquePaths(int m, int n) {
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                dp[i][j] = -1;
        
        return recursion(0, 0, m, n);
    }
};