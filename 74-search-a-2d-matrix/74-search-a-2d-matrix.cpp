class Solution {
public:
    bool searchMatrix(vector<vector<int>>& a, int target) {
        int n = (int)a.size();
        int m = (int)a[0].size();
        
        int l = 0, r = n * m - 1;
        
        map<int, pair<int,int>> mp;
        int d = 0;
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                mp[d++] = {i, j};
            }
        }
        
        while(l <= r){
            int mid = (l + r) / 2;
            pair<int, int> p = mp[mid];
            
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