class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        int n = (int)nums.size();
        vector<vector<int>>ans;
        
        for(int i = 0; i < n; i++){
            if(i > 0 && nums[i] == nums[i - 1])
                continue;
            int j = i + 1;
            int k = n - 1;
            int prevj = INT_MIN;
            int prevk = INT_MIN;
            
            while(j < k){
                if(nums[j] == prevj){
                    j++;
                    continue;
                }
                if(nums[k] == prevk){
                    k--;
                    continue;
                }
                if(nums[j] + nums[k] + nums[i] == 0){
                    prevj = nums[j];
                    prevk = nums[k];
                    ans.push_back({nums[i], nums[j], nums[k]});
                    continue;
                }
                if(nums[j] + nums[k] + nums[i] > 0){
                    k--;
                    continue;
                }
                j++;
            }
        }
        return ans;
    }
};