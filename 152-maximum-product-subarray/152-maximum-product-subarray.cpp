class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int bestAns = nums[0];
        int currentProduct = 1;
        for(int i : nums){
            currentProduct *= i;
            bestAns = max(bestAns, currentProduct);
            
            if(i == 0){
                currentProduct = 1;
            }
        }
        currentProduct = 1;
        reverse(nums.begin(), nums.end());
        
        for(int i : nums){
            currentProduct *= i;
            bestAns = max(bestAns, currentProduct);
            
            if(i == 0){
                currentProduct = 1;
            }
        }
        
        return bestAns;
    }
};