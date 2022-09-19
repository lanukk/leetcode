class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        priority_queue<int, vector<int>> pq;
        unordered_map<int, int> mp;
        for(int i = 0; i < k; i++){
            pq.push(nums[i]);
        }
        
        ans.push_back(pq.top());
        
        for(int i = k; i < (int)nums.size(); i++){
            mp[nums[i - k]]++;
            
            while(mp.find(pq.top()) != mp.end()){
                mp[pq.top()]--;
                if(mp[pq.top()] == 0){
                    mp.erase(pq.top());
                }
                
                pq.pop();
            }
            pq.push(nums[i]);
            ans.push_back(pq.top());
        }
        
        return ans;
    }
};