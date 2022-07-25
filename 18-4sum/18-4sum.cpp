class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int n = (int)nums.size();
        
        for(int i = 0; i < n; i++){
            if(i > 0 && nums[i] == nums[i - 1])continue;
            
            for(int j = i + 1; j < n; j++){
                if(j > i + 1 && nums[j] == nums[j - 1]) continue;
                int prevk = INT_MIN, prevl = INT_MIN;
                
                int k = j + 1, l = n - 1;
                
                while(k < l){
                    if(nums[k] == prevk){
                        k++;
                        continue;
                    }
                    if(nums[l] == prevl){
                        l--;
                        continue;
                    }
                    long long sum = (long long)nums[i] + (long long)nums[j] + (long long)nums[k] + (long long)nums[l];
                    if(sum == target){
                        ans.push_back({nums[i], nums[j], nums[k], nums[l]});
                        prevk = nums[k];
                        prevl = nums[l];
                        continue;
                    }
                    if(sum > target){
                        l--;
                    } else{
                        k++;
                    }
                }
                
            }
        }
        return ans;
    }
};