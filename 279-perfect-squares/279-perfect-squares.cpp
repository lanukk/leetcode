class Solution {
public:
    
    int dp[10002][200];
    
    int recursion(vector<int>&nums, int n, int i){
        if(n == 0)
            return 0;
        
        if(n - nums[i] < 0)
            return 1e5;
        
        if(dp[n][i] != -1)
            return dp[n][i];
        
        return dp[n][i] =  min(1 + recursion(nums, n - nums[i], i), recursion(nums, n, i + 1));        
    }
    
    int numSquares(int n) {
        vector<int> nums;
        int p = 1;
        while(p*p <= 1e4){
            nums.push_back(p * p);
            p++;
        }
        
        for(int i = 0; i <= n; i++){
            for(int j = 0; j <= (int)nums.size(); j++){
                dp[i][j] = -1;
            }
        }
        
        int ans = recursion(nums, n, 0);
        if(ans == 1e5)
            ans = -1;
        
        return recursion(nums, n, 0);
    }
};