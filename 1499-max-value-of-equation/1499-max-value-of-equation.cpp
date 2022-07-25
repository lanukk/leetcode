class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        int ans = INT_MIN;
        
        reverse(points.begin(), points.end());
        multiset<int, greater<int>> s;
        s.insert(points[0][1] - points[0][0]);
        
        int l = 1;
        
        for(int i = 0; i < (int)points.size(); i++){
            auto it = s.find(points[i][1] - points[i][0]);
            if(it != s.end())
                s.erase(it);
            l = max(l, i + 1);
            int j = l;
            while(j < (int)points.size() && points[i][0] - k <= points[j][0]){
                s.insert(points[j][1] - points[j][0]);
                l++;
                j++;
            }
            
            if((int)s.size() > 0){
                // cout<<*s.begin()<<" ";
                ans = max(ans, points[i][0] + points[i][1] + *s.begin());
                // if(ans == 14)cout<<i<<"\n";
            }
                        
        }
        
        return ans;
    }
};