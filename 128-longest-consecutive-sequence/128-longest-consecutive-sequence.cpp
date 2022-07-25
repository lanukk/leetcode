class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        unordered_map<int,int> mp;
        for(int i : nums)
            mp[i] = 1;
        int max_ans = 1;
        
        for(int i : nums){
            if(mp.find(i) == mp.end())
                continue;
            int k = i - 1;
            while(mp.find(k) != mp.end()){
                mp[i] += mp[k];
                mp.erase(k);
                k--;
            }
            max_ans = max(max_ans, mp[i]);            
        }
        return max_ans;
    }
};