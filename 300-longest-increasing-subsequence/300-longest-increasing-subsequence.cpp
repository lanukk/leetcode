class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        set<int> s;
        for(int i : nums){
            auto it = s.lower_bound(i);
            if(it == s.end())
                s.insert(i);
            else{
                s.erase(it);
                s.insert(i);
            }
        }
        return (int)s.size();
    }
};