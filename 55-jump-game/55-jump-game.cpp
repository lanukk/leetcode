class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = (int)nums.size();
        
        int lastPossible = n - 1;
        
        for(int i = n - 2; i >= 0; i--){
            if(i + nums[i] >= lastPossible)
                lastPossible = i;
        }
        
        return (lastPossible == 0);
    }
};