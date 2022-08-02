class Solution {
public:

/*
[1, 2, 3]
 0

swaped([1], [1]) => vector --> [1, 2, 3]

swaped([1], [2]) => vector --> [2, 1, 3]

swaped([1], [3]) => vector --> [3, 2, 1]

[1] or [2] or [3]

*/
    vector<vector<int>> ans;
    void recursion(int i, vector<int> nums){
        if(i == (int)nums.size()){
            ans.push_back(nums);
            
            return;
        }
        
        for(int j = i; j < (int)nums.size(); j++){
            swap(nums[j], nums[i]);
            recursion(i + 1, nums);
            swap(nums[j], nums[i]);
        }
        
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        ans.clear();
        recursion(0, nums);
        return ans;
    }
};