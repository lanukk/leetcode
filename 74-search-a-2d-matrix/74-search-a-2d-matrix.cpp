class Solution {
public:
    bool searchMatrix(vector<vector<int>>& a, int target) {
        int n = (int)a.size();
        int m = (int)a[0].size();
        
        int l = 0, r = n * m - 1;
        
                
        while(l <= r){
            int mid = (l + r) / 2;
            pair<int, int> p = {mid / m, mid % m};
            
            if(a[p.first][p.second] == target)
                return true;
            
            if(a[p.first][p.second] > target)
                r = mid - 1;
            else
                l = mid + 1;
        }
        return false;
    }
};