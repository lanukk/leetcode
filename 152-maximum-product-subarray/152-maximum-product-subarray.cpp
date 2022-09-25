class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int negativeSubarray = 1;
        int currentAns = 1;
        int bestAns = nums[0];
        
        for(int i : nums){
            if(i == 0){
                currentAns = 1;
                negativeSubarray = 1;
                
                bestAns = max(bestAns, 0);
                continue;
            }
            
            currentAns *= i;
            if(currentAns < 0){
                currentAns *= negativeSubarray;
                if(currentAns < 0){
                    negativeSubarray = currentAns;
                    currentAns = 1;
                    continue;
                } else {
                    negativeSubarray = 1;
                }
            }
            
            bestAns = max(bestAns, currentAns);
        }
        
        reverse(nums.begin(), nums.end());
        negativeSubarray = 1;
        currentAns = 1;
        
        for(int i : nums){
            if(i == 0){
                currentAns = 1;
                negativeSubarray = 1;
                
                bestAns = max(bestAns, 0);
                continue;
            }
            
            currentAns *= i;
            if(currentAns < 0){
                currentAns *= negativeSubarray;
                if(currentAns < 0){
                    negativeSubarray = currentAns;
                    currentAns = 1;
                    continue;
                } else {
                    negativeSubarray = 1;
                }
            }
            
            bestAns = max(bestAns, currentAns);
        }
        
        return bestAns;        
    }
};