class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = (int)nums.size();
        int dp[2505] = {0};
        dp[0] = 1;
        int ans = 1;
        
        for(int i = 1; i < n; i++){
            int maxx = 1;
            for(int j = 0; j < i; j++){
                if(nums[j] < nums[i])
                    maxx = max(maxx, dp[j] + 1);
            }
            dp[i] = maxx;
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};