class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int sum = 0;
        int ans = 0;
        for(int i : nums){
            if(i == 0)
                sum = 0;
            sum += i;
            ans = max(ans, sum);
        }
        
        return ans;
    }
};