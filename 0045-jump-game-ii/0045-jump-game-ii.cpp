class Solution {
public:
    int jump(vector<int>& nums) {
        int maxTravelled = -1;
        int n = (int)nums.size();
        vector<int> dp(n);
        
        for(int i = 0; i < n; i++){
            int lower_bound = i + 1;
            int upper_bound = min(n - 1, i + nums[i]);
            
            if(lower_bound <= maxTravelled){
                lower_bound = maxTravelled + 1;
            }
            while(lower_bound <= upper_bound){
                dp[lower_bound] = dp[i] + 1;
                lower_bound++;
            }
            maxTravelled = max(maxTravelled, upper_bound);
        }
        return dp[n - 1];
    }
};