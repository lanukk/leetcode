#include<bits/stdc++.h>
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int ans = 0;
        int k = 0;
        vector<int> b;
        for(int i = 0; i < (int)nums.size(); i++){
            int j = i;
            while(j < (int)nums.size() && nums[i] == nums[j])
                j++;
            
            b.push_back(nums[i]);
            i = j - 1;
            ans++;
        }
        nums = b;
        
        return ans;
    }
};