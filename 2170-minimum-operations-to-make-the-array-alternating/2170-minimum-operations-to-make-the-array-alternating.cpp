class Solution {
public:
    int minimumOperations(vector<int>& a) {
        unordered_map<int,int> mp1, mp2;
        int n = (int) a.size();
        
        if(n == 1)
            return 0;
        
        for(int i = 0; i < n; i+= 2)
            mp1[a[i]]++;
        
        for(int i = 1; i < n; i+=2)
            mp2[a[i]]++;
        
        
        vector<pair<int, int> > v1, v2;
        
        for(auto x : mp1)
            v1.push_back({x.second, x.first});
        
        for(auto x : mp2)
            v2.push_back({x.second, x.first});
        
        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());
        reverse(v1.begin(), v1.end());
        reverse(v2.begin(), v2.end());
 
        if(v1[0].second != v2[0].second)
            return n - v1[0].first - v2[0].first;
        
        int best_ans = n - v1[0].first;
        
        if((int)v1.size() > 1)
            best_ans = min(best_ans, n - v1[1].first - v2[0].first);
        if((int)v2.size() > 1)
            best_ans = min(best_ans, n - v1[0].first - v2[1].first);
        
        return best_ans;        
    }
};