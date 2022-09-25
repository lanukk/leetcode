class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> v;
        v.push_back(nums[0]);
        int ans = 1;
        
        for(int i : nums){
            if(i > v.back()){
                v.push_back(i);
                ans++;
            } else {
                v[lower_bound(v.begin(), v.end(), i) - v.begin()] = i;
            }
        }
        
        return ans;
    }
};