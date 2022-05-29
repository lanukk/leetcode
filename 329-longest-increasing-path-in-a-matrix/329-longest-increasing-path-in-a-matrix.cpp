class Solution {
public:
    
    //0 --> up
    //1 --> right
    //2 --> down
    //3 --> left
    
    int dp[202][202][4];
    int recursion(vector<vector<int>>&a, int &n, int &m, int i, int j){
        int ans = 0;
        
        
        if(dp[i][j][0] == -1){
            if(i - 1 >= 0 && a[i - 1][j] > a[i][j])
                dp[i][j][0] = 1 + recursion(a, n, m, i - 1, j);
            else
                dp[i][j][0] = 0;
        }
        
        if(dp[i][j][1] == -1){
            if(j + 1 < m && a[i][j + 1] > a[i][j])
                dp[i][j][1] = 1 + recursion(a, n, m, i, j + 1);
            else
                dp[i][j][1] = 0;
        }
        
        if(dp[i][j][2] == -1){
            if(i + 1 < n && a[i + 1][j] > a[i][j])
                dp[i][j][2] = 1 + recursion(a, n, m, i + 1, j);
            else
                dp[i][j][2] = 0;
        }
        
        if(dp[i][j][3] == -1){
            if(j - 1 >= 0 && a[i][j - 1] > a[i][j])
                dp[i][j][3] = 1 + recursion(a, n, m, i, j - 1);
            else 
                dp[i][j][3] = 0;
        }
        
        ans = max({dp[i][j][0], dp[i][j][1], dp[i][j][2], dp[i][j][3]});
        
        return ans;        
    }
    
    int longestIncreasingPath(vector<vector<int>>& a) {
        int n = (int)a.size();
        int m = (int)a[0].size();
        for(int i = 0; i <= n; i++)
            for(int j = 0; j <= m; j++)
                dp[i][j][0] = dp[i][j][1] = dp[i][j][2] = dp[i][j][3] = -1;
        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                ans = max(ans, 1 + recursion(a, n, m, i, j));
            }
        }
        return ans;
        
    }
};