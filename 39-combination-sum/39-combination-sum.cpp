class Solution {
public:
    vector<vector<int>> ans;
    
    void recursion(int i, int target, vector<int> & a, vector<int> temp){
        if(i == (int)a.size()){
            if(target == 0)
                ans.push_back(temp);
            return;
        }
        
        if(target - a[i] >= 0){
            temp.push_back(a[i]);
            recursion(i, target - a[i], a, temp);
            temp.pop_back();
        }
        recursion(i + 1, target, a, temp);
        
        return;
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        recursion(0, target, candidates, {});
        return ans;
    }
};