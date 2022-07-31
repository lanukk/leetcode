class Solution {
public:
    vector<vector<int>> ans;
    
    void recursion(int i, int target, vector<int> temp, vector<int> & a){

        
        if(target == 0){
            ans.push_back(temp);
            return;
        }
        
        if(i == (int)a.size())
            return;
        
        if(target < 0)
            return;
        
        for(int index = i; index < (int)a.size(); index++){
            if(index > i && a[index] == a[index - 1])
                continue;
                       
            temp.push_back(a[index]);
            
            recursion(index + 1, target - a[index], temp, a);
            
            temp.pop_back();
        }
           
        
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        recursion(0, target, {}, candidates);
        
        return ans;
    }
};