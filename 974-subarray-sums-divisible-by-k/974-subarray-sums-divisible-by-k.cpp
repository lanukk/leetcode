class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int sum = 0;
        int ans = 0;
        
        for(int i : nums){
            sum += i;
            sum = ((sum % k) + k) % k;
            if(sum == 0)
                ans++;
            if(mp.find(sum) != mp.end())
                ans += mp[sum];
            mp[sum]++;
        }
        return ans;
    }
};