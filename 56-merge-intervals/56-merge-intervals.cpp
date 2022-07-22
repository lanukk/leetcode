class Solution {
public:
    
    int lie(int a, int b, int c, int d){
        if(c >= a && c <= b)
            return 1;
        if(d >= a && d <= b)
            return 1;
        return 0;
    }
    
    
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> v;
        int l = INT_MAX, r = INT_MIN;
        sort(intervals.begin(), intervals.end());
        
        for(auto x : intervals){
            if(l == INT_MAX && r == INT_MIN){
                l = x[0];
                r = x[1];
            } else {
                bool check = (lie(l, r, x[0], x[1]) | lie(x[0], x[1], l, r));
                if(check){
                    l = min(l, x[0]);
                    r = max(r, x[1]);
                } else {
                    v.push_back({l, r});
                    l = x[0];
                    r = x[1];
                }
            }
        }
        v.push_back({l, r});
        
        return v;
    }
};