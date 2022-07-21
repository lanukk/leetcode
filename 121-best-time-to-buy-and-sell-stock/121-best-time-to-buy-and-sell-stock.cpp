class Solution {
public:
    /*
    
    1. if we buy a stock of price x: then our money = - x
    2. if we sell a stock of price y: then our money = y
    
    profit = y - x
    
    7 1 5 3 6 4
    
    recursion(int index, bool bought)
    
    intially, boolean bought == false.
    
    
    
    if(bought == false){
        buying   -> recursion(index + 1, 1) - nums[index]
        skipping -> recursion(index + 1, 0)
        
        return max(buying, skipping);
        
    } else {
        selling  -> nums[index]
        skipping -> recursion(index + 1, 1)
        
        return max(selling, skipping);
    }
    
    */
    
    int recursion(int index, bool bought, vector<int>& prices, vector<vector<int>>&dp){
        if(index == (int)prices.size())
            return 0;
        if(dp[index][bought] != -1)
            return dp[index][bought];
        
        if(bought == false){
            return dp[index][bought] = max(
                recursion(index + 1, 1, prices, dp) - prices[index],
                recursion(index + 1, 0, prices, dp)
            );
        } else {
            return dp[index][bought] = max(
                prices[index],
                recursion(index + 1, 1, prices, dp)
            );
        }
        return -1;
    }
    
    int maxProfit(vector<int>& prices) {
        vector<vector<int>>dp((int)prices.size(), vector<int>(2, -1));
        return recursion(0, false, prices, dp);
    }
};